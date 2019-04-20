#include "../include/graal.h"
#include <cstring>
#include <iostream>
#include <iterator> // std::begin() , std::end()

const void *graal::min(const void *first, const void *last, size_t size, Compare cmp){
    const byte *menor = (const byte*)first; //const int menor = first;
    const byte *it = (const byte*) first; //auto it{first};
    it += size; //começar do segundo
    while( it != last ){
        if(cmp(it, menor)){
            //Atualizar o menor
            menor = it;
        }
        it += size;
    }
    return menor;
}

void graal::reverse(void *first, void *last, size_t size){
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    byte *aux = new byte[size];
    plast -= size;
    while(pfirst < plast){
        std::memcpy(aux, pfirst, size); //int aux = *pfirst+i;
        std::memcpy(pfirst, plast, size); //*pfirst+i = *plast-i-1;
        std::memcpy(plast, aux, size); //*plast-i-1 = aux;
        pfirst += size;
        plast -= size;
    }
}

void *graal::copy(const void *first, const void *last, const void *d_first, size_t size){
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    byte *pd_first = (byte *)d_first;
    byte *pd_last = (byte *)pd_first; //pointer that will be returned
    // int cont = 0;
    while(pfirst != plast){
        std::memcpy(pd_first, pfirst, size);
        pfirst += size;
        pd_first += size;
        // cont++;
        pd_last = pd_first;
    }
    pd_last += size;
    // pd_last = (pd_first+(cont*size));
    return pd_last;
}

void *graal::clone(const void *first, const void *last, size_t size){
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    int distance = (plast-pfirst)/size;
    byte *newArray = new byte[distance*size];
    byte *toReturn = newArray;
    while(pfirst != plast){
        std::memcpy(newArray, pfirst, size);
        // std::cout << (int)*(newArray) << " ";
        pfirst += size;
        newArray += size;
    }
    return toReturn;
}

const void *graal::find_if(const void *first, const void *last, size_t size, Predicate p){
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    while(pfirst != plast){
        if(p(pfirst)){
            byte *toReturn = pfirst;
            return toReturn;
        }
        pfirst += size;
    }
    return plast;
}

const void *graal::find(const void *first, const void *last, size_t size, const void *value, Equal eq){
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    byte *pvalue = (byte *)value;
    while(pfirst != plast){
        if(eq(pfirst, pvalue)){
            byte *toReturn = pfirst;
            return toReturn;
        }
        pfirst += size;
    }
    return plast;
}

bool graal::all_of(const void *first, const void *last, size_t size, Predicate p){
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    if((plast-pfirst)/size == 0){
        return true;
    }
    else{
        while(pfirst != plast){
            if(!p(pfirst)){
                return false;
            }
            pfirst += size;
        }
    }
    return true;
}

bool graal::any_of(const void *first, const void *last, size_t size, Predicate p){
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    if((plast-pfirst)/size == 0){
        return true;
    }
    else{
        while(pfirst != plast){
            if(p(pfirst)){
                return true;
            }
            pfirst += size;
        }
    }
    return false;
}

bool graal::none_of(const void *first, const void *last, size_t size, Predicate p){
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    while(pfirst != plast){
        if(p(pfirst)){
            return false;
        }
        pfirst += size;
    }
    return true;
}

bool graal::equal(const void *first1, const void *last1, const void *first2, size_t size, Equal eq){
    byte *pfirst1 = (byte *)first1;
    byte *plast1 = (byte *)last1;
    byte *pfirst2 = (byte *)first2;
    byte *lastRange = (byte *)((pfirst2+(plast1-pfirst1)));
    while(pfirst2 != lastRange){
        if(!eq(pfirst1, pfirst2)){
            return false;
        }
        pfirst1 += size;
        pfirst2 += size;
    }
    if(pfirst1 != plast1){
        return false;
    }
    return true;
}

bool graal::equal(const void *first1, const void *last1, const void *first2, const void *last2, size_t size, Equal eq){
    byte *pfirst1 = (byte *)first1;
    byte *plast1 = (byte *)last1;
    byte *pfirst2 = (byte *)first2;
    byte *plast2 = (byte *)last2;
    while(pfirst2 != plast2){
        if(!eq(pfirst1, pfirst2)){
            return false;
        }
        pfirst1 += size;
        pfirst2 += size;
    }
    if(pfirst1 != plast1){
        return false;
    }
    return true;
}

void *graal::unique(void *first, void *last, size_t size, Equal eq){
    byte *clone = (byte *)first; //para conferir com cada valor anterior no for
    // value_type *clone = first; //para conferir com cada valor anterior no for
    byte *aux = (byte *)first; //será o novo last. Possui o local do próximo elemento candidato
    // value_type *aux = first; //será o novo last. Possui o local do próximo elemento candidato
    int cont = 0; //para saber em que indice o first(que anda pelo vetor) está
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    while(pfirst != plast){
        if(cont == 0){ //pois cont=0 faz não entrar no for
            aux += size;
        }
        else{
            for(int i = 0; i < cont; i++){
                if(eq(pfirst, (clone+i*size))){
                    break;
                }
                else if(!eq(pfirst, clone+i*size) && i == cont-1){
                    *aux = *pfirst;
                    aux += size;
                }
            }
        }
        pfirst += size;
        cont++;
    }
    return aux;
}

void *graal::partition(void *first, void *last, size_t size, Predicate p){
    byte *aux = (byte *)first; // Marca a região dos menores-que-o-pivot    
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    while(pfirst < plast-size){
        if(p(pfirst)){
            //Sim, então devemos lançar o elemento na região dos menores:
            byte temp[size]; //variável auxiliar pra fazer o swap
            std::memcpy(temp, aux, size); //std::swap(*aux, *pfirst);
            std::memcpy(aux, pfirst, size);
            std::memcpy(pfirst, temp, size);
            //Não esquecer de aumentar a região dos menores-que-o-pivot:
            aux += size; //Avança quando faz swap com fast quando fast < pivot
        }
        pfirst += size; //first sempre é incrementado a cada iteração. Sempre move.
    }
    byte temp2[size];
    std::memcpy(temp2, (plast-size), size); // std::swap(*(plast-size), *aux);
    std::memcpy((plast-size), aux, size);
    std::memcpy(aux, temp2, size);
    return aux;
}

void *graal::partition(void *first, void *last, void *pivot, size_t size, Compare cmp){
    byte *aux = (byte *)first; // Marca a região dos menores-que-o-pivot    
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    byte *p_pivot  = (byte *)pivot;
    byte temp[size]; //variável auxiliar pra fazer o swap
    std::memcpy(temp, p_pivot, size); //std::swap(*aux, *pfirst);
    std::memcpy(p_pivot, plast-size, size);
    std::memcpy(plast-size, p_pivot, size);
    while(pfirst != plast){
        if(cmp(pfirst, plast-size)){
            //Sim, então devemos lançar o elemento na região dos menores:
            std::memcpy(temp, aux, size); //std::swap(*aux, *pfirst);
            std::memcpy(aux, pfirst, size);
            std::memcpy(pfirst, temp, size);
            //Não esquecer de aumentar a região dos menores-que-o-pivot:
            aux += size; //Avança quando faz swap com fast quando fast < pivot
        }
        pfirst += size; //first sempre é incrementado a cada iteração. Sempre move.
    }
    std::memcpy(temp, (plast-size), size); // std::swap(*(plast-size), *aux);
    std::memcpy((plast-size), aux, size);
    std::memcpy(aux, temp, size);
    return aux;
}

void graal::qsort(void *first, void *last, size_t size, Compare cmp){
    byte *pfirst = (byte *)first; 
    byte *plast = (byte *)last;
    if(pfirst < plast){
        byte *pivot = (byte *)graal::partition(pfirst, plast, plast-size, size, cmp);
        graal::qsort(pfirst, pivot, size, cmp);
        graal::qsort(pivot+size, plast, size, cmp);
    }
}

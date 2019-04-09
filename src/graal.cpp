#include "../include/graal.h"
#include <cstring>
#include <iostream>
#include <iterator> // std::begin() , std::end()

const void *min(const void *first, const void *last, size_t size, Compare cmp){
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

void reverse(void *first, void *last, size_t size){
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    byte *aux = new byte[size];
    plast -= size;
    while(pfirst != plast){
        std::memcpy(aux, pfirst, size); //int aux = *pfirst+i;
        std::memcpy(pfirst, plast, size); //*pfirst+i = *plast-i-1;
        std::memcpy(plast, aux, size); //*plast-i-1 = aux;
        pfirst += size;
        plast -= size;
        // std::swap(*(first+i), *(last-i-1));
    }
}

void *copy(const void *first, const void *last, const void *d_first, size_t size){
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

void *clone(const void *first, const void *last, size_t size){
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

const void *find_if(const void *first, const void *last, size_t size, Predicate p){
    byte *pfirst = (byte *)first;
    byte *plast = (byte *)last;
    while(pfirst != plast){
        if(p(pfirst)){
            byte *toReturn = pfirst;
            return toReturn;
        }
        pfirst++;
    }
    return plast;
}

// void reverse( void *first, void *last, size_t size )
// {
//     byte *pfirst = (byte *)first;
//     byte *plast = (byte *)last;
//     byte *aux = new byte[size];
//     int half = std::distance(pfirst,plast)/2;
//     plast -= size;
//     for(int i = 0; i < half; i++){
//         pfirst += i*size;
//         plast -= i*size;
//         std::memcpy(aux, pfirst, size); //int aux = *pfirst+i;
//         std::memcpy(pfirst, plast, size); //*pfirst+i = *plast-i-1;
//         std::memcpy(plast, aux, size); //*plast-i-1 = aux;
//         // std::swap(*(first+i), *(last-i-1));
//     }
// }

// void scalar_multiplication(value_type *first, value_type *last, value_type scalar){
//     while(first != last){
//         *first *= scalar;
//         first++;
//     }
// }

// value_type dot_product(const value_type *a_first, const value_type *a_last, const value_type *b_first){
//     value_type lenght = std::distance(a_first, a_last);
//     value_type s_prod = 0;
//     for(value_type i = 0; i < lenght; i++){
//         s_prod += *(a_first+i) * *(b_first+i);
//     }
//     return s_prod;
// }

// value_type *compact(value_type *first, value_type *last){
//     value_type *aux = first;
//     while(first != last){
//         if(*first > 0){
//             *aux = *first;
//             aux++;
//         }
//         first++;
//     }
//     return aux;
// }

// value_type *unique(value_type *first, value_type *last){
//     value_type *clone = first; //para conferir com cada valor anterior no for
//     value_type *aux = first; //será o novo last. Possui o local do próximo elemento candidato
//     value_type cont = 0; //para saber em que indice o first(que anda pelo vetor) está
//     while(first != last){
//         if(cont == 0){ //pois cont=0 faz não entrar no for
//             aux++;
//         }
//         else{
//             for(value_type i = 0; i < cont; i++){
//                 if(*first == *(clone+i)){
//                     break;
//                 }
//                 else if(*first != *(clone+i) && i == cont-1){
//                     *aux = *first;
//                     aux++;
//                 }
//             }
//         }
//         first++;
//         cont++;
//     }
//     return aux;
// }

// value_type *sort_marbles(value_type *first, value_type *last){
//     value_type *aux = first;
//     value_type *clone = first;
//     value_type cont = 0;
//     while(aux != last){
//         if(*first == 1 && *aux == 0){
//             std::swap(*first, *aux);
//             first++;
//         }
//         aux++;
//         if(*first == *(first+1)){
//             cont++;
//         }
//     }
//     if(cont == std::distance(first, last) && *(last-1)==1){ //se todas bolas forem brancas
//         return last;
//     }
//     else if(cont == std::distance(first, last) && *(last-1)==0){ //se todas bolas forem brancas
//         return clone;
//     }
//     return first;

// }

// void partition(value_type *first, value_type *last, value_type *pivot){
//     int i, j, aux;
//     for (i = 1; i < std::distance(first, last); i++){
//         j = i;
//         while(j > 0 && first[j - 1] > first[j]){
//             aux = first[j];
//             first[j] = first[j - 1];
//             first[j - 1] = aux;
//             j--;
//         }
//     }
// }

// void *rotate(value_type *first, value_type *n_first, value_type *last){
//     int *aux = new int[(n_first-first)];
//     copy(first, first + (n_first-first), aux);
//     while(n_first < last){
//         *first = *(first+(n_first - first));
//         first++;
//         n_first++;
//     }
//     while(first < last){
//         *first = *aux;
//         aux++;
//         first++;
//     }
// }

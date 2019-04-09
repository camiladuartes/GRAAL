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

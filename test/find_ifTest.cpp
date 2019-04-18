#include <iostream> // std::cout , std::endl
#include <iterator> // std::begin() , std::end()

#include "../include/graal.h"

using namespace std;

bool p_int(const void *pred){
    const int *p_pred = (const int*)pred;
    int value = 2;
    return *p_pred == value;
}

bool p_float(const void *pred){
    const float *p_pred = (const float*)pred;
    float value = 98.5;
    return *p_pred == value;
}

int main(void){
    int A [] = {1, 2, 3, 4, 5, 4, 4};
    float B[] = {2.3, 1.1, 4.5, 6.7, 3, 1.1, 5};

    std::cout << ">>> pointerA: ";
    int *pointerA = (int *)graal::find_if(begin(A), end(A), sizeof(int), p_int);
    if(pointerA != std::end(A)){
        std::cout << "Elemento: " << *pointerA;
        std::cout << ". Endereço: " << pointerA << std::endl;
    }
    else{
        std::cout << "Valor não encontrado\n";
    }

    std::cout << ">>> pointerB: ";
    float *pointerB = (float *)graal::find_if(begin(B), end(B), sizeof(float), p_float);
    if(pointerB != std::end(B)){
        std::cout << "Elemento: " << *pointerB;
        std::cout << ". Endereço: " << pointerB << std::endl;   
    }
    else{
        std::cout << "Valor não encontrado\n";
    }
    return 0;
}

#include <iostream> // std::cout , std::endl
#include <iterator> // std::begin() , std::end()

#include "../include/graal.h"

using namespace std;

bool p_int(const void *pred){
    const int *p_pred = (const int*)pred;
    return *p_pred == 4;
}

bool p_float(const void *pred){
    const float *p_pred = (const float*)pred;
    return *p_pred == 1.1;
}

int main(void){
    int A [] = {1, 2, 3, 4, 5, 4, 4};
    float B[] = {2.3, 1.1, 4.5, 6.7, 3, 1.1};

    std::cout << ">>> pointerA: ";
    int *pointerA = (int *)find_if(begin(A), end(A), sizeof(int), p_int);
    std::cout << "Elemento: " << *pointerA;
    std::cout << ". Endereço: " << pointerA << std::endl;
   
    std::cout << ">>> pointerB: ";
    float *pointerB = (float *)find_if(begin(B), end(B), sizeof(float), p_float);
    std::cout << "Elemento: " << *pointerB;
    std::cout << ". Endereço: " << pointerB << std::endl;   

    return 0;
}
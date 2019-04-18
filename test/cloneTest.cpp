#include <iostream> // std::cout , std::endl
#include <iterator> // std::begin() , std::end()

#include "../include/graal.h"

using namespace std;

int main(void){
    int A [] = {1, 2, 3, 4, 5};
    float B[] = {2.3, 4.5, 6.7, 8, 3};
	
    std::cout << ">>> arrayA: ";
	/*Precisa do cast(int) pois é retornado um ponteiro
	void já que a função é do tipo void*/
	int *arrayA = (int *)graal::clone(A+1, A+4, sizeof(int));
	int cont = 0;
	while(cont < std::distance(A+1, A+4)){
		cout << *(arrayA+cont) << " ";
		cont++;
	}
	cout << std::endl;

    std::cout << ">>> arrayB: ";
	float *arrayB = (float *)graal::clone(B, B+4, sizeof(float));
	cont = 0;
	while(cont < std::distance(B, B+4)){
		cout << *(arrayB+cont) << " ";
		cont++;
	}
	cout << std::endl;

	return 0;
}

#include <iostream> // std::cout , std::endl
#include <iterator> // std::begin() , std::end()
#include <cassert>
#include <algorithm>

#include "../include/graal.h"

using namespace std;

void print_ints(int *first, int *last){
	std::cout << "[ ";
	while(first != last){
		std::cout << *first++ << " ";
	}
	std::cout << "]";
}
void print_floats(float *first, float *last){
	std::cout << "[ ";
	while(first != last){
		std::cout << *first++ << " ";
	}
	std::cout << "]";
}
bool compare_floats(const void *va, const void *vb){
	//Converter o ponteiro genérico para o tipo esperado.
	const float *a = (const float *) va;
	const float *b = (const float *) vb;
	// ... de maneira de que agora é possível desrreferenciar o ponteiro.
	return *a < *b;
}
bool compare_ints(const void *va, const void *vb){
	//Converter o ponteiro genérico para o tipo esperado.
	const int *a = (const int *) va;
	const int *b = (const int *) vb;
	// ... de maneira de que agora é possível desrreferenciar o ponteiro.
	return *a < *b;
}

int main () {
	float A[]{2.3, 5.8, -2.1, 10.3, -5};
	int B[]{4, 3, -2, 5, -1, 0, 9};

	std::cout << ">>> Array A: ";
	print_floats(A, std::end(A)); std::cout << std::endl;
	float *menorA = (float*) min(A, std::end(A), sizeof(float), compare_floats);
	std::cout << ">>> O menor elemento em A eh: " << *menorA << std::endl;

	std::cout << ">>> Array B: ";
	print_ints(B, std::end(B)); std::cout << std::endl;
	int *menorB = (int*) min(B, std::end(B), sizeof(int), compare_ints);
	std::cout << ">>> O menor elemento em B eh: " << *menorB << std::endl;

	return 0;
}

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
	//COnverter o ponteiro genérico para o tipo esperado.
	const float *a = (const float *) va;
	const float *b = (const float *) vb;
	// ... de maneira de que agora é possível desrreferenciar o ponteiro.
	return *a < *b;
}
bool compare_ints(const void *va, const void *vb){
		//COnverter o ponteiro genérico para o tipo esperado.
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

/*
	int Vet[] = {1,2,-3,-4,5,-6};
	scalar_multiplication(begin(Vet), end(Vet), 3);
	for(auto i(begin(Vet)); i!= end(Vet); ++i){
		cout << *i << " ";
	}
	cout << std::endl;
*/

/*
	int Vet[] = {1, 3, -5, 4, -2, -1};
	auto result = dot_product(begin(Vet), begin(Vet)+3, begin(Vet)+3);
	cout << ">>> O resultado é: " << result << std::endl;
*/

/*
	int A[] = {1,2,3,4,5};
	int B[] = {0,0,0};

	auto b_last = copy(cbegin(A)+1, cbegin(A)+4, begin(B));
	for(auto i(begin(B)); i!= b_last; ++i){
		cout << *i << " ";
	}
	cout << std::endl;

	return 0;
*/

/*
		int A[] = {-2, -8, 2, 7, -3, 10, 1, 0, -3, 7};

	auto new_last = compact(begin(A), end(A));
	for(auto i(begin(A)); i!= new_last; ++i){
		cout << *i << " ";
	}
	cout << std::endl;

	return 0;
*/

/*
	int A[] = {1,2,1,2,3,3,1,2,4,5,3,4,5};

	auto last = unique(begin(A), end(A));
	for(auto i(begin(A)); i!= end(A); ++i){
		cout << *i << " ";
	}
	cout << std::endl;

	return 0;
*/

/*
	enum ball_t {B = 0, W = 1};

	int main () {

		ball_t A[] = {W, B, B, W, W, B, W};

		auto result = sort_marbles(begin(A), end(A));
		for(auto i(begin(A)); i!= result; ++i){
			cout << *i << " ";
		}
		cout << std::endl;

	}
*/

/*
	int A[] = {-5, 7, 10, 7, 8, 9, 1, 7, -2, 3};
	int *pivot = &A[3];
	partition(begin(A), end(A), pivot);
	for(auto i(begin(A)); i!= end(A); ++i){
		cout << *i << " ";
	}
	cout << std::endl;
*/

/*
	value_type A[]{ 1, 2, 3, 4, 5, 6 };

	rotate( std::begin(A), std::begin(A)+5, std::end(A) );
	for(auto i(begin(A)); i!= end(A); ++i){
		cout << *i << " ";
	}
	cout << std::endl;
*/
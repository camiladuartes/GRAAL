#include <iostream> // std::cout , std::endl
#include <iterator> // std::begin() , std::end()
#include <cassert>
#include <algorithm>

#include "../include/graal.h"

using namespace std;

int main(void){
    int A [] = {1 , 2 , 3, 4, 5};
    int A1[] = {0, 0, 0};
    float B[] = {2.3, 4.5, 6.7, 8, 3};
    float B1[] = {0, 0, 0};
	
    std::cout << ">>> Array A1: ";
	std:: cout << copy(A+1, A+4, A1, sizeof(int));
	for(auto i(begin(A1)); i!= end(A1); ++i){
		cout << *i << " ";
	}
	cout << std::endl;

    std::cout << ">>> Array B1: ";
	copy(B+1, B+4, B1, sizeof(float));
	for(auto i(begin(B1)); i!= end(B1); ++i){
		cout << *i << " ";
	}
	cout << std::endl;

	return 0;
}

#include <iostream> // std::cout , std::endl
#include <iterator> // std::begin() , std::end()
#include <cassert>
#include <algorithm>

#include "../include/graal.h"

using namespace std;

int main(void){
    int A [] = {1 , 2 , 3, 4, 5};
    float B[] = {2.3, 4.5, 6.7, 8, 3};
	
    std::cout << ">>> Array A: ";
	reverse(begin(A), end(A), sizeof(int));
    //expect: 5,4,3,2,1	
	for(auto i(begin(A)); i!= end(A); ++i){
		cout << *i << " ";
	}
	cout << std::endl;

    std::cout << ">>> Array B: ";
	reverse(begin(B), end(B), sizeof(float));
    //expect: 3,8,6.7,4.5,2.3
	for(auto i(begin(B)); i!= end(B); ++i){
		cout << *i << " ";
	}
	cout << std::endl;

	return 0;
}
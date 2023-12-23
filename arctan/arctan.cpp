#include <iostream>
#include <iomanip>
#include <chrono>

/*
 * Am using a double for now since the cfloat library was a little difficult to navigate
 * The exponent function could be replaced with a cmath function but this is all from the basics, 
 * should also be changed to be a recursive function and not have a for loop
 */

double exponent(double base, int exponent){
	double result = base;
	for (int i=1; i<exponent; i++){
		result *= base;
	}
	return result;
}

double arctan(double input, int order){
	double result = 0;
	for (int i=1; i<=order; i+=2){
		result += exponent(-1, (i+1)/2)*exponent(input, i)/i;
	}
	return -result;
}

int main() {
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << std::fixed << std::setprecision(40);
    std::cout<< (arctan(1, 100000)*4) << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
    return 0;
}

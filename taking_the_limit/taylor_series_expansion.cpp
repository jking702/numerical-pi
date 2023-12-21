#include <iostream>
#include <iomanip>

/*
 * Am using a double for now since the cfloat library was a little difficult to navigate
 * The exponent function could be replaced with a cmath function but this is all from the basics
 */

double exponent(double base, int exponent){
	double result = base;
	for (int i=1; i<exponent; i++){
		result *= base;
	}
	return result;
}

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

double sine(double input, int order){
	double result = 0;
	for (int i=1; i<order; i+=2){
		result += exponent(-1, (i+1)/2)*exponent(input, i)/factorial(i);
	}
	return -result;
}

int main() {
	std::cout << std::fixed << std::setprecision(40);
    std::cout<< exponent(2, 3) << std::endl;
    std::cout<< exponent(-1, (1+1)/2) <<std::endl;
    std::cout<< sine(0.1, 5) << std::endl;
    return 0;
}

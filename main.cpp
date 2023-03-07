#include "heat.h"
// Include header file for standard input/output stream library
#include <iostream>

int main(int argc, char* argv[])
{
	// Verification of 1d system matrix
	Heat<1, double> Heat1d(0.3125, 3, 0.1);
	std::cout << "1D matrix: " << std::endl;
	Heat1d.getMatrix();
	std::cout << std::endl;

	// Verification of 2d system matrix
	Heat<2, double> Heat2d(0.3125, 3, 0.1);
	std::cout << "2D matrix: " << std::endl;
	Heat2d.getMatrix();
	std::cout << std::endl;

	return 0;
}
#include <iostream>
#include <cmath>

void fillValues(std::vector<double> &input, const double fillValue) {
	for (size_t i = 0; i < input.size() - 1; ++i) {
		input[i +1] = input[i] + fillValue;
	}
} 

double phi(double x) { //начальное условие при t = 0
	return x
}

double psi(double t) { //граничное условие при r = 0
	return 0
}

int main(int argc, char*argv[]) {
	int gridHeight;
	int gridDepth;
	
	std::vector<double> x(gridHeight + 1, 0); //значения x
	std::vector<double> t(gridDepth + 1, 0); //значения t
	std::vector<double> upperLayerValues(gridHeight + 1);
	std::vector<double> bottomLayerValues(gridHeight + 1);

	const double xStep = L / gridHeight;
	const double tau = T / gridDepth;

	fillValues(x, xStep);
	fillValues(t, tau);

	double Q = tau / xStep; //число Куранта
	
	std::ofstream out("start0.txt");

	std::cout << "depth = " << 0 <<std::endl;

	for (size_t i = 0; i <= gridHeight; ++i) {
		upperLayerValues[i] = phi(x[i]);
		out << x[i] << std::setw(10) << upperLayerValues[i] << " ";
		
	}
	
	std::cout << std::endl;

	const std::string filename = "start";

	 

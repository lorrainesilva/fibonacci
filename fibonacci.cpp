#include <cmath>
#include <iostream>

long long unsigned int recursive(long long unsigned int n) {
	if (n == 1 || n == 2)
		return 1;
	else
		return recursive(n - 1) + recursive(n - 2);
}

long long unsigned int iterative(int n) {
	long long unsigned int fib_n1, fib_n2, fib_n;
	for (int i = 1; i <= n; i++) {
		if (i == 1 || n == 2)
			fib_n = 1;
		else
			fib_n = fib_n1 + fib_n2;

		fib_n2 = fib_n1;
		fib_n1 = fib_n;
	}
	return fib_n;
}

long long unsigned int formula(long long unsigned int n) {
	double gold_number = (1 + sqrt(5)) / 2.0;

	return round(pow(gold_number, n) / sqrt(5));
}

long long unsigned int matrix(long long unsigned int n) {
	long long unsigned int mat[2][2];
	long long unsigned int fib[2][2];

	long long unsigned int fib_n_p_1;
	long long unsigned int fib_n_m_1;
	long long unsigned int fib_n;

	mat[0][0] = 1;
	mat[0][1] = 1;
	mat[1][0] = 1;
	mat[1][1] = 0;

	fib[0][0] = 1;
	fib[0][1] = 1;
	fib[1][0] = 1;
	fib[1][1] = 0;

	for (int i = 0; i < n; i++) {
		fib_n_p_1 = (fib[0][0] *  mat[0][0]) + (fib[0][1] * mat[1][0]);
		fib_n_m_1 = (fib[1][0] *  mat[0][1]) + (fib[1][1] * mat[1][1]);
		fib_n_m_1 = (fib[0][0] *  mat[0][1]) + (fib[0][1] * mat[1][1]);

		fib[0][0] = fib_n_p_1;
		fib[0][1] = fib_n;
		fib[1][0] = fib_n;
		fib[1][1] = fib_n_m_1;
	}

	return fib[0][1];

}

int main() {
	std::cout << "Formula:" << std::endl;
	std::cout << formula(5) << std::endl;
	std::cout << formula(10) << std::endl;
	std::cout << formula(20) << std::endl;
	std::cout << formula(40) << std::endl;
	std::cout << formula(60) << std::endl;

	std::cout << "\nMatriz:" << std::endl;
	std::cout << matrix(5) << std::endl;
	std::cout << matrix(10) << std::endl;
	std::cout << matrix(20) << std::endl;
	std::cout << matrix(40) << std::endl;
	std::cout << matrix(60) << std::endl;

	std::cout << "\nLaco for:" << std::endl;
	std::cout << iterative(5) << std::endl;
	std::cout << iterative(10) << std::endl;
	std::cout << iterative(20) << std::endl;
	std::cout << iterative(40) << std::endl;
	std::cout << iterative(60) << std::endl;

	std::cout << "\nRecursivo:" << std::endl;
	std::cout << recursive(5) << std::endl;
	std::cout << recursive(10) << std::endl;
	std::cout << recursive(20) << std::endl;
}

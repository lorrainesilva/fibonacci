#include <cmath>
#include <iostream>
#include <ctime>

long long unsigned int recursive(long long unsigned int n) {
	if (n == 1 || n == 2)
		return 1;
	else
		return recursive(n - 1) + recursive(n - 2);
}

long long unsigned int iterative(int n) {
	long long unsigned int fib_n1, fib_n2, fib_n;
	for (int i = 1; i <= n; i++) {
		if (i == 1 || i == 2)
			fib_n = 1;
		else
			fib_n = fib_n1 + fib_n2;

		fib_n2 = fib_n1;
		fib_n1 = fib_n;
	}
	return fib_n;
}

long long unsigned int formula(int n) {
	long double gold_number = (1 + sqrt(5)) / 2.0;

	return std::round(std::pow(gold_number, n) / sqrt(5));
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

	for (int i = 2; i <= n; i++) {
		fib_n_p_1 = (fib[0][0] *  mat[0][0]) + (fib[0][1] * mat[1][0]);
		fib_n_m_1 = (fib[1][0] *  mat[0][1]) + (fib[1][1] * mat[1][1]);
		fib_n = (fib[0][0] *  mat[0][1]) + (fib[0][1] * mat[1][1]);

		fib[0][0] = fib_n_p_1;
		fib[0][1] = fib_n;
		fib[1][0] = fib_n;
		fib[1][1] = fib_n_m_1;
	}

	return fib[0][1];

}

int main() {
	clock_t begin, end;
	long long unsigned int result;

	std::cout << "Formula:" << std::endl;

	begin = std::clock();
	result = formula(5);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;
	begin = std::clock();
	result = formula(10);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;
	begin = std::clock();
	result = formula(20);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;
	begin = std::clock();
	result = formula(40);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;
	begin = std::clock();
	result = formula(60);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;

	std::cout << "\nMatriz:" << std::endl;
	begin = std::clock();
	result = matrix(5);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;

	begin = std::clock();
	result = matrix(10);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;

	begin = std::clock();
	result = matrix(20);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;

	begin = std::clock();
	result = matrix(40);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;

	begin = std::clock();
	result = matrix(60);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;


	std::cout << "\nLaco for:" << std::endl;
	begin = std::clock();
	result = iterative(5);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;

	begin = std::clock();
	result = iterative(10);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;

	begin = std::clock();
	result = iterative(20);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;

	begin = std::clock();
	result = iterative(40);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;

	begin = std::clock();
	result = iterative(60);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;


	std::cout << "\nRecursivo:" << std::endl;
	begin = std::clock();
	result = recursive(5);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;

	begin = std::clock();
	result = recursive(10);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;

	begin = std::clock();
	result = recursive(20);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;

	begin = std::clock();
	result = recursive(40);
	end = std::clock() - begin;
	std::cout << result << " " << (float(end))/CLOCKS_PER_SEC << std::endl;
}

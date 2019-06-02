long long unsigned int recursive(long long unsigned int n) {
	if (n == 1 || n == 2)
		return 1;
	else
		return recursive(n - 1) + recursive(n - 2);
}

int iterative(int n) {
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

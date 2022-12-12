#include <iostream>
using namespace std;
int factorial(int);

int main(void) {
	int N, result = 1;
	cin >> N;
	if (N != 0)
		result = factorial(N);
	cout << result;
}

int factorial(int n) {
	if (n > 2)
		n *= factorial(n - 1);
	return n;
}
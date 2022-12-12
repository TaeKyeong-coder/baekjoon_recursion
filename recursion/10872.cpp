#include <iostream>
using namespace std;
int fiv(int);

int main(void) {
	//0, 1, 0+1=1, 1+1=2...
	int n;
	cin >> n;

	int answer = fiv(n);

	cout << answer;
}

int fiv(int f) {
	if (f == 0)
		return 0;
	else if (f == 1) return 1;
	else
		return fiv(f - 1) + fiv(f - 2);
}
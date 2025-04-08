#include <iostream>

int countDigit(int n) {
	int ans;
	if (n == 0)
		return 0;
	ans = countDigit(n / 10) + 1;
	return ans;
}

int main() {
	int n = 123;
	std::cout << countDigit(n);
	return 0;
}
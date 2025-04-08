#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{	
	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int l, r;
		cin >> l >> r;
		int count = 0;
		int a = l + 1;
		int diff = a - l;
		while (l < r) {
			count++;
			l = l + l;
		}
		cout << count << endl;
	}
	
	return 0;
}
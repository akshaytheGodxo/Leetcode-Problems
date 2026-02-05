#include <cmath>
#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
		
		bool isPowerOfTwo(unsigned int x) {
			return x && (!(x & (x - 1)));
		}
		
		bool isDifferent(unsigned int a, unsigned int b) {
			return isPowerOfTwo(a ^ b);
		}

		std::vector<int> grayCode(int n) {
			std::vector<int> ans;
			int range = pow(2, n) - 1;
			std::map<int, bool> check;
			for (int i=0;i<= range;i++) check[i] = false;
			ans.push_back(0);
			check[0] = true;
			int val = 0;
			int size = 1;
			while (size != range) {
				for (int i=0;i<= range;i++) {
					if (!check[i]) {
						std::cout << check[i] << std::endl;
						int bit = isDifferent(val, i);
							
						if (bit == 1) {
							val = i;
							ans.push_back(i);
							check[i] = true;
						} else {
							continue;
						}
					} else {
						continue;
					}
					
				}

				size++;
			}

			return ans;
		}
};


int32_t main() {
	Solution st;

	int n;
	std::cin >> n;

	std::vector<int> v = st.grayCode(n);

	for (auto i : v) std::cout << i << " ";
	
	int bit = 1 & 3;
	std::cout << bit << "\n";
	return EXIT_SUCCESS;
}

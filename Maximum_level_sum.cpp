#include "tree.h"
#include <iostream>


using namespace Aks;
using namespace std;


class Solution {
public:
	int maxLevelSum(BTREE* root) {
		int level;
		int max_sum = 0;

		int ans = max(maxLevelSum(root->right) + maxLevelSum(root->left), max_sum);
		return ans;
	}
};

int main() {
	BTREE* root = CreateNode(1);
	AddChildren(root, 7, 0);
	AddChildren(root->right, 7, -8);


	return 0;
}
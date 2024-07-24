#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
int main() {
    std::vector<int> v = {1, 2, 3};
    std::vector<int> u = {4, 5, 3};
    int m = 3;
    for (auto i : v) {
        std::vector<int>::iterator it = std::find(u.begin(), u.end(), i);
        if (it != u.end()) {
            std::cout << i << " is present\n";
        } else {
            std::cout << "Value is not present\n";
        }

    }
    return 0;

}
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    string k = "aa";
    int size = k.length();
    int req = pow(2, size) - size;
    for (int i = 0;i < req;i++) {
        k += k;
    }
    cout << k;
    return 0;
}
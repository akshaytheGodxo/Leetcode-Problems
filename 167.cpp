/* 
Two Sum II - Input Array Is Sorted

we can run a simple binary search approach here,
    v = {-1, -1};
    initialise start and end
    if start + end > target : 
        end--;
    elif start+end < target:
        start++;
    else:
        v.push_back(start);
        v.push_back(end);

*/  




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> output(2, -1);
    int s = 0;
    int e = numbers.size() -1 ;
    while (s <= e) {
        if (numbers[s] + numbers[e] > target)
            e--;
        else if (numbers[s]+ numbers[e] < target)
            s++;
        else if (numbers[s] + numbers[e] == target)
        {   
            output[0] = s+1;
            output[1] = e+1;
            break;
        }
    }   
    return output;
}
//  driver code 
int main() {

    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(numbers, target);
    
    for (auto i : ans) cout << i << " ";

    return 0;
}
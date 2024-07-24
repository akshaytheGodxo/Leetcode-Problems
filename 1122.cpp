/*

    Warning -> don't use an unordered_map

    Approach -> first we have to make an array which will contain those elements which are not either present in arr1 or in arr2
    second we will use the map <index, frequency> and will print accordingly
    lastly we will insert the array which contains unique elements


*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> uniqueEle(vector<int> nums1, vector<int> nums2) {
        vector<int> ans;
        for (auto i : nums1) {
            int c = count(nums2.begin(), nums2.end(), i);
            if (c == 0)
                ans.push_back(i);
        }
        return ans;
    }

public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> output;
        map<int, int> umap;

        // find those elements who are not present in arr2

        vector<int> uniqueEl = uniqueEle(arr1, arr2);
        // sorted array with all the unique elements
        sort(uniqueEl.begin(), uniqueEl.end());

        // using a hash map , we store all the values of arr2 with the frequency
        for (int i = 0; i < arr2.size(); i++) {
            int c = count(arr1.begin(), arr1.end(), arr2[i]);
            umap[i] = c;
        }

        // simply push back the elements in correct order
        for (auto x : umap) {
            int val = x.first;
            int range = x.second;
            for (int k = 0; k < range; k++)
                output.push_back(arr2[val]);
        }
        if (uniqueEl.size() != 0) {
            for (auto i : uniqueEl)
                output.push_back(i);
        }

        return output;
    }
};
int main()
{

    vector<int> arr1 = {666, 921, 366, 859, 743, 900, 334, 845, 154, 436, 494, 629, 838, 361, 109, 191, 52, 94, 815, 393, 220, 252, 451, 398, 262, 111, 28, 49, 11, 805, 668, 824, 564, 187, 333, 37, 929, 213, 388, 853, 61, 680, 487, 147, 939, 128, 389, 344, 637, 245};
    vector<int> arr2 = {11, 668, 487, 147, 929, 361, 388, 398, 680, 838, 805, 629, 262, 61, 28, 220, 52, 111, 451, 939, 344, 252, 213, 94, 333, 187, 436, 37, 743, 494, 245, 637, 853, 191, 900, 921, 815, 845, 154, 824, 49, 334, 564, 389, 109, 859, 666, 366, 128, 393};

    Solution solution;
    vector<int> ans = solution.relativeSortArray(arr1, arr2);
    for (auto i : ans) cout << i << endl;

    return 0;
}
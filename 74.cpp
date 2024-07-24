// we use the target element and the given data of the matrix
/* 
    let's say that our target element is 3 and the mid row arr{1] has it's first value 10 i.e. arr[1][0] = 10
    so this implies that our answer cannot be in the row => arr[1] since arr[1] always contains values >= 10
    so we reduce the row and we get our new row which is arr[0] , this is the row which will contain our answer
    now we can simply just implement binary search bitch

*/
#include <bits/stdc++.h>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<int> ansRow;
    int s = 0;
    int e = matrix.size() - 1;
    while (s <= e) {
        int m = s + (e - s) / 2;
        int currSize = matrix[m].size();
        if (matrix[m][0] <= target && matrix[m][-1] >= target) 
        {
            ansRow = matrix[m];
            break;
        }
        else if (matrix[m][currSize - 1] > target)
            e = m - 1;
        else if (matrix[m][currSize - 1] < target)
            s = m + 1;
    }

    // we got the answerow
    // normal binary search to get the answer
    bool ans = false;
    int start = 0;
    int end = ansRow.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (ansRow[mid] == target) {
            ans = true;
            break;
        }
        else if (ansRow[mid] > target)
            end = mid - 1;
        else if (ansRow[mid] < target)
            start = mid + 1;
    } 

    return ans;
}


// driver code
int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    
    cout << searchMatrix(matrix, target);
    return 0;
}
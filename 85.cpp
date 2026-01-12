#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
            if (matrix.empty()) return 0;

        int n = matrix[0].size();

        vector<int> height(n+1, 0);
        int max_area = 0;
        for (int i=0;i<matrix.size();i++) {
            for (int col = 0;col < n;col++){
                if (matrix[i][col] == '1') {
                    height[col] = height[col] + 1;
                } else {
                    height[col] = 0;
                }
            }

            stack<int> st;
            st.push(-1);

            for (int col = 0;col <= n;col++) {
                while ( st.top() != -1 && height[col] < height[st.top()] ) {
                    int h = height[st.top()];
                    st.pop();
                    int w = col - st.top() - 1;

                    max_area = max(max_area, h*w);
                }

                st.push(col);
            }
        }

        return max_area;
    }
};



int main() {
    Solution solution;
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << solution.maximalRectangle(matrix);
    return 0;
}
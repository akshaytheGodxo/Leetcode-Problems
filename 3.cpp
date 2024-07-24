// Longest Substring with no repeating characters

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int lengthOfLongestSubstring(std::string s) {

    // use the unordered_map to store the maxLength
    // use the deque to slide the window starting from the minimum
    if (s.size() == 0) return 0;

    std::vector<int> v;
    for (int i = 0; i < s.size();i++) {
        std::string subString = "";
        subString += s[i];
        for (int j = i + 1;j < s.size();j++) {
            int c = subString.find(s[j]);
            if (c != -1) {
                break;
            }
            else {
                subString += s[j];
            }
        }
        v.push_back(subString.size());
    }
    sort(v.begin(), v.end());
    return v[v.size() - 1];

}
// abcabcbb -> 3
int main() {
    std::string s;
    std::cin >> s;

    int ans = lengthOfLongestSubstring(s);
    std::cout << ans << std::endl;
    return 0;
}
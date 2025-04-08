#include <bits/stdc++.h>
using namespace std;
vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    map<char, int> charTracker;
    /*
        store the maxFrequency of each element 
        store the maxFrequency of each word too
        le eo
    */

   map<string, int> wordTracker;
   // first store the maxFrequency of all the character in words2 
    for (auto word : words2) {
            for (auto chr : word) {
                int cnt = count(word.begin(), word.end(), chr);
                if (cnt > charTracker[chr]) {
                    charTracker[chr] = cnt;
                }
        }
    }
    string allWords = "";
    for (auto i : charTracker)
        for (int j = 0;j < i.second;j++) {
            allWords += i.first;
        }
    vector<string> ans;
    int charSize = 0;
    for (auto i : words1) {
        charSize = 0;
        for (auto j : allWords) {
            int cnt = count(i.begin(), i.end(), j);
            if (cnt >= charTracker[j]) {
                charSize++;
            }
        }
        if (charSize == allWords.size()) {
            ans.push_back(i);
        }
        
    }
    return ans;
}    

int main() {
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e", "o"};
    vector<string> output = wordSubsets(words1, words2);
    for (auto i : output) {
        cout << i << " ";
    }
    return 0;
}
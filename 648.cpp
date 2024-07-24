#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int searchRoot(string s, vector<string> root) {
    
    int index = -1;


    for (auto i : root) {
        int c = i.find(s);
        if ( c != -1)
            index = c;
            break;
    }
    return index;

}

int main() {

    string x= "the cattle was rattled by the battery";
    vector<string> v = {"cat", "rat", "bat"};
    string k = "";    
    for (auto i = 0;x[i] != '\0';i++) {
        if (x[i] == ' ')
            {
                int a = searchRoot(k, v);
                cout <<k << " "<< a << endl;
                k = "";
            }   
            k += x[i];
    }

    return 0;
}
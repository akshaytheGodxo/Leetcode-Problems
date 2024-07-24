// String to Integer (atoi)

#include <iostream>
#include <string>
#include <climits>
using namespace std;



int myAtoi(string s) 
{
    int i=0;
    int sign=1;
    long ans=0;
    // this loop will reach the pointer to the first digit that is not a white space
    while(i<s.length() && s[i]==' ')
        i++;

    // we gonna check the sign of the digit
    if(s[i]=='-')
    {
        sign=-1;
        i++;
    }
    else if(s[i]=='+')
        i++;
    // start a new loop from the next digit 
    while(i<s.length())
    {
        if(s[i]>='0' && s[i]<='9')
        {
            ans=ans*10+(s[i]-'0');
            if(ans>INT_MAX && sign==-1)
                return INT_MIN;
            else if(ans>INT_MAX && sign==1)
                return INT_MAX;
            i++;
        }
        else
            return ans*sign;
    }
    return (ans*sign);
}



int main() {
    string s;
    cin >> s;

    int ans = myAtoi(s);
    
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

bool repeatedSubstringPattern(string s) {
    int len=s.length();
    for (int i = 0; i < len/2; i++) // 只用取一半，超过一半肯定不是
    {
        if(len%(i+1)!=0) continue;  // 非子串长度倍数，肯定不是
        string substr = s.substr(0,i+1);
        int flag = 1;
        for (int j = i+1; j <= len-i-1; j+=i+1) {
            if(substr.compare(s.substr(j,i+1))) { //不等
                flag=0;
                break;
            }
        }
        if (flag == 1)  return true;
    }
    return false;
}

int main(){
    cout<<repeatedSubstringPattern("abac")<<endl;


    return 0;
}
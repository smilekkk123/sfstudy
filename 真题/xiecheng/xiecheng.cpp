#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dtfStr(int len,vector<string>& strs) {
    for(int i=0;i<len;i++) {
        string s;
        int count=0;
        for(int j=0;j<strs[i].length();j++) {
            if(j==0) {
                strs[i][j] = std::toupper(strs[i][j]);
            }
            if(strs[i][j] == '_' && j+1 < strs[i].length()) {
                strs[i][j+1] = std::toupper(strs[i][j+1]);
            }
        }
        for(int j=0;j<strs[i].length();j++) {
            if(strs[i][j] != '_') {
                s+= strs[i][j];
            }
        }
        cout<<s<<endl;
    }
}

int main() {
    int n;
    cin>>n;

    vector<string> strs;

    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        strs.push_back(s);
    }

    dtfStr(n,strs);
    return 0;
}
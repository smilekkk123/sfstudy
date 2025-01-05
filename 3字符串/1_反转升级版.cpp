#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string reverseStr(string s, int k) {
    int i=0;
    while(i<s.length()){
        if(s.length()-i<k){
            reverse(s.begin()+i,s.end());
        }
        else{
            reverse(s.begin()+i,s.begin()+i+k); // 后面这个结束的部分是不会参加反转的
        }
        i+=2*k;
    }
    return s;

}


int main(){
    string s="abcdefg";
    int k=2;

    cout<<reverseStr(s,k)<<endl;

    return 0;
}
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int ifMatch(string s){
    stack<char> sta;
    if(s.length()%2==1){
        return 0;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            sta.push(')');
        }
        else if(sta.empty() || s[i]!=sta.top()){
            return 0;
        }
        else{
            sta.pop();
        }
    }
    return sta.empty();
}

int main(){
    string s="()(()";
    int i;
    i=ifMatch(s);
    if(i==1){
        cout<<"ok"<<endl;
    }else{
        cout<<"notok"<<endl;
    }

    return 0;
}
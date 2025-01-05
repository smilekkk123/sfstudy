#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> sta;
    
    for (int i = 0; i < s.size(); i++)
    {
        // ---如果是左括号，则入栈（入相反的方便比较
        if(s[i]=='('){
            sta.push(')');
        }
        else if(s[i]=='['){
            sta.push(']');
        }
        else if (s[i]=='{')
        {
            sta.push('}');
        }
        // ---如果是右括号
        // 如果栈是空的或括号未匹配
        else if (sta.empty()||s[i]!=sta.top()){
            return false;
        }
        // 如果括号匹配
        else{
            sta.pop();
        }
    }
    return sta.empty();
}

int main(){
    string s;
    cin>>s;
    if (isValid(s))
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    



    return 0;
}

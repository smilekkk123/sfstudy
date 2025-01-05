#include <iostream>
#include <string>
using namespace std;

/*************** 滑动窗口 ****************/
int findByWindow(const string& a,const string& b){
    for (int i = 0; i <= a.length()-b.length(); i++)
    {
        if(!b.compare(a.substr(i,b.length()))){
            return i;
        }
    }
    return -1;
}

/**************** KMP ********************/
// 生成next数组
int* getNext(const string b){
    int* next=new int[b.length()];
    next[0]=0;

    for(int i=1;i<b.length();i++){
        int j = next[i-1]; // 取需要比较的上一个节点
        while(j > 0 && b[i] != b[j]) { // 不等则不断回退
            j = next[j-1];
        }
        if (b[i] == b[j]) { // 匹配
            next[i] = j + 1;
        } else {
            next[i] = 0; // 完全不匹配的情况
        }
    }
    return next;

}

// i不动，j回退
int findByKMP(const string& a,const string& b){
    int i = 0;
    int j = 0;
    int* next = getNext(b);
    for (i = 0; i < a.length(); i++) {
        if (a[i] == b[j]) {
            j++;
            if (j == b.length()) {
                return i - j + 1;
            }
        } 
        else {
            if(j!=0){
                j = next[j-1];
                i--;
            }     
        }
    }
    return -1;
}



int main(){
    string a="";
    string b="";
    cin>>a;
    cin>>b;

    // 滑动窗口
    cout<<findByWindow(a,b);

    // KMP算法
    cout<<findByKMP(a,b);


    return 0;
}
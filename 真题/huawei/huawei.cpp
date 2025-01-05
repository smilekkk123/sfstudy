#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
int* arr_r=new int[32];  // 寄存器
int* prin=new int[100];  // print操作的数
int p_count=0; // 记录print总数

int getNum(const string& s){
    if(s[0]=='a'){
        return arr_r[stoi(s.substr(1))-1];
    }
    else{
        return stoi(s);
    }
}

void Operation(const string& line){
    istringstream iss(line); // 使用字符串流来处理输入的字符串
    string substring;
    vector<string> ops; // 子串向量

    while (iss >> substring) { // 逐个单词读取
        ops.push_back(substring); // 将单词添加到向量中
    }

    string oprt=ops[0];  // 操作
    int n_r=stoi(ops[1].substr(1)); //目标寄存器编号

    if(!oprt.compare("MOV")){
        arr_r[n_r-1]=getNum(ops[2]);
    }
    else if (!oprt.compare("ADD"))
    {
        arr_r[n_r-1]=getNum(ops[2])+getNum(ops[3]);
    }
    else if (!oprt.compare("SUB"))
    {
        arr_r[n_r-1]=getNum(ops[2])-getNum(ops[3]);   
    }
    else if (!oprt.compare("MUL"))
    {
        arr_r[n_r-1]=getNum(ops[2])*getNum(ops[3]); 
    }
    else if (!oprt.compare("DIV"))
    {
        arr_r[n_r-1]=getNum(ops[2])/getNum(ops[3]); 
    }
    else if(!oprt.compare("PRINT"))
    {
        prin[p_count]=arr_r[n_r-1];
        p_count++;
    }

}

int main(){
    string line;
    vector<string> ops;

    while(getline(cin,line)){
        if(line.empty()){
            break;
        }
        ops.push_back(line);
    }

    for (const auto& op : ops) {
        Operation(op);
    }

    for (int i = 0; i < p_count; i++)
    {
        cout<<prin[i]<<endl;
    }
    

    return 0;
}
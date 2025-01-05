#include<iostream>
#include<vector>
using namespace std;

int sumWater(vector<int>& arr){
    int len=arr.size();
    if(len<3){
        return 0;
    }
    int i=0,j=len-1,sum=0;
    int maxleft=arr[i];
    int maxright=arr[j];
    while(i<=j){ // 从两边开始往中间逼近并计算每一处存水值
        if(maxleft<maxright){  // 找出两边中最高处的较低者 
            if(maxleft<arr[i]){  // 目前遍历到的地方更高，无法存水，更新最高值
                maxleft=arr[i]; 
            }
            else if(maxleft>arr[i]){ // 目前遍历到的地方较矮，则可存水，可存两边中的较低者-该处值
                sum+=(maxleft-arr[i]);
            }
            i++;
        }
        else{
            if(maxright<arr[j]){
                maxright=arr[j];
            }
            else if(maxright>arr[j]){
                sum+=(maxright-arr[j]);
            }
            j--;
        }
    }
    return sum;
}



int main(){
    vector<int> arr;
    int n;
    do{
        cin>>n;
        arr.push_back(n);
    }while (getchar()!='\n');
    cout<<sumWater(arr)<<endl;
    


    return 0;
}
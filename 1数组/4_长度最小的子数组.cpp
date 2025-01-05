#include<iostream>
#include<vector>
using namespace std;

// 滑动窗口，右边先走，找到之后左边再左移检查，不够了再右移
int search(vector<int>& arr,int s){
    int min=arr.size();
    int left=0,right=0;
    int sum=0;
    while(right<arr.size()){
        sum+=arr[right];
        if(sum>=s){ // 如果满足条件
            while(sum-arr[left]>=s){
                left++;
                sum-=arr[left];
            }
            int tmp=right-left+1;
            if(tmp<min){
                min=tmp;
            }
        }
        right++;
    }
    if(min==arr.size()+1){
        return 0;
    }

    return min;
}


int main(){
    int target;
    vector<int> arr;
    int input;

    cin>>target;
    
    do {
        cin >> input;
        arr.push_back(input);
    } while (getchar() != '\n' );

    
    cout<<search(arr,target)<<endl;

    return 0;

}
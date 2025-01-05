// 有序数组，且无重复数字
#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int left=0;
    int right=nums.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;

}

int main(){
    int target;
    vector<int> arr;
    int input;

    do {
        cin >> input;
        arr.push_back(input);
    } while (getchar() != '\n' );

    cin>>target;
    
    cout<<search(arr,target);

    return 0;

}
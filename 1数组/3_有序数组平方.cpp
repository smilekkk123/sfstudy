#include<iostream>
#include<vector>
using namespace std;

vector<int> solution(vector<int>& nums){
    vector<int> res(nums.size(),0);
    int left=0;
    int right=nums.size()-1;
    int i=nums.size()-1;
    while(left<=right){
        if(nums[left]*nums[left]>=nums[right]*nums[right]){
            res[i--]=nums[left]*nums[left];
            left++;
        }
        else{
            res[i--]=nums[right]*nums[right];
            right--;
        }
    }
    return res;
}


int main(){
    vector<int> nums;
    int n;
    do{
        cin>>n;
        nums.push_back(n);
    }while(getchar()!='\n');

    vector<int> res;

    res=solution(nums);

    for(int i=0;i<nums.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;



    return 0;
}
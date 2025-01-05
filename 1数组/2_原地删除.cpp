#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
        int slow=0;
        int fast=0;

        while(fast<nums.size()){
            if(nums[fast]!=val){
                nums[slow++]=nums[fast];
            }
            fast++;
        }
        return slow;

    }

int main(){
    vector<int> nums;
    int input;
    int target;

    do{
        cin>>input;
        nums.push_back(input);
    }while (getchar()!='\n');

    cin>>target;

    cout<<removeElement(nums,target);

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;


/**** 求最长严格递增子序列 **********/

int lengthOfLIS(vector<int>& nums) {
    int count=1;
    vector<int> dp(nums.size(),1);

    for(int i=1;i<nums.size();i++) {
        int res = dp[i];
        for(int j=0;j<i;j++) {
            // 遍历前面的＋1和dp[i]，这些里面找最大值
            if(nums[i]>nums[j] && dp[j]+1>res) {
                res=dp[j]+1;
            }
        }
        dp[i] = res;
        count = max(count,dp[i]);
    }
    return count;
}


/***** 最长连续递增子序列 **********/

int findLengthOfLCIS(vector<int>& nums) {
    int count=1;
    vector<int> dp(nums.size(),1);
    for(int i=1;i<nums.size();i++) {
        if(nums[i]>nums[i-1]) dp[i]=dp[i-1]+1;
        count = max(dp[i],count);
    }
    return count;
}

/***** 最长重复子数组，要求连续且一样 ******/
int findLength(vector<int>& nums1, vector<int>& nums2) {
    int count=0;
    vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
    for(int i=1;i<=nums1.size();i++) {
        for(int j=1;j<=nums2.size();j++) {
            if(nums1[i-1] == nums2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            count = max(dp[i][j],count);
        }
    }
    return count;
}

/****** 最长公共子序列，要求不连续，但顺序不能乱，且一样 *************/
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
    for (int i = 1; i <= text1.length(); i++) {
        for (int j = 1; j <= text2.length(); j++) {
            if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }  
    }
    return dp[text1.length()][text2.length()];
}



int main(){
    vector<int> arr = {1,3,6,7,9,4,10,5,6};
    cout<<lengthOfLIS(arr)<<endl;


    return 0;
}
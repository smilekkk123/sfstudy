#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


int minimizeSum(const vector<int>& nums,int maxExplosions){
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(maxExplosions+1,0));
    //int dp[n+1][3];

    dp[0][0]=0;

    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+nums[i-1];
    }
    
    for(int j=1;j<=maxExplosions;j++){
        for (int i = 1; i <=n; i++)
        {
            dp[i][j]=dp[i-1][j]+nums[i-1];
            for (int k = 1; k <=3 ; k++)
            {
                if(i>=k){
                    int sum=0;
                    for (int m=0;m<k;m++)
                    {
                        sum+=nums[i-1-m];
                    }
                    dp[i][j]=min(dp[i][j],dp[i-k][j-1]);
                }
            }
            
        }
        
    }

    return dp[n][maxExplosions];

}




int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);        
    }
    
    int maxExplosions=2;
    cout<<minimizeSum(arr,maxExplosions)<<endl;
    


    return 0;
}
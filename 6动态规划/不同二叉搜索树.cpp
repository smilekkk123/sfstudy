#include<iostream>
#include<vector>
using namespace std;

int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i/2;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
            dp[i]=dp[i]*2;
            if(i%2==1){
                dp[i]+=dp[i/2]*dp[i/2];
            }
        }
        return dp[n];

    }
int main(){
    int n;
    cin>>n;
    cout<<numTrees(n)<<endl;


    return 0;
}
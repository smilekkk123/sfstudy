#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int maxGcd(int n,int m,vector<int>& arr) {
    vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MIN));
    dp[0][0] = 0;

    for(int j=1;j<=m;++j) {
        for(int i=j;i<=n;++i) {
            int curgcd = 0;
            for(int k=i-1;k<=j-1;--k) {
                curgcd = gcd(curgcd,arr[k]);
                dp[i][j] = max(dp[i][j],dp[k][j-1]+curgcd);
            }
        }
    }
    return dp[n][m];
}

int main() {
    int n,m;
    cin>>n>>m;

    vector<int> arr;

    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    cout<<maxGcd(n,m,arr);

    return 0;
}
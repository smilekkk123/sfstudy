#include<iostream>
#include<vector>

using namespace std;

int maxPathSum(vector<vector<int>>& matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));

    dp[0][0]=matrix[0][0]+matrix[n-1][m-1];

    for(int j=1;j<m;j++){
        dp[0][j]=dp[0][j-1]+matrix[0][j]+matrix[n-1][m-1-j];
    }
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+matrix[i][0]+matrix[n-1-i][m-1];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+matrix[i][j]+matrix[n-1-i][m-1-j];
        }
    }

    int center_i = (n-1)/2;
    int center_j = (m-1)/2;
    return dp[center_i][center_j]-matrix[center_i][center_j];
}



int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>matrix[i][j];
        }
        
    }

    cout<<maxPathSum(matrix)<<endl;
    


    return 0;
}
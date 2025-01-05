#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;



int main() {
    int m,n;
    cin>>n;
    cin>>m;
    
    vector<int> marr;
    marr.push_back(n);
    for(int i=0;i<m;i++) {
        int x;
        cin>>x;
        marr.push_back(x);  // xi数组
    }
    vector<int> dp(m+1);
    dp[0]=0;
    for(int i=1;i<marr.size();i++) {
        if(marr[i]<marr[i-1]) {
            dp[i] = dp[i-1]+1;
        }
        else if(marr[i] == marr[i-1]) {
            dp[i] = dp[i-1];
        }
        else {
            int j=i-2;
            while(marr[i]>marr[j]){
                j--;
            }
            dp[i] = dp[j]+1;
        }
    }

    for(int i=1;i<=m;i++) {
        cout<<dp[i]+1<<" ";
    }
    cout<<endl;


    return 0;
}
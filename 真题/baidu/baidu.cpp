#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findMax(vector<vector<int>>& arrs, vector<int> ks,int n) {
    for(int i=0;i<n;i++) {
        int sum=1;
        for(int j=0;j<ks[i];j++) {
            sort(arrs[i].begin(),arrs[i].end());
            arrs[i][0]++;
        }
        for(int k=0;k<4;k++) {
            sum*=arrs[i][k];
        }
        cout<<sum<<endl;
    }
}

int main() {
    int n;
    cin>>n;  // 测试组数

    vector<vector<int>> arrs;
    vector<int> ks;
    for(int i=0;i<n;i++) {
        vector<int> tmp;
        for(int j=0;j<4;j++) {
            int x;
            cin>>x;
            tmp.push_back(x);
        }
        arrs.push_back(tmp);
        int k;
        cin>>k;
        ks.push_back(k);
    }
    findMax(arrs,ks,n);



    return 0;
}
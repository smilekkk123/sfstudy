#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;



int main() {
    int m,n;
    cin>>n;
    cin>>m;
    
    vector<int> marr(m);
    for(int i=0;i<m;i++) {
        int x;
        cin>>x;
        marr[i]=x;  // xi数组
    }

    vector<int> canvas(n+1,0);  // 画布

    for(int i=1;i<=m;++i) {
        int xi=marr[i-1];
        for(int pos =1;pos<=xi;++pos) {
            canvas[pos]=i;
        }
        unordered_set<int> colors;
        for(int pos=1;pos<=n;++pos) {
            colors.insert(canvas[pos]);
        }

        cout<<colors.size()<<" ";

    }
    cout<<endl;


    return 0;
}
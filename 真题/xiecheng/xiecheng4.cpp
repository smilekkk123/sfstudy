#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;

int findres(int op,int l,int r) {
    int res = arr[l];
    if(op == 1) {
        int flag=0;
        for(int i=l+1;i<=r;i++) {
            if(flag == 0) {
                res=res&arr[i];
                flag=1;
            }
            if(flag == 1) {
                res=res|arr[i];
                flag=0;
            }
        }
    }

    if(op == 2) {
        int flag=1;
        for(int i=l+1;i<=r;i++) {
            cout<<res<<endl;
            if(flag == 0) {
                res=res&arr[i];
                flag=1;
            }
            if(flag == 1) {
                res=res|arr[i];
                flag=0;
            }
        }
    }

    return res;
}

int main() {
    int n,q;
    cin>>n>>q;

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    for(int i=0;i<q;i++) {
        int op,l,r;
        cin>>op>>l>>r;
        res.push_back(findres(op,l-1,r-1));
    }

    for(int i=0;i<q;i++) {
        cout<<res[i]<<endl;
    }
    
    return 0;
}
#include <iostream>
using namespace std;

bool sushu(int n) {
    if(n<=1) {
        return false;
    }
    for(int i=2;i<=n/2;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

int eatCandy(int n) {
    int cur=n;
    int count=0;
    while(cur>0) {
        if(sushu(cur)) {
            cur-=cur/3+1;
        }else {
            cur-=cur/2+1;
        }
        count++;
    }
    return count;
}

int main() {
    long n;
    cin>>n;
    cout<<eatCandy(n)<<endl;
    return 0;
}
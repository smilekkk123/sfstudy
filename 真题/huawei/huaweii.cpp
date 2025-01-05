#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> grs;
vector<int> col;
int n;
int cnt=0; // 记录现在颜色数

void dfs(int m,int c) {
    if(col[m]!=0) {
        return ;
    }
    col[m]=c;
    for (int i = 0; i < n; i++)
    {
        if(grs[m][i]==1 && col[i]==0) {
            dfs(i,c);
        }
        
    }
    
}

int main() {
    cin>>n;
    
    grs.resize(n);
    col.resize(n,0);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            grs[i].push_back(0);
        }
    }

    for(int i=0;i<n;i++) {
        int x;
        int isfirst=0;
        int cur;
        do{
            cin>>x;
            if(isfirst == 0) {
                cur = x;
                isfirst=1;
            } else {
                grs[cur][x]=1;
                grs[x][cur]=1;
            }
            
        }while(getchar()!='\n');
    }

    //

    if(n<=0) {
        cout<<-1<<endl;
    }
    else {
        for(int i=0;i<n;i++) {
            if(col[i]==0) {
                cnt++;
                dfs(i,cnt);
            }
        }
    }

    if(cnt!=2) {
        cout<<-1<<endl;
    }
    else {
        vector<vector<int>> res;
        res.resize(2);
        for (int i = 0; i < n; i++)
        {
            if(col[i]==1) {
                res[0].push_back(i);
            }
            else {
                res[1].push_back(i);
            }
        }

        for(int i=0;i<2;i++) {
            for(int j=0;j<res.size();j++) {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }


        
    }


    return 0;
}
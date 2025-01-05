#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> arr;
int sum=0;
vector<bool> visited;
int n,m,k;

void dfs(int m,int step) {
    if (visited[m] || step == k+1) {
        return;
    }
    visited[m] = true;
    sum++;
    for (int i=0;i<arr[m].size();i++)
    {
        dfs(arr[m][i],step+1);
    }
}

void bfs(int m) {
    queue<int> que;
    que.push(m);
    visited[m]=true;
    int step=0;
    while (!que.empty()&&step<k)
    {
        int size=que.size();
        for(int j=0;j<size;j++) {
            int tmp = que.front();
            que.pop();
            for(int i=0;i<arr[tmp].size();i++) {
                if(!visited[arr[tmp][i]]) {
                    que.push(arr[tmp][i]);
                    visited[arr[tmp][i]] = true;
                    sum++;
                }
            }
        }
        step++;   
    }
    
}




int main() {
    
    cin>>n;
    cin>>m;
    cin>>k;

    arr.resize(n); // n个节点这么长
    visited.resize(n, false); // 初始化visited向量

    for(int i=0;i<n;i++) { // 输入所有边，得到邻接矩阵
        int x,y;
        cin>>x;
        cin>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    //dfs(m,0);
    bfs(m);
    cout<<sum<<endl;

    return 0;
}
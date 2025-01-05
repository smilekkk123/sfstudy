#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<set>

using namespace std;

int bfs(int start,int target,const unordered_map<int,vector<int>>& graph,const vector<vector<int>>& routes,unordered_set<int>& visitedRoutes) {
    unordered_set<int> visitedStations;
    queue<pair<int,int>> queue;
    queue.push({start,0});

    while(!queue.empty()) {
        auto current = queue.front();
        queue.pop();
        int currentStation = current.first;
        int buses=current.second;

        for(int routeIndex:graph.at(currentStation)) {
            if(visitedRoutes.count(routeIndex)) continue;

            visitedRoutes.insert(routeIndex);
            for(int station:routes[routeIndex]) {
                if(station == target) return buses+1;
                if(visitedStations.count(station) == 0) {
                    visitedStations.insert(station);
                    queue.push({station,buses+1});
                }
            }
        }

    }
    return -1;
}

int minBusRoutes(int x,int y,int z,const vector<vector<int>>& routes) {
    if(x==y&&y==z) {
        return 0;
    }
    if(y==z) {
        return -1;
    }
    unordered_map<int,vector<int>> graph;
    for(int i=0;i<routes.size();i++ ) {
        for(int station: routes[i]) {
            graph[station].push_back(i);
        }
    }

    unordered_set<int> visitedRoutes;
    int busesToY = bfs(x,y,graph,routes,visitedRoutes);
    if(busesToY == -1) {
        return -1;
    }
    for(int routeIndex: graph[y]) {
        if(find(routes[routeIndex].begin(),routes[routeIndex].end(),z)!=routes[routeIndex].end()) {
            return busesToY;
        }
    }

    int busesToZ = bfs(y,z,graph,routes,visitedRoutes);
    if(busesToZ == -1) return -1;

    return busesToY+busesToZ-1;
    
}

int main(){
    int x,y,z,n;
    cin>>x>>y>>z>>n;
    vector<vector<int>> routesTotal(n);
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        routesTotal[i].resize(num);
        for(int j=0;j<num;j++) {
            cin>>routesTotal[i][j];
        }
    }
    cout<<minBusRoutes(x,y,z,routesTotal)<<endl;

    return 0;
}
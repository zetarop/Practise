#include <bits/stdc++.h>
using namespace std;

int N;
int M;

vector<vector<pair<int, int>>> adj;
vector<int> visited;

/*

10 16
4 5 4
5 6 1
0 6 4
1 7 3
6 7 5
2 7 1
0 1 1
1 2 2
2 3 100
3 4 3
2 8 9
7 9 2
5 8 8
3 9 80
4 9 6
6 9 60

*/

void initGraph(){
    
    cin >> N >> M;
    adj.resize(N);
    visited.resize(N, 0);
    
    for(int i = 0; i < M; i++){
        
        int u;
        int v;
        int w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}


void dfs(int u){
    
    if(visited[u])
        return;
    
    cout << u << " ";
    
    visited[u] = 1;
    
    for(auto x : adj[u]){
        
        int v = x.first;
        if(!visited[v])
            dfs(v);
    }
}
void bfs(int u){
    
    queue<int> Q;
    Q.push(u);
    visited[u] = 1;
    
    while(!Q.empty()){
        
        int currSize = Q.size();
        for(int i = 0; i < currSize; i++){
            
            int v = Q.front();
            Q.pop();
            cout << v << " ";
            for(auto x : adj[v]){
                
                int t = x.first;
                if(!visited[t]){
                    Q.push(t);
                    visited[t] = 1;
                }
            }
        }
    }
}


int dijkshtra(int u){
    
    vector<int> dp(N, 2e9);
    dp[u] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({dp[u], u});
    
    while(!Q.empty()){
        
        int t = Q.top().second;
        Q.pop();
        
        visited[u] = 1;
        
        for(auto x : adj[t]){
            
            if(dp[x.first] > dp[t] + x.second){
                dp[x.first] = dp[t] + x.second;
                Q.push({dp[x.first], x.first});
            }
        }
    }
    
    for(auto x : dp){
        cout << x << " ";
    }
}


int main() {
  
	initGraph();
  dijkshtra(0);
 
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int n = 6;
bool visited[n];
vector<int> adj[n];

void dfs(int i) {
    visited[i] = 1;
    cout << i << '\n';
    for(auto num:adj[i]) {
        if(!visited[num]) dfs(num);
    }
    return;
}

int main() {
    adj[1].push_back(2); adj[1].push_back(3);
    adj[2].push_back(1); adj[2].push_back(4); adj[2].push_back(5);
    adj[3].push_back(1);
    adj[4].push_back(2);
    adj[5].push_back(2);

    dfs(1);

    return 0;
    
}
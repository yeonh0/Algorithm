#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100]; int visited[100];

void BFS(int start) {
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while(q.size()) {
        int here = q.front(); q.pop();
        for(int there:adj[here]) {
            if(visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }
}

int main() {
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);
    adj[12].push_back(18);
    adj[12].push_back(20);
    adj[20].push_back(22);
    adj[20].push_back(24);

    BFS(10);

    int nodeList[] = {10, 12, 14, 16, 18, 20, 22, 24};
    for(int i : nodeList){
        cout << i << " : " << visited[i] << '\n';
    }

    return 0;
}
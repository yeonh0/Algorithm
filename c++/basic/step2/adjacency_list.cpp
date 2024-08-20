#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool visited[10];

void go(int from) {
    cout << from << '\n';
    visited[from] = 1;
    for(int there:adj[from]) {
        if(!visited[there]) go(there);
    }
}

int main() {
    adj[1].push_back(2); adj[2].push_back(1);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[3].push_back(4); adj[4].push_back(3);

    for(int i=0; i<10; i++) {
        for(auto num:adj[i]) {
            if(!visited[i]) go(i);
        }
    }
    
    return 0;
}
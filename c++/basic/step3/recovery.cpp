#include <bits/stdc++.h>
using namespace std;

int visited[4];
vector<int> v, adj[4];

void go(int here) {
    for(int there : adj[here]) {
        visited[there] = 1;
        go(there);
        visited[there] = 0;
    }
}

void print() {
    for(int i : v) cout << char(i + 'A') << " ";
    cout << '\n';
}

void tree(int here) {
    if(v.size() == 3) {
        print();
        return;
    }

    for(int there : adj[here]) {
        if(visited[there]) continue;
        visited[there] = 1;
        v.push_back(there);
        tree(there);
        visited[there] = 0;
        v.pop_back();
    }
}

int main() {
    adj[0].push_back(1); adj[1].push_back(0);
    adj[2].push_back(1); adj[1].push_back(2);
    adj[3].push_back(1); adj[1].push_back(3);

    visited[0] = 1;
    v.push_back(0);
    tree(0);
}
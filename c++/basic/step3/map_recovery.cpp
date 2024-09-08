#include <bits/stdc++.h>
using namespace std;

int a[3][3] = {
    {10, 20, 21},
    {70, 90, 12},
    {80, 110, 120}
};

int cnt, visited[3][3], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
vector<int> v;

void print() {
    for(int i : v) cout << i << " ";
    cout << "\n";
    return;
}

void search(int y, int x) {
    if(y == 2 && x == 2) {
        cnt++;
        print();
        return;
    }

    for(int i=0; i<4; i++) {
        int ny = y + dy[i]; int nx = x + dx[i];
        if(ny<0 || nx<0 || ny>=3 || nx>=3 || visited[ny][nx]) continue;

        visited[ny][nx] = 1;
        v.push_back(a[ny][nx]);
        search(ny, nx);
        visited[ny][nx] = 0;
        v.pop_back();
    }
}

int main() {
    visited[0][0] = 1;
    v.push_back(a[0][0]);
    search(0, 0);
    cout << "cnt: " << cnt << '\n';
}
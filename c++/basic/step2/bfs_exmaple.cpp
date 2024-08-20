#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, cx, cy, destx, desty;
int mymap[104][104], visited[104][104];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}; 

void BFS() {
    queue<pair<int, int>> q;
    visited[cy][cx] = 1;
    q.push({cy, cx});

    while(q.size()) {
        tie(y, x) = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 > ny || ny >= n || 0 > nx || nx >= m) continue;
            if(visited[ny][nx]) continue;
            if(mymap[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

}

int main() {
    cin >> n >> m;
    cin >> cx >> cy;
    cin >> destx >> desty;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> mymap[i][j];
    }

    BFS();
    
    cout << visited[desty][destx] << '\n';
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cout << visited[i][j] << ' ';
        cout << '\n';
    }
}
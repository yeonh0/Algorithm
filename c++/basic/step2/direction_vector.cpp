#include <bits/stdc++.h>
using namespace std;

int mymap[3][3];
bool visited[3][3];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void go(int y, int x) {
    visited[y][x] = 1;
    cout << x << " : " << y << '\n';

    for(int i=0; i<4; i++) {
        int newy = y + dy[i]; int newx = x + dx[i];
        if(newy < 0 || newy >= 3 || newx < 0 || newx >= 3) continue;
        if(!mymap[newy][newx]) continue;
        if(!visited[newy][newx]) go(newy, newx);
    }
}

int main() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) cin >> mymap[i][j];
    }
    go(0, 0);

    return 0;
}
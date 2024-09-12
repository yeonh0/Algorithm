// BOJ 12869 뮤탈리스크 (G4)
//
#include <bits/stdc++.h>
using namespace std;

int n, visited[64][64][64], a[3], attack[6][3] = { {1,3,9},{1,9,3},{3,1,9},{3,9,1},{9,1,3},{9,3,1} };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue<vector<int>> q;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    q.push({a[0], a[1], a[2]});
    while (q.size()) {
        vector<int> tmp = q.front(); q.pop();
        int ta = tmp[0]; int tb = tmp[1]; int tc = tmp[2];
        for (int i = 0; i < 6; i++) {
            int na = max(0, ta - attack[i][0]);
            int nb = max(0, tb - attack[i][1]);
            int nc = max(0, tc - attack[i][2]);

            if (visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[ta][tb][tc] + 1;
            if (na == 0 && nb == 0 && nc == 0) {
                cout << visited[na][nb][nc];
                return 0;
            }
            q.push({ na, nb, nc });
        }
    }
    
    
    return 0;
}
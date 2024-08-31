// BOJ 10709 기상캐스터 (S5)
//
#include <bits/stdc++.h>
using namespace std;

int h, w, a[101][101];
string s;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // 남북방향이 H 킬로미터, 동서방향이 W 킬로미터인 직사각형 
    // 가로와 세로의 길이가 1킬로미터인 H × W 개의 작은 구역
    // 북쪽으로부터 i 번째, 서쪽으로부터 j 번째에 있는 구역을 (i, j) 
    // 각 구역의 하늘에는 구름이 있을 수도, 없을 수도 있다. 
    // 모든 구름은 1분이 지날 때마다 1킬로미터씩 동쪽으로 이동한다.
    // 몇 분뒤 처음으로 하늘에 구름이 오는지를 예측.

    fill(&a[0][0], &a[0][0] + 101*101, -1);
    cin >> h >> w;
    for(int i=0; i<h; i++) {
        cin >> s;
        for(int j=0; j<w; j++) {
            if(s[j] == 'c') {
                v.push_back({i, j});
                a[i][j] = 0;
            }
        }
    }

    for(auto it:v) {
        int x = 0, y = 0;
        tie(y, x) = it;

        int cnt = 1;
        for(int k=x+1; k<w; k++) {
            if(a[y][k] == 0) continue;
            else{
                if(a[y][k] == -1) a[y][k] = cnt;
                else if(a[y][k] > cnt) a[y][k] = cnt;
            }
            cnt++;
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
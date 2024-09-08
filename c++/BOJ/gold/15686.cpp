// BOJ 15686 치킨 배달 (G5)
//
#include <bits/stdc++.h>
using namespace std;

int n, m, result = 9999999, a[54][54];
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> _home, _chicken;
vector<vector<int>> _chickenList;

int getdistance(vector<int> v) {
    int ret = 0;
    for (pair<int, int> home : _home) {
        int _min = 9999999;
        for (int ch : v) {
            int distance = abs(_chicken[ch].first - home.first) + abs(_chicken[ch].second - home.second);
            _min = min(distance, _min);
        }
        ret += _min;
    }
    return ret;
}

void combi(int start, vector<int> v) {
    if(v.size() == m) {
        // int ret = getdistance(v);
        // result = min(ret, result);
        _chickenList.push_back(v);
    }

    for(int i=start+1; i<_chicken.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) _home.push_back({i, j});
            else if(a[i][j] == 2) _chicken.push_back({i, j});
        }
    }

    vector<int> v;
    combi(-1, v);

    for(vector<int> cList : _chickenList) {
        int ret = 0;
        for(pair<int, int> home : _home) {
            int _min = 9999999;
            for(int ch : cList) {
                int _dist = abs(_chicken[ch].first - home.first) + abs(_chicken[ch].second - home.second);
                _min = min(_min, _dist);
            }
            ret += _min;
        }
        result = min(result, ret);
    }
    
    cout << result << '\n';

    return 0;
}
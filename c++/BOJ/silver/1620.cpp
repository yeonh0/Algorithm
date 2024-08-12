// BOJ 1620 나는야 포켓몬 마스터 이다솜 (S4)
// string-int, int-string : map, map - 200ms, map, array - 164ms
#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;
map<string, int> mp;
string a[1000004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> s;
        a[i+1] = s;
        mp[s] = i+1;
    }

    for(int i=0; i<M; i++) {
        cin >> s;
        if(64 < (int)s[0]) {
            cout << mp[s] << '\n';
        }
        else {
            cout << a[stoi(s)] << '\n';
        }
    }
}
// BOJ 2910 빈도 정렬 (S3)
//
#include <bits/stdc++.h>
using namespace std;

int n, c, a[1004];
map<int, int> mp, mp_first;
vector<pair<int, int>> v;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    // 빈도가 같은 경우 : 먼저 나온 것부터
    if(a.first == b.first) 
        return mp_first[a.second] < mp_first[b.second];
    // 빈도가 다른 경우 : 많이 나온 것부터
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> c;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;                                     // 빈도 세기
        if(mp_first[a[i]] == 0) mp_first[a[i]] = i+1;   // 순서 세기
    }

    for(auto it:mp) {
        v.push_back({it.second, it.first});
    }

    sort(v.begin(), v.end(), cmp);
    
    for(auto it:v) {
        for(int i=0; i<it.first; i++) {
            cout << it.second << " ";
        }
    }

    return 0;
}
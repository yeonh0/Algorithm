// BOJ 1940 주몽 (S4)
// 이중 for 문 - 80ms, 재귀 함수 - 380ms 
#include <bits/stdc++.h>
using namespace std;

int N, M, sum;
int a[20000];

void f(int depth, vector<int>& v) {
    if(v.size() == 2) {
        if(a[v[0]] + a[v[1]] == M) sum++;
        return;
    }

    for(int i=depth+1; i<N; i++) {
        v.push_back(i);
        f(i, v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> M;
    for(int i=0; i<N; i++) cin >> a[i];

    // 이중 for 문
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            if(a[i]+a[j] == M) sum++;
        }
    }

    // 재귀 함수
    vector<int> v;
    f(-1, v);
    cout << sum;

    return 0;
}
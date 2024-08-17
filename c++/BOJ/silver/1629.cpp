// BOJ 1629 곱셈 (S1)
// 곱하는 시도를 줄이고, 로그 스케일로 줄여서 제곱하면 횟수 줄어듦
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a, b, c;

ll f(ll a, ll b) {
    if(b == 1) return a % c;

    ll ret = f(a, b/2);
    ret = ret * ret % c;
    if(b & 1) ret = ret * a % c;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;

    cout << f(a, b);

    return 0;
}
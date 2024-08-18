// BOJ 4375 1 (S3)
// 2, 5로 나누어 떨어지지 않는 정수 n : 각 자리 수가 모두 1로 이루어진 n의 배수는?
#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(cin >> N) {
        int cnt = 0; int mod = 0;
        while(true) {
            cnt++;
            mod = (mod * 10 + 1) % N;
            if(mod == 0) break;
        }
        cout << cnt << endl;
    }

    return 0;
}

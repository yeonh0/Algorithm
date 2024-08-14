// BOJ 9375 패션왕 신해빈 (S3)
// map value : for auto, second로 접근
#include <bits/stdc++.h>
using namespace std;

int trial, n;
string name, c_case;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> trial;
    while(trial--) {
        map<string, int> mp;
        cin >> n;

        for(int j=0; j<n; j++) {
            cin >> name >> c_case;

            mp[c_case]++;
        }

        // 경우의 수는 커질 수 있으므로 long long으로 선언하기
        long long ret = 1;
        for(auto c:mp) {
            ret *= ((long long)c.second + 1);
        }
        ret --;
        cout << ret << '\n';
    }

    return 0;
}
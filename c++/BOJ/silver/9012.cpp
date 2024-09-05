// BOJ 9012 괄호 (S4)
//
#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    while(n--) {
        cin >> s;
        cnt = 0;
        bool flag = 1;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                cnt++;
            }
            else {
                cnt--;
            }
            if(cnt<0) {
                flag = 0;
            }
        }
        if(flag && cnt == 0) {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }

    return 0;
}

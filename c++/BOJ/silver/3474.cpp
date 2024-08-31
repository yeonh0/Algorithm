// BOJ 3474 교수가 된 현우 (S3)
//
#include <bits/stdc++.h>
using namespace std;

long long t, num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> num;
        int num5 = 1, ret = 0;
        while(true) {
            num5 *= 5;
            if(num5 > num) break;
            ret = ret + num / num5;
        }
        cout << ret << '\n';
    }

    return 0;
}
// BOJ 1436 영화감독 숌 (S5)
//
#include <bits/stdc++.h>
using namespace std;

int n, ret = 666;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(;;ret++) {
        if(to_string(ret).find("666") != string::npos) n--;
        if(n == 0) break;
    }

    cout << ret;

    return 0;
}

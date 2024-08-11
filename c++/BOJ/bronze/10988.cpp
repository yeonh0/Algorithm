// BOJ 10988 팰린드롬인지 확인하기 (B3)
#include <bits/stdc++.h>
using namespace std;

string myin, temp;

int main() {
    // 내 풀이
    cin >> myin;
    for(int i=0; i<myin.size(); i++) {
        if(myin[i] != myin[myin.size() - i - 1]) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;

    // 해설 풀이
    temp = myin;
    reverse(temp.begin(), temp.end());
    if(temp == myin) cout << 1;
    else cout << 0;

    return 0;
}
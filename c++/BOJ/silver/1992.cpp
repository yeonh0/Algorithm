// BOJ 1992 쿼드트리 (S1)
//
#include <bits/stdc++.h>
using namespace std;

int n;
string s;
char a[65][65];

string f(int num, int y, int x) {
    if(num == 1) return string(1, a[y][x]);
    char tmp = a[y][x];
    string ret = "";

    for(int i=y; i<y+num; i++) {
        for(int j=x; j<x+num; j++) {
            if(tmp != a[i][j]) {
                ret += "(";
                ret += f(num/2, y, x);
                ret += f(num/2, y, x+num/2);
                ret += f(num/2, y+num/2, x);
                ret += f(num/2, y+num/2, x+num/2);
                ret += ")";
                return ret;
            }
        }
    }
    return string(1, a[y][x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<n; j++) {
            a[i][j] = s[j];
        }
    }

    cout << f(n, 0, 0);

    return 0;
}
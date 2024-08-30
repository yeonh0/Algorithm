// BOJ 2870 수학숙제 (S4)
//
#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a, string &b) {
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

string f(string s) {
    int zcnt = 0;
    for(int j=0; j<s.size(); j++) {
        if(s[j] != '0') break;
        zcnt++;
    }
    if(zcnt == s.size()) return string(1, '0');
    return s.erase(0, zcnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    string s;
    vector<string> v;

    cin >> n;
    while(n--) {
        cin >> s;

        bool flag = 0;
        string ret = "";

        for(int i=0; i<s.size(); i++) {
            if(97 <= int(s[i]) && int(s[i]) <= 122) {
                if(flag) {
                    string tmp = f(ret);
                    v.push_back(tmp);
                    flag = 0; ret = "";
                }
            }
            else {
                flag = 1;
                ret += s[i];
            }
        }
        if(flag) v.push_back(f(ret));
    }

    sort(v.begin(), v.end(), cmp);

    for(auto it:v) cout << it << '\n';

    return 0;
}
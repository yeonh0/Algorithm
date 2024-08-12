// BOJ 9996 한국이 그리울 땐 서버에 접속하지 (S3)
// 
#include <bits/stdc++.h>
using namespace std;

int n;
string fname, pre, suf, check;

int main() {
    cin >> n;
    cin >> fname;
    int pos = fname.find('*');
    pre = fname.substr(0, pos);
    suf = fname.substr(pos+1);
    
    for(int i=0; i<n; i++) {
        cin >> check;
        // 반례: ab*ab -> ab
        if(pre.size() + suf.size() > check.size()) {
            cout << "NE" << endl;
            continue;
        }
        if(check.substr(0, pre.size()) == pre && check.substr(check.size() - suf.size()) == suf)
            cout << "DA" << endl;
        else
            cout << "NE" << endl;
    }

}
// BOJ 11655 ROT13 (B1)
// 알파벳을 13글자씩 밀기
#include <bits/stdc++.h>
using namespace std;

string s;
int num;

int main() {
    getline(cin, s);
    for(int i=0; i<s.size(); i++) {
        num = s[i];
        if(65 <= num && num <= 90) {
            if(num < 78) cout << char(num+13);
            else cout << char(num-13);
        }
        else if(97 <= num && num <= 122) {
            if(num < 110) cout << char(num+13);
            else cout << char(num-13);
        }
        else cout << s[i];
    }
}
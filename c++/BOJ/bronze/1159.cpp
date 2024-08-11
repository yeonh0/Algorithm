// BOJ 1159 농구 경기 (B2)
// 첫 글자 같은 선수 5명, 없으면 기권
#include <bits/stdc++.h>
using namespace std;

int trial, cnt[26];
bool istrue = false;
string myin;
char myfirst;
map<char, int> name;

int main() {
    cin >> trial;

    // 내 풀이: map
    for(int i=0; i<trial; i++) {
        cin >> myin;
        myfirst = myin[0];
        name[myfirst]++;
    }

    for(auto hi:name) {
        if(hi.second > 4) {
            cout << hi.first;
            istrue = true;
        }
    }
    if(!istrue) cout << "PREDAJA";

    // 강의: 배열
    for(int i=0; i<trial; i++) {
        cin>>myin;
        cnt[(int)myin[0] - 'a']++;
    }

    for(int i=0; i<26; i++) {
        if(cnt[i] > 4) {
            istrue = true;
            cout << char(i + 'a');
        }
    }
    if(!istrue) cout << "PREDAJA";

    return 0;
}
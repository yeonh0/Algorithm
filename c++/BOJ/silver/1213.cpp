// BOJ 1213 팰린드롬 만들기 (S3)
//
#include <bits/stdc++.h>
using namespace std;

string myin, myout;
char mid;
int cnt[200], flag(0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> myin;
    for(char ch:myin) cnt[ch]++;

    for(int i='Z'; i>='A'; i--) {
        if(cnt[i]) {
            if(cnt[i] & 1) {
                if(flag == 1) {
                    cout << "I'm Sorry Hansoo";
                    return 0;
                }
                mid = char(i); flag=1;
                cnt[i]--;
            }

            for(int j=0; j<cnt[i]; j+=2) {
                myout = char(i) + myout;
                myout += char(i);
            }
        }

    }
    if(mid) myout.insert(myout.begin()+myout.size()/2, mid);
    cout << myout << endl;

    return 0;
}
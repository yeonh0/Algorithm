// BOJ 2852 NBA 농구 (S3)
//
#include <bits/stdc++.h>
using namespace std;

int n, t, minn, sec, a[48][60];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    while(n--) {
        cin >> t >> s;
        minn = int(s[0]-'0')*10 + int(s[1]-'0');
        sec = int(s[3]-'0')*10 + int(s[4]-'0');
        
        for(int i=minn; i<48; i++) {
            for(int j=0; j<60; j++) {
                if(i==minn && j<sec) continue;
                if(t == 1) a[i][j]--;
                else if(t == 2) a[i][j]++;
            }
        }
    }

    int scr1 = 0, scr2 = 0;
    for(int i=0; i<48; i++) {
        for(int j=0; j<60; j++) {
            if(a[i][j] > 0) scr2++;
            else if(a[i][j] < 0) scr1++;
        }
    }

    printf("%02d:%02d\n", scr1/60, scr1 % 60);
    printf("%02d:%02d", scr2/60, scr2 % 60);

    return 0;
}
// BOJ 4659 비밀번호 발음하기 (S5)
//
#include <bits/stdc++.h>
using namespace std;

string s;

void printaccept(string args) {
    cout << "<" << args << "> is acceptable." << '\n';
}
void printnotaccept(string args) {
    cout << "<" << args << "> is not acceptable." << '\n';
}

bool jamo(char chr) {
    return chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true) {
        cin >> s;
        if(s == "end") break;

        bool b_isjamo, n_isjamo, ismo = false, istrue = true;
        char b_chr; 
        int cnt = 1;

        b_chr = s[0]; b_isjamo = jamo(s[0]);
        ismo = b_isjamo;

        for(int i=1; i<s.size(); i++) {
            n_isjamo = jamo(s[i]);
            if(n_isjamo) ismo = true;

            if(b_chr == s[i] && s[i] != 'e' && s[i] != 'o') {
                istrue = false;
                break;
            }

            if(b_isjamo == n_isjamo) {
                if(cnt == 2) {
                    istrue = false;
                    break;
                }
                cnt++;
            }
            else {
                cnt = 1;
            }

            b_isjamo = n_isjamo;
            b_chr = s[i];
        }
        
        if(istrue == false || ismo == false) printnotaccept(s);
        else printaccept(s);
    }

    return 0;
}
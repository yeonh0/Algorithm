#include <bits/stdc++.h>
using namespace std;

string mystr;
int myarr[26];

int main() {
    cin >> mystr;
    for(auto i:mystr) {
        myarr[i-'a']++;
    }

    for(int i:myarr) cout << i << " ";

    return 0;
}
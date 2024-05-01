#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delim) {
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while((pos = input.find(delim)) != string::npos) {
        token = input.substr(0, pos);
        input.erase(0, pos + delim.length());
        ret.push_back(token);
    }
    ret.push_back(input);

    return ret;
}


int main() {
    string s = "helloadmyadnameadisadjoadyeonadho", d = "ad";
    vector<string> a = split(s, d);
    for(string b:a) cout << b << '\n';
}
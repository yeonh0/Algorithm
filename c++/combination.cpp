// do combination(5, 3)
#include <bits/stdc++.h>
using namespace std;

int combFor(int a[5]) {
    for(int i=0; i<5; i++) {
        for(int j=i+1; j<5; j++) {
            for(int k=j+1; k<5; k++) {
                cout << a[i] << " " << a[j] << " " << a[k] << '\n';
            }
        }
    }
}

void combi(int start, vector<int> v, int a[5]) {
    if(v.size() == 3) {
        for(int i:v) cout << a[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=start+1; i<5; i++) {
        v.push_back(i);
        combi(i, v, a);
        v.pop_back();
    }
}

int main() {
    vector<int> b;
    int arr1[5] = {2, 3, 4, 6, 7};
    
    combFor(arr1);
    cout << '\n';

    combi(-1, b, arr1);

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int i = 1, j = 1;
    bool to_right = true;
    for(int t=0; t<k - 1; t++) {
        cout << 2;
        for(int p=0; p<=1; p++) {
            if(j < 1 || j > m) {
                to_right = !to_right;
                i++;
                j += to_right? 1 : -1;
            }
            cout << ' ' << i << ' ' << j;
            j += to_right? 1 : -1;
        }
        cout << endl;
    }
    cout << (n * m) - 2 * (k - 1);
    for(int x=i; x<=n; x++) {
        int dir = to_right? 1 : -1;
        for(int y=j; y>0 && y<=m; y+=dir) 
            cout << ' ' << x << ' ' << y;
        j = to_right? m : 1;
        to_right = !to_right;
    }

    return 0;
}
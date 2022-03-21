#include <bits/stdc++.h>
 
using namespace std;
 
bool willItChange(vector<string>& m, int i, int j) {
    int r = m.size(), c = m[0].length();
    if(i - 1 >= 0 && m[i - 1][j] == m[i][j]) return true;
    if(j - 1 >= 0 && m[i][j - 1] == m[i][j]) return true;
    if(i + 1 < r && m[i + 1][j] == m[i][j]) return true;
    if(j + 1 < c && m[i][j + 1] == m[i][j]) return true;
    return false;
}
 
int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<string> rows;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        rows.push_back(s);
    }
 
    vector<vector<int>> mat(n, vector<int>(m, -1));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> spread;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(willItChange(rows, i, j)) {
                mat[i][j] = 0;
                spread.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while(!spread.empty()) {
        auto cell = spread.front();
        spread.pop();
        int i = cell.first, j = cell.second;

        vector<pair<int, int>> neighborhoods({
            {i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}
        });
        for(auto neigh : neighborhoods) {
            int ik = neigh.first, jk = neigh.second;
            if(ik < 0 || ik >= n || jk < 0 || jk >= m || visited[ik][jk]) continue;
            mat[ik][jk] = mat[i][j] + 1;
            spread.push({ik, jk});
            visited[ik][jk] = true;
        }
    }
 
    map<pair<int, int>, pair<int, int>> mem;
    while(t--) {
        long long int i, j, p;
        cin >> i >> j >> p;
        i--, j--;
        int turns = mat[i][j];
        if(turns == -1 || p <= turns) cout << rows[i][j] << endl;
        else {
            int diff = p - turns;
            if(diff % 2 == 0)
                cout << rows[i][j] << endl;
            else
                cout << (rows[i][j] == '0'? '1' : '0') << endl;
        }
    }
 
    return 0;
}
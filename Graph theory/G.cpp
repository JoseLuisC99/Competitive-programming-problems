#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main() {
    int n;
    lli a;
    cin >> n;
    map<lli, int> v_map;
    map<int, lli> val_map;
    vector<vector<int>> g(n);
    for(int i=0; i<n; i++) {
        cin >> a;
        v_map[a] = i;
        val_map[i] = a;
    }

    for(auto tuple : v_map) {
        lli val = tuple.first;
        int key = tuple.second;
        if(v_map.find(val * 2) != v_map.end()) 
            g[key].push_back(v_map[val * 2]);
        if(val % 3 == 0 && v_map.find(val / 3) != v_map.end())
            g[key].push_back(v_map[val / 3]);
    }

    vector<int> path;
    for(int v=0; v<n; v++) {
        vector<bool> visited(n, false);
        int next = v;
        while(!visited[next]) {
            visited[next] = true;
            path.push_back(next);
            for(int child : g[next]) {
                if(!visited[child]) {
                    next = child;
                    break;
                }
            }
        }

        if(path.size() == n) break;
        else path.clear();
    }

    for(int v : path)
        cout << val_map[v] << ' ';
    cout << endl;

    return 0;
}
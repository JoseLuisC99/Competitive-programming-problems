#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<pair<int, int>> edges;

    while(m--) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v});
    }

    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> next;
    map<pair<int, int>, int> dirs;

    next.push({1, 0});
    visited[1] = true;
    bool impossible = false;

    while(!next.empty()) {
        auto _next = next.front();
        next.pop();
        int v = _next.first, dir = _next.second;
        int next_dir = dir == 0? 1 : 0;

        for(int next_v : g[v]) {
            if(!visited[next_v]) {
                visited[next_v] = true;
                dirs[{v, next_v}] = dir;
                next.push({next_v, next_dir});
            } else {
                if(dirs.find({next_v, v}) != dirs.end()) {
                    int e_dir = dirs.at({next_v, v});
                    if(e_dir == dir) {
                        impossible = true;
                        break;
                    }
                } else {
                    dirs[{v, next_v}] = dir;
                }
            }
        }
        if(impossible) break;
    }

    if(impossible)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for(auto e : edges) {
            int u = e.first, v = e.second;
            pair<int, int> edge;
            if(dirs.find({u, v}) != dirs.end()) {
                if(dirs.at({u, v}) == 0)
                    cout << 0;
                else
                    cout << 1;
            } else {
                if(dirs.at({v, u}) == 0)
                    cout << 1;
                else
                    cout << 0;
            }
        }
        cout << endl;
    }

    return 0;
}
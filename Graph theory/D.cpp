#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

int main() {
    int t, n, m, u, v;
    cin >> t;
    
    while(t--) {
        cin >> n >> m;
        Graph g(n + 1);

        while(m--) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        queue<pair<int, int>> next;
        vector<bool> visited(n + 1, false);
        next.push({1, 0});
        visited[1] = true;
        Graph components(2);

        while(!next.empty()) {
            auto e = next.front();
            next.pop();
            int v = e.first, c = e.second;
            int next_color = c == 0? 1 : 0;
            components[c].push_back(v);

            for(int next_v : g[v]) {
                if(visited[next_v]) continue;
                visited[next_v] = true;
                next.push({next_v, next_color});
            }
        }

        vector<int> sol = components[0].size() < components[1].size()? components[0] : components[1];
        cout << sol.size() << endl;
        for(int v : sol)
            cout << v << ' ';
        cout << endl;
    }

    return 0;
}
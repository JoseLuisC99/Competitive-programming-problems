#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

bool isCyclicUtil(Graph g, int v, vector<bool>& visited, vector<bool>& rs) {
    if(!visited[v]) {
        visited[v] = true;
        rs[v] = true;

        for(int i : g[v]) {
            if(!visited[i] && isCyclicUtil(g, i, visited, rs))
                return true;
            else if(rs[i])
                return true;
        }
    }
    rs[v] = false;
    return false;
}

bool isCyclic(Graph g) {
    vector<bool> visited(g.size(), false);
    vector<bool> rs(g.size(), false);

    for(int i=0; i<g.size(); i++)
        if(!visited[i] && isCyclicUtil(g, i, visited, rs)) return true;
    return false;
}

void topologicalSortUtil(Graph g, int v, vector<bool>& visited, stack<int>& s) {
    visited[v] = true;
    for(int c : g[v])
        if(!visited[c]) topologicalSortUtil(g, c, visited, s);
    s.push(v);
}

vector<int> topologicalSort(Graph g) {
    stack<int> s;
    vector<bool> visited(g.size(), false);

    for(int i=0; i<g.size(); i++)
        if(!visited[i]) topologicalSortUtil(g, i, visited, s);
    
    vector<int> v;
    while(!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}

int main() {
    int n, next_pos = 1;
    cin >> n;
    
    string s, prev_s = "";
    bool impossible = false;
    Graph g(26);

    for(int i=0; i<n; i++) {
        cin >> s;

        for(int j=0; j<prev_s.length(); j++) {
            if(j > s.length() - 1) {
                impossible = true;
            } else if(s[j] != prev_s[j]) {
                g[prev_s[j] - 'a'].push_back(s[j] - 'a');
                break;
            }
        }

        prev_s = s;
    }

    if(impossible || isCyclic(g))
        cout << "Impossible" << endl;
    else {
        vector<int> sol = topologicalSort(g);
        for(int c : sol)
            cout << char(c + 'a');
        cout << endl;
    }

    return 0;
}
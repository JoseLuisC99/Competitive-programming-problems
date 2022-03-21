#include <bits/stdc++.h>

using namespace std;

class DisjoinSet {
    int n;
    vector<int> parent;
    vector<int> size;
    
public:
    DisjoinSet(int n) {
        this->n = n;
        this->parent = vector<int>(n, -1);
        this->size = vector<int>(n, 1);
    }

    int make_set(int v) {
        if(parent[v] == -1) {
            parent[v] = v;
            size[v] = 1;
        }
        return parent[v];
    }

    int find_set(int v) {
        if(parent[v] == -1)
            return make_set(v);
        else if(v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    int union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if(a != b) {
            if(size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }

        return a;
    }

    vector<int> getParents() {
        return parent;
    }

    vector<int> getSizes() {
        return size;
    }
};

int main() {
    int n, m, k, x;
    cin >> n >> m;
    DisjoinSet ds(n + 1);

    while(m--) {
        cin >> k;
        int parent;
        for(int i=0; i<k; i++) {
            cin >> x;
            ds.make_set(x);
            if(i == 0)
                parent = x;
            else
                parent = ds.union_sets(parent, x);
        }
    }

    vector<int> size = ds.getSizes();
    for(int v=1; v<=n; v++)
        cout << size[ds.find_set(v)] << ' ';
    cout << endl;

    return 0;
}
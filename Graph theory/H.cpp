#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, x, y;
    cin >> n >> k;

    vector<vector<int>> snacks(n + 1);
    vector<tuple<int, int>> guests(k + 1);
    for(int i=1; i<=k; i++) {
        cin >> x >> y;
        snacks[x].push_back(i);
        snacks[y].push_back(i);

        guests[i] = {x, y};
    }

    vector<bool> visited(k + 1, false);
    vector<bool> was_taken(n + 1, false);
    int sad = 0;
    for(int i=1; i<=k; i++) {
        if(visited[i]) continue;

        queue<int> next_guest;
        next_guest.push(i);
        visited[i] = true;

        while(!next_guest.empty()) {
            int guest = next_guest.front();
            next_guest.pop();

            x = get<0>(guests[guest]), y = get<1>(guests[guest]);
            vector<int> snack_taken;
            if(!was_taken[x]) snack_taken.push_back(x);
            if(!was_taken[y]) snack_taken.push_back(y);
            if(was_taken[x] && was_taken[y]) sad++;

            for(int snack : snack_taken) {
                was_taken[snack] = true;
                for(int g : snacks[snack]) {
                    if(!visited[g]) {
                        visited[g] = true;
                        next_guest.push(g);
                    }
                }
            }
        }
    }

    cout << sad << endl;

    return 0;
}
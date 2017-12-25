#include<bits/stdc++.h>

using namespace std;

vector < int > adj[100];

vector < int > cost[100];

int dis[100];

void dijk(int s, int n) {
    queue <int > mh;
    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    mh.push(s);
    dis[s] = 0;

    while(!mh.empty()) {
    int u = mh.front();
    mh.pop();

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(dis[u]+cost[u][i] < dis[v]) {
            dis[v] = dis[u] + cost[u][i];
            mh.push(v);
        }

    }
  }
}

int main() {
        int e, n;
        cout << "Enter edges no and nodes no\n";
        cin >> e >> n;
        for (int i = 0; i < e; i++) {
            int x, y, c;
            cin >> x >> y >>c;
            adj[x].push_back(y);
            cost[x].push_back(c);
        }

        cout << "Enter source node\n";
        int s;
        cin >> s;
        dijk( s, n );
        cout << "measeurable node\n";
        int m;
        cin >> m;
        cout << "diatance is " << dis[m] << endl;

return 0;}

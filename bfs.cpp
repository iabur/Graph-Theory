#include<bits/stdc++.h>

using namespace std;

int visited[1000];
int cost[1000];
vector <int> adj[1000];

void bfs(int s, int n) {

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    queue <int> Q;
    Q.push(s);
    visited[s] = 1;
    cost[s] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for(int i = 0; i < adj[u].size(); i++ ) {
              int  v = adj[u][i];
            if(visited[v] == 0) {
                visited[v] = 1;
                Q.push(v);
                cost[v] = cost[u] + 1;
            }
        }
    }

}
int main() {
    int n, e;
    cout << "Enter nodes and edges" << endl;
    cin >> n >> e;
    for (int i = 1; i <= e; i++) {
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
   cout << "source node\n";
   int s;
   cin >> s;
  bfs(s, n);
  int nn;
  cout << "Enter the measured node number\n";
  cin >> nn;
  cout << cost[nn];
return 0;}

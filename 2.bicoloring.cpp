#include<bits/stdc++.h>

using namespace std;

 char visited[100];

 vector < int > G[1000];

bicoloring(int s, int n) {
    for(int i = 1; i <= n; i++) {
        visited[i] = 'w';

    }
    queue < int > Q;
    Q.push(s);
    visited[s] = 'r';
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

    for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
        if(visited[v] == 'w') {
            if(visited[u] == 'r') {
                visited[v] = 'b';

            }
            else {
                visited[v] = 'r';

            }
          Q.push(v);

        }
        if(visited[u] == visited[v]) {
            return false;

        }

    }
   }
    return true;
}
int main() {
    int edge, n;
    cout << "Enter edge and node number\n" << endl;
    cin >> edge >> n;
    for(int i = 1; i <= edge; i++) {
        cout << "Edge " << i << endl;
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    if(bicoloring(1,n)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

return 0;}

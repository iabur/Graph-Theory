#include<bits/stdc++.h>

using namespace std;

int main() {
    vector <int> edge[1000];
    vector <int> cost[1000];
    int e, n;
    cin >> e >> n;
    for (int i = 0; i < e; i++) {
        int x, y, cx, cy;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
        cost[x].push_back(1);
        cost[y].push_back(1);

    }
    for (int j = 1; j <= n; j++) {
            cout << j << " ";
 int p = edge[j].size();
 for (int i = 0; i < p; i++) {
    cout << edge[j][i] << " ";
 }
 cout << endl;
    }
return 0;}

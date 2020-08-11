#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> edge[100];
    vector <int> cost[100];
    int e, n, co;
    cout << "Enter number of edges and nodes\n";
    cin >> e >> n;
    for (int i = 0; i < e; i++){
        cout << "Enter two nodes pair and their cost\n";
        int a, b;
        cin >> a >> b >> co;
        edge[a].push_back(b);
        cost[a].push_back(co);
    }
    for (int i = 1; i <= n; i++){
        int p = edge[i].size();
        for (int j = 0; j < p; j++){
            cout << i << " to " << edge[i][j] << "(" << cost[i][j] <<")" << "   ";
        }
        cout << endl;

    }
return 0;}

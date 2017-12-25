#include<bits/stdc++.h>
#define NIL 0
using namespace std;
vector <int> adj[100];
int parent[100], visited[100], ap[100], low[100], disc[100], tim = 0;

void APUtil(int n, int v)
{
    int u = v;

    int children = 0;

    visited[u] = true;

    disc[u] = low[u] = tim++;

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(n, v);

           low[u]  = min(low[u], low[v]);


            if (parent[u] == NIL && children > 1)
               ap[u] = true;


            if (parent[u] != NIL && low[v] >= disc[u])
               ap[u] = true;
        }

        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}


void Graph(int n)
{

    for (int i = 1; i <= n; i++)
        if (visited[i] == false)
            APUtil(n, i);


    cout << endl << endl << endl;
    for (int i = 1; i <= n; i++)
        if (ap[i] == true)
            cout << i << " ";
}


int main()
{
    int n, e;
    cout << "Enter nodes and edges" << endl;
    cin >> n >> e;
    cout << "Enter u to v \n";
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
        Graph(n);


    return 0;
}

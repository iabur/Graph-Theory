#include<bits/stdc++.h>
using namespace std;
vector <int> adj1[100];
int cf[100][100],parent[100];
int call(int d);

bool maxflow(int n, int s, int d)
{
    queue <int> q;
    int color[100], check = false;
    for(int i = 1; i <= n; i++)
    {
        color[i] = false;
        parent[i] = -1;
    }

    q.push(s);
    color[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj1[u].size(); i++)
        {
            int v = adj1[u][i];
            if(color[v] == false && cf[u][v]>0)
            {
                color[v] = true;
                q.push(v);
                parent[v] = u;



            }
        }

    }

    return color[d];
}

int call(int n, int s, int d)
{
    int mf = 0;
    while(maxflow(n, s, d))
    {
        int m = INT_MAX;
        for (int i = d; i != s; i = parent[i])
        {
            int u = parent[i];
            int v = i;
            m = min(m,cf[u][v]);

        }

        for(int i = d; i != s; i = parent[i])
        {
            int u = parent[i];
            int v = i;
            cf[u][v] = cf[u][v] - m;
            cf[v][u] = cf[v][u] + m;
        }
        mf = mf + m;
    }
    return mf;
}

int main()
{
    int n, e;
    cout << "Enter nodes and edges\n";
    cin >> n >> e;
    cout << "Enter edges u to v and capacity of u to v\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
        cf[u][v] = w;
    }
    cout <<"maximum flow is: " << call(n, 1, 6);

}

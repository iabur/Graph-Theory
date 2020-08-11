#include<bits/stdc++.h>
using namespace std;

vector <int> adj1[100];
vector <int> adj2[100];
vector <int> component[100];
queue <int> q;

int color[100], tem;

void dfs1(int s)
{
    int u = s;
    color[u] = 1;
    q.push(u);
    for(int i = 0; i < adj1[u].size(); i++)
    {
        int v = adj1[u][i];
        if(color[v] == 0)
        {
            dfs1(v);
        }
    }
}

void dfs2(int s)
{
    int u = s;
    color[u] = 2;
    component[tem].push_back(u);
   // cout << adj2[u].size() << " ";
    for(int i = 0; i < adj2[u].size(); i++)
    {

        int v = adj2[u][i];
        if(color[v] == 1)
        {
            dfs2(v);
        }
    }

}

void call(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(color[i] == 0)
        {
            dfs1(i);
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
       // cout << ":" << u <<":" << endl;
        if(color[u] == 1)
        {
            tem++;
            dfs2(u);
        }
    }
     for(int i = 1; i <= tem; i++)
     {
        for(int j = 0; j < component[i].size(); j++)
        {
            cout << component[i][j] << " ";
        }
        cout << endl;
     }


}

int main()
{
    int e, n;
    cin >> e >> n;
    for(int i  = 0; i < e; i++)

    {
        int a, b;
        cin >> a >> b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    call(n);
}

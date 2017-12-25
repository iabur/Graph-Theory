#include<bits/stdc++.h>
using namespace std;
vector <int> adj1[100];
vector <int> adj2[100];
vector <int> component[100];
#define white 0
#define gray 1
int color[100], visited[100], mark = 0;
stack <int> stk;
void dfs2 (int n, int u);
void call (int n);
void dfs(int n, int s)
{
    int u = s;
    color[u] = gray;
    for(int i = 0; i < adj1[u].size(); i++)
    {
        int v = adj1[u][i];
        if(color[v] == white)
        {
            dfs(n, v);
        }
    }
    stk.push(u);

}

void dfs2(int n, int s)
{
    int u = s;
    component[mark].push_back(u);
    visited[u] = true;
    for (int i = 0; i < adj2[u].size(); i++)
    {
        int v = adj2[u][i];
        if(visited[v] == false)
        {
            dfs2(n, v);
        }
    }
}
void call (int n)
{
    for(int i = 1; i <= n; i++)
    {
        if (color[i] == white)
        {
            dfs(n, i);
        }
    }
    while(!stk.empty())
    {
        int u = stk.top();
        stk.pop();
        if(visited[u] == false )
        {
            mark++;
            dfs2(n, u);
        }
    }
    for (int i = 1; i <= mark; i++)
    {
        cout << "Component " << i << " :";
        for (int j = 0; j < component[i].size(); j++)
        {
            cout << component[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter nodes and edges" << endl;
    int n, e;
    cin >> n >> e;
    cout << "Enter u and v" << endl;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);

    }
    call(n);

    return 0;
}

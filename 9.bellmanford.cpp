#include<bits/stdc++.h>

using namespace std;

vector < int > adj[100];

vector < int > cost[100];

int dis[100];

void dijk(int s, int n)
{
    //queue <int > mh;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    //mh.push(s);
    dis[s] = 0;

    // while(!mh.empty()) {
    // int u = mh.front();
    // mh.pop();
    for(int i = 1; i <= n-1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < adj[j].size(); k++)
            {
                int v = adj[j][k];
                int u = j;
                if(dis[u]+cost[u][k] < dis[v])
                {
                    dis[v] = dis[u] + cost[u][k];
                    //mh.push(v);
                }

            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if(dis[i]+cost[i][j]<dis[adj[i][j]])
            {
                cout << "Negative cycle detected\n";
                return;
            }

        }
    }
}


int main()
{
    int e, n;
    cout << "Enter edges no and nodes no\n";
    cin >> e >> n;
    for (int i = 0; i < e; i++)
    {
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

    return 0;
}

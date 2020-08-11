 #include<bits/stdc++.h>
using namespace std;

int parent[100];
int Find(int r)
{
    if(parent[r]== r)
        return r;

    return parent[r] = Find(parent[r]);
}

void Union(int a, int b)
{
    int u = Find(a);
    int v = Find(b);


    parent[v] = u;
}

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        parent[i] = i;
    }
    int n, m;
    cout << "Enter nodes and edges number: "<< endl;
    cin >> n >> m;
    vector<pair<int, pair<int,int> > > edge;
    cout << "Enter nodes and weight"<< endl;
    for (int i = 0; i < m; i++)
    {
        int p, q, w;
        cin >> p >>q >> w;
        edge.push_back(make_pair(w,make_pair(p,q)));
    }
    sort(edge.begin(),edge.end());
    int weight = 0, ed = 0, ni = 0;
    while(ed < n-1)
    {
        int a = edge[ni].second.first;
        int b = edge[ni].second.second;
        int w = edge[ni].first;
        if(Find(a)!=Find(b))
        {
            Union(a,b);
            cout << "shortage path and weight ";
            cout << a << " " << b << " " << w << endl;
            weight+=w;
            ed++;

        }
        ni++;
    }
    cout << endl;
    cout << "Weight is: " << weight;
    return 0;
}

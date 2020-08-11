#include<bits/stdc++.h>

using namespace std;
int parent[100];

void makeset(int n)
{
    parent[n] = n;
}

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

    if (u != v)
    {
        parent[v] = u;
    }
    else cout << "already friend\n";

}

int show(int m)
{
    if(parent[m]==m)
    {
        return 0;
    }
    cout << parent[m];
    return show(parent[m]);


}

int main()
{
    cout << "node\n";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        makeset(i);
    }
    Union(1,2);
    Union(2,3);
    Union(3,4);
    Union(4,5);
    Union(1,3);
    //cout << Find(3) << endl;
    cout << parent[4] << endl;
    show(5);

    return 0;

}

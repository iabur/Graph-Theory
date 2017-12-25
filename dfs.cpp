#include<bits/stdc++.h>
using namespace std;
#define white 0
#define green 1
#define black 2
int tim = 0, d[100], f[100], color[100];
vector < int > adj[100];
 int n , e;
 void dfs(int n, int p);

void check(int n) {
    for (int i = 1; i <= n; i++) {
        if(color[i] == 0)
            dfs(n,i);
    }
}

void dfs(int n, int p) {
    int s = p;
    tim++;
    d[s] = tim;
    color[s] = green;
    cout << "d:"<<s<<" "<<d[s] << endl;
    for(int i = 0; i < adj[s].size(); i++) {
        int p = adj[s][i];

        if (color[p] == white) {
            dfs(n,p);
        }
    }
    color[s] = black;
    tim++;
    f[s] = tim;
     cout << "f:"<<s<<" "<< f[s] << endl;

    }


int main(){



    cout << "Enter number of nodes and edges" << endl;

    cin >> n >> e;
    cout << "Enter pair of nodes" << endl;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }


        check(n);



return 0;}

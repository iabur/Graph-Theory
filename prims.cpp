#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
vector< int > cost[100];
int node[100];
void bfs(int s, int n){

 for(int i = 1; i <= n; i++){
    node[i] = 0;
 }

 vector < int > q;
 q.push_back(s);
 node[s] = 1;
   for(int i = 1; i <= n-1; i++) {
    int p = 100000, y, z;
     for(int j = 0; j < q.size(); j++) {
        for(int k = 0; k < adj[q[j]].size(); k++){
            if(node[adj[q[j]][k]]==0){
                if(cost[q[j]][k]<=p) {
                        p = cost[q[j]][k];
                        y = q[j];
                        z = adj[q[j]][k];


                }

            }
        }
     }
       cout << p << " " << y << " " << z << endl;
      q.push_back(z);
        node[z] = 1;
      }
}

int main() {
 cout << "Enter the node and edges number\n";
 int n, e;
 cin>> n >> e;
 cout << "Enter node1 node2 and weight \n";
 for (int i = 0; i < e; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back(b);
    adj[b].push_back(a);
    cost[a].push_back(w);
    cost[b].push_back(w);
    }
    cout << "enter source\n";
    int s;
    cin >> s;
    bfs(s,n);

return 0;}

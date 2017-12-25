#include <bits/stdc++.h>

using namespace std;

const int N =  1000;

int matrix[N][N];

int next[N][N];

void floydwarshall(int n) {

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
               if(matrix[i][j] > matrix[i][k]+matrix[k][j]) {
                 matrix[i][j] = matrix[i][k] + matrix[k][j];
                 next[i][j] = next[i][k];
               }

            }
        }
    }
}

void path(int n1, int n2) {
    int i = n1;
    int j = n2;
    while(j != n2) {
        j = next[i][j];
        cout << "j ";
        }
}

int main() {
 cout << "Enter nodes number\n";
 int n;
 cin >> n;
 for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if(i == j) matrix [i][j] = 0;
        else matrix[i][j] = INT_MAX;
        next[i][j] = j;
    }
 }
 cout << "Enter edge numbers\n";
 int e;
 cin >> e;
 for (int i = 0; i < e; i++) {

       int a, b, w;
       cin >> a >> b >> w;
       matrix[a][b] = w;

    }


 floydwarshall(n);
 cout << "Enter node 1 to node 2 for calculate distance\n";
 int n1, n2;
 cin >> n1 >> n2;
 cout << matrix[n1][n2] << endl;
 path(n1,n2);
 return 0;
}

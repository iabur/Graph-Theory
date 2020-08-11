#include<bits/stdc++.h>

using namespace std;

int main() {
    cout << "Enter nodes number" << endl;
    int N;
    int p[100][100];
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << i << "to" << j << endl;
            cin >> p[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
return 0;}

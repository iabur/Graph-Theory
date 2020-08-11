#include<bits/stdc++.h>

using namespace std;

int main()
{
    int edge, p[100][100];
    cin >> edge;
    for (int i = 0; i < edge; i++)
    {
        int n1, n2, cost;
        cin >> n1 >> n2 >> cost;
        p[n1][n2] = cost;
        p[n2][n1] = cost;
    }
    return 0;
}

#include <iostream>

using namespace std;

const int N = 20;

int n;
char c[N][N];
bool col[N], dg[N], udg[N];

void dfs(int x)
{
    if (x == n) {
        for (int i = 0; i < n; i ++) puts(c[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i ++) {
        if (!col[i] && !dg[i + x] && !udg[n - x + i]) {
            c[x][i] = 'Q';
            col[i] = dg[i + x] = udg[n - x + i] = true;
            dfs(x + 1);
            col[i] = dg[i + x] = udg[n - x + i] = false;
            c[x][i] = '.';
        }
        
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            c[i][j] = '.';

    dfs(0);

    return 0;
}
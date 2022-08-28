#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N], row[N];

void dfs(int x, int y, int s)
{
    if (y == n) y = 0, x ++;
    if (x == n) {
        if (s == n) {
            for (int i = 0; i < n; i ++) puts(g[i]);
            puts("");
        }
        return;
    }
    
    dfs(x, y + 1, s);
    if (!row[x] && !col[y] && !dg[x + y] && !udg[n + x - y]) {
        row[x] = col[y] = dg[x + y] = udg[n + x - y] = true;
        g[x][y] = 'Q';
        dfs(x, y + 1, s + 1);
        g[x][y] = '.';
        row[x] = col[y] = dg[x + y] = udg[n + x - y] = false;
    }
    
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            g[i][j] = '.';

    dfs(0, 0, 0);

    return 0;
}
#include <iostream>

using namespace std;

const int N = 10;

int n;
bool used[N];
int num[N];

void dfs(int x)
{
    if (n == x) {
        for (int i = 0; num[i]; i ++) printf("%d ", num[i]);
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i ++)
        if (!used[i]) {
            num[x] = i;
            used[i] = true;
            dfs(x + 1);
            used[i] = false;
        }  
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}
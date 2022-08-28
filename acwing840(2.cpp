#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int e[N];

int find(int x)
{
    int k = (x % N + N) % N;
    while (e[k] != null && e[k] != x) {
        k ++;
        if (k == N) k = 0;
    }
    return k;
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(e, 0x3f, sizeof e);

    while (n --) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        int k = find(x);
        if (*op == 'I') e[k] = x;
        else {
            if (e[k] == x) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
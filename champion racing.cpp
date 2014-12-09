#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define N 1001

const int a[12] = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int fn;
map < string, int > f;
char na[N][100];
int b[N][N], c[N];
bool vis[N];

void so1() {
    int i, k, cnt, mx, mi;

    memset(vis, 0, sizeof(vis));

    cnt = 0;
    mx = -1;
    for (i = 1; i <= fn; ++i)
        if (c[i] > mx) {
            mx = c[i]; cnt = 1; mi = i;
        } else if (c[i] == mx)
            ++cnt;
    if (cnt == 1) {
        puts(na[mi]);
        return;
    }
    for (i = 1; i <= fn; ++i)
        if (c[i] == mx)
            vis[i] = 1;

    for (k = 1; ; ++k) {
        mx = -1;
        cnt = 0;
        for (i = 1; i <= fn; ++i)
            if (vis[i]) {
                if (b[i][k] > mx) {
                    mx = b[i][k]; cnt = 1; mi = i;
                } else if (b[i][k] == mx)
                    ++cnt;
            }
        if (cnt == 1) {
            puts(na[mi]);
            return;
        }
        for (i = 1; i <= fn; ++i)
            if (vis[i] && b[i][k] == mx)
                vis[i] = 1;
            else
                vis[i] = 0;
    }
}

void so2() {
    int i, k, cnt, mx, mi;

    memset(vis, 0, sizeof(vis));

    k = 1;
    mx = -1;
    cnt = 0;
    for (i = 1; i <= fn; ++i)
        if (b[i][k] > mx) {
            mx = b[i][k]; cnt = 1; mi = i;
        } else if (b[i][k] == mx)
            ++cnt;
    if (cnt == 1) {
        puts(na[mi]);
        return;
    }
    for (i = 1; i <= fn; ++i)
        if (b[i][k] == mx)
            vis[i] = 1;

    cnt = 0;
    mx = -1;
    for (i = 1; i <= fn; ++i)
        if (vis[i]) {
            if (c[i] > mx) {
                mx = c[i]; cnt = 1; mi = i;
            } else if (c[i] == mx)
                ++cnt;
        }
    if (cnt == 1) {
        puts(na[mi]);
        return;
    }
    for (i = 1; i <= fn; ++i)
        if (vis[i] && c[i] == mx)
            vis[i] = 1;
        else
            vis[i] = 0;

    for (k = 2; ; ++k) {
        mx = -1;
        cnt = 0;
        for (i = 1; i <= fn; ++i)
            if (vis[i]) {
                if (b[i][k] > mx) {
                    mx = b[i][k]; cnt = 1; mi = i;
                } else if (b[i][k] == mx)
                    ++cnt;
            }
        if (cnt == 1) {
            puts(na[mi]);
            return;
        }
        for (i = 1; i <= fn; ++i)
            if (vis[i] && b[i][k] == mx)
                vis[i] = 1;
            else
                vis[i] = 0;
    }
}

int main() {
    int t, n, i;
    char s[100];
    fn = 0;
    f.clear();
    memset(c, 0, sizeof(c));
    memset(b, 0, sizeof(b));
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            scanf("%s", s);
            if (!f[s]) {
                f[s] = ++fn;
                strcpy(na[fn], s);
            }
            if (i <= 10)
                c[ f[s] ] += a[i];
            ++b[ f[s] ][i];
        }
    }
    so1();
    so2();
    return 0;
}



/*
ID: huangch7
TASK:twofive
LANG:C++

*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int f[6][6][6][6][6], code, len[5], t[5], mode, maxr[5], maxc[5];
char cmd[2], chmat[5][5];
bool v[25];

int dp(int a, int b, int c, int d, int e, int k)
{
    int &ans = f[a][b][c][d][e];
    if (ans) return ans;
    if (!v[k]) return dp(a, b, c, d, e, k + 1);
    if (a < 5 && k > maxr[0] && k > maxc[a]) ans += dp(a+1, b, c, d, e, k+1);
    if (b < a && k > maxr[1] && k > maxc[b]) ans += dp(a, b+1, c, d, e, k+1);
    if (c < b && k > maxr[2] && k > maxc[c]) ans += dp(a, b, c+1, d, e, k+1);
    if (d < c && k > maxr[3] && k > maxc[d]) ans += dp(a, b, c, d+1, e, k+1);
    if (e < d && k > maxr[4] && k > maxc[e]) ans += dp(a, b, c, d, e+1, k+1);
    return ans;
}

int main()
{
    freopen("twofive.in", "r", stdin);
    freopen("twofive.out", "w", stdout);
    scanf("%s\n", cmd);
    memset(len, 0, sizeof(len));
    code = 0;
    memset(chmat, 0, sizeof(chmat));
    if (cmd[0] == 'N') scanf("%d", &code), mode = 0;
    else
    {
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                scanf("%c", &chmat[i][j]);
        mode = 1;
    }
    memset(v, true, sizeof(v));
    memset(maxr, -1, sizeof(maxr));
    memset(maxc, -1, sizeof(maxc));
    for (int i = 0; i < 5; ++i)
    {
        len[i] = 0;
        for (int j = 0; j < 5; ++j)
        {
            len[i]++;
            if (mode == 0)
            {
              for (int k = 0; k < 25; ++k) // 尝试在i，j位置填入k
                    if (v[k] && k > maxr[i] && k > maxc[j])
                    {
                        memset(f, 0, sizeof(f));
                        f[5][5][5][5][5] = 1;
                        v[k] = false;
                        maxr[i] = maxc[j] = k;
                        int tmp = dp(len[0], len[1], len[2], len[3], len[4], 0);
                        if (code <= tmp)
                        {
                          chmat[i][j] = 'A' + k;// 直到放入k的可能性比code 大，此时再填下一个字符。
                            break;
                        }
                        else
                        {
                            v[k] = true;
                            code -= tmp;// 填入k后，最多有tmp中可能
                        }
                    }
            }
            else
            {
                for (int k = 0; k < chmat[i][j] - 'A'; ++k)
                    if (v[k] && k > maxr[i] && k > maxc[j])
                    {
                        memset(f, 0, sizeof(f));
                        f[5][5][5][5][5] = 1;
                        v[k] = false;
                        maxr[i] = maxc[j] = k;
                        code += dp(len[0], len[1], len[2], len[3], len[4], 0);
                        v[k] = true;
                    }
                v[chmat[i][j] - 'A'] = false;
            }
        }
    }
    if (mode == 0)
    {
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                printf("%c", chmat[i][j]);
        printf("\n");
    }
    else printf("%d\n", code + 1);
    return 0;
}

/*
ID:huangch7
PROB:fence8
LANG:C++
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=2000;

int orz[maxn],take,r,h[maxn],l[maxn],n,sum[maxn],tv;

bool cmp(int a,int b)
{
    return a>b;
}

bool dfs(int now,int nowp,int maxp)
{
    if (now==0) return true;
    if (take>tv-sum[maxp]) return false;
    for (int a=nowp;a<=n;a++)
        if (l[a]>=h[now])
        {
            l[a]-=h[now];
            if (l[a]<h[1]) take+=l[a];
            if (h[now]==h[now-1])
            {
                if (dfs(now-1,a,maxp)) return true;
            }
            else
            {
                if (dfs(now-1,1,maxp)) return true;
            }
            if (l[a]<h[1]) take-=l[a];
            l[a]+=h[now];
        }
    return false;
}

bool check(int now)
{
    return dfs(now,1,now);
}

int main()
{
    freopen("fence8.in","r",stdin);
    freopen("fence8.out","w",stdout);

    scanf("%d",&n);
    for (int a=1;a<=n;a++)
        scanf("%d",&l[a]),tv+=l[a];
    scanf("%d",&r);
    for (int a=1;a<=r;a++)
        scanf("%d",&h[a]);
    sort(l+1,l+n+1);
    sort(h+1,h+r+1);
    for (int a=1;a<=r;a++)
        sum[a]=sum[a-1]+h[a];
    for (int a=1;a<=n;a++)
        orz[a]=l[a];
    int le=0;
    while (sum[r]>tv)
        r--;
    if (r==0)
    {
        printf("0\n");
        return 0;
    }
    r++;
    while (le+1!=r)
    {
        for (int a=1;a<=n;a++)
            l[a]=orz[a];
        take=0;
        int m=(le+r)>>1;
        if (check(m)) le=m;
        else r=m;
    }
    printf("%d\n",le);

    return 0;
}

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}

#define MP(A,B) make_pair(A,B)
#define ALL(A) A.begin(),A.end()

#define PB push_back
#define SIZE(X) ((int)(X.size()))
#define REP(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, l, h) for(int i=(l); i<=(h); ++i)
#define FORD(i, h, l) for(int i=(h); i>=(l);--i)
#define ALL(A) A.begin(),A.end()

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;


const int maxn=100000+5;
 
int nA,nB,n,m;
PII A[maxn],B[maxn];
 
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	nA=nB=0;
	for (int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if (a==1) A[++nA]=MP(b,i+1);
		else B[++nB]=MP(b,i+1);
	}
	sort(A+1,A+nA+1);
	sort(B+1,B+nB+1);
	reverse(A+1,A+nA+1);
	reverse(B+1,B+nB+1);
	int R=0,sA=0,sB=0;
	A[0]=MP(0,0);
	for (int i=1;i<=nA;i++)
		A[i].first+=A[i-1].first;
	B[0]=MP(0,0);
	for (int i=1;i<=nB;i++)
		B[i].first+=B[i-1].first;
	for (int i=0;i<=nB && i+i<=m;i++)
	{
		int t=B[i].first+A[min(m-i-i,nA)].first;
		if (t>R) R=t,sA=min(m-i-i,nA),sB=i;
	}
	printf("%d\n",R);
	for (int i=1;i<=sA;i++)
		printf("%d\n",A[i].second);
	for (int i=1;i<=sB;i++)
		printf("%d\n",B[i].second);
	return 0;
}

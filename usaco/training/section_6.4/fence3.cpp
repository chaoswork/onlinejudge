/*
ID:huangch7
PROB:fence3
LANG:C++
*/
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
#define MATRIX(n, m, v) vector<vector<int> >((n), vector<int>((m), (v)))
#define DISPLAY_MATRIX(mat, n, m) REP(i, min(SIZE(mat), n)){ REP(j, min(SIZE(mat[0]), m)) {cout << mat[i][j] << "\t";} cout << endl;}


typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;


// To store the point
#define Point pair<double, double>
#define X first
#define Y second
using namespace std;
 
// Function to return the minimum distance
// between a line segment AB and a point E
double minDistance(Point A, Point B, Point E)
{
  // 有两个端点相同的fence
  if (abs(A.X - B.X) < 1e-9 && abs(A.Y - B.Y) < 1e-9){
    double y = E.Y - B.Y;
    double x = E.X - B.X;
    return sqrt(x * x + y * y);
  }
 
    // vector AB
    pair<double, double> AB;
    AB.X = B.X - A.X;
    AB.Y = B.Y - A.Y;
 
    // vector BP
    pair<double, double> BE;
    BE.X = E.X - B.X;
    BE.Y = E.Y - B.Y;
 
    // vector AP
    pair<double, double> AE;
    AE.X = E.X - A.X,
    AE.Y = E.Y - A.Y;
 
    // Variables to store dot product
    double AB_BE, AB_AE;
 
    // Calculating the dot product
    AB_BE = (AB.X * BE.X + AB.Y * BE.Y);
    AB_AE = (AB.X * AE.X + AB.Y * AE.Y);
 
    // Minimum distance from
    // point E to the line segment
    double reqAns = 0;
 
    // Case 1
    if (AB_BE > 0) {
 
        // Finding the magnitude
        double y = E.Y - B.Y;
        double x = E.X - B.X;
        reqAns = sqrt(x * x + y * y);
    }
 
    // Case 2
    else if (AB_AE < 0) {
        double y = E.Y - A.Y;
        double x = E.X - A.X;
        reqAns = sqrt(x * x + y * y);
    }
 
    // Case 3
    else {
 
        // Finding the perpendicular distance
        double x1 = AB.X;
        double y1 = AB.Y;
        double x2 = AE.X;
        double y2 = AE.Y;
        double mod = sqrt(x1 * x1 + y1 * y1);
        reqAns = abs(x1 * y2 - y1 * x2) / mod;
    }
    return reqAns;
}
 



int main() {
  freopen("fence3.in","r",stdin);
  freopen("fence3.out","w",stdout);

  /*
  Point aa = MP(0, 0);
  Point bb = MP(2, 0);
  Point cc = MP(4, 0);
  cout << minDistance(aa, bb, cc) << endl;
  return 0;*/
  int n;
  double x, y, xx, yy;
  vector<Point> points_A;
  vector<Point> points_B;
  VI dirs_x = {0, 1, 0, -1};
  VI dirs_y = {-1, 0, 1, 0};
  cin >> n;
  double min_x = 10000;
  double max_x = -1;
  double min_y = 10000;
  double max_y = -1;
  REP(i, n){
    cin >> x >> y >> xx >> yy;
    //    x *= 10;
    //    y *= 10;
    //    xx *= 10;
    //    yy *= 10;
    Point a = MP(x, y);
    points_A.PB(a);
    min_x = min(min_x, x);
    max_x = max(max_x, x);
    min_y = min(min_y, y);
    max_y = max(max_y, y);
    Point b = MP(xx, yy);
    points_B.PB(b);
    min_x = min(min_x, xx);
    max_x = max(max_x, xx);
    min_y = min(min_y, yy);
    max_y = max(max_y, yy);
    
  }
  //  cout << min_x << " " << max_x << " | " << min_y << " " << max_y << endl;
  double best = -1;
  double best_x, best_y;

  Point start = MP((min_x + max_x) / 2, (min_y + max_y) / 2);
  int loop = 0;
  while (true){
    loop++;

    double step = 10;
    bool found = false;
    while (step > 0.01){
      // 多个 step 防止跑到过高的地方
      REP(k, 4){
        Point P;
        P.X = start.X + step * dirs_x[k];
        P.Y = start.Y + step * dirs_y[k];

        double total = 0;
        REP(i, n){
          Point A = points_A[i];
          Point B = points_B[i];
          total += minDistance(A, B, P);
          //if(x == 1.0 && y == 1.6) cout << distanceAndIntersection(A, B, P) << endl;
        }
        // cout << loop << " " << k << " " << step << " " << P.X << " " << P.Y <<  " " << total << endl;        
        if (best < 0 || best > total) {
          best = total;
          best_x = P.X;
          best_y = P.Y;
          start = MP(best_x, best_y);
          found = true;
        }
      
      } // end REP(k, 4)
      if (found) break;
      step *= 0.9;
    }
    if (!found) break;
  }
  cout << fixed << setprecision(1) <<  best_x  << " " << best_y << " " << best << endl;
  
    

    return 0;
}




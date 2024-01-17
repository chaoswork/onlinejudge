/*
ID: huangch7
LANG: C++
TASK: cowtour
 */


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include<sstream>
#include<cstdio>
#include <cmath>
#include <iomanip> 

using namespace std;

const string task_name = "cowtour";

  // 计算两点之间的距离
double get_dist(int i, int j, vector<pair<int, int> > pos) {
    int dx = pos[i].first - pos[j].first;
    int dy = pos[i].second - pos[j].second;
    return sqrt(dx * dx + dy * dy);
  };


int main() {
  freopen("cowtour.in","r",stdin);
  freopen("cowtour.out","w",stdout);

  // 读取输入数据
  int n;
  cin >> n;
  vector<pair<int, int> > pos(n);
  vector<string > conn;
  
  for (int i = 0; i < n; i++) {
    cin >> pos[i].first >> pos[i].second;
  }
    string line;
    std::getline(std::cin, line);
  
  for (int i = 0; i < n; i++) {
    //    cin >> line;
    std::getline(std::cin, line);

    conn.push_back(line);
  }
  //  for (int i = 0; i<conn.size(); ++i){
  //    cout << conn[i] <<endl;
  //  }


  // 计算所有点之间的最短距离
  vector<vector<double> > dist(n, vector<double>(n, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      //      cout << "debug " << i <<"," <<j<< " " << conn[i] << " " << conn[i][j] <<endl;
      if (conn[i][j] == '0') {
        continue;
      }
      dist[i][j] = get_dist(i, j, pos);
    }
    dist[i][i] = 0;
  }
//  for (int i = 0; i < n; i ++){
//    for (int j = 0; j < n; j ++) {
//        cout << dist[i][j] << " ";
//    }
//    cout << endl;
//  }

  // 使用 Floyd-Warshall 算法计算所有点之间最短距离
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] < -0.5 || dist[k][j] < -0.5 ) {
          continue;
        }
        if (dist[i][j] <-0.5 || dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

//  for (int i = 0; i < n; i ++){
//    for (int j = 0; j < n; j ++) {
//        cout << dist[i][j] << " ";
//    }
//    cout << endl;
//  }

  // 计算两个不同颜色点的最大距离
  double ans = -1;
  vector<int> colors(n, -1);
  
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (colors[i] > -0.5) {
      continue;
    }
    colors[i] = cnt++;
    for (int j = 0; j < n; j++) {
      if (dist[i][j] > -0.5) {
        colors[j] = colors[i];
      }
    }
  }
  // 计算每个点的最大距离
  vector<double> max_dist(n, 0);
  vector<double> max_field_dist(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dist[i][j] < -0.5) {
        continue;
      }
      if (max_dist[i] < dist[i][j]) {
        max_dist[i] = dist[i][j];
      }
    }
    if (max_dist[i] > max_field_dist[colors[i]])
      max_field_dist[colors[i]] = max_dist[i];
    
  }
  
//  for (int i = 0; i< n; ++){
//  cout<< colors[i] << endl;
//    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (colors[i] == colors[j]) {
        continue;
      }
      double cur = max_dist[i] + max_dist[j] + get_dist(i, j, pos);
      cur = max(cur, max_field_dist[colors[i]]);
      cur = max(cur, max_field_dist[colors[j]]);
      if (ans < -0.5 || ans > cur) {
        ans = cur;
      }
    }
  }

  // 输出答案
  //cout << setprecision(6) << ans << endl;
  printf("%.6f\n", ans);

  return 0;
}

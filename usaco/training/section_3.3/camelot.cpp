/*
ID: huangch7
LANG: C++
TASK: camelot
*/

#include <iostream>
#include <fstream>
#include <deque>
#include <unordered_map>
#include <cmath>
#include <cstring>

using namespace std;

const int INF = 100000;

int R, C;
int king_x, king_y;
int knight_pos[30][30];

int dist_cache[30][30][30][30];

 


int king_distance(int x1, int y1, int x2, int y2) {
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    return max(dx, dy);
}



int bfs(int sx, int sy, int ex, int ey) {
  if (dist_cache[sx][sy][ex][ey] != -1) {
    return dist_cache[sx][sy][ex][ey];
  }
    bool visited[30][30] = {false};
    int dist[30][30] = {0};
    int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    
    deque<pair<int, int> > q;
    q.push_back(make_pair(sx, sy));
    visited[sx][sy] = true;
    dist_cache[sx][sy][sx][sy] = 0;
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop_front();
        int x = curr.first;
        int y = curr.second;
        
//        if (x == ex && y == ey) {
//            return dist[x][y];
//        }
//        
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                dist_cache[sx][sy][nx][ny] = dist[x][y] + 1;
                dist_cache[nx][ny][sx][sy] = dist[x][y] + 1;
                q.push_back(make_pair(nx, ny));
            }
        }
    }
    if (dist_cache[sx][sy][ex][ey] == -1) {
      dist_cache[sx][sy][ex][ey] = INF;
      dist_cache[ex][ey][sx][sy] = INF;
    }
    
    return dist_cache[sx][sy][ex][ey];
}

int main() {
    ifstream fin("camelot.in");
    ofstream fout("camelot.out");
 for(int i = 0; i < 30; ++i)
   for(int j = 0; j < 30; ++j)
     for(int k = 0; k < 30; ++k)
        for(int p = 0; p < 30; ++p)
          dist_cache[i][j][k][p] = -1;
    

    fin >> R >> C;
    char col;
    int row;
    fin >> col >> row;
    king_x = row - 1;
    king_y = col - 'A';
    
    while (fin >> col >> row) {
        knight_pos[row - 1][col - 'A'] = 1;
    }

    int min_moves = INF;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            int total_dist = 0;
            for (int k = 0; k < R; ++k) {
                for (int l = 0; l < C; ++l) {
                    if (knight_pos[k][l]) {
                        total_dist += bfs(k, l, i, j);
                    }
                }
            }
            //            int dist_king = king_distance(i, j, king_x, king_y);
            //            int total = total_dist + dist_king;
            int best = INF;
            for (int len = 0; len < max(R, C); ++len){
              for (int px = max(0, king_x - len); px < min(R, king_x + len + 1); ++px) {
                 for (int py = max(0, king_y - len); py < min(C, king_y + len + 1); ++py) {
                    for (int k = 0; k < R; ++k) {
                       for (int l = 0; l < C; ++l) {
                         if (knight_pos[k][l]) {
                   
                            if (bfs(k, l, px, py) + bfs(px, py, i, j) == bfs(k, l, i, j)){
                              best = len;
                              break;
                            }
                        }
                      }
                       if (best != INF) break;
                    }
                    if (best != INF) break;
                 }
                }
                if (best != INF) break;
                 
            }
            min_moves = min(min_moves, total_dist + min(best, king_distance(i, j, king_x, king_y)));

//            for (int k = 0; k < R; ++k) {
//                for (int l = 0; l < C; ++l) {
//                    if (knight_pos[k][l]) {
//                      // pick up position
//                      for (int px = 0; px < R; ++px) for (int py = 0; py < C; ++ py) {
//                        
//                          int pick_king = total_dist - bfs(k, l, i, j) + bfs(k, l, px, py) + bfs(px, py, i, j) + king_distance(px, py, king_x, king_y);
//                        // int pick_king = total_dist - bfs(k, l, i, j) + bfs(k, l, king_x, king_y) + bfs(king_x, king_y, i, j);
//                        total = min(total, pick_king);
//                      }
//                    }
//                }
//            }
//            min_moves = min(min_moves, total);
        }
    }

    fout << min_moves << endl;

    fin.close();
    fout.close();

    return 0;
}

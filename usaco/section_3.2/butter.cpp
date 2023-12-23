/*
ID: huangch7
LANG: C++
TASK: butter
*/

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

const int MAX_N = 805; // Adjust the maximum number of elements as needed
const int INF = 1e9;

int cows[MAX_N];
// int pathes[MAX_N][MAX_N];
vector<pair<int, int> > adj[MAX_N];
int res[MAX_N][MAX_N];

int main() {
    ifstream fin("butter.in");
    ofstream fout("butter.out");

    int N, P, C;
    fin >> N >> P >> C;

    for (int i = 0; i < N; ++i) {
        fin >> cows[i];
    }

    // for (int i = 0; i < MAX_N; ++i) {
    //     for (int j = 0; j < MAX_N; ++j) {
    //         pathes[i][j] = INF;
    //     }
    // }

    for (int i = 0; i < C; ++i) {
        int a, b, d;
        fin >> a >> b >> d;
        // pathes[a][b] = d;
        // pathes[b][a] = d;
        adj[a].push_back(make_pair(b, d));
        adj[b].push_back(make_pair(a, d));
    }

    int best = INF;
    //    for (int start_index = 0; start_index < N; ++start_index) {
    for (int start = 1; start <= P; ++start) {
      //        int start = cows[start_index];
        bool visited[MAX_N] = {false};
        int dist[MAX_N];
        for (int i = 0; i <= P; ++i) {
            dist[i] = INF;
        }
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > todo;
        todo.push(make_pair(0, start));

        for (int k = 0; k < P; ++k) {
            int best_node = -1;
            while (!todo.empty()) {
                int node = todo.top().second;
                todo.pop();
                if (!visited[node]) {
                    best_node = node;
                    break;
                }
            }
            if (best_node == -1) break;
            visited[best_node] = true;
            // ETL here, change to adj
            // for (int node = 1; node <= P; ++node) {
            //     if (pathes[best_node][node] != INF && dist[node] > dist[best_node] + pathes[best_node][node]) {
            //         dist[node] = dist[best_node] + pathes[best_node][node];
            //         todo.push(make_pair(dist[node], node));
            //     }
            // }
            for (auto e : adj[best_node]) {
              if (dist[e.first] > dist[best_node] + e.second) {
                dist[e.first] = dist[best_node] + e.second;
                todo.push(make_pair(dist[e.first], e.first));
              }
            }
        }

        for (int node = 1; node <= P; ++node) {
            res[node][start] = dist[node];
        }

        int cur = 0;
        bool cannot_reach = false;
        for (int i = 0; i < N; ++i) {
            if (res[cows[i]][start] == INF) {
                cannot_reach = true;
                break;
            }
            cur += res[cows[i]][start];
        }

        if (!cannot_reach && (best == INF || best > cur)) {
            best = cur;
        }
    }

    fout << best << endl;

    fin.close();
    fout.close();

    return 0;
}

// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <queue>
// #include <climits>
// #include <algorithm>
// 
// using namespace std;
// 
// const int MAX_P = 801;
// const int INF = INT_MAX / 4; // To avoid integer overflow
// 
// int main() {
//     ifstream fin("butter.in");
//     ofstream fout("butter.out");
// 
//     int N, P, C;
//     fin >> N >> P >> C;
// 
//     vector<int> cows(N);
//     for (int i = 0; i < N; ++i) {
//         fin >> cows[i];
//     }
// 
//     int pathes[MAX_P][MAX_P];
//     int res[MAX_P][MAX_P];
//     for (int i = 1; i <= P; ++i) {
//         fill_n(pathes[i], P + 1, INF);
//         fill_n(res[i], P + 1, INF);
//         pathes[i][i] = 0;
//     }
// 
//     for (int i = 0; i < C; ++i) {
//         int a, b, d;
//         fin >> a >> b >> d;
//         pathes[a][b] = d;
//         pathes[b][a] = d;
//     }
// 
//     for (int start : cows) {
//       int visited[P + 1];
//       int dist[P + 1];
//       fill_n(visited, P + 1, 0);
//       fill_n(dist, P + 1, INF);
//       dist[start] = 0;
//       for (int i = 0; i < P; ++i) {
//         int best = INF;
//         int best_node = -1;
//         for(int node = 1; node <= P; ++node){
//           if(visited[node]) continue;
//           if(dist[node] == INF) continue;
//           if(best > dist[node]){
//             best = dist[node];
//             best_node = node;
//           }
//         }
//         visited[best_node] = 1;
//         for(int node = 1; node <= P; ++node){
//           dist[node] = min(dist[node], best + pathes[best_node][node]);
//         }
//       }
//       for(int node = 1; node <= P; ++node){
//         res[node][start] = dist[node];
//       }
//     }
//     int best = INT_MAX;
//     for(int i = 1; i <= P; ++i){
//       int cur = 0;
//       bool cannot_reach = false;
//       for (int j: cows){
//         if(res[i][j] == INF){
//           cannot_reach = true;
//           break;
//         }
//         cur += res[i][j];
//       }
//       if(cannot_reach) continue;
//       best = min(best, cur);
//     }
// 
//     fout << best << endl;
// 
//     fin.close();
//     fout.close();
//     return 0;
// }
//
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <climits>
//
//using namespace std;
//
//int main() {
//    ifstream fin("butter.in");
//    ofstream fout("butter.out");
//
//    int N, P, C;
//    fin >> N >> P >> C;
//
//    vector<int> cows;
//    int pathes[801][801]; // Using 801 instead of 1000 to match the constraints (800 cows + 1)
//    int result = INT_MAX;
//
//    for (int i = 0; i < N; ++i) {
//        int cow;
//        fin >> cow;
//        cows.push_back(cow);
//    }
//
//    // Initialize pathes array with a very large number (instead of INT_MAX to avoid overflow in calculations)
//    const int INF = 1e8;
//    for (int i = 1; i <= P; ++i) {
//        for (int j = 1; j <= P; ++j) {
//            pathes[i][j] = INF;
//        }
//        pathes[i][i] = 0;
//    }
//
//    for (int i = 0; i < C; ++i) {
//        int a, b, d;
//        fin >> a >> b >> d;
//        pathes[a][b] = d;
//        pathes[b][a] = d;
//    }
//
//    // Floyd-Warshall Algorithm
//    for (int k = 1; k <= P; ++k) {
//        for (int i = 1; i <= P; ++i) {
//          // for (int j = 1; j <= P; ++j) {
//          for (int j : cows) {
//                pathes[i][j] = min(pathes[i][j], pathes[i][k] + pathes[k][j]);
//            }
//        }
//    }
//
//    for (int i = 1; i <= P; ++i) {
//        int cur = 0;
//        bool cannot_reach = false;
//        for (int j : cows) {
//            cur += pathes[i][j];
//            if (cur >= result) {
//                cannot_reach = true;
//                break;
//            }
//        }
//        if (!cannot_reach) {
//            result = cur;
//        }
//    }
//
//    fout << result << endl;
//
//    fout.close();
//    return 0;
//}
//
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <map>
//#include <climits>
//
//using namespace std;
//
//int main() {
//    ifstream fin("butter.in");
//    ofstream fout("butter.out");
//
//    int N, P, C;
//    fin >> N >> P >> C;
//
//    vector<int> cows;
//    int pathes[1000][1000];
//    int result = INT_MAX;
//
//    for (int i = 0; i < N; ++i) {
//        int cow;
//        fin >> cow;
//        cows.push_back(cow);
//    }
//
//    for (int i = 1; i <= P; ++i) {
//        for (int j = 1; j <= P; ++j) {
//            pathes[i][j] = INT_MAX;
//        }
//        pathes[i][i] = 0;
//    }
//
//    for (int i = 0; i < C; ++i) {
//        int a, b, d;
//        fin >> a >> b >> d;
//        pathes[a][b] = d;
//        pathes[b][a] = d;
//    }
//
//    for (int k = 1; k <= P; ++k) {
//        for (int i = 1; i <= P; ++i) {
//            for (int j = 1; j <= P; ++j) {
//                if (pathes[i][k] != INT_MAX && pathes[k][j] != INT_MAX) {
//                    pathes[i][j] = min(pathes[i][j], pathes[i][k] + pathes[k][j]);
//                }
//            }
//        }
//    }
//
//    for (int i = 1; i <= P; ++i) {
//        int cur = 0;
//        bool cannot_reach = false;
//        for (int j : cows) {
//            if (pathes[i][j] == INT_MAX) {
//                cannot_reach = true;
//                break;
//            }
//            cur += pathes[i][j];
//        }
//        if (cannot_reach) {
//            continue;
//        }
//        if (result == INT_MAX || result > cur) {
//            result = cur;
//        }
//    }
//
//    fout << result << endl;
//
//    fout.close();
//    return 0;
//}
//

/*
ID: huangch7
LANG: C++
TASK: telecow

 */
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 100000000;

map<int, int>  bfs(int start, int target, map<int, map<int, int> >& adj){
  map<int, int> level;
  for (auto kv: adj) level[kv.first] = 0;
  level[start] = 1;
  queue<int> q;
  q.push(start);
  while (!q.empty()){
    int cur = q.front();
    q.pop();
    for (auto kv: adj[cur]){
      int x = kv.first;
      int w = kv.second;
      if (level[x] == 0 && w > 0){
        level[x] = level[cur] + 1;
        q.push(x);
      }
      
    }
    
  }
  return level;
  
}

int dfs(int start, int target, map<int, map<int, int> >& adj, int cap, map<int, int>& level){
  int left = cap;
  if (start == target) return cap;
  for (auto kv: adj[start]){
    int x = kv.first;
    int f = kv.second;
    if ((level[x] == level[start] + 1) && f > 0){
      int cur_flow = dfs(x, target, adj, min(left, f), level);
      adj[start][x] -= cur_flow;
      if (adj[x].find(start) == adj[x].end()) adj[x][start] = 0;
      adj[x][start] += cur_flow;
      left -= cur_flow;
                                                
    }
  }
  return cap - left;
}

int max_flow(int start, int target, map<int, map<int, int> >& adj){
  int total = 0;
  while (true){
    map<int, int> level = bfs(start, target, adj);
    if (level[target] == 0) break;
    total += dfs(start, target, adj, INF, level);
  }
  return total;
}


int max_flow_2(int start, int target, map<int, map<int, int> >& adj, const vector<int>& remove_node) {
    int total = 0;
    while (true) {
        map<int, int> flow, prev, visited;
        for (auto kv : adj) {
            flow[kv.first] = -1;
            prev[kv.first] = -1;
            visited[kv.first] = 0;
        }
        flow[start] = INF;

        for (int x : remove_node) {
            visited[x] = 1;
        }

        while (true) {
            int best = 0;
            int best_pos = 0;

            for (auto& kv : adj) {
              int i = kv.first;
                if (visited[i]) continue;
                if (flow[i] == -1) continue;
                if (best < flow[i]) {
                    best = flow[i];
                    best_pos = i;
                }
            }

            if (best_pos == 0 || best_pos == target) break;

            visited[best_pos] = 1;
            for (auto& kv : adj[best_pos]) {
              int j = kv.first;
              int val = kv.second;
                int cur_flow = min(val, flow[best_pos]);
                if (flow[j] == -1 || flow[j] < cur_flow) {
                    flow[j] = cur_flow;
                    prev[j] = best_pos;
                }
            }
        }

        if (flow[target] == -1) break;

        int cur = target;
        while (cur != start) {
            adj[prev[cur]][cur]--;
            if (adj[cur].find(prev[cur]) == adj[cur].end()) {
                adj[cur][prev[cur]] = 0;
            }
            adj[cur][prev[cur]]++;
            cur = prev[cur];
        }
        total += flow[target];
    }
    return total;
}


std::map<int, std::map<int, int>> get_new_adj(const std::map<int, std::map<int, int>>& old_adj, const std::vector<int>& remove_node) {
    std::map<int, std::map<int, int>> adj;

    for (const auto& i : old_adj) {
        if (std::find(remove_node.begin(), remove_node.end(), i.first) != remove_node.end()) {
            continue;
        }

        int i_1000 = i.first + 1000;
        int i_2000 = i.first + 2000;

        adj[i_1000] = {};
        adj[i_2000] = {};

        adj[i_1000][i_2000] = 1;

        for (const auto& j : i.second) {
            if (std::find(remove_node.begin(), remove_node.end(), j.first) != remove_node.end()) {
                continue;
            }

            int j_1000 = j.first + 1000;
            int j_2000 = j.first + 2000;

            adj[i_2000][j_1000] = INF;
            adj[j_2000][i_1000] = INF;
        }
    }

    return adj;
}

int main() {
    ifstream fin("telecow.in");
    ofstream fout("telecow.out");

    int N, M, start, target;
    fin >> N >> M >> start >> target;

    map<int, map<int, int>> adj, adj_init, adj_new;

    for (int i = 1; i <= N; ++i) {
        adj[i] = {};
        adj_init[i] = {};
    }

    for (int i = 0; i < M; ++i) {
        int s, e;
        fin >> s >> e;
        adj[s][e] = 1;
        adj[e][s] = 1;
        adj_init[s][e] = 1;
        adj_init[e][s] = 1;
    }
    adj_new = get_new_adj(adj_init, {});
    int total = max_flow(start + 2000, target + 1000, adj_new);

    int cnt = 0;
    vector<int> ans;

    for (int i = 1; i <= N; ++i) {
        if (i == start || i == target) continue;

        adj = adj_init;
        adj_new = get_new_adj(adj_init, {});
        vector<int> remove_node;
        for (auto x: ans) remove_node.push_back(x);
        remove_node.push_back(i);
        adj_new = get_new_adj(adj_init, remove_node);

        int cur = max_flow(start + 2000, target + 1000, adj_new);
        
        if (cur == total - ans.size() - 1) {
            ans.push_back(i);
            cnt++;
        }

        if (cnt == total) break;
    }

    fout << total << endl;

    string line;
    for (int i = 0; i < ans.size(); ++i) {
        line += to_string(ans[i]);
        if (i != ans.size() - 1) line += " ";
    }

    fout << line << endl;

    fin.close();
    fout.close();

    return 0;
}

/*
ID: huangch7
LANG: C++
TASK: shuttle
*/  
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <array>

using namespace std;

const int INF = 100000000;

unordered_map<string, int> state2id;
unordered_map<int, string> id2state;

int get_idx(string x){
  if (state2id.find(x) == state2id.end()){
    id2state[state2id.size()] = x;
    state2id[x] = state2id.size();
  }
  return state2id[x];
}

string get_state(int x){
  return id2state[x];
}

int main() {
    ifstream fin("shuttle.in");
    ofstream fout("shuttle.out");

    int N;
    fin >> N;


    string target = "";
    for (int i = 0; i < N; ++i) target += "1";
    target += "A";
    for (int i = 0; i < N; ++i) target += "0";

    string start = "";
    for (int i = 0; i < N; ++i) start += "0";
    start += "A";
    for (int i = 0; i < N; ++i) start += "1";

    unordered_map<int, int> next;
    unordered_map<string, int> ans;

    queue<int> q;
    q.push(get_idx(target));
    next[get_idx(target)] = -1;
    ans[target] = -1;

    while (!q.empty()) {
      string cur = get_state(q.front());
        q.pop();

        int black = -1;
        for (int i = 0; i < cur.size(); ++i) {
            if (cur[i] == 'A') {
                black = i;
                break;
            }
        }

        for (int i : {-2, -1, 1, 2}) {
            int idx = black + i;
            if (idx < 0 || idx >= 2 * N + 1) {
                continue;
            }

            string state = cur;
            swap(state[black], state[idx]);

            if (next.find(get_idx(state)) != next.end()) {
                continue;
            }

            next[get_idx(state)] = get_idx(cur);
            ans[state] = idx;

            if (state == start) {
                break;
            }

            q.push(get_idx(state));
        }
    }

    vector<int> final_ans_;
    string cur = start;
    while (cur != target) {
        final_ans_.push_back(ans[cur] + 1);
        cur = get_state(next[get_idx(cur)]);
    }
    
    vector<int> final_ans;
    for (int i = final_ans_.size() - 1; i >= 0; --i) {
      //      cout << i << " " << final_ans_[i] << endl;
      final_ans.push_back(final_ans_[i]);
    }
    
    for (size_t i = 0; i < final_ans.size(); i += 20) {
        for (size_t j = i; j < min(i + 20, final_ans.size()); ++j) {
          if (j != i) fout << " ";
          fout << final_ans[j];
        }
        fout << "\n";
    }

    fout.close();
    fin.close();

    return 0;
}

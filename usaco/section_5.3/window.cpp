/*
ID: huangch7
LANG: C++
TASK: window
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

int INF = 100000000;

struct Window {
    string name;
    vector<short> coords;
};

Window makeWindow(const string& name, const vector<short>& coords) {
    Window win;
    win.name = name;
    win.coords = coords;
    return win;
}

vector<short> merge(const vector<short>& a, const vector<short>& b) {
    short min_x = a[0];
    short min_y = a[1];
    short max_x = a[2];
    short max_y = a[3];

    short min_X = b[0];
    short min_Y = b[1];
    short max_X = b[2];
    short max_Y = b[3];

    max_x = min(max_x, max_X);
    min_x = max(min_x, min_X);
    max_y = min(max_y, max_Y);
    min_y = max(min_y, min_Y);

    return {min_x, min_y, max_x, max_y};
}

void display_cache(int i, vector<vector<int> > v){
  cout << "display cache i=" << i << endl;
  for (auto it=v.begin(); it != v.end(); ++it){
    for (auto it2=it->begin(); it2 != it->end(); ++it2){
      cout << *it2 << " ";
    }
    cout << endl;
  }
}

double getArea(const vector<Window>& win, int start) {
    short max_X = max(win[start].coords[0], win[start].coords[2]);
    short min_X = min(win[start].coords[0], win[start].coords[2]);
    short max_Y = max(win[start].coords[1], win[start].coords[3]);
    short min_Y = min(win[start].coords[1], win[start].coords[3]);

    vector<vector<short> > cache;
    double res = 0;
    double total = (max_X - min_X) * (max_Y - min_Y);

    for (size_t t = start + 1; t < win.size(); ++t) {
        short max_x = max(win[t].coords[0], win[t].coords[2]);
        short min_x = min(win[t].coords[0], win[t].coords[2]);
        short max_y = max(win[t].coords[1], win[t].coords[3]);
        short min_y = min(win[t].coords[1], win[t].coords[3]);

        if (max_x <= min_X || min_x >= max_X || max_y <= min_Y || min_y >= max_Y) {
            continue;
        }

        max_x = min(max_x, max_X);
        min_x = max(min_x, min_X);
        max_y = min(max_y, max_Y);
        min_y = max(min_y, min_Y);

        if (cache.empty()) {
            cache.push_back({min_x, min_y, max_x, max_y});
            res += (max_y - min_y) * (max_x - min_x);
            //            cout << "init res = " << res << endl;
        } else {
            cache.push_back({});
            for (int i = cache.size() - 1; i >= 0; --i) {
                if (i == 0) {
                    cache[0].push_back(min_x);
                    cache[0].push_back(min_y);
                    cache[0].push_back(max_x);
                    cache[0].push_back(max_y);
                    res += (max_y - min_y) * (max_x - min_x);
                    //                    cout << "i = 0, res = " << res << endl;
                    
                } else {
                    for (size_t j = 0; j < cache[i - 1].size(); j += 4) {
                        short min_xx = cache[i - 1][j];
                        short min_yy = cache[i - 1][j + 1];
                        short max_xx = cache[i - 1][j + 2];
                        short max_yy = cache[i - 1][j + 3];

                        if (max_xx <= min_x || min_xx >= max_x || max_yy <= min_y || min_yy >= max_y) {
                            continue;
                        }

                        vector<short> merged = merge({min_x, min_y, max_x, max_y}, {min_xx, min_yy, max_xx, max_yy});
                        min_xx = merged[0];
                        min_yy = merged[1];
                        max_xx = merged[2];
                        max_yy = merged[3];
                        cache[i].insert(cache[i].end(), merged.begin(), merged.end());
                        int op = 1;
                        if (i % 2) op = -1;
                        //                        cout << "xyXY" << min_xx << " " << min_yy << " " <<  max_xx << " " <<  max_yy << endl;
                        res += op * ((max_yy - min_yy) * (max_xx - min_xx));
                        //                        cout << "i = " << i << ",res = " << res << endl;
                        
                    }
                }
                //                display_cache(i, cache);
            }
        }
        //        display_cache(100 + t, cache);
    }
    //    cout << res << " " << total << endl;
    return 100 * (total - res) / total;
}

int main() {
    ifstream fin("window.in");
    ofstream fout("window.out");

    vector<Window> windows;

    while (!fin.eof()) {
        string line;
        getline(fin, line);
        if (line.empty()) {
            break;
        }
        char cmd = line[0];
        string params = line.substr(2, line.length() - 3); // )\r\n
        if (cmd == 'w') {
            size_t pos = params.find(',');
            string name = params.substr(0, pos);
            string coordStr = params.substr(pos + 1);
            vector<short> coords;
            std::istringstream iss(coordStr);
            std::string token;
            while (std::getline(iss, token, ',')) {
              coords.push_back(short(stoi(token)));
            }
            windows.push_back(makeWindow(name, coords));
        } else {
            size_t idx = 0;
            for (size_t i = 0; i < windows.size(); ++i) {
              //              cout << "windows[i].name=" << windows[i].name <<endl;
              //              cout << "params=" << params <<endl;
                if (windows[i].name == params) {
                    idx = i;
                    break;
                }
            }
            //            cout << "idx=" << idx << endl;
            if (cmd == 't') {
                Window temp = windows[idx];
                windows.erase(windows.begin() + idx);
                windows.push_back(temp);
            } else if (cmd == 'b') {
                Window temp = windows[idx];
                windows.erase(windows.begin() + idx);
                windows.insert(windows.begin(), temp);
            } else if (cmd == 'd') {
                windows.erase(windows.begin() + idx);
            } else if (cmd == 's') {
              fout << fixed << setprecision(3) << getArea(windows, idx) << endl;
            }
        }
    }

    fin.close();
    fout.close();

    return 0;
}

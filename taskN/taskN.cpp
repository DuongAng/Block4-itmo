#include <bits/stdc++.h>
using namespace std;

int open_all(const vector<vector<int>>& graph, vector<bool>& opened, vector<bool>& inner_opens, int i_opened) {
    inner_opens[i_opened] = true;
    for (int key_in : graph[i_opened]) {
        if (opened[key_in]) return 0;
        if (inner_opens[key_in]) return 1;
        return open_all(graph, opened, inner_opens, key_in);
    }
}

int main() {
    int n, key;
    cin >> n;

    vector<vector<int>> keys;
    vector<bool> opened;

    keys.resize(n);
    opened.resize(n, false);
    for (int i = 0; i < n; i++) {
        cin >> key;
        key-=1;
        keys[i].push_back(key);
    }

    int count = 0;
    vector<bool> inner_opens;
    for (int i = 0; i < n; i++) {
        inner_opens.clear();
        inner_opens.resize(n, false);
        count += open_all(keys, opened, inner_opens, i);
        for (int j = 0; j < inner_opens.size(); j++) {
            if (inner_opens[j]) opened[j] = true;
        }
    }

    cout << count;
    return 0;
}

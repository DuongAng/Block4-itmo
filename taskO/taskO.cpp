#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(const vector<vector<int>>& adj, int N) {
    vector<int> color(N, -1); // -1: chưa được tô màu, 0: màu 0, 1: màu 1

    for (int i = 0; i < N; i++) {
        if (color[i] == -1) { // Nếu đỉnh chưa được tô màu
            queue<int> q;
            q.push(i);
            color[i] = 0; // Bắt đầu tô màu với màu 0

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        // Nếu đỉnh kề chưa được tô màu, tô màu với màu đối lập
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        // Nếu đỉnh kề đã được tô màu và có cùng màu, đồ thị không phải lưỡng phân
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // Chuyển từ chỉ số 1-based sang 0-based
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartite(adj, N)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

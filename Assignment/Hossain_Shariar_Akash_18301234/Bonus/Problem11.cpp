#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100000;

vector<int> graph[MAX_N + 1];
vector<int> colors(MAX_N + 1);
vector<int> subtreeBlackCount(MAX_N + 1, 0);

void dfs(int node, int parent) {
    subtreeBlackCount[node] = colors[node];

    for (int child : graph[node]) {
        if (child != parent) {
            dfs(child, node);
            subtreeBlackCount[node] += subtreeBlackCount[child];
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> colors[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, -1);

    while (q--) {
        int x;
        cin >> x;
        cout << subtreeBlackCount[x] << " ";
    }

    cout << endl;

    return 0;
}

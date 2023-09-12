#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100000;

int n, m;
vector<int> graph[MAX_N + 1];
int team[MAX_N + 1];

bool dfs(int node, int t) {
    team[node] = t;

    for (int neighbor : graph[node]) {
        if (team[neighbor] == t) {
            return false;
        }

        if (team[neighbor] == 0 && !dfs(neighbor, 3 - t)) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (team[i] == 0 && !dfs(i, 1)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << team[i] << " ";
    }
    cout << endl;

    return 0;
}

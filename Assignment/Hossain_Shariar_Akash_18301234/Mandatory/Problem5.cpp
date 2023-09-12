#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 100000;

int n, m;
vector<int> graph[MAX_N + 1];
bool visited[MAX_N + 1];
int parent[MAX_N + 1];
int start_city = -1;
int end_city = -1;

bool dfs(int node, int par) {
    visited[node] = true;
    parent[node] = par;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node)) {
                return true;
            }
        } else if (neighbor != par) {
            start_city = neighbor;
            end_city = node;
            return true;
        }
    }

    return false;
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
        if (!visited[i] && dfs(i, -1)) {
            break;
        }
    }

    if (start_city == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> route;
        route.push_back(start_city);

        int current = end_city;
        while (current != start_city) {
            route.push_back(current);
            current = parent[current];
        }

        route.push_back(start_city);

        cout << route.size() << endl;
        for (int city : route) {
            cout << city << " ";
        }
        cout << endl;
    }

    return 0;
}

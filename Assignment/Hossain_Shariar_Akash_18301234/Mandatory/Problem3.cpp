#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX_N = 100000;
const int INF = 1e9;

int n, m;
vector<int> graph[MAX_N];
int parent[MAX_N];
bool visited[MAX_N];

void bfs(int start) {
    deque<int> q;
    q.push_back(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty()) {
        int current = q.front();
        q.pop_front();

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push_back(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);

    if (!visited[n]) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> route;
        int node = n;

        while (node != -1) {
            route.push_back(node);
            node = parent[node];
        }

        cout << route.size() << endl;
        for (int i = route.size() - 1; i >= 0; --i) {
            cout << route[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

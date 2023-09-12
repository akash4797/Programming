#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX_N = 100000;
const long long INF = 1e18;

int n, m;
vector<pair<int, int>> graph[MAX_N + 1];
vector<long long> dist(MAX_N + 1, INF);

void dijkstra(int start) {
    priority_queue<pair<long long, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        long long d = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) {
            continue;
        }

        for (auto edge : graph[node]) {
            int neighbor = edge.first;
            long long w = edge.second;

            if (dist[node] + w < dist[neighbor]) {
                dist[neighbor] = dist[node] + w;
                pq.push({-dist[neighbor], neighbor});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    dijkstra(1);

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}

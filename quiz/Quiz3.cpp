#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int MAXN = 1e5 + 5;
vector<pair<int, long long>> adj[MAXN]; // Adjacency list

long long dijkstra(int n) {
    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF)); // [node][usedCoupon]
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;

    dist[1][0] = 0;
    pq.push({0, {1, 0}}); // {distance, {node, usedCoupon}}

    while (!pq.empty()) {
        long long d = pq.top().first;
        int node = pq.top().second.first;
        int usedCoupon = pq.top().second.second;
        pq.pop();

        if (dist[node][usedCoupon] < d) continue;

        for (auto edge : adj[node]) {
            int neighbor = edge.first;
            long long cost = edge.second;

            // If the coupon hasn't been used yet
            if (usedCoupon == 0) {
                // Transition without using the coupon
                if (dist[neighbor][0] > d + cost) {
                    dist[neighbor][0] = d + cost;
                    pq.push({dist[neighbor][0], {neighbor, 0}});
                }
                // Transition using the coupon
                if (dist[neighbor][1] > d + cost / 2) {
                    dist[neighbor][1] = d + cost / 2;
                    pq.push({dist[neighbor][1], {neighbor, 1}});
                }
            } else {
                // Only one transition when the coupon has been used
                if (dist[neighbor][1] > d + cost) {
                    dist[neighbor][1] = d + cost;
                    pq.push({dist[neighbor][1], {neighbor, 1}});
                }
            }
        }
    }
    return min(dist[n][0], dist[n][1]);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    cout << dijkstra(n) << endl;
    return 0;
}

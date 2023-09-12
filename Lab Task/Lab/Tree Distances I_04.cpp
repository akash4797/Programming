#include <iostream>
#include <vector>

using namespace std;

vector<int> depth, diameter;

void dfs(int node, int parent, const vector<vector<int>>& tree) {
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node, tree);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    depth.resize(n + 1);
    diameter.resize(n + 1);

    dfs(1, 0, tree); // Start DFS from node 1

    int farthestNode = 1;
    for (int i = 1; i <= n; ++i) {
        if (depth[i] > depth[farthestNode]) {
            farthestNode = i;
        }
    }

    dfs(farthestNode, 0, tree); // Start DFS from the farthest node
    int maxDiameter = 0;
    for (int i = 1; i <= n; ++i) {
        maxDiameter = max(maxDiameter, depth[i]);
        diameter[i] = depth[i];
        depth[i] = 0; // Reset the depth array for the next DFS
    }

    dfs(farthestNode, 0, tree); // Start DFS from the farthest node again
    for (int i = 1; i <= n; ++i) {
        maxDiameter = max(maxDiameter, diameter[i]);
        cout << maxDiameter << " ";
    }

    return 0;
}

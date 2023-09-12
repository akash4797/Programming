#include <iostream>
#include <vector>

using namespace std;

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    int components = n;
    int largestComponent = 1;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        if (dsu.find(a) != dsu.find(b)) {
            int sizeA = dsu.size[dsu.find(a)];
            int sizeB = dsu.size[dsu.find(b)];

            dsu.unite(a, b);
            components--;
            largestComponent = max(largestComponent, max(sizeA, sizeB) + 1);
        }

        cout << components << " " << largestComponent << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(int x, int y) {
    int volume = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        volume += grid[cx][cy];

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (isValid(nx, ny) && grid[nx][ny] > 0 && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    return volume;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        grid.assign(n, vector<int>(m));
        visited.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        int maxVolume = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    maxVolume = max(maxVolume, bfs(i, j));
                }
            }
        }

        cout << maxVolume << endl;
    }

    return 0;
}

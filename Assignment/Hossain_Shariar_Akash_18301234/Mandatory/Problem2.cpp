#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm> // Include this header for the 'reverse' function

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int n, m;
char labyrinth[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int dist[MAX_N][MAX_M];
int parent[MAX_N][MAX_M];
pair<int, int> start, end_;

// Define possible movements (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != '#' && !visited[x][y];
}

string construct_path() {
    int x = end_.first, y = end_.second;
    string path = "";

    while (x != start.first || y != start.second) {
        int p = parent[x][y];
        path += dir[p];
        x -= dx[p];
        y -= dy[p];
    }

    reverse(path.begin(), path.end());
    return path;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int new_x = current.first + dx[i];
            int new_y = current.second + dy[i];

            if (is_valid(new_x, new_y)) {
                q.push({new_x, new_y});
                visited[new_x][new_y] = true;
                dist[new_x][new_y] = dist[current.first][current.second] + 1;
                parent[new_x][new_y] = i;

                if (make_pair(new_x, new_y) == end_) {
                    return;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'A') {
                start = {i, j};
            } else if (labyrinth[i][j] == 'B') {
                end_ = {i, j};
            }
        }
    }

    bfs();

    if (!visited[end_.first][end_.second]) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << dist[end_.first][end_.second] << endl;
        cout << construct_path() << endl;
    }

    return 0;
}

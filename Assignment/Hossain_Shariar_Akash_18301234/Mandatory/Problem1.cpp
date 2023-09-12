#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int n, m;
char grid[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

// Define possible movements (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y];
}

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (is_valid(new_x, new_y)) {
            dfs(new_x, new_y);
        }
    }
}

int count_rooms() {
    int room_count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                room_count++;
            }
        }
    }

    return room_count;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = count_rooms();
    cout << result << endl;

    return 0;
}

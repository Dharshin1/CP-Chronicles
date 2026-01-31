/*
Problem: Cycle in Maze

Short Problem Statement:
A robot is placed in a grid with obstacles. Starting from a given cell,
find a lexicographically smallest cycle of exactly k moves that starts
and ends at the initial cell. The robot can move only to empty cells and
may revisit cells.

Detailed Approach:
- If k is odd, it is impossible to form a cycle.
- Use BFS from the starting cell to compute the minimum distance from
  every cell back to the start.
- Build the answer greedily for k steps.
- At each step, try moves in lexicographical order: D, L, R, U.
- Choose a move only if the robot can return to the start in the
  remaining steps (distance ≤ remaining steps and parity matches).

Time Complexity:
- BFS: O(n * m)
- Path construction: O(k)

Space Complexity:
- O(n * m) for distance array

Example:
Input:
2 3 2
.**
X..

Output:
RL

Submission Link:
https://github.com/your-username/your-repo/pull/XXX
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
long long k;
vector<string> grid;
vector<vector<int>> dist;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'D', 'L', 'R', 'U'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                sx = i;
                sy = j;
            }
        }
    }

    if (k % 2 == 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    dist.assign(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == '*') continue;
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if (dist[sx][sy] != 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    string ans;
    int x = sx, y = sy;

    for (long long step = 0; step < k; step++) {
        bool moved = false;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == '*') continue;
            if (dist[nx][ny] == -1) continue;

            long long rem = k - step - 1;
            if (dist[nx][ny] <= rem && (rem - dist[nx][ny]) % 2 == 0) {
                ans.push_back(dir[d]);
                x = nx;
                y = ny;
                moved = true;
                break;
            }
        }
        if (!moved) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << ans << "\n";
    return 0;
}

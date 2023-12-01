#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int quickestWayUp(const vector<int>& ladders, const vector<int>& snakes) {
    const int boardSize = 100;
    const int numRolls = 6;

    // Construct the board with -1 as the initial value for all cells
    vector<int> board(boardSize + 1, -1);

    // Add ladders to the board
    for (int i = 0; i < ladders.size(); i += 2) {
        int start = ladders[i];
        int end = ladders[i + 1];
        board[start] = end;
    }

    // Add snakes to the board
    for (int i = 0; i < snakes.size(); i += 2) {
        int start = snakes[i];
        int end = snakes[i + 1];
        board[start] = end;
    }

    // Perform breadth-first search (BFS) to find the shortest path
    queue<int> q;
    q.push(1);

    unordered_map<int, int> dist;
    dist[1] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == boardSize) {
            return dist[current];
        }

        for (int i = 1; i <= numRolls; i++) {
            int next = current + i;

            // If the next position exceeds the board size, ignore it
            if (next > boardSize) {
                continue;
            }

            // If the next position leads to a ladder or snake, update the next position
            if (board[next] != -1) {
                next = board[next];
            }

            if (dist.find(next) == dist.end()) {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }

    return -1;  // No path to the destination
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int numLadders, numSnakes;
        cin >> numLadders;

        vector<int> ladders(2 * numLadders);
        for (int i = 0; i < 2 * numLadders; i++) {
            cin >> ladders[i];
        }

        cin >> numSnakes;

        vector<int> snakes(2 * numSnakes);
        for (int i = 0; i < 2 * numSnakes; i++) {
            cin >> snakes[i];
        }

        int result = quickestWayUp(ladders, snakes);
        cout << result << endl;
    }

    return 0;
}

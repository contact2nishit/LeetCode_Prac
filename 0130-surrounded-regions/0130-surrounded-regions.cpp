class Solution {
public:
    void bfs(vector<vector<char>>& board, int y, int x, bool& change, vector<pair<int, int>>& changed) {
        if (board[y][x] == 'X') return;
        if (x != 0 && y != 0 && x != board[0].size() - 1 && y != board.size() - 1) {
            //change = false;
            board[y][x] = 'X';
            changed.push_back({x, y});
            bfs(board, y - 1, x, change, changed);
            bfs(board, y + 1, x, change, changed);
            bfs(board, y, x - 1, change, changed);
            bfs(board, y, x + 1, change, changed);
        } else {
            change = true;
        }
        //std::cout << x << y << " " << change << std::endl;

        //if (!change) board[y][x] = 'O';
    }
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                bool change = false;
                vector<pair<int, int>> changed;
                bfs(board, i, j, change, changed);
                if (change) {
                    for (auto i: changed) {
                        board[i.second][i.first] = 'O';
                    }
                }
            }
        }
    }
};
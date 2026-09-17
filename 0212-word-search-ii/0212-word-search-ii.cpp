class TrieNode {
    public:
        TrieNode* children[26];
        string word;
        TrieNode() {
            word = "";
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
};
TrieNode* buildTrie(vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (auto i: words) {
        TrieNode* curNode = root;
        for (auto j: i) {
            if (curNode->children[j-'a'] == nullptr) {
                curNode->children[j-'a'] = new TrieNode();
            }
            curNode = curNode->children[j-'a'];
        }
        curNode->word = i;
    }
    return root;
}

void dfs(vector<vector<char>>& board, vector<string>& result, TrieNode* root, int row, int col) {
    if (root->word != "") {
        result.push_back(root->word);
        root->word = "";
    }
    char c = board[row][col];
    board[row][col] = '#';
    if (row > 0 && board[row-1][col] != '#' && root->children[board[row-1][col] - 'a'] != nullptr) {
        dfs(board, result, root->children[board[row-1][col] - 'a'], row - 1, col);
    }
    if (row < board.size() - 1 && board[row+1][col] != '#' && root->children[board[row+1][col] - 'a'] != nullptr) {
        dfs(board, result, root->children[board[row+1][col] - 'a'], row + 1, col);
    }
    if (col > 0 && board[row][col-1] != '#' && root->children[board[row][col-1] - 'a'] != nullptr) {
        dfs(board, result, root->children[board[row][col-1] - 'a'], row, col - 1);
    }
    if (col < board[0].size() - 1 && board[row][col+1] != '#' && root->children[board[row][col+1] - 'a'] != nullptr) {
        dfs(board, result, root->children[board[row][col+1] - 'a'], row, col + 1);
    }
    board[row][col] = c;
}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       vector<string> result;
       TrieNode* root = buildTrie(words);
       for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (root->children[board[i][j] - 'a'] == nullptr) continue;
            dfs(board, result, root->children[board[i][j] - 'a'], i, j);
        }
       }
       return result;
    }
};

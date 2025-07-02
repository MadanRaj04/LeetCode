class Solution {
public:
    bool fnhelper(vector<vector<char>>& board, string& word, int i, int j, int k) {
        // Base condition
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) {
            return false;
        }
        // If full word is matched
        if (k == word.size() - 1) {
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '#';  // mark visited

        // Explore all 4 directions
        bool found = fnhelper(board, word, i + 1, j, k + 1) ||
                     fnhelper(board, word, i - 1, j, k + 1) ||
                     fnhelper(board, word, i, j + 1, k + 1) ||
                     fnhelper(board, word, i, j - 1, k + 1);

        board[i][j] = temp;  // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (fnhelper(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

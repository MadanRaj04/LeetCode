class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int up = matrix[i - 1][j];
                int leftDiag = (j > 0) ? matrix[i - 1][j - 1] : INT_MAX;
                int rightDiag = (j < n - 1) ? matrix[i - 1][j + 1] : INT_MAX;

                matrix[i][j] += std::min({up, leftDiag, rightDiag});
            }
        }

        // Minimum value in the last row
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};

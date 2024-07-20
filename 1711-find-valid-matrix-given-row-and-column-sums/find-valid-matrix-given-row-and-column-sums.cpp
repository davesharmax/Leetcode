class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n= rowSum.size();
        int m = colSum.size();
        int cur_row = 0, cur_col = 0;
        vector<vector<int>> res(n, vector<int>(m, 0));

        while (cur_row < n || cur_col < m) {
            if (cur_row >= n) {
                res[n - 1][cur_col] = colSum[cur_col];
                cur_col++;
                continue;
            } else if (cur_col >= m) {
                res[cur_row][m - 1] = rowSum[cur_row];
                cur_row++;
                continue;
            }

            int value_to_put = min(rowSum[cur_row], colSum[cur_col]);
            rowSum[cur_row] -= value_to_put;
            colSum[cur_col] -= value_to_put;
            res[cur_row][cur_col] = value_to_put;
            if (rowSum[cur_row] == 0) {
                cur_row++;
            }
            if (colSum[cur_col] == 0) {
                cur_col++;
            }
        }
        return res;
    }
};
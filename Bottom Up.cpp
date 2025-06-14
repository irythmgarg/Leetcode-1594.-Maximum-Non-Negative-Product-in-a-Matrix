class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j] stores a pair {min product to reach (i,j), max product to reach (i,j)}
        vector<vector<pair<ll, ll>>> dp(m, vector<pair<ll, ll>>(n));

        // Initialize first column
        ll prev = 1;
        for (int i = 0; i < m; i++) {
            // Multiply previous value to get the cumulative product along the column
            dp[i][0] = {grid[i][0] * prev, grid[i][0] * prev};
            prev = grid[i][0] * prev;
        }

        // Initialize first row
        prev = 1;
        for (int j = 0; j < n; j++) {
            // Multiply previous value to get the cumulative product along the row
            dp[0][j] = {grid[0][j] * prev, grid[0][j] * prev};
            prev = grid[0][j] * prev;
        }

        // Fill the rest of the dp table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                vector<ll> candidates;

                // Consider all 4 possibilities from top and left cells (min and max products)
                candidates.push_back(grid[i][j] * dp[i - 1][j].first);
                candidates.push_back(grid[i][j] * dp[i - 1][j].second);
                candidates.push_back(grid[i][j] * dp[i][j - 1].first);
                candidates.push_back(grid[i][j] * dp[i][j - 1].second);

                // Get min and max product at (i, j)
                dp[i][j].first = *min_element(candidates.begin(), candidates.end());
                dp[i][j].second = *max_element(candidates.begin(), candidates.end());
            }
        }

        // Final result: max product at bottom-right cell
        return dp[m - 1][n - 1].second >= 0 ? dp[m - 1][n - 1].second % mod : -1;
    }
};

class Solution {
public:
    const int mod = 1e9 + 7;  // Modulo value for the final result
    typedef long long ll;    // Typedef for easier usage of long long

    // Recursive function to find the minimum and maximum product from (i,j) to (m-1,n-1)
    pair<ll, ll> hlo(vector<vector<int>>& grid, int i, int j, int m, int n) {
        // If out of bounds, return neutral values (1, 1) — won't affect min/max logic
        if (i >= m || j >= n)
            return {1, 1};

        // If reached the destination cell, return its value as both min and max
        if (i == m - 1 && j == n - 1)
            return {grid[i][j], grid[i][j]};

        // Recursive calls: move down and right
        pair<ll, ll> down = hlo(grid, i + 1, j, m, n);
        pair<ll, ll> right = hlo(grid, i, j + 1, m, n);

        // Store all valid product possibilities
        vector<ll> candidates;

        // If moving down is within bounds, calculate possible products
        if (!(i + 1 >= m || j >= n)) {
            candidates.push_back(down.first * grid[i][j]);   // min product from down
            candidates.push_back(down.second * grid[i][j]);  // max product from down
        }

        // If moving right is within bounds, calculate possible products
        if (!(i >= m || j + 1 >= n)) {
            candidates.push_back(right.first * grid[i][j]);   // min product from right
            candidates.push_back(right.second * grid[i][j]);  // max product from right
        }

        // Determine the minimum and maximum product at cell (i, j)
        ll p = *min_element(candidates.begin(), candidates.end());
        ll q = *max_element(candidates.begin(), candidates.end());

        return {p, q};  // Return pair of {min, max} product from this cell to end
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Call the recursive function starting from top-left corner
        pair<ll, ll> result = hlo(grid, 0, 0, m, n);

        // If max product is negative, return -1 as per problem statement
        if (result.second < 0)
            return -1;

        // Return the max product modulo 1e9+7
        return result.second % mod;
    }
};

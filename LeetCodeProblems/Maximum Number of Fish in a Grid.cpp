// Problem Link
// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

// Source Code

class Solution {
public:

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int dfs(vector<vector<int>>& grid, int r, int c, int m, int n, int res){
        if(r >= m || r < 0 || c >= n || c < 0 || grid[r][c] == 0){
            return 0;
        }

        res += grid[r][c];
        grid[r][c] = 0;

        for(int i = 0; i < 4;i++){
            int x = r + dx[i];
            int y = c + dy[i];
            res = max(res, dfs(grid, x, y, m, n, res));
        }

        return res;
    }



    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] != 0){
                    res = max(res, dfs(grid, i, j, m, n, 0));
                    // cout << res << endl;
                }
            }
        }

        // for(int i = 0;i < m;i++){
        //     for(int j = 0; j < n;j++){
        //         cout << grid[i][j] << " ";
        //     }

        //     cout << endl;
        // }
        
        return res;
    }
};
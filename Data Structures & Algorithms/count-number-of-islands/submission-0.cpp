class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector(m,0));

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){

                    cnt++;
                    q.push({i,j});
                    vis[i][j] = 1;

                        while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        for(int i=0; i<4; i++){
                            int nrow = r + delRow[i];
                            int ncol = c + delCol[i];
                            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] != 1 && grid[nrow][ncol] == '1'){
                                q.push({nrow, ncol});
                                vis[nrow][ncol] = 1;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

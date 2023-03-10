class Solution {
public:
    int dfs(vector<vector<int>>&g,int i,int j,vector<vector<int>>&vis){
        if(i==0 || j==0 || i==g.size()-1 || j==g[0].size()-1)return 0;
        vis[i][j] = 1;
        int t1 = 1;
        if(i+1<g.size() && !vis[i+1][j] && g[i+1][j]==0){
            t1 &= dfs(g,i+1,j,vis);
        }
        if(i-1>=0 && !vis[i-1][j] && !g[i-1][j] ){
            t1 &= dfs(g,i-1,j,vis);
        }
        if(j+1<g[0].size() && !vis[i][j+1] && !g[i][j+1]){
            t1 &= dfs(g,i,j+1,vis);
        }
        if(j-1>=0 && !vis[i][j-1] && !g[i][j-1]){
            t1 &= dfs(g,i,j-1,vis);
        }
        return t1;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(!vis[i][j] && !grid[i][j]){
                    ans += dfs(grid,i,j,vis);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    int dfs(vector<vector<int>>& grid,int r,int c)
    {
        if(r<0 || c <0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==0)
        {
            return 0;
        }
        int count=1;
        grid[r][c]=0;
        for(int i=0;i<directions.size();i++)
        {
            count+=dfs(grid,r+directions[i][0],c+directions[i][1]);
        }
        return count;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxcount=0;
        int count;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    count=dfs(grid,i,j);
                    if(count>maxcount)
                    {
                        maxcount=count;
                    }
                }

            }

        }
        return maxcount;
    }
};
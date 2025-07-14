class Solution {
public:
    const vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int ones=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    ones++;
                }
            }
        }
        if(ones==0) return 0;
        int count=0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto [r,c] = q.front();q.pop();
                
                for(auto it:directions)
                {
                    int nx = r+it[0];
                    int ny = c+it[1];
                    if(nx>=0 && ny >=0 && nx<grid.size() && ny <grid[0].size() && grid[nx][ny]==1)
                    {
                        grid[nx][ny]=2;
                        ones--;
                        q.push({nx,ny});
                    }
                    
                }
            }
            count++;
        }
//        cout<<ones<<endl;
        return (ones==0)?(count-1):-1;
    }
};
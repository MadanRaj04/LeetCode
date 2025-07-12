class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        int ones=0;
        queue<pair<int,int>> qp;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    qp.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    ones++;
                }
            }
        }
        if(qp.empty() && ones==0)
        {

            return 0;
        }


        int count=0;
        while(!qp.empty())
        {
            int size = qp.size();
            for(int i=0;i<size;i++)
            {
                auto [r,c] = qp.front();qp.pop();

                for(auto& it:directions)
                {
                    int nx = r+it[0];
                    int ny = c+it[1];
                    if(nx>=0 && ny >= 0 && nx<grid.size() && ny<grid[0].size() &&grid[nx][ny]==1)
                    {
                        grid[nx][ny]=2;
                        qp.push({nx,ny});
                        ones--;
                    }
                }
            }
            count+=1;
        }
        if(ones!=0) return -1;

        return count == 0 ? 0 : count - 1;
    }
};
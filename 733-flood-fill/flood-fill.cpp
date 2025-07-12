class Solution {
public:
    const vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& image,int sr,int sc,int color)
    {
        int tvar=image[sr][sc];
        image[sr][sc]=color;
        for(auto& it : directions)
        {
            int nx = it[0]+sr;
            int ny = it[1]+sc;
            if(nx>=0 && ny>=0 && nx < image.size() && ny< image[0].size() && image[nx][ny]==tvar)
            {
                dfs(image,nx,ny,color);
            }
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,color);
        return image;
    }
};
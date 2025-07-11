class Solution {
public:
    void dfs(vector<vector<int>>& adjmat,int cur,vector<int>& visited){
        visited[cur]=1;
        for(int i=0;i<adjmat[cur].size();i++)
        {
            if(adjmat[cur][i]==1 && visited[i]==0)
            {
                dfs(adjmat,i,visited);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        int count=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(visited[i]==0)
            {
                dfs(isConnected,i,visited);
                count+=1;
            }
        }
        return count;
    }
};
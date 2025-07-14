class Solution {
public:
    void dfs(vector<int>& visited,int cur,vector<vector<int>>& isConnected)
    {
        if(visited[cur]==1) return;
        visited[cur]=1;
        for(int i=0;i<isConnected[cur].size();i++)
        {
            if(isConnected[cur][i]==1 && visited[i]!=1)
            {
                dfs(visited,i,isConnected);
            }
    
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {



        vector<int> visited(isConnected[0].size(),0);
        int count=0;
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==0)
            {
                cout<<visited[i]<<endl;
                dfs(visited,i,isConnected);
                count+=1;
            }
        }
        return count;
    }
    
};
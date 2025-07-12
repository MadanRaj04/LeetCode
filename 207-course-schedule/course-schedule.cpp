class Solution {
public:
    unordered_map<int,vector<int>> buildadj(vector<vector<int>>& prerequisites){
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<prerequisites.size();i++)
        {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return mp;
    }

    bool dfs(vector<int>& visited,int cur,unordered_map<int,vector<int>>& mp){
        if(visited[cur]==1) return true;
        if(visited[cur]==2) return false;
        visited[cur]=1;

        for(auto it: mp[cur])
        {
            if(visited[it]==1) return true;
            else if(visited[it]==0){
            if(dfs(visited,it,mp)) return true;
            }
        }
        visited[cur]=2;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp = buildadj(prerequisites);
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0)
            {
                if(dfs(visited,i,mp)) return false;
            }
        }
        return true;
    }
};
        /* Khan's BFS
        vector<int> indegree(numCourses,0);
        for(int i=0;i<mp.size();i++)
        {
            for(auto it:mp[i])
            {
                indegree[it]++;
            }
        }

        
        queue<int> zero;
        int res=0;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                zero.push(i);
            }
        }
        while(!zero.empty())
        {
            int cur = zero.front();
            zero.pop();
            res++;
            for(auto it:mp[cur])
            {
                indegree[it]--;

                if(indegree[it]==0) zero.push(it);
            }
        }
        if(res != numCourses)
        {
            return false;
        }
        return true;
    */

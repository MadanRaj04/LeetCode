class Solution {
public:

    unordered_map<int,vector<int>> buildadj(vector<vector<int>>& prerequisites)
    {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<prerequisites.size();i++)
        {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return mp;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp = buildadj(prerequisites);
        vector<int> indegree(numCourses,0);
        for(int i=0;i<mp.size();i++)
        {
            for(auto& it:mp[i])
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
            for(auto& it:mp[cur])
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

    }
};
class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adjlst(vector<vector<int>>& times)
    {
        unordered_map<int,vector<pair<int,int>>> adj;
        for (int i=0;i<times.size();i++)
        {
            int a = times[i][0];
            int b = times[i][1];
            int c = times[i][2];
            
            adj[a].push_back({b,c});
        }
        return adj;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        adj = adjlst(times);
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({dist[k],k});
        while(!pq.empty())
        {
            auto [w,s] = pq.top();
            pq.pop();
            if(w>dist[s]) continue;
            for(auto& [d,weights] : adj[s])
            {
                if(weights+dist[s] < dist[d])
                {
                    dist[d] = weights+dist[s];
                    pq.push({dist[d],d});
                }
            }   
        }
        int maxx = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            maxx = max(maxx, dist[i]);
        }
        return maxx;
    }
};
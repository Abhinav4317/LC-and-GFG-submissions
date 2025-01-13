class Solution {
public:
    /**
        Intuition: we can ignore threshold because we only need one edge to connect a node    (directly or indirectly) to node zero.

    Approach
    We build a reversed adjacency list ral. We then run dfs from node zero, and count nodes we can reach while limiting weight to m.

    Then, we binary-search for the smallest weight that allows us to reach all nodes.
    */
    void dfs(int node,int& cnt,vector<pair<int,int>> adj[],int vis[],int mid){
        vis[node]=1;
        cnt--;
        for(auto nbr:adj[node]){
            if(!vis[nbr.first]&&nbr.second<=mid){
                dfs(nbr.first,cnt,adj,vis,mid);
            }
        }
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int s=0,e=INT_MIN;
        vector<pair<int,int>> adj[100000];
        for(auto it:edges){
            e=max(e,it[2]);
            adj[it[1]].push_back({it[0],it[2]});
        }
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int vis[100000]={0};
            int cnt=n;
            dfs(0,cnt,adj,vis,mid);
            if(cnt==0){
                ans=mid;e=mid-1;
            }else s=mid+1;
        }
        return ans;
    }
};
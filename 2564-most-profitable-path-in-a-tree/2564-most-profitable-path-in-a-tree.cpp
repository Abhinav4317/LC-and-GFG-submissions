class Solution {
public:
    bool findBobPath(int node,int parent,vector<int>& path,vector<vector<int>>& adj){
        if(node==0) return true;
        path.push_back(node);
        for(int nbr:adj[node]){
            if(nbr!=parent){
                if(findBobPath(nbr,node,path,adj)) return true;
            }
        }
        path.pop_back();
        return false;
    }
    int solve(int node,int parent,int cur,int tm,vector<int>& bpath,vector<int>& amount,vector<vector<int>>& adj){
        if(bpath[node]==-1||bpath[node]>tm){
            cur+=amount[node];
        }else if(bpath[node]==tm){
            cur+=amount[node]/2;
        }
        if(adj[node].size()==1&&node!=0) return cur;

        int mx=INT_MIN;
        for(int nbr:adj[node]){
            if(nbr!=parent) mx=max(mx,solve(nbr,node,cur,tm+1,bpath,amount,adj));
        }
        return mx;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> bpath(n,-1);
        vector<int> path;
        findBobPath(bob,-1,path,adj);
        for(int i=0;i<path.size();i++){
            bpath[path[i]]=i;
        }
        return solve(0,-1,0,0,bpath,amount,adj);
    }
};
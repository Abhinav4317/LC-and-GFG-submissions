class Solution {
public:
    void solve(int node,vector<int> adj[],vector<vector<int>>& charNodeMap,vector<int>& parent,string& s,int n){
        char ch=s[node];
        if(charNodeMap[ch-'a'].size()!=0){
            int anc=charNodeMap[ch-'a'].back();
            parent[node]=anc;
        }
        charNodeMap[ch-'a'].push_back(node);
        for(int child:adj[node]){
            solve(child,adj,charNodeMap,parent,s,n);
        }
        charNodeMap[ch-'a'].pop_back();
    }
    void solve2(int node,vector<int> adj2[],vector<int>& ans){
        ans[node]=1;
        for(int child:adj2[node]){
            solve2(child,adj2,ans);
            ans[node]+=ans[child];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<int> adj[n];
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        vector<vector<int>> charNodeMap(26);
        solve(0,adj,charNodeMap,parent,s,n);
        vector<int> adj2[n];
        for(int i=1;i<n;i++){
            adj2[parent[i]].push_back(i);
        }
        vector<int> ans(n);
        solve2(0,adj2,ans);
        return ans;
    }
};
class Solution {
public:
    void dfs(int node,int p,vector<int> adj[],vector<vector<int>>& pos,vector<int>& parent,string& s,int n){
        int idx=s[node]-'a';
        if(pos[idx].size()>0){
            parent[node]=pos[idx].back();
        }
        pos[idx].push_back(node);
        for(auto it:adj[node]){
            if(it==p) continue;
            dfs(it,node,adj,pos,parent,s,n);
        }
        pos[idx].pop_back();
    }
    void dfs2(int node,int p,vector<int> adj2[],vector<int>& ans){
        ans[node]=0;
        for(auto it:adj2[node]){
            if(it==p) continue;
            dfs2(it,node,adj2,ans);
            ans[node]+=ans[it]+1;
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<int> adj[n];
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        vector<vector<int>> pos(26);
        dfs(0,-1,adj,pos,parent,s,n);
        //for(int x:parent) cout<<x<<endl;
        vector<int> ans(n);
        vector<int> adj2[n];
        for(int i=1;i<n;i++) adj2[parent[i]].push_back(i);
        dfs2(0,-1,adj2,ans);
        for(int i=0;i<n;i++) ans[i]++;
        return ans;
    }
};
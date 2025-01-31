class Solution {
public:
    class DisjointSet {
    public:
        vector<int> rank, parent, size;
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }
        int findUPar(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionByRank(int u, int v) {
            int up_u = findUPar(u);
            int up_v = findUPar(v);
            if (rank[up_u] < rank[up_v]) {
                parent[up_u] = up_v;
            }
            else if (rank[up_u] > rank[up_v]) {
                parent[up_v] = up_u;
            }
            else {
                parent[up_v] = up_u;
                rank[up_u]++;
            }
        }
        void unionBySize(int u, int v) {
            int up_u = findUPar(u);
            int up_v = findUPar(v);
            if (size[up_u] < size[up_v]) {
                parent[up_u] = up_v;
                size[up_v] += size[up_u];
            }
            else {
                parent[up_v] = up_u;
                size[up_u] += size[up_v];
            }
        }
    
    };
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k],nc=j+dc[k];
                        if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]==1){
                            int u=i*n+j,v=nr*n+nc;
                            if(ds.findUPar(u)!=ds.findUPar(v)) ds.unionBySize(u,v);
                        }
                    }
                }
            }
        }
        for(int i=0;i<n*n;i++) ans=max(ans,ds.size[i]);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> s;
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k],nc=j+dc[k];
                        if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]==1){
                            int v=nr*n+nc;
                            int up_v = ds.findUPar(v);
                            s.emplace(up_v);
                        }
                    }
                    int sum=0;
                    for(auto it:s) sum+=ds.size[it];
                    ans=max(ans,sum+1);
                }
            }
        }
        return ans;
    }
};
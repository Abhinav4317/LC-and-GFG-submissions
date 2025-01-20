class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<pair<int,int>> pos(m*n+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pos[mat[i][j]]={i,j};
            }
        }
        vector<int> row(m,n);
        vector<int> col(n,m);
        for(int i=0;i<m*n;i++){
            auto p=pos[arr[i]];
            int r=p.first,c=p.second;
            row[r]--;col[c]--;
            if(row[r]==0||col[c]==0) return i;
        }
        return m*n-1;//never executed
    }
};
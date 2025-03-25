class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if(a[0] < b[0]) return true;
        else if(a[0] == b[0]) return (a[1] < b[1]);
        else return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x,y;
        int sz=rectangles.size();
        for(auto it:rectangles){
            int x1=it[0],x2=it[2];
            x.push_back({x1,x2});
            int y1=it[1],y2=it[3];
            y.push_back({y1,y2});
        }
        sort(x.begin(),x.end(),cmp);
        sort(y.begin(),y.end(),cmp);
        int cnt=2;
        int lx=x[0][1];
        for(int i=1;i<sz;i++){
            int cx=x[i][0];
            if(cx>=lx) cnt--;
            lx=max(lx,x[i][1]);
            if(cnt==0) return true;
        }
        cnt=2;
        int ly=y[0][1];
        for(int i=1;i<sz;i++){
            int cy=y[i][0];
            if(cy>=ly) cnt--;
            ly=max(ly,y[i][1]);
            if(cnt==0) return true;
        }
        return false;
    }
};
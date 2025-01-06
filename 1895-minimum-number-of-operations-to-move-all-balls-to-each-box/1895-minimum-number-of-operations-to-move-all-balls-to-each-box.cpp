class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> preCnt(n,0),preOp(n,0);
        preCnt[0]=(boxes[0]=='1')?1:0;
        for(int i=1;i<n;i++){
            preCnt[i]=preCnt[i-1]+((boxes[i]=='1')?1:0);
        }
        for(int i=1;i<n;i++){
            preOp[i]=preOp[i-1]+preCnt[i-1];
        }
        vector<int> sufCnt(n,0),sufOp(n,0);
        sufCnt[n-1]=(boxes[n-1]=='1')?1:0;
        for(int i=n-2;i>=0;i--){
            sufCnt[i]=sufCnt[i+1]+((boxes[i]=='1')?1:0);
        }
        for(int i=n-2;i>=0;i--){
            sufOp[i]=sufOp[i+1]+sufCnt[i+1];
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=preOp[i]+sufOp[i];
        }
        return ans;
    }
};
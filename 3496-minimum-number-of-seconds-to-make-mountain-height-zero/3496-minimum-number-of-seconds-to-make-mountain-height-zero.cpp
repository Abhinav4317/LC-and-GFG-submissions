class Solution {
public:
    bool isPos(long long pos,int mh,vector<int>& wt){
        for(int w:wt){
            long long l=0,r=1e6;
            while(l<=r){
                long long mid=l+(r-l)/2;
                if(w*mid*(mid+1)/2<=pos) l=mid+1;
                else r=mid-1;
            }
            mh-=r;
            if(mh<=0) return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        long long s=0,e=1e18;
        long long ans=-1;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(isPos(mid,mh,wt)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
        
    }
};
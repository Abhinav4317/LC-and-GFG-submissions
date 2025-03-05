class Solution {
public:
    long long coloredCells(int n) {
        if(n==1) return 1;
        long long ans=n;
        ans=ans*n;
        ans+=(n-1)*1LL*(n-1);
        return ans;
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       long long n= size(nums);
       bool p=0;
       for( long long i=0;i<n;i++){
        if(nums[i]==1) {p=1; break;}
       }
       if(!p) return 1;
       else{
        for( long long i=0;i<n;i++){
            if(nums[i]<=0) nums[i]=1;
        }
        for( long long i=0;i<n;i++){
            long long num=abs(nums[i]);
            long long idx=num-1;
            if(num>n) continue;
            else nums[idx]=(nums[idx]>0)?(-nums[idx]):nums[idx];
        }
        for(long long i=0;i<n;i++){
            if(nums[i]>0) return (int)(i+1);
        }
        for(long long i=0;i<n;i++){
            if(nums[i]>0) return (int)(i+1);
        }
        return (int)(n+1);
       }
       
    }
};
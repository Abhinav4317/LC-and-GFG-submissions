class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int s1=0,s2=0,ans1=0,ans2=0;
        for(int i=0;i<n;i++){
            s1+=nums[i];
            ans1=max(ans1,s1);
            if(s1<0) s1=0;
        }
        for(int i=0;i<n;i++){
            s2+=nums[i];
            ans2=min(ans2,s2);
            if(s2>0) s2=0;
        }
        //cout<<s1<<" "<<s2<<endl;
        return max(ans1,abs(ans2));
    }
};
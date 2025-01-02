class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int prev,n=nums.size();
        set<int> ans;
        ans.emplace(nums[0]-k);
        prev=nums[0]-k;
        for(int i=1;i<n;i++){
            int pos=prev+1;
            if(pos<nums[i]-k){
                ans.emplace(nums[i]-k);
                prev=nums[i]-k;
            }else if(pos>nums[i]+k){
                ans.emplace(nums[i]+k);
            }else{
                ans.emplace(pos);
                prev=pos;
            }
        }
        return ans.size();
    }
};
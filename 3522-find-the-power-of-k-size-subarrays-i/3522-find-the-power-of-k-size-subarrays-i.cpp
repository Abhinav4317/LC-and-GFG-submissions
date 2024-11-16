class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<=(n-k);i++){
            bool ch=1;
            for(int j=i+1;j<(i+k);j++){
                if(nums[j]==nums[j-1]+1) continue;
                else {ch=0; break;}
            }
            if(ch) ans.push_back(nums[i+k-1]);
            else ans.push_back(-1);
        }
        return ans;
    }
};
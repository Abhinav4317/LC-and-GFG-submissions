class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int ans=0;
        if(n2&1){
            for(int x:nums1) ans^=x;
        }
        if(n1&1){
            for(int x:nums2) ans^=x;
        }
        return ans;
    }
};
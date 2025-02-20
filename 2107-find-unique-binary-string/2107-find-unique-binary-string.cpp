class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int c0=0,c1=0;
            for(int j=0;j<n;j++){
                if(nums[j][i]=='1') c1++;
                else c0++;
            }
            if(c1>=c0) ans+='0';
            else ans+='1';
        }
        int ind=0;
        for(int j=0;j<n;j++){
            if(ans==nums[j]){
                ans[ind]=(ans[ind]=='1')?'0':'1';
                ind++;
                if(ind==n) break;
            }
        }
        return ans;
    }
};
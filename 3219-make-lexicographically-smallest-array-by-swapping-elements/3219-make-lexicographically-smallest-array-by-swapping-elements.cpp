class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int s=0;
        vector<int> ans(n);
        vector<int> idx;
        for(int i=1;i<n;i++){
            if(v[i].first-v[i-1].first<=limit) idx.push_back(v[i].second);
            else{
                idx.push_back(v[s].second);
                sort(idx.begin(),idx.end());
                for(int j=s;j<=i-1;j++){
                    ans[idx[j-s]]=v[j].first;
                }
                idx.clear();
                s=i;
            }
        }
        if(idx.size()==0) ans[v[n-1].second]=v[n-1].first;
        else{
            idx.push_back(v[s].second);
            sort(idx.begin(),idx.end());
            for(int j=s;j<=n-1;j++){
                ans[idx[j-s]]=v[j].first;
            }
            idx.clear();
        }
        return ans;

    }
};
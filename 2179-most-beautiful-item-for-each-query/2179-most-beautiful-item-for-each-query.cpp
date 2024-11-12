class Solution {
public:
    int upperBound(vector<vector<int>>& arr, int x, int n) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid][0] > x) {
                ans = mid;
                //look for smaller index on the left
                high = mid - 1;
            }
            else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n=items.size();
        unordered_map<int,int> mp;
        int mx=-1;
        for(int i=0;i<n;i++){
            mx=max(mx,items[i][1]);
            mp[items[i][0]]=mx;
        }
        vector<int> ans;
        for(int x:queries){
            int lb=upperBound(items,x,n);
            lb--;
            if(lb>=0&&lb<n){
                ans.push_back(mp[items[lb][0]]);
            }else ans.push_back(0);
        }
        return ans;
    }
};
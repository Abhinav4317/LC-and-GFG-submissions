class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<long long,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]=i;

        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                long long pp=arr[i],p=arr[j];
                long long sum=pp+p;
                int len=2;
                while(mp.find(sum)!=mp.end()){
                    pp=p;p=sum;
                    sum=pp+p;
                    len++;
                }
                if(len>=3) ans=max(ans,len);
            }
        }
        return ans;
    }
};
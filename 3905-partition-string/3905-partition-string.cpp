class Solution {
public:
    int binpowmod(int a,int b,int m){
        a%=m;
        long long res=1;
        while(b>0){
            if(b&1){
                res=(res*a)%m;
            }
            a=(a*1LL*a)%m;
            b>>=1;
        }
        return (int)(res);
    }
    vector<string> partitionString(string s) {
        unordered_map<long long,int> mp;
        int n=s.size();
        string t="";
        int p=31,m=1e9+7;
        long long h=0;
        int j=0;
        vector<string> ans;
        for(int i=0;i<n;i++){
            t+=s[i];
            h+=(binpowmod(p,j,m)*1LL*(s[i]-'a'+1))%m;
           // cout<<h<<endl;
            j++;
            if(mp.find(h)==mp.end()){
                mp[h]=1;
                ans.push_back(t);
                t="";
                h=0;
                j=0;
            }
        }
        return ans;
    }
};
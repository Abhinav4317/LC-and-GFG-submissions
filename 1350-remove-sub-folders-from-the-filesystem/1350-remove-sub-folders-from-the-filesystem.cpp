class Solution {
public:
    static bool cmp(string& s1,string& s2){
        return (s1.size()<s2.size());
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end(),cmp);
        int n=folder.size();
        map<string,int> mp;
        for(int i=0;i<n;i++){
            string s=folder[i];
            string t="";
            bool ch=1;
            for(char ch:s){
                if(ch=='/'){
                    if(mp.find(t)!=mp.end()) {ch=0;break;}
                }
                t+=ch;
            }
            if(ch) mp[t]=1;
        }
        vector<string> ans;
        for(auto it:mp){
            ans.push_back(it.first);
        }
        return ans;
    }
};
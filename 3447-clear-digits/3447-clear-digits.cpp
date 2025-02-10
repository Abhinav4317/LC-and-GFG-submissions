class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(s[i]>='0'&&s[i]<='9') {
                vis[i]=1;
                int j=i-1;
                while(j>=0){
                    if(s[j]>='a'&&s[j]<='z'&&vis[j]==0) {vis[j]=1; break;}
                    j--;   
                }
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(vis[i]==0) ans+=s[i];
        }
        return ans;        
    }
};
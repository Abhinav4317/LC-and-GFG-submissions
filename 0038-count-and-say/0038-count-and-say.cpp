class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1);
        string ans="";
        int sz=s.size();
        for(int i=0;i<sz-1;i++){
            if(s[i]==s[i+1]){
                int cnt=1;
                int j=i+1;
                while(j<sz&&s[j]==s[i]) {cnt++; j++;}
                i=j-1;
                ans+=to_string(cnt);
                ans+=s[i];
            }
            else{
                ans+="1";
                ans+=s[i];
            }
        }
        if(s=="1") return "11";
        if(s[sz-1]!=s[sz-2]){
            ans+="1";
            ans+=s[sz-1];
        } 
        return ans;
    }
};
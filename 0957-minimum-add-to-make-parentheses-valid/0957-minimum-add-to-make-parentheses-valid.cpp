class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0,cnt1=0,cnt2=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='(') {cnt1++;}
            else {
                if(cnt1>0) cnt1--;
                else cnt2++;
            }
        }
        ans=cnt1+cnt2;
        return ans;
    }
};
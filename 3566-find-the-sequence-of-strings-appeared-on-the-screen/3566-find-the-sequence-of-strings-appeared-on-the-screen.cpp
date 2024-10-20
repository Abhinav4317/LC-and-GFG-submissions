class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> v;
        string ans="";
        for(char ch:target){
            for(char c='a';c<=ch;c++){
                ans+=c;
                v.push_back(ans);
                ans.pop_back();
            }
            ans+=ch;
        }
        return v;
    }
};
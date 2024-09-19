class Solution {
public:
    static bool cmp(int a,int b){
        //basically ye dekhna hai ki agar do number hn toh kisko kaun pehle aayega kaun baad mein:-
        //do options:-
        //1.1st no.pehle aayega 2nd baad mein
        //2.1st num baad mein aayega 2nd pehle
        //dono try karlo aur ek choose karlo
        string sa=to_string(a);
        string sb=to_string(b);
        if((sa+sb)>(sb+sa)){
            return true;
        }
        return false;
    }
    string largestNumber(vector<int>& nums) {
        string ans="";
        sort(nums.begin(),nums.end(),cmp);
        for(int x:nums){
            //cout<<s<<endl;
            ans+=to_string(x);
        }
        int ind=0,n=ans.size();
        while(ind<n&&ans[ind]=='0'){
            ind++;
        }
        if(ind==n) ans="0";
        else ans=ans.substr(ind,n-ind);
        return ans;
    }
};
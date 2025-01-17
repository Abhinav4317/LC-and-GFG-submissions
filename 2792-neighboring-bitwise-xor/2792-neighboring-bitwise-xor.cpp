class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans=0;
        for(int x:derived){
            ans=ans^x;
        }
        if(ans==0) return true;
        return false;
    }
};
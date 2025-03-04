class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n==1||n==3) return true;
        if(n==2) return false;
        while(n>3){
            int rem=n%3;
            if(rem==2) return false;
            n=n/3;
        }
        return !(n==2);

    }
};
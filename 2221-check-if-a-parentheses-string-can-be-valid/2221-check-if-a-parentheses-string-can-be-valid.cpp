class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        int bMin=0, bMax=0;
        if(n&1) return false;
        for(int i=0; i<n; i++){
            char c=s[i];
            //treat locked[i]=='0' as * and locked[i]=='1' as not *
            //everything is similar top LC 678 but one thing changes.there were 3 cases only in that ques=>(,) or * but here a character can be simultaneously (or) and */not *
            //so 4 combos:->(,*   ;   (,not *    ;    ),*    ;    ),not *
            //just remember bMin measures count of (,and every ( or ) that can be converted to (
            //bMax does the opposite
            if(c==')'&&locked[i]=='0'){
                bMin--;
                bMax++;
            }else if(c==')'&&locked[i]=='1'){
                bMin--;
                bMax--;
            }else if(c=='('&&locked[i]=='0'){
                bMin--;
                bMax++;
            }else if(c=='('&&locked[i]=='1'){
                bMin++;
                bMax++;
            }
            if (bMax<0) return 0;//logic here is that if despite considering every * as ),total count is still -ve at any i,that means ( is still definitely more than ) ,so simply return false

            if(bMin<0) bMin=0;//logic here is that if considering every * as (,the total count is -ve,it means that we took too many * as (,so just reset the count
        }
        return bMin==0;
    }
};
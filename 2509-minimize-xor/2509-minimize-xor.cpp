class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits=__builtin_popcount(num2);
        int x=0;
        //cout<<setBits<<endl;
        for(int i=30;i>=0;i--){
            if(((num1&(1<<i))!=0)){
                //cout<<i<<endl;
                if(setBits==0) continue;
                x=x|(1<<i);setBits--;
            }
        }
        // cout<<x<<endl;
        // cout<<setBits<<endl;
        for(int i=0;i<=30 && setBits>0;i++){
            if((x&(1<<i))==0){
                x=x|(1<<i);setBits--;
            }
        }
        return x;
    }
};
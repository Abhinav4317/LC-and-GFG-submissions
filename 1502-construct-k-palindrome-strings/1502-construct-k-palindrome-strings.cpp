class Solution {
public:
    bool canConstruct(string s, int k) {
        int f[26]={0};
        for(char ch:s){
            f[ch-'a']++;
        }
        sort(f,f+26);
        int cnt1=0,ce=0;
        for(int x:f){
            if(x==0) continue;
            if(x==1){
                cnt1++;
            }else if(x&1){
                ce+=(x-1)/2;cnt1++;
            }else{
                ce+=x/2;
            }
        }
        //cout<<cnt1+ce<<endl;
        if(cnt1+ce<k) {
            int inc=k-(cnt1+ce);
            if(ce>=inc) return true;
            return false;
        }
        else if(cnt1+ce>k){
            int red=(cnt1+ce)-k;
            if(red<=ce) return true;
            return false;
        }
        return true;
    }
};
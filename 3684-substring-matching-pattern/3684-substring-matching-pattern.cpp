class Solution {
public:
    /**
        class Solution {
public:
    bool hasMatch(string s, string p) {
        int x = p.find("*");
        string b = p.substr(0, x);
        string e = p.substr(x + 1);
        int i = s.find(b);
        int j = s.rfind(e);
        return i != -1 && j != -1 && i + b.size() <= j;
    }
};
    */
    bool hasMatch(string s, string p) {
        int n1=s.size(),n2=p.size();
        if(n2-1>n1) return false;
        int ind=-1;
        for(int i=0;i<n2;i++){
            if(p[i]=='*') {ind=i; break;}
        }
        int ls=-2,le=-2,rs=-2,re=-2;
        if(p[0]=='*'){ls=-1;le=-1;}
        else{
            for(int i=0;i<n1;i++){
                bool ch=1;
                //cout<<s[0]<<endl;
                if(s[i]==p[0]){
                    //cout<<"true\n";
                    int j=0,k=i;
                    //cout<<j<<" "<<i<<endl;
                    while(j<ind&&k<n1){
                        if(s[k]!=p[j]){ch=0;break;}
                        j++;k++;
                    }
                    if(j!=ind) ch=0;
                    if(ch) {ls=i; le=k-1;}
                }else ch=0;
                if(ch) break;
            }
        }
        if(p[n2-1]=='*'){rs=n1;re=n1;}
        else{
            for(int i=n1-1;i>=0;i--){
                bool ch=1;
                if(s[i]==p[n2-1]){
                    int j=n2-1,k=i;
                    while(j>ind&&k>=0){
                        if(s[k]!=p[j]){ch=0;break;}
                        j--;k--;
                    }
                    if(j!=ind) ch=0;
                    if(ch) {rs=k+1; re=i;}
                }else ch=0;
                if(ch) break;
            }
        }
        //cout<<ls<<le<<rs<<re<<endl;
        if(le==-2||rs==-2) return false;
        if(le<rs) return true;
        return false;
    }
};
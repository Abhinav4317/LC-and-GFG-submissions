class Solution {
public:
    int maximumSwap(int num) {
        //simple greedy=>start from 0th index and find the larger digit in its right and swap
        //make sure if there are multiple occurences of the larger digit,then you swap with the farthest one,so that the value of the current digit gets placed as far as possible,making the result lexographically largest
        vector<int> v;
        int n=num;
        while(n>0){
            int d=n%10;
            v.push_back(d);
            n=n/10;
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            int mx=v[i],ind=i;
            for(int j=i+1;j<v.size();j++){
                if(v[j]>mx){mx=v[j]; ind=j;}
                else if(v[j]==mx){ind=j;}
            }
            if(mx>v[i]){
                swap(v[i],v[ind]);
                break;
            } 
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans=ans*10+v[i];
        }
        return ans;
    }
};
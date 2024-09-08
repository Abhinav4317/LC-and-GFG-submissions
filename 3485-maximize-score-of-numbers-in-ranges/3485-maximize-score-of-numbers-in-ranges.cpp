class Solution {
public:
    bool pos(int mid,vector<int>& start, int d){
        long long beg=start[0];//you might think ki begin start[0] se hi kyun kiya when the interval is [start[0],start[0]+d]?
        //reason is simple everytime i want to check that if i select an integer,say,
        //k for an interval then (k+mid) should either lie in the next interval or before it
        //(since the next chosen number should be atleast at a distance of mid or more,bit never less)
        //now what can i do from my end to ensure that (k+mid) does not exceed the next interval=>choose minimum possible k.
        //so,in the beginning k=start[0] 

        long long n=start.size();
        for(int i=1;i<n;i++){
            long long end=start[i]+d;
            long long mn=beg+mid;
            if(mn>end) return false;
            beg=max(mn,1LL*start[i]);//as per the above logic,here too,I want to take the   
            //first integer in the current interval that is atleast at a distance of mid or
            //more from the previous integer,but at the same time,I want to choose minimum possible value to ensure from my end that the current value+mid lies in the next interval or before it.
            //so,logically i can just take current integer=previous integer+mid but there is a chance that this value may lie before the beginning of next interval.In that case ,I can just take the beginning point of next interval(start[i]).
            
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        int n=start.size();
        long long s=0,e=start[n-1]+d-start[0];
        int ans=-1;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(pos(mid,start,d)){
                ans=static_cast<int>(mid);
                s=mid+1;
            }else e=mid-1;
        }
        if(ans==-1) ans=0;
        return ans;
    }
};
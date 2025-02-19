class Solution {
public:
    double solve(double pos,vector<vector<int>>& squares){
        int n=squares.size();
        double ab=0,bel=0;
        for(int i=0;i<n;i++){
            int x = squares[i][0], y = squares[i][1];
            int l = squares[i][2];
            double total = (double) l * l;

            if(pos<=y) ab+=total;
            else if(pos>=y+l) bel+=total;
            else{
                double ahi = (y + l) - pos;
                double bhi = pos - y;
                ab += l * ahi;
                bel += l * bhi;
            } 
        }
        return ab-bel;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low=0,high=2e9;
        double lim=1.0e-5;
        while(high-low>=lim){
            double mid=(low+high)/2.0;
            double diff=solve(mid,squares);
            if(diff>0) low=mid;
            else high=mid;
        }
        return high;
    }
};
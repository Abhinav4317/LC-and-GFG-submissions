class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<long long> pq1;
        priority_queue<long long,vector<long long>,greater<long long>> pq2;
        int n=weights.size();
        for(int i=0;i<(n-1);i++){
            long long sum=weights[i]+weights[i+1];
            pq1.push(sum);
            pq2.push(sum);
        }
        long long sum1=weights[0]+weights[n-1];
        int cnt=k-1;
        while(cnt>0){
            sum1+=pq1.top();pq1.pop();cnt--;
        }

        long long sum2=weights[0]+weights[n-1];
        cnt=k-1;
        while(cnt>0){
            sum2+=pq2.top();pq2.pop();cnt--;
        }

        long long ans=sum1-sum2;
        return ans;
        
    }
};
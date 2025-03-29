const int N=sqrt(100000);
vector<bool> isPrime(N+1, 1);
vector<int> prime;
/**
basic intuition:
for element at index i,find left[i] and right[i] which are first indices,on left and right of i, starting from i,that have elements with score greater than that of element at i itself.
Do this using a slight modification of previous greater and next greater algo utilising stack.
Now,traverse the array in descending order of elements=>for each element,find left[i],right[i]=>
then how many subarrays exist from left[i] to right[i] that contain i,which is given by subCnt=(i-left[i])*(right[i]-i)=>for each of these subarrays,we pick i as element with highest score=>so new score=old score*pow(nums[i],min(subCnt,k))=>REMEMBER JUST BCOZ WE HAVE subCnt NUMBER OF SUBARRAYS THAT HAVE ITH ELEMENT WITH HIGHEST SCOIRE DOES NOT MEAN WE INCLUDE ALL OF THEM=>WE NEED TO CHECK HOW MUCH k IS REMAINING AND TAKE MINIMUM OF subCnt AND k.

OTHERS ARE UTIL FUNCTIONS FOR SIEVE,PRIME FACTORIZATION,AND MOD EXPONENTIATION
*/
class Solution {
public:
    const int mod=1e9+7;
    //Use Eratosthenes' sieve method
    void Sieve(){
        if (prime.size()>0) return ;
        isPrime[0]=isPrime[1]=0;
        const int n_sqrt=int(sqrt(N));
        for(int i=2; i<=n_sqrt; i++){
            if (isPrime[i]){
                prime.push_back(i);
                for(int j=i*i ; j<=N; j+=i)
                    isPrime[j]=0;
            }
        }
        for(int i=n_sqrt+1; i<=N; i++)
            if (isPrime[i]) prime.push_back(i);
    }

    //computing prime score
    int prime_score(int x){
        if (x<=N && isPrime[x]) return 1;
        int xsqrt=sqrt(x);
        int cnt=0;
        for(int p: prime){
            if (p>xsqrt) break;
            if (x%p!=0) continue;
            while (x%p==0){
                x/=p;
            }
            cnt++;
        }
        cnt+=(x>1);
        return cnt;
    }

    long long modPow(long long x, int exp) {
        if (x == 0) return 0;
        if (exp == 0) return 1;
        long long a = (exp % 2 == 1) ? x : 1;
        return modPow(x * x % mod, exp / 2) * a % mod;
    }

    int maximumScore(vector<int>& nums, int k) {
        const int n = nums.size();
        Sieve();

        vector<int> score(n), left(n), right(n);
        for (int i = 0; i < n; i++) {
            score[i] = prime_score(nums[i]);
        }

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && score[i] > score[st.top()]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && score[i] >= score[st.top()]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<pair<int, int>> num_idx(n);
        for(int i=0; i<n; i++)
            num_idx[i]={nums[i], i};
        sort(num_idx.begin(), num_idx.end(), greater<pair<int, int>>());

        long long ans=1;
        for(int i=0; i<n && k>0; i++){
            auto [x, idx]=num_idx[i];
            int exp=min((long long)(idx-left[idx])*(right[idx]-idx), (long long)k);
            ans=(ans*modPow(x, exp)%mod);
            k-=exp;
        }
    //    cout<<"k="<<k<<endl;
        return ans; 
    }
};
class Solution {
public:
    void nextGreaterPermutation(vector<int> &A,bool& ch) {
        int n = A.size(); // size of the array.

        // Step 1: Find the break point:
        int ind = -1; // break point
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                // index i is the break point
                ind = i;
                break;
            }
        }
        //cout<<ind<<endl;
        // If break point does not exist:
        if (ind == -1) {
            // reverse the whole array:
            ch=1;
            return;
        }

        // Step 2: Find the next greater element
        //         and swap it with arr[ind]:

        for (int i = n - 1; i > ind; i--) {
            if (A[i] > A[ind]) {
                //cout<<"SWAP HUA"<<endl;
                swap(A[i], A[ind]);
                break;
            }
        }
        // for(int x:A) cout<<x<<" ";
        // cout<<endl;
        // Step 3: reverse the right half:
        reverse(A.begin() + ind + 1, A.end());
        // for(int x:A) cout<<x<<" ";
        // cout<<endl;
    }
    int nextGreaterElement(int n) {
        if(n>=0&&n<=9) return -1;
        int k=n;
        vector<int> num;
        while(k>0){
            int d=k%10;
            k=k/10;
            num.push_back(d);
        }
        reverse(num.begin(),num.end());
        // for(int x:num) cout<<x<<" ";
        // cout<<endl;
        bool ch=0;
        nextGreaterPermutation(num,ch);
        // for(int x:num) cout<<x<<" ";
        // cout<<endl;
        long long ans=0;
        for(int x:num){
            ans=ans*1LL*10+x;
            //cout<<ans<<endl;
        }
        long long lim=INT_MAX;
        if(ans>lim||ch==1) ans=-1;
        return (int)(ans);
    }
};
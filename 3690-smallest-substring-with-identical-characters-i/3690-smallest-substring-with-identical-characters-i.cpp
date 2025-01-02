class Solution {
public:
    /**
        Clasical binary search code where we need to minimise the answer
The important part of this problem is the isValid function that check if a particular mid length substring is answer or not
To check this we break this in to two cases:

Case 1: When mid is equal to 1
in this case we have only two possible substring possible - one with start char is 1 where other with start char is 0. (i.e 10101010... or 01010101.... )
so simply check in which of the above two we can possibly filp with in given numOps operations
To do this you can simply consider start char as '1' once and keep on fliping it and check the number of mismatch with the original string. The number of missmatch will be the operation needed to covert the string to 101010... Similarly we can start with start char equal to '0' and keep on counting the number of missmatch
Case 2: When mid is not equal to 1
In this case we count the continous chars in s

when there is mis match then for the total cont char we need to break it in to multiple smaller part where each part have less then equal to mid count of continuous char

To do this we just need to divede the count by (mid + 1) and that many number of flip is needed

For example :
Let say we have 1000001 and mid equal to 2 and ops is 2
the continuos count o zeros here is 5 and so we can split it in to two group by fliping the the last of first (mid +1) chars of '0' that is the 3rd zero we can flip it to 1 resulting in 1001001. We can get this by (count)/(mid + 1).

Complexity :
Time : O(N.logN)
Space : O(1)

    */
    bool check(string& s, int numOps, int mid, char startChar){
        for(int i = 0; i < s.size(); ++i){
            if(startChar == s[i]) numOps--;
            startChar = (startChar == '0')?'1':'0';
        }
        return (numOps >= 0);
    }

    bool isValid(string& s, int numOps, int mid){
        if(mid == 1) return check(s, numOps, mid, '1') || check(s, numOps, mid, '0');
        int count = 0;
        for(int i = 0, last = -1; i < s.size(); ++i){
            if(s[i] == last) count++; 
            else{
                numOps -= count/(mid+1);
                last = s[i];
                count = 1;
            }
        }
        if(count > mid) numOps -= count/(mid+1);
        return (numOps >= 0);
    }

    int minLength(string s, int numOps) {
        int start = 1, end = s.size(), mid, ans = s.size();
        while(start <= end){
            mid = start + (end - start)/2;
            if(isValid(s, numOps, mid)){
                ans = mid;
                end = mid - 1;
            }else start = mid + 1;
        }
        return ans;
    }
};
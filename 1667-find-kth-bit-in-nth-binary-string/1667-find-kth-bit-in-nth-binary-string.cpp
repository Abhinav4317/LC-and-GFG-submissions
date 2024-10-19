class Solution {
public:
    char findKthBit(int n, int k) {
        /**
            Approach
Recursive Structure: We know that each string is formed from the previous one. For any string Sn, it has a clear midpoint (at index 2^(n-1)). The second half of the string is the inverted and reversed version of the first half.

Base Case: When n = 1, the string is "0", so the first bit is always "0".

Recursion:

If k is the middle bit, return '1' since that’s how the binary string is defined.
If k is in the first half of the string, it directly corresponds to a position in the previous string Sn-1.
If k is in the second half, find its corresponding position in the first half of Sn-1, then invert the result.
This approach avoids generating the string explicitly, instead using recursive calls to efficiently determine the k-th bit.
        */
        // Base case: When n = 1, the binary string is "0"
        if (n == 1) return '0';
        
        // Find the length of the current string Sn, which is 2^n - 1
        int length = (1 << n) - 1;
        
        // Find the middle position
        int mid = length / 2 + 1;
        
        // If k is the middle position, return '1'
        if (k == mid) return '1';
        
        // If k is in the first half, find the bit in Sn-1
        if (k < mid) return findKthBit(n - 1, k);
        
        // If k is in the second half, find the bit in Sn-1 and invert it
        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
    }
};
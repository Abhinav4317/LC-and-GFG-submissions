class Solution {
public:
/** 
The problem naturally lends itself to a sliding window approach because we're dealing with substrings, which are contiguous segments of the original string. However, this problem requires some modifications to the general sliding window technique:
We need to keep track of two conditions simultaneously: the presence of all vowels and the count of consonants.
The valid window can extend beyond the point where we find a valid substring, as adding more characters to the right might create more valid substrings. The right can extend before the point where the next consonent found(this will alter the condition of k consonents).
The efficiency of this solution hinges on a crucial insight: we don't need to explicitly extend our window to the right to count all valid substrings starting at the left pointer. Instead, we use precalculation to achieve this in constant time.
*/
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        unordered_map<char, int> vowels;
        int consonantCount = 0;
        long long result = 0;

        // Precompute next consonant positions
        vector<int> nextConsonant(n);
        int lastConsonant = n;
        for (int i = n - 1; i >= 0; i--) {
            nextConsonant[i] = lastConsonant;
            if (!isVowel(word[i])) lastConsonant = i;
        }

        // Sliding window
        int left = 0, right = 0;
        while (right < n) {
            // Expand window
            if (isVowel(word[right])) {
                vowels[word[right]]++;
            } else {
                consonantCount++;
            }

            // Shrink window if too many consonants
            while (left <= right && consonantCount > k) {
                if (isVowel(word[left])) {
                    if (--vowels[word[left]] == 0) vowels.erase(word[left]);
                } else {
                    consonantCount--;
                }
                left++;
            }

            // Count valid substrings
            //here,what is happening is that lets say i have expanded my window on  the right
            //but i can still reduce my window from left even more to create more substrings
            while (left < right && vowels.size() == 5 && consonantCount == k) {
                result += (nextConsonant[right] - right);
                if (isVowel(word[left])) {
                    if (--vowels[word[left]] == 0) vowels.erase(word[left]);
                } else {
                    consonantCount--;
                }
                left++;
            }

            right++;
        }

        return result;
    }
};
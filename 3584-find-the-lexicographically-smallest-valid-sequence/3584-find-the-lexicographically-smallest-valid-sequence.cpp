class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        /**
        Tutorial
            Save the last seen position of each character of word2, by iterating over word1 backwards.
            Use two pointers for matching letters from word1 and word2: we must accept a "coin" when the char match is not equal between them. The coin is accepted if the word2 pointer is in its last position, or if the next letter in word2 was last seen ahead of the current pointer of word2.
            I hope I could help! \U0001f60a

            Complexity
            Time complexity:
            O(M + N) = O(M)

            Space complexity:
            O(2*N) = O(N)
         */
        int m = word1.size(), n = word2.size();
        vector<int> lastSeen(n, -1);
        vector<int> res;


        for (int i = m - 1, j = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                lastSeen[j] = i;
                j--;
            }
        }

        int matchPos = 0, coin = 0;
        for (int i = 0; i < m; i++) {
            if (matchPos < n) {
                bool letterMatch = word1[i] == word2[matchPos];
                if (letterMatch || (!coin && (matchPos == n - 1 || (i + 1 <= lastSeen[matchPos + 1])))) {
                    if (!letterMatch)
                        coin = 1;
                    res.push_back(i);
                    matchPos++;
                }
            }
        }

        return matchPos == n ? res : vector<int>();
    }
};
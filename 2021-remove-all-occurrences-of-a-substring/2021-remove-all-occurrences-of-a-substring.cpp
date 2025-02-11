class Solution {
public:
    short lps[1000]={0};
    // cpmpute lps for pattern
    void preKMP(const string& pattern, int pz) {
        for (int i=1, j=0; i<pz; i++) {
            while (j>0 && pattern[i]!=pattern[j]) 
                j=lps[j-1];
            lps[i]=(pattern[i]==pattern[j])?++j:j;
        }
    }

    string removeOccurrences(string& s, string& part) {
        const int pz=part.size(), n=s.size();
        preKMP(part, pz);
        string ans;
        vector<short> jStack;  // Store pattern index j
        jStack.reserve(n);
        int j=0;  // Current pattern index
        int az=0;
        for (char c : s) {
            ans.push_back(c);
            az++;
            // KMP matching 
            while (j>0 && c != part[j]) 
                j=lps[j-1];
            if (c==part[j]) 
                j++;
            jStack.push_back(j); // put j to jStack

            // Found part, remove it
            if (j==pz) {
                az-=pz;
                ans.resize(az);  // Remove last pz chars
                jStack.resize(az);  // Restore jStack
                
                // Backtrack j using jStack
                j=(az==0)?0:jStack.back();
            }
        }
        return ans;
    }
};
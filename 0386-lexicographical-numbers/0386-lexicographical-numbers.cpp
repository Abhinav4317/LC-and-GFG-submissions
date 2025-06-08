class Solution {
public:
/**
Intuition:
Imagine a tree-like structure starting from 1 to 9 as the root nodes.
For each number curr, its children are formed by appending digits 0–9 (i.e., curr * 10 + d).
This naturally builds a prefix tree (Trie) where traversing in pre-order gives the numbers in lexicographical order.
\U0001f332 Tree Walkthrough (n = 13)
Visualizing the DFS expansion as a vertical, triangle-shaped tree:

           [1]
         /  |  \  \
      [10] [11] [12] [13]
      / \    .    .    .
 [100] [101]       .    .  ❌ >13 stops

           [2]
         /  |  \  \
     [20] [21] [22] [23]
      .     .    .    .  ❌

 ...

           [9]
         /  |  \  \
     [90] [91] [92] [93]
      .     .    .    .  ❌
Level 0 (roots): 1 → 9
Level 1: Append digits 0–3 for 1 (10–13) since n=13
Level 2+: Further appending exceeds n, so branches stop
This illustrates how each node (curr) spawns children (curr*10 + d), forming a triangular expansion.

\U0001f4c8 Traversal Flow
DFS visits:

1 → 10 → 11 → 12 → 13 → backtrack → 2 → 3 → ... → 9
Final Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
*/

    void f(int i,int n,vector<int>& ans){
        if(i>n) return;
        ans.push_back(i);
        for(int j=0;j<=9;j++) f(i*10+j,n,ans);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<10;i++){
            f(i,n,ans);
        }
        return ans;
    }
};
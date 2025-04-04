/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findHeight(TreeNode* node){
        if(node==NULL) return 0;
        int lh=findHeight(node->left),rh=findHeight(node->right);
        return max(lh,rh)+1;
    }
    bool solve(TreeNode* node,int lvl,int h,TreeNode* &ans){
        if(!node) return 0;
        if(!node->left&&!node->right){
            if(lvl==h-1) {ans=node;return 1;}
            return 0;
        }
        bool l=solve(node->left,lvl+1,h,ans);
        bool r=solve(node->right,lvl+1,h,ans);
        if(l&&r) {ans=node; return true;}
        else if(!l&&!r) return false;
        else return true;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans=NULL;
        int lvl=0;
        int h=findHeight(root);
        solve(root,lvl,h,ans);
        //cout<<ans->val<<endl;
        return ans;
    }
};
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<pair<TreeNode*,int>> q2;
        q1.push(root);
        int sum=0;
        while(!q1.empty()||!q2.empty()){
            int sz2=q2.size();
            //cout<<sz2<<endl;
            for(int i=0;i<sz2;i++){
                TreeNode* f2=q2.front().first;
                int sib=q2.front().second;
                q2.pop();
                f2->val=sum-(f2->val+sib);
                q1.push(f2);
            }
            sum=0;
            int sz=q1.size();
            for(int i=0;i<sz;i++){
                TreeNode* f=q1.front();
                q1.pop();
                if(f->left&&f->right){
                    q2.push({f->left,f->right->val});
                    sum+=f->left->val;
                    q2.push({f->right,f->left->val});  
                    sum+=f->right->val;
                }else if(f->left){
                    q2.push({f->left,0});
                    sum+=f->left->val;
                }else if(f->right){
                    q2.push({f->right,0});
                    sum+=f->right->val;
                }
            }
            //cout<<sum<<endl;
        }
        root->val=0;
        return root;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(ListNode* tmp,TreeNode* node,ListNode* head){

        if(!tmp) {return true;}
        if(!node){return false;}
        if(node->val==tmp->val){
            tmp=tmp->next;
        }else if(head->val==node->val){
            head=head->next;
        }else{
            tmp=head;
        }
        return solve(tmp,node->left,head)||solve(tmp,node->right,head);

    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        ListNode* tmp=head;
        TreeNode* node=root;
        return solve(tmp,node,head);
        //return ans;
    }
};
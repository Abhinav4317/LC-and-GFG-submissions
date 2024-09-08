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
class Solution {
public:
    //BRUTE FORCE APPROACH HAS BEEN USED=>POINT TO NOTE HERE IS HOW I SPECIFY WHICH PART HAS HOW MUCH LENGTH
    int getLength(ListNode* head){
        int len=0;
        ListNode* tmp=head;
        while(tmp!=NULL) {len++; tmp=tmp->next;}
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=getLength(head);
        vector<ListNode*> ans;
        if(len==0) {
            for(int i=0;i<k;i++) ans.push_back(NULL);
            return ans;
        }
        int ak=min(k,len);
        int rem=len%ak;
        vector<int> l(ak);
        //cout<<ak<<" "<<len<<" "<<rem<<endl;
        for(int i=0;i<ak;i++){
            if(rem>0) l[i]=(len/ak)+1;
            else l[i]=(len/ak);
            rem--;
        }
        // for(int x:l) cout<<x<<" ";
        // cout<<endl;
        ListNode* node=head;
        ListNode* prev=NULL;
        int ind=0;
        //vector<ListNode*> ans;
        while(node!=NULL){
            ListNode* nhead=node;
            while(l[ind]>0){
                prev=node;node=node->next;
                l[ind]--;
            }
            ind++;
            prev->next=NULL;
            ans.push_back(nhead);
            if(ind>=ak) break;
        }
        k-=ak;
        while(k>0){
            ans.push_back(NULL);
            k--;
        }
        return ans;
    }
};
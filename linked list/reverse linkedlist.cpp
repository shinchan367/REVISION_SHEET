class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*curr=head;
        ListNode*next=nullptr;
        ListNode*prev=nullptr;
        while(curr!=NULL){
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
        }
        return prev;
    }
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        for (ListNode *p=head;p!=NULL;p=p->next){
            ListNode *pre = p;
            while (p->next!=NULL && p->next->val==p->val) p=p->next;
            pre->next=p->next;
        }
        return head;
    }
};
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *vis = new ListNode(0);
        vis->next = head;
        ListNode *pre = vis;
        for (ListNode *p=head;p!=NULL;p=p->next){
            int tot=0;
            while (p->next!=NULL && p->next->val==p->val){
                ++tot;
                p=p->next;
            }
            if (tot) pre->next=p->next;
            else pre=pre->next;
        }
        return vis->next;
    }
};
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *now = head, *vis = new ListNode(0);
        vis -> next = head;
        ListNode *pre = vis;
        while (now!=NULL && now->val<x){
            pre = now;
            now = now->next;
        } 
        if (now == NULL) return head;
        ListNode *pre2 = now, *tmp;
        for (ListNode *p = now->next; p!=NULL; p=tmp){
            tmp = p->next;
            if (p->val<x){
                p->next=pre->next;
                pre2->next=tmp;
                pre->next=p;
                pre=pre->next;
            }else pre2=p;
        }
        return vis->next;
    }
};
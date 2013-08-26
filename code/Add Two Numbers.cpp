class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1==NULL && l2==NULL) return l1;
        if (l1==NULL) l1 = new ListNode(0);
        if (l2==NULL) l2 = new ListNode(0);
        ListNode *ans = l1;   
        l1->val += l2->val;
        int pre = 0;
        if (l1->val>=10){
            l1->val-=10;
            pre=1;
        }else pre=0;
        while (l1->next!=NULL || l2->next!=NULL || pre!=0){
            if (l1->next==NULL) l1->next = new ListNode(0);
            if (l2->next==NULL) l2->next = new ListNode(0);
            l1 = l1->next;
            l2 = l2->next;
            l1->val += l2->val + pre;
            if (l1->val>=10){
                l1->val-=10;
                pre=1;
            }else pre=0;
        }
        return ans;
    }
};
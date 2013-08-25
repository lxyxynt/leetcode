class Solution {
public:
    void dfs(ListNode *now, ListNode *pre, ListNode *end){
        if (now != end) dfs(now->next, now, end);
        now -> next = pre;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *ans = head;
        ListNode *now = head;
        for (int i=1;i<m;++i){
            if (now == NULL) return ans;
            now = now->next;
        }
        ListNode *suc = now;
        for (int i=m;i<n;++i){
            if (suc == NULL) return ans;
            suc = suc->next;
        }
        if (suc == NULL) return ans;
        ListNode *nxt = suc -> next;
        
        dfs(now, nxt, suc);
        if (m!=1){
            ListNode *pre = head;
            for (int i=2;i<m;++i){
                if (pre == NULL) return ans;
                pre = pre->next;
            }
            pre -> next = suc;
            return ans;
        }else return suc;
    }
};
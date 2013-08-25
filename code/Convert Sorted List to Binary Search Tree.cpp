class Solution {
public:
    TreeNode *build(ListNode *&head, int l, int r){
        if (l >= r) return NULL;
        int mid = (l + r) >> 1;
        TreeNode *left = build(head, l, mid);
        TreeNode *now = new TreeNode(head->val);
        head = head->next;
        now->left  = left;
        now->right = build(head, mid+1, r);
        return now;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        int n;
        ListNode *temp = head;
        for (n=0;temp!=NULL;temp=temp->next) ++n;
        return build(head, 0, n);
    }
};

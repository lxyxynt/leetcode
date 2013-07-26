class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL || root->left == NULL || root->right == NULL) return;
        root->left->next = root->right;
        if (root->next != NULL) root->right->next = root->next->left;
        else root->right->next = NULL;
        connect(root->left);
        connect(root->right);
    }
};

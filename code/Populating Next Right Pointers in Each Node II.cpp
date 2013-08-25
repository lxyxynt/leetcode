class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        if (root->right != NULL){
            root->right->next = NULL;
            for (TreeLinkNode* it=root->next;it!=NULL;it=it->next){
                if (it->left!=NULL){
                    root->right->next = it->left;
                    break;
                } 
                if (it->right!=NULL){
                    root->right->next = it->right;
                    break;
                } 
            }
            connect(root->right);
        }
        if (root->left != NULL){
            root->left->next = NULL;
            if (root->right == NULL){
                for (TreeLinkNode* it=root->next;it!=NULL;it=it->next){
                    if (it->left!=NULL){
                        root->left->next = it->left;
                        break;
                    } 
                    if (it->right!=NULL){
                        root->left->next = it->right;
                        break;
                    } 
                }
            }else root->left->next = root->right;
            connect(root->left);
        }
    }
};

class Solution{
public:
    TreeNode*temp=NULL;
    void recoverTree(TreeNode* root){
        if(!root) return;
        recoverTree(root->left);
        if(!temp){
            temp=root;
        }else{
            if(temp->val>root->val){
                swap(temp->val,root->val);
                return;
            }
        }
        recoverTree(root->right);
    }
};
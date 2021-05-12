class Solution{
public:
    bool isCompleteTree(TreeNode* root){
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool b=false;
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(temp==NULL){
                b=true;
                continue;
            }
            if(b){
                return false;
            }
            q.push(temp->left);
            q.push(temp->right);
        }
        return true;
    }
};
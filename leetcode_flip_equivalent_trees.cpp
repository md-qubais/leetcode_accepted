class Solution{
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2){
    	if(!root1 and root2){
    		return false;
    	}
    	if(!root2 and root1){
    		return false;
    	}
    	if(!root1 and !root2){
    		return true;
    	}
    	if(root1->val!=root2->val){		
    		return false;
    	}
    	if(flipEquiv(root1->left,root2->left) and flipEquiv(root1->right,root2->right)){
    		return true;
    	}
    	swap(root2->left,root2->right);
    	if(flipEquiv(root1->left,root2->left) and flipEquiv(root1->right,root2->right)){
    		return true;
    	}
    	return false;
    }
};
class Solution {
public:
	
    int pathSum(TreeNode* root, int targetSum){      
    	return pathSum(root,targetSum,targetSum);
    }
};
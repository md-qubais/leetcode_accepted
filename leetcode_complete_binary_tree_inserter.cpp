class CBTInserter {
public:
	TreeNode*root=NULL;
	vector<TreeNode*> arr;
	CBTInserter(TreeNode* root){
		arr.push_back(NULL);
    	this->root=root;
    	queue<TreeNode*> q;
    	q.push(root);
    	arr.push_back(root);
    	while(!q.empty()){
    		TreeNode*temp=q.front();
    		q.pop();
    		if(temp->left){
    			arr.push_back(temp->left);
    			q.push(temp->left);
    		}
    		if(temp->right){
    			arr.push_back(temp->right);
    			q.push(temp->right);
    		}
    	}
    }

    int insert(int val){
    	TreeNode*temp=new TreeNode(val);
    	arr.push_back(temp);
    	int i=arr.size()-1;
    	if(i/2>0){
    		if(!arr[i/2]->left){
    			arr[i/2]->left=temp;
    		}
    		else if(!arr[i/2]->right){
    			arr[i/2]->right=temp;
    		}
    	}
    	return arr[i/2]->val;
    }
    
    TreeNode* get_root(){
    	return root;
    }

};

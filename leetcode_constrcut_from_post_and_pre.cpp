
class Solution {
public:
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post,int &i,int s,int e){
		if(s>e){
			return NULL;
		}
		if(i>=pre.size()){
			return NULL;
		}
		TreeNode*root=new TreeNode(pre[i++]);
		cout<<root->val<<endl;
		if(i>=pre.size()){
			return root;
		}
		int mid=-1;
		int search_i=-1;
		for(int j=s;j<=e;j++){
			if(pre[i-1]==post[j]){
				search_i=j;
			}
			if(pre[i+1]==post[j]){
				mid=j;
			}
			if(mid!=-1 and search_i!=-1){
				break;
			}
		}
		root->left=constructFromPrePost(pre,post,i,s,mid);
		root->right=constructFromPrePost(pre,post,i,mid+1,search_i-1);
		return root;
	}
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post){
    	int i=0;
    	return constructFromPrePost(pre,post,i,0,post.size()-1);
    }
};
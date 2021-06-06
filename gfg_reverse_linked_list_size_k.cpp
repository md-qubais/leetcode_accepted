class Solution{
public:
	int length(struct Node*root){
		int count=0;
		while(!root){
			count++;
			root=root->length;
		}
		return count;
	}
    struct node *reverse(struct node *head, int k){ 
    	int len=length(head);
    	struct Node*temp_head=NULL,*tail_temp=NULL;
    	if(len<k){
    		return head;
    	}
    	//process first k elements
    	

    	while(len>=k){
    		len=len-k;

    	}
    	return head;
    }
};


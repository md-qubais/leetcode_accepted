class Solution
{
    public:
    struct Node* reverseList_iteratively(struct Node *head){
    	struct Node*curr=head,*prev=NULL;
    	head=head->next;
    	while(head){
    		curr->next=prev;
    		prev=curr;
    		curr=head;
    		head=head->next;
    	}
    	curr->next=prev;
    	return curr;
    }
    struct Node* reverseList_recursively(struct Node *head,struct Node*prev=NULL){
    	if(!head){
    		return prev;
    	}
    	struct Node* temp=head->next;
    	head->next=prev;
    	prev=head;
    	return reverseList_recursively(temp,head);
    }   
    struct Node* reverseList(struct Node *head){
    	return reverseList_recursively(head);
    }     
};
    
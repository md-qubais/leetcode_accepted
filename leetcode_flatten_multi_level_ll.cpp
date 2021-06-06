class Solution {
public:
    Node* flatten(Node* head,Node* temp=NULL){
        if(!head){
            return NULL;
        }
        if(head->child){
            Node*forward=head->next;
            temp=head;
            Node*temp2=flatten(head->child,NULL);
            temp->child=NULL;
            temp->next=temp2;
            temp2->prev=temp;
            while(temp2->next){
                temp2=temp2->next;
            }
            temp2->next=forward;
            if(forward){
                forward->prev=temp2;
                forward->next=flatten(forward->next,head);
            }
            return head;
        }
        head->next=flatten(head->next,head);
        return head;
    }
    
};
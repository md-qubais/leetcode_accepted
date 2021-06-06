class Solution {
public:
    void copy_list(Node*head){
        while(head){
            Node*n=new Node(head->val);
            Node*Next=head->next;
            head->next=n;
            n->next=Next;
            head=Next;
        }
    }
    void map_list(Node*head){
        while(head){
            if(head->random){
                head->next->random=head->random->next;
            }
            head=head->next->next;
        }
    }
    Node* extract_list(Node*head){
        Node*ans=head->next;
        Node*tail=head->next;
        while(head and tail){
            head->next=head->next->next;
            head=head->next;
            if(head){
                tail->next=head->next;
            }else{
                tail->next=head;
            }
            tail=tail->next;
        }
        return ans;
    }
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        copy_list(head);
        map_list(head);
        Node*ans=NULL;
        ans=extract_list(head);
        return ans;
    }
};
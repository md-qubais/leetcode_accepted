
class Solution {
public:
    Node* copyRandomList(Node* head){
        unordered_map<Node*,Node*> m;
        Node*root=NULL;
        Node*root_tail=NULL;
        Node*temp=head;
        while(temp){
            if(!root){
                root=new Node(temp->val);
                root_tail=root;
            }else{
                Node*t=new Node(temp->val);
                root_tail->next=t;
                root_tail=t;
            }
            m[temp]=root_tail;
            temp=temp->next;
        }
        temp=head;
        Node*temp1=root;
        while(temp){
            if(m[temp->random]){
                temp1->random=m[temp->random];
            }
            temp1=temp1->next;
            temp=temp->next;
        }
        return root;
    }
};

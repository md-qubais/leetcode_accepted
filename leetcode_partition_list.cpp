class Solution{
public:
    ListNode* partition(ListNode* head, int x){
        ListNode*small_start=NULL;
        ListNode*small=NULL;
        ListNode*big_start=NULL;
        ListNode*big=NULL;
        ListNode*curr=head;
        while(curr){
            if(curr->val<x){
                if(small_start==NULL){
                    small_start=curr;
                    small=curr;
                }else{
                    small->next=curr;
                    small=curr;
                }
            }else{
                if(big_start==NULL){
                    big_start=curr;
                    big=curr;
                }else{
                    big->next=curr;
                    big=curr;
                }
            }
            curr=curr->next;
        }
        if(big_start){
            big->next=NULL;
        }
        if(small_start){
            small->next;
        }
        if(small_start and big_start){
            small->next=big_start;
            return small_start;
        }
        if(small_start){
            return small_start;
        }
        return big_start;
    }
};
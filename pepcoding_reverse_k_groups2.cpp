class Solution{
public:
    ListNode*th=NULL,*tt=NULL;
    int length(ListNode*head){
        int len=0;
        while(head){
            head=head->next;
            len++;
        }
        return len;
    }
    void add_first(ListNode*head){
        if(!th){
            th=tt=head;
            tt->next=NULL;
        }else{
            head->next=th;
            th=head;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k){
        int len=length(head);
        if(len<k or k<=1 or !head){
            return head;
        }
        ListNode*ans_head=NULL;
        ListNode*ans_tail=NULL;
        while(len>=k){
            len=len-k;
            int num=k;
            while(num--){
                ListNode*curr=head;
                head=head->next;
                add_first(curr);
            }
            if(ans_head==NULL){
                ans_head=th;
                ans_tail=tt;
            }else{
                ans_tail->next=th;
                ans_tail=tt;
            }
            th=tt=NULL;
            ans_tail->next=head;
        }

        return ans_head;
    }
};
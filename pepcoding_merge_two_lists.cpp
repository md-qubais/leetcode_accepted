ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
    ListNode *ans=NULL;
    ListNode *tail=NULL;
    while(l1 and l2){
        if(l1->val<l2->val){
            if(ans==NULL){
                ans=tail=l1;
                l1=l1->next;
            }else{
                tail->next=l1;
                tail=l1;
                l1=l1->next;
            }
        }else{
            if(ans==NULL){
                ans=tail=l2;
                l2=l2->next;
            }else{
                tail->next=l2;
                tail=l2;
                l2=l2->next;
            }
        }
    }
    if(ans==NULL){
        ans=tail=l1?l1:l2;
    }else{
        tail->next=l1?l1:l2;
    }
    return ans;
}
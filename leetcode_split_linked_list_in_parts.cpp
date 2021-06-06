
class Solution {
public:
    int length(ListNode*root){
        int len=0;
        while(root){
            len++;
            root=root->next;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k){
        vector<ListNode*> ans(k);
        if(!root){
            return ans;
        }
        int idx=0;
        int n=length(root);
        //first n%k part will have (n/k)+1 elements 
        int first_part=n%k;
        int i=1;
        int count=1;
        ListNode*head=root;
        while(i<=first_part){
            if(count>=(n/k)+1){
                i++;
                ans[idx++]=root;
                root=head->next;
                if(!root){
                    return ans;
                }
                head->next=NULL;
                head=root;
                count=1;
            }else{
                count++;
                head=head->next;
            }
        }
        int second_part=k;
        //and next parts-k will have n/2 elements
        while(i<=k){
            if(count>=(n/k)){
                i++;
                ans[idx++]=root;
                root=head->next;
                if(!root){
                    return ans;
                }
                head->next=NULL;
                head=root;
                count=1;
            }else{
                count++;
                head=head->next;
            }
        }
        return ans;
    }
};
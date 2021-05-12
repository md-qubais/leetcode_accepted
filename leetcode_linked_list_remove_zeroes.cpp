
class Solution {
public:
    bool update_array(vector<int>&arr,vector<int>&pre_sum){
        bool b=false;
        for(int i=0;i<pre_sum.size();i++){
            for(int j=i;j<pre_sum.size();j++){
                if(i==j){
                    if(pre_sum[j]==0){
                        pre_sum.erase(pre_sum.begin(),pre_sum.begin()+j+1);
                        arr.erase(arr.begin(),arr.begin()+j+1);
                        b=true;
                    }
                }else{
                    if(pre_sum[j]-pre_sum[i]==0){
                        b=true;
                        pre_sum.erase(pre_sum.begin()+i+1,pre_sum.begin()+j+1);
                        arr.erase(arr.begin()+i+1,arr.begin()+j+1);
                    }
                }
            }
            if(b){
                break;
            }
        }
        return b;
    }
    ListNode* removeZeroSumSublists(ListNode* head){
        vector<int> arr;
        ListNode*temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        vector<int> pre_sum(arr.size());
        pre_sum[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            pre_sum[i]=pre_sum[i-1]+arr[i];
        }
        bool b=true;
        while(b){
            b=update_array(arr,pre_sum);
        }
        ListNode*ans=NULL;
        ListNode*tail=NULL;
        for(auto&it:arr){
            if(!ans){
                ans=new ListNode(it);
                tail=ans;
            }else{
                tail->next=new ListNode(it);
                tail=tail->next;
            }
        }
        return ans;
    }
};

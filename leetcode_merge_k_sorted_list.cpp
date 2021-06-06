class compare{
public:
	bool operator()(ListNode*l1,ListNode*l2){
		return l1->val>l2->val;
	}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
    	if(lists.size()==0){
            return NULL;
        }
        int k=lists.size();
        ListNode*ans=NULL;
    	ListNode*tail=NULL;
    	priority_queue<ListNode*,vector<ListNode*>,compare> pq;
    	for(int i=0;i<lists.size();i++){
            if(lists[i]) pq.push(lists[i]);
        }
        while(!pq.empty()){
            ListNode*temp=pq.top();
            pq.pop();
            if(temp->next!=NULL) pq.push(temp->next);
            if(ans==NULL){
                ans=temp;
                tail=ans;
            }else {
                tail->next=temp;
                tail=temp;
            }
    	}
     	if(ans) tail->next=NULL;
    	return ans;
    }
};
class Solution{
public:
    int numComponents(ListNode* head, vector<int>& nums){
    	unordered_map<int,bool> connected;
    	for(auto&it:nums){
    		connected[it]=true;
    	}
    	int ans=0;
    	bool b=false;
    	while(head){
    		if(connected[head->val]){
    			if(!b){
    				b=true;
    				ans++;
    			}
    			connected[head->val]=false;
    		}else{
    			b=false;
    		}
    		head=head->next;
    	}
    	return ans;
    }
};
class Solution{
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
    	int ans=0;
    	int max_ans=0;
    	nums.push_back(-1);
    	for(int i=0;i<nums.size();i++){
    		if(nums[i]==1){
    			max_ans++;
    		}else{
    			ans=max(ans,max_ans);
    			max_ans=0;
    		}
    	}
    	return ans;
    }
};
class Solution{
public:
    int findLengthOfLCIS(vector<int>& nums){
    	int ans=INT_MIN;
    	int curr_max=0;
    	nums.push_back(-1);
    	for(int i=0;i<nums.size()-1;i++){
    		if(nums[i]<nums[i+1]){
    			curr_max++;
    		}else{
    			ans=max(curr_max+1,ans);
    			curr_max=0;
    		}
    	}
    	return max(ans,curr_max);
    }
};
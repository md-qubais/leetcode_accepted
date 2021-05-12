class Solution {
public:
    int maxProduct(vector<int>& nums){
    	vector<int> pre(nums.size());
    	pre[0]=nums[0]
    	for(int i=1;i<nums.size();i++){
    		pre[i]*=nums[i];
    	}
    	int ans=INT_MIN;
    	for(int i=0;i<nums.size();i++){
    		for(int j=i;j<nums.size();j++){

    		}
    	}
    	return ans;
    }
};
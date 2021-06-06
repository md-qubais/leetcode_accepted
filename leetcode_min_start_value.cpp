class Solution{
public:
    int minStartValue(vector<int>& nums){
    	vector<int> presum(nums.size());
    	presum[0]=nums[0];
    	for(int i=1;i<nums.size();i++){
    		presum[i]=presum[i-1]+nums[i];
    	}
    	int Min=INT_MAX;
    	for(auto&it:presum){
    		Min=min(Min,it);
    	}
    	return Min<=0?(-Min)+1:Min;
    }
};
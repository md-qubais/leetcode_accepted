class Solution{
public:
    int largestSumAfterKNegations(vector<int>& nums, int k){
    	sort(nums.begin(),nums.end());
    	int i=0;
    	while(i<nums.size() and k>0){
    		nums[i]=-nums[i];
    		k--;
    		i++;
    	}
    	int sum=0;
    	for(auto&it:nums){
    		sum+=it;
    	}
    	return sum;
    }
};
class Solution {
public:
    bool isMonotonic(vector<int>& nums){
    	bool increasing=false;
    	bool decreasing=false;
    	for(int i=0;i<nums.size()-1;i++){
    		if(nums[i]<=nums[i+1]){
    			
    			increasing=true;
    		}else{
    			decreasing=true;
    		}
    	}
    	if(increasing and decreasing){
    		return false;
    	}
    	return true;
    }
};
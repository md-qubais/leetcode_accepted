class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
    	unordered_map<int,vector<int>> m;
    	for(int i=0;i<nums.size();i++){
    		if(m.count(nums[i])!=0){
    			for(auto&it:m[nums[i]]){
    				if(abs(it-i)<=k){
    					return true;
    				}
    			}
    			m[nums[i]].push_back(i);
    		}else{
    			m[nums[i]].push_back(i);
    		}
    	}
    	return false;
    }
};
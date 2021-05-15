class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums){
    	int i=0;
    	int j=i+1;
    	vector<int> ans;
    	while(i<nums.size() and j<nums.size()){
    		for(int k=1;k<=nums[i];k++){
    			ans.push_back(nums[j]);
    		}
    		i+=2;
    		j=i+1;
    	}
    	return ans;
    }
};
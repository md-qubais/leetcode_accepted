class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums){
    	vector<int> arr;
    	for(auto&it:nums){
    		arr.push_back(it);
    	}
    	sort(begin(arr),end(arr));
    	vector<int> ans;
    	for(int i=0;i<nums.size();i++){
    		for(int j=0;j<arr.size();j++){
    			if(nums[i]==arr[j]){
    				ans.push_back(j);
    				break;
    			}
    		}
    	}
    	return ans;
    }
};
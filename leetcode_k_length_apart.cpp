class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k){
    	if(nums.size()==0 or nums.size()==1 or k==0){
    		return true;
    	}
    	vector<int> vals;
    	for(int i=0;i<nums.size();i++){
    		if(nums[i]==1){
    			vals.push_back(i);
    		}
    	}
    	for(int i=0;i<vals.size()-1;i++){
    		int first=vals[i];
    		int second=vals[i+1];
    		if(second-first+1<k){
    			return false;
    		}
    	}


    	return true;
    }
};
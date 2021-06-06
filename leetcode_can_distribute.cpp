class Solution{
public:
	unordered_map<int,int> freq;
	bool can_distribute(vector<int>& quantity,int i=0){
		if(i==quantity.size()){
			return true;
		}
		for(auto&it:freq){
			if((freq[it.first]-quantity[i])>=0){
				freq[it.first]-=quantity[i];
				if(can_distribute(quantity,i+1)){
					return true;
				}
				freq[it.first]+=quantity[i];
			}
		}
		return false;
	}
    bool canDistribute(vector<int>& nums, vector<int>& quantity){
    	for(auto&it:nums){
    		freq[it]++;
    	}
    	sort(quantity.begin(),quantity.end(),greater<int>{});
    	return can_distribute(quantity);
    }
};
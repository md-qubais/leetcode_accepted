class Solution{
public:
	
	int numSquarefulPerms(vector<int>&nums,vector<int> temp,map<int,int> freq,int i=0){
		if(i==temp.size()){
			return 1;
		}
		int ans=0;
		for(auto it: freq){
			if(freq[it.first]>0){
				temp[i]=it.first;
				if(i>0 and ceil((double)sqrt(temp[i-1]+temp[i])) == floor((double)sqrt(temp[i-1]+temp[i]))){
					freq[it.first]--;
				    ans+=numSquarefulPerms(nums,temp,freq,i+1);
				    freq[it.first]++;
				}else if(i==0){
					freq[it.first]--;
				    ans+=numSquarefulPerms(nums,temp,freq,i+1);
				    freq[it.first]++;
				}
			}
		}
		return ans;
	}
    
    int numSquarefulPerms(vector<int>& nums){
    	if(nums.size()<2){
    		return 0;
    	}
    	map<int,int> freq;
    	for(auto&it:nums){
    		freq[it]++;
    	}
    	vector<int> temp(nums.size());
    	return numSquarefulPerms(nums,temp,freq);
    }

};
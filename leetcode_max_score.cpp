class Solution {
public:
    int maxScore(vector<int> nums,int i=0,int asf=1){
    	if(asf>n/2){
    		return 0;
    	}
    	int ans=0;
    	for(int j=i;j<nums.size()-1;j++){
    		for(int k=j+1;k<nums.size();k++){
    			vector<int> temp=nums;
    		}
    	}
    	return ans*asf;
    }
};
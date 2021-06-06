class Solution{
public:
	int maxScore(vector<int> temp,int n,int osf=0,int op=1){
		if(osf==n){
			return 0;
		}
		int ans=0;
		for(int i=0;i<temp.size()-1;i++){
			for(int j=i+1;j<temp.size();j++){
				ans=max(ans,op*__gcd(temp[i],temp[j])+maxScore(temp,n,osf+1,op+1));
			}
		}
		return ans;
	}
    int maxScore(vector<int>& nums){
    	int n=nums.size()/2;
    	return maxScore(nums,n);
    }
};
class Solution{
public:

    unordered_map<int,bool> is_power;
	int countPairs(vector<int>&arr,int k,int set_bit,int i=0,int sum=0,int nsf=0){
		if(nsf==k){
			if(__builtin_popcount(sum)==1){
				is_power[sum]=true;
				return 1;
			}
			is_power[sum]=false;
			return 0;
		}
		int ans=0;
		for(int j=i;j<arr.size();j++){
			ans+=countPairs(arr,k,set_bit,j+1,sum+arr[j],nsf+1);
		}
		return ans;
	}
    int countPairs(vector<int>& arr){
    	sort(arr.begin(),arr.end());
    	return countPairs(arr,2,1,0);
    }
};
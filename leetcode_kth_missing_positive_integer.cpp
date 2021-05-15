class Solution {
public:
    int findKthPositive(vector<int>& arr, int k){
    	map<int,bool> m;
    	for(auto&it:arr){
    		m[it]=true;
    	}
    	int ans=-1;
    	for(int i=1;i<=1000;i++){
    		if(k==0){
    			return ans;
    		}
    		if(!m[i]){
    			k--;
    			ans=i;
    		}
    	}
    	return ans;
    }
};
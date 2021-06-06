class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour){
    	int tot=0;
    	for(auto&it:dist){
    		tot+=it;
    	}
    	int start=1;
    	int end=tot;
    	int ans=-1;
    	while(start<=end){
    		int mid=start+(end-start)/2;
    		if(){
    			ans=mid;
    			start++;
    		}else{
    			end--;
    		}
    	}
    	return ans;
    }
};
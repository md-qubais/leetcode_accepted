class Solution {
public:
    double average(vector<int>& salary){
    	int Min=INT_MAX;
    	int Max=INT_MIN;
    	double ans=0;
    	int sum=0;
    	for(auto&it:salary){
    		Min=min(Min,it);
    		Max=max(Max,it);
    		sum+=it;
    	}
    	sum=sum-Min-Max;
    	ans=(double)(sum)/(double)(salary.size()-2);
    	return ans;
    }
};
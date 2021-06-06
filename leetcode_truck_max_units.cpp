bool compare(pair<int,int> p1,pair<int,int> p2){
	return p1.second>p2.second;
}
class Solution{
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize){
    	vector<pair<int,int>> arr;
    	for(int i=0;i<boxTypes.size();i++){
    		arr.push_back({boxTypes[i][0],boxTypes[i][1]});
    	}
    	int ans=0;
    	sort(arr.begin(),arr.end(),compare);
    	int i=0;
    	while(i<arr.size() and truckSize>0){
    		if(truckSize-arr[i].first>=0){
    			truckSize-=arr[i].first;
    			ans+=arr[i].first*arr[i].second;
    			i++;
    		}else{
    			int count=0;
    			while(truckSize>0){
    				truckSize--;
    				count++;
    			}
    			ans+=count*arr[i].second;
    		}
    	}
    	return ans;
    }
};
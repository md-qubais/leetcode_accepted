class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr){
    	unordered_map<int,int> occ;
    	unordered_map<int,int> m;//storing occurances
    	for(auto&it:arr){
    		occ[it]++;
    	}
    	for(auto&it:occ){
    		m[occ[it.first]]++;
    	}
    	for(auto&it:m){
    		if(m[it.first]>1){
    			return false;
    		}
    	}
    	return true;
    }
};
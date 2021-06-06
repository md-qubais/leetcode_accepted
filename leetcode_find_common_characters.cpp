class Solution {
public:
    vector<string> commonChars(vector<string>&arr){
    	unordered_map<char,int> count;
    	vector<string> ans;
    	for(auto&it:arr){
    		for(auto&i:it){
    			count[i]=INT_MAX;
    		}
    	}
    	for(auto&it:arr){
    		unordered_map<char,int> temp;
    		for(auto&i:it){
    			temp[i]++;
    		}
    		for(auto&i:count){
    			count[i.first]=min(temp[i.first],count[i.first]);
    		}
    	}
    	for(auto&it:count){
    		while(count[it.first]>0){
    			count[it.first]--;
    			string temp="";
    			temp+=it.first;
    			ans.push_back(temp);
    		}
    	}
    	return ans;
    }
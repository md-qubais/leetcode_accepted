class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first){
    	vector<int> ans;
    	ans.push_back(first);
    	int dec=first;
    	for(int i=0;i<encoded.size();i++){
    		dec^=encoded[i];
    		ans.push_back(dec);
    	}
    	return ans;
    }
};
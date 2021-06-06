class Solution {
public:
	int len=0;
	bool isunique(string s){
		unordered_map<char,int> mask;
		for(auto&it:s){
			if(mask[it]==0){
				mask[it]++;
			}else{
				return false;
			}
		}
		return true;
	}
	int maxLength(vector<string>&arr,int i,string asf=""){
		if(!isunique(asf)){
			return 0;
		}
		if(len<asf.length()){
			len=asf.length();
		}
		for(int j=i;j<arr.size();j++){
			maxLength(arr,j+1,asf+arr[j]);
		}
		return len;
	}
    int maxLength(vector<string>& arr){
    	return maxLength(arr,0);
    }
};
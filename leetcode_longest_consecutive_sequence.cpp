class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
    	if(arr.size()==0){
    		return 0;
    	}
    unordered_map<int,bool> m;
	for(auto&it:arr){
		m[it]=true;
	}
	for(auto&it:arr){
		if(m.count(it-1)){
			m[it]=false;
		}
	}
	int max_length=INT_MIN;
	int start_val;
	for(auto&it:m){
		if(m[it.first]){
			int len=0;
			int val=it.first;
			int temp=val;
			while(m.count(val)){
				len++;
				val++;
			}
			if(max_length<len){
				max_length=len;
				start_val=temp;
			}else if(max_length==len){
				if(start_val>temp){
					start_val=temp;
				}
			}
		}
	}
	return max_length;      
    }
};
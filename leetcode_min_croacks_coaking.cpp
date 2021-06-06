class Solution {
public:
    int minNumberOfFrogs(string s){
    	unordered_map<char,int> m;
    	for(int i=0;i<s.length();i++){
    		m[s[i]]++;
    	}
    	int ans=0;
    	bool b=true;
    	while(b){
    		b=false;
    		string temp="";
    		for(auto it:m){
    			if(m[it.first]<=0){
    			}else{
    				temp+=it.first;
    				m[it.first]--;
    			}
    		}
    		if(temp.length()==5){
    			b=true;
    			ans++;
    		}
    	}
    	return ans;
    }
};
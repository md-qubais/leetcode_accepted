class Solution {
public:
    int maxPower(string s){
    	s+='$';
    	int ans=0;
    	int curr_max=1;
    	for(int i=0;i<s.length();i++){
    		if(s[i]==s[i+1]){
    			curr_max++;
    		}else{
    			ans=max(ans,curr_max);
    			curr_max=1;
    		}
    	}
    	return ans;
    }
};
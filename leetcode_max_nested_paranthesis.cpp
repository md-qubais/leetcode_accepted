class Solution {
public:
    int maxDepth(string s){
    	int ans=INT_MIN;
    	int curr_max=0;
    	for(int i=0;i<s.length();i++){
    		if(s[i]=='('){
    			curr_max++;
    			ans=max(ans,curr_max);
    		}else if(s[i]==')'){
    			curr_max--;
    		}
    	}
    	ans=max(ans,curr_max);
    	return ans;
    }
};
class Solution {
public:
	bool ispalindrome(string s,int start,int end){
		while(start<end){
			if(s[start]==s[end]){
				start++;
				end--;
			}else return false;
		}
		return true;
	}
    bool validPalindrome(string s){
    	int start=0;
    	int end=s.length()-1;
    	while(start<end){
    		if(s[start]==s[end]){
    			start++;
    			end--;
    		}else{
    			if(ispalindrome(s,start+1,end)){
    				return true;
    			}else if(ispalindrome(s,start,end-1)){
    				return true;
    			}else{
    				return false;
    			}
    		}
    	}
    	return true;
    }
};
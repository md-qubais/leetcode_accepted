class Solution {
public:
    bool checkOnesSegment(string s){
    	int count=0;
    	for(int i=0;i<s.length();i++){
    		if(count==2 and s[i]=='1'){
    			return false;
    		}
    		if(count==0 and s[i]=='1'){
    			count=1;
    		}
    		else if(s[i]=='0'){
    			count=2;
    		}
    	}
    	return true;
    }
};
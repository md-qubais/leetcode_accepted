class Solution {
public:
    bool checkZeroOnes(string s){
    	int one=0;
    	int curr_one=0;
    	int zero=0;
    	int curr_zero=0;
    	s=s+" ";
    	for(int i=0;i<s.length();i++){
    		if(s[i]=='1'){
    			zero=max(zero,curr_zero);
    			curr_zero=0;
    			curr_one++;
    		}
    		if(s[i]=='0'){
    			one=max(one,curr_one);
    			curr_one=0;
    			curr_zero++;
    		}
    		if(s[i]==' '){
    			one=max(one,curr_one);
    			zero=max(zero,curr_zero);
    		}
    	}
    	if(one>zero){
    		return true;
    	}
    	return false;
    }
};
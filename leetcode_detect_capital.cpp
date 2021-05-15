class Solution {
public:
    bool detectCapitalUse(string word){
    	int capital=0;
    	int small=0;
    	bool start=false;
    	bool middle=false;
    	for(int i=0;i<word.length();i++){
    		if(i==0 and word[i]>='A' and word[i]<='Z'){
    			start=true;
    		}
    		if(word[i]>='A' and word[i]<='Z'){
    			capital++;
    		}else if(word[i]>='a' and word[i]<='z'){
    			small++;
    		}
    		if(i!=0 and word[i]>='A' and word[i]<='Z'){
    			middle=true;
    		}
    	}
    	if(capital==word.length() or small==word.length()){
    		return true;
    	}
    	if(start and !middle){
    		return true;
    	}
    	return false;
    }
};
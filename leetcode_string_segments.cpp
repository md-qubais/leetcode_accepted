class Solution{
public:
    int countSegments(string s){
    	s+=" ";
    	string ans="";
    	int count=0;
    	for(int i=0;i<s.length();i++){
    		if(s[i]==' '){
    			if(ans.length()>0){
    				count++;
    			}
    			ans="";
    		}else{
    			ans+=s[i];
    		}
    	}
    	return count;
    }
};
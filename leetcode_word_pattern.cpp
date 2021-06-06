class Solution{
public:
    bool wordPattern(string pattern, string s){
    	unordered_map<string,char> mapping1;
    	unordered_map<char,string> mapping2;
    	vector<string> strings;
    	s+=" ";
    	string temp="";
    	for(int i=0;i<s.length();i++){
    		if(s[i]==' '){
    			strings.push_back(temp);
    			temp="";
    			continue;
    		}
    		temp+=s[i];
    	}
    	if(strings.size()!=pattern.length()){
    		
    	}
    	for(int i=0;i<pattern.length() and i<strings.size();i++){
    		if(mapping1.count(strings[i])==0){
    			if(mapping2.count(pattern[i])==0){
    				mapping1[strings[i]]=pattern[i];
    				mapping2[pattern[i]]=strings[i];
    			}else return false;
    		}else{
    			if(mapping1[strings[i]]!=pattern[i]){
    				return false;
    			}
    		}
    	}	
    	return true;
    }
};
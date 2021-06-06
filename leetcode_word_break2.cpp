class Solution {
public:
	vector<string> ans;
	unordered_map<string,bool> find;
    void wordBreak(string s, vector<string>& wordDict,int i,string asf,string temp){
    	if(i==s.length()){
    		ans.push_back(asf);
    		return;
    	}
    	for(int j=i;j<s.length();j++){
    		temp+=s[j];
    		if(find[temp]){
    			if(j+1==s.length()) wordBreak(s,wordDict,j+1,asf+temp,"");
    			else wordBreak(s,wordDict,j+1,asf+temp+" ","");
    		}
    	}
    }

    vector<string> wordBreak(string s,vector<string>&wordDict){
    	for(auto&it:wordDict){
    		find[it]=true;
    	}
    	wordBreak(s,wordDict,0,"","");
    	return ans;
    }

};
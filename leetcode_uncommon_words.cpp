class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2){
    	unordered_map<string,int> m;
    	vector<string> arr1;
    	string temp="";
    	s1+=" ";
    	for(int i=0;i<s1.length();i++){
    		if(s1[i]==' '){
    			if(temp.length()>0){
    				arr1.push_back(temp);
    				m[temp]++;
    			}
    			temp="";
    		}else{
    			temp+=s1[i];
    		}
    	}
    	vector<string> arr2;
    	temp="";
    	s2+=" ";
    	for(int i=0;i<s2.length();i++){
    		if(s2[i]==' '){
    			if(temp.length()>0){
    				arr2.push_back(temp);
    				m[temp]++;
    			}
    			temp="";
    		}else{
    			temp+=s2[i];
    		}
    	}
    	vector<string> ans;
    	for(auto&it:arr1){
    		if(m[it]==1){
    			ans.push_back(it);
    		}
    	}
    	for(auto&it:arr2){
    		if(m[it]==1){
    			ans.push_back(it);
    		}
    	}
    	return ans;
    }
};
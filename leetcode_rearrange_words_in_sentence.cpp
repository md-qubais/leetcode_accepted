bool compare(pair<string,int> s1,pair<string,int> s2){
	if(s1.first.length()==s2.first.length()){
		return s1.second<s2.second;
	}
	return s1.first.length()<s2.first.length();
}
class Solution{
public:
    string arrangeWords(string s){
    	s+=' ';
    	string temp="";
    	vector<pair<string,int>> arr;
    	for(int i=0;i<s.length();i++){
    		if(s[i]==' '){
    			arr.push_back({temp,i});
    			temp="";
    			continue;
    		}
    		temp+=s[i];
    	}
    	sort(arr.begin(),arr.end(),compare);
    	string ans="";
    	for(int i=0;i<arr.size();i++){
    		if(i==arr.size()-1){
    			ans+=arr[i].first;
    			continue;
    		}
    		ans+=arr[i].first+" ";
    	}
    	for(int i=0;i<ans.length();i++){
    		if(i==0){
    			if(ans[i]>='a' and ans[i]<='z'){
    				ans[i]-=32;
    			}
    		}else{
    			if(ans[i]>='A' and ans[i]<='Z'){
    				ans[i]+=32;
    			}
    		}
    	}
    	return ans;
    }
};
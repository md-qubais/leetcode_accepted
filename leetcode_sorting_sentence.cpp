class Solution{
public:
    string sortSentence(string s){
    	vector<pair<int,string>> p;
    	s+=' ';
    	string temp="";
    	for(int i=0;i<s.length();i++){
    		if(s[i]>='1' and s[i]<='9'){
    			string number="";
    			number+=s[i];
    			stringstream str(number);
    			int n;
    			str>>n;
    			p.push_back({n,temp});
    			temp="";
    			continue;
    		}
    		if(s[i]!=' '){
    			temp+=s[i];
    		}
    	}
    	string ans="";
    	sort(p.begin(),p.end());
    	for(int i=0;i<p.size();i++){
    		if(i==p.size()-1){
    			ans+=p[i].second;
    			continue;
    		}
    		ans+=p[i].second+" ";
    	}
    	return ans;
    }
};
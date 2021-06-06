class Solution{
public:
    string freqAlphabets(string s){
    	string ans="";
    	s+="  ";
    	for(int i=0;i<s.length()-2;i++){
    		int j=i+1;
    		if(s[i]==' '){
    			return ans;
    		}
    		if(s[j+1]=='#'){
    			string temp="";
    			while(i<j+1){
    				temp+=s[i++];
    			}
    			stringstream str(temp);
    			int n;
    			str>>n;
    			char ch=(n-1)+'a';
    			ans+=ch;
    			i=j+1;
    			continue;
    		}else{
    			string temp="";
    			temp+=s[i];
    			stringstream str(temp);
    			int n;
    			str>>n;
    			char ch=(n-1)+'a';
    			ans+=ch;
    		}
    	}
    	return ans;
    }
};
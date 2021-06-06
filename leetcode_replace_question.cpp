class Solution{
public:
	void reverse(string&s,int i,int j){
		while(i<j){
			swap(s[i++],s[j--]);
		}
	}
    string reverseWords(string s){
    	s+=" ";
    	for(int i=0;i<s.length()-1;i++){
    		int j=i;
    		while(s[j+1]!=' '){
    			j++;
    		}
    		reverse(s,i,j);
    		i=j+1;
    	}
    	reverse(s,0,s.length()-1);
    	s=s.substr(1);
    	reverse(s,0,s.length()-1);
    	return s;
    }
};
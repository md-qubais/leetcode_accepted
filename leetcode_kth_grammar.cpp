class Solution{
public:
    int kthGrammar(int n, int k,string ans=""){
    	if(n==0){
    		char ch=ans[k-1];
    		if(ch=='0'){
    			return 0;
    		}
    		return 1;
    	}
    	if(ans.length()==0){
    		return kthGrammar(n-1,k,"0");
    	}
    	string temp="";
    	for(int i=0;i<ans.length();i++){
    		if(ans[i]=='0'){
    			temp+="01";
    		}else{
    			temp+="10";
    		}
    	}
    	return kthGrammar(n-1,k,temp);
    }
};
class Solution{
public:
    string decodeAtIndex(string s, int k) {
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' and s[i]<='z'){
                ans+=s[i];
                if(ans.length()>=k){
                    string answer="";
                    answer+=ans[k-1];
                    return answer;
                }
            }else{
                int num=s[i]-'0';
                string temp=ans;
                ans="";
                while(num--){
                    ans+=temp;
                }
                if(ans.length()>=k){
                    string answer="";
                    answer+=ans[k-1];
                    return answer;
                }
            }
        }
        string answer="";
        answer+=ans[k-1];
        return answer;
    }
};
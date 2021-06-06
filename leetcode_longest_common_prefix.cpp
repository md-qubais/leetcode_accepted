class Solution{
public:
    string longestCommonPrefix(vector<string>& str){
        string ans="";
        int size=INT_MAX;
        for(int i=0;i<str.size();i++){
            int k=str[i].size();
            size=min(size,k);
        }
        for(int i=0;i<size;i++){
            int count=1;
            char ch=str[0][i];
            for(int j=1;j<str.size();j++){
                if(ch==str[j][i]){
                    count++;
                }
            }
            if(count==str.size()){
                ans+=ch;
            }else{
                return ans;
            }
        }
        return ans;
    }
};
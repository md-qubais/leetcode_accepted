class Solution {
public:
    unordered_map<string,bool> find;
    bool wordBreak(string s, vector<string>& wordDict,int i,string asf,string temp){
        if(i==s.length()){
            return true;
        }
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            if(find[temp]){
                 if(wordBreak(s,wordDict,j+1,asf+temp,"")) return true;
            }
        }
        return false;
    }

    bool wordBreak(string s,vector<string>&wordDict){
        for(auto&it:wordDict){
            find[it]=true;
        }
        return wordBreak(s,wordDict,0,"","");
    }
};
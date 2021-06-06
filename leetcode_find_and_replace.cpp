class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& arr, string pattern){
        vector<string> ans;
        for(auto&words:arr){
            unordered_map<char,char> mapped1;
            unordered_map<char,char> mapped2;
            int i=0;
            int j=0;
            bool b=true;
            for(;i<words.length() and j<pattern.length();i++,j++){
                if(mapped1.count(words[i])==0){
                    if(mapped2.count(pattern[j])==0){
                        mapped1[words[i]]=pattern[j];
                        mapped2[pattern[j]]=words[i];
                    }else{
                        b=false;
                        break;
                    }
                }else{
                    if(mapped1[words[i]]==pattern[j] and mapped2[pattern[j]]==words[i]){

                    }else{
                        b=false;
                    }
                }
            }
            if(i==words.length() and j==words.length() and b){
                ans.push_back(words);
            }
        }
        return ans;
    }
};
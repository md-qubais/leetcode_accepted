class Solution{
public:
    bool areSentencesSimilar(string s1, string s2){
        vector<string> str1;
        vector<string> str2;
        string temp="";
        for(int i=0;i<s1.length();i++){
            if(s1[i]==' '){
                if(temp.length()>0){
                    str1.push_back(temp);
                }
                temp="";
                continue;
            }
            temp+=s1[i];
        }
        if(temp.length()>0) str1.push_back(temp);
        temp="";
        for(int i=0;i<s2.length();i++){
            if(s2[i]==' '){
                if(temp.length()>0){
                    str2.push_back(temp);
                }
                temp="";
                continue;
            }
            temp+=s2[i];
        }
        if(temp.length()>0) str2.push_back(temp);
        if(str1.size()<str2.size()){
            swap(str1,str2);
        }
        int start=0;
        while(str1[start]==str2[start]){
            start++;
        }
        int end1=str1.size();
        int end2=str2.size();
        while(str1[end1]==str2[end2]){
            end2--;
            end1--;
        };
        vector<string> ans;
        for(int i=0;i<start;i++){
            ans.push_back(str2[i]);
        }
        for(int i=start;i<=end1){

        }
        return true;
    }
};
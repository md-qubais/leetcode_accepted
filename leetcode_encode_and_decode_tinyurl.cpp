class Solution{
public:
    unordered_map<int,string> mapping;
    string start="https://";
    string encode(string s){
        int count=1;
        string temp="";
        s+='/';
        for(int i=8;i<s.length();i++){
            if(s[i]=='/'){
                if(temp.length()>0){
                    mapping[count++]=temp;
                }
                temp="";
                continue;
            }
            temp+=s[i];
        }
        string ret="";
        ret+=start+mapping[count-1]+"/"+to_string(count);
        return ret;
    }

    string decode(string s){
        int i=s.length();
        string num="";
        while(s[i]!='/'){
            num=s[i]+num;
        }
        stringstream str(num);
        int n;
        str>>n;
        string ans="";
        ans+=start;
        i=1;
        while(i<n){
            ans+=mapping[i++];
        }
        return ans;
    }
};
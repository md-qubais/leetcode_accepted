class Solution{
public:
    string maxValue(string s, int x){
        bool neg=false;
        string target="";
        target+=(x+'0');
        if(s[0]=='-'){
            neg=true;
            s=s.substr(1);
        }
        if(neg){
            bool b=false;
            for(int i=0;i<s.length();i++){
                if(s[i]>target[0]){
                    b=true;
                    if(i>0){
                        s.insert(i,target);
                        break;
                    }else{
                        s.insert(0,target);
                        break;
                    }
                }
            }
            if(!b){
                s+=target;
            }
            return "-"+s;
        }else{
            bool b=false;
            for(int i=0;i<s.length();i++){
                if(s[i]<target[0]){
                    b=true;
                    if(i==s.length()-1){
                        s=s+target;
                        break;
                    }else{
                        s.insert(i,target);
                        break;
                    }
                }
            }
            if(!b){
                s+=target;
            }
        }      
        return s;
    }
};
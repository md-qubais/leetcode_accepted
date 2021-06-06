class Solution{
public:
    bool isAdditiveNumber(string num,int i=0,long long int first=-1,long long int second=-1,long long int third=-1){
        string temp="";
        for(int j=i;j<num.length();j++){
            temp+=num[j];
            if(temp.length()>1 and temp[0]=='0'){
                return false;
            }
            if(first==-1){
                stringstream str(temp);
                long long int n;
                str>>n;
                if(isAdditiveNumber(num,j+1,n,second,third)){
                    return true;
                }
            }else if(second==-1){
                stringstream str(temp);
                long long int n;
                str>>n;
                if(isAdditiveNumber(num,j+1,first,n,third)){
                    return true;
                }
            }else if(third==-1){
                stringstream str(temp);
                long long int n;
                str>>n;
                if(n==first+second){
                    if(j==num.length()-1){
                        return true;
                    }
                    if(isAdditiveNumber(num,j+1,second,n,-1)){
                        return true;
                    }
                    return false;
                }else if(third<first+second){
                    continue;
                }else if(third>first+second){
                    return false;
                }
            }
        }
        return false;
    }
};
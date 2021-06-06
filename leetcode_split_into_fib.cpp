class Solution{
public:
    deque<int> ans;
    bool splitIntoFibonacci(string num,int i,long long int first,long long int second,long long int third,deque<int> arr){
        string temp="";
        if(first!=(int)first){
            return false;
        }
        if(second!=(int)second){
            return false;
        }
        if(third!=(int)third){
            return false;
        }
        for(int j=i;j<num.length();j++){
            temp+=num[j];
            if(temp.length()>1 and temp[0]=='0'){
                return false;
            }
            if(first==-1){
                stringstream str(temp);
                long long int n;
                str>>n;
                arr.push_back(n);
                if(splitIntoFibonacci(num,j+1,n,second,third,arr)){
                    return true;
                }
                arr.pop_back();
            }else if(second==-1){
                stringstream str(temp);
                long long int n;
                str>>n;
                arr.push_back(n);
                if(splitIntoFibonacci(num,j+1,first,n,third,arr)){
                    return true;
                }
                arr.pop_back();
            }else if(third==-1){
                stringstream str(temp);
                long long int n;
                str>>n;
                arr.push_back(n);
                if(n==(first+second)){
                    if(j==num.length()-1){
                        ans=arr;
                        return true;
                    }
                    if(splitIntoFibonacci(num,j+1,second,n,-1,arr)){
                        return true;
                    }
                    return false;
                }else if(third<first+second){
                    arr.pop_back();
                    continue;
                }else if(third>first+second){
                    return false;
                }
                arr.pop_back();
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num){
        deque<int> result;
        vector<int> temp;
        if(splitIntoFibonacci(num,0,-1,-1,-1,result)){
            while(!ans.empty()){
                if(ans.front()<0){
                    temp.clear();
                    return temp;
                }
                temp.push_back(ans.front());
                ans.pop_front();

            }
            return temp;
        }
        return temp;
    }
};

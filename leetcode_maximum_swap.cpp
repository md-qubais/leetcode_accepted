class Solution {
public:
    int maximumSwap(int num){
        string n=to_string(num);
        int max_index=-1;
        int max_val=INT_MIN;
        int min_index=-1;
        int min_val=INT_MAX;
        for(int i=0;i<n.length();i++){
            if((n[i]-'0')>max_val){
                max_val=n[i]-'0';
                max_index=i;
            }
            if((n[i]-'0')<min_val){
                min_val=n[i]-'0';
                min_index=i;
            }
        }
        if(min_index!=-1 and max_index!=-1 and min_index<max_index){
            swap(n[min_index],n[max_index]);
        }
        stringstream str(n);
        int ans;
        str>>ans;
        return ans;
    }
};
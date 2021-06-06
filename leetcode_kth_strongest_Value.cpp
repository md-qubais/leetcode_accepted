int m;
bool compare(int n1,int n2){
    if(abs(n1-m)==abs(n2-m)){
        return n1>n2;
    }
    return abs(n1-m)>abs(n2-m);
}
class Solution{
public:
    vector<int> getStrongest(vector<int>& arr, int k){
        int median=arr[(arr.size()-1)/2];
        m=median;
        sort(arr.begin(),arr.end(),compare);
        arr.erase(arr.begin()+k,arr.end());
        return arr;
    }
};
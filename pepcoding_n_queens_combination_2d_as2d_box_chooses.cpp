#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define pb push_back
#define p push
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
void queens_box_ch_combination(int n,int i=0,int j=0,int asf=0,string ans=""){
  if(j==n){
    if(asf==n){
      for(int i=0;i<ans.length();i++){
        if(i!=0 and i%n==0){
          cout<<endl;
        }
        cout<<ans[i];
      }
      cout<<endl;
      cout<<endl;
    }
    return;
  }
  if(i==n){
    queens_box_ch_combination(n,0,j+1,asf,ans);
    return;
  }
  queens_box_ch_combination(n,i+1,j,asf+1,ans+"q");
  queens_box_ch_combination(n,i+1,j,asf,ans+'-');
}
int32_t main(){
  qubais_judge;
  IOS;
  int n;
  cin>>n;
  queens_box_ch_combination(n);
  return 0;
}
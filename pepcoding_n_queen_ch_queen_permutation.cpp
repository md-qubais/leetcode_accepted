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
int chess[1000][1000];

void queen_ch_permutation(int n,int asf=0){
	if(asf==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(chess[i][j]==0){
					cout<<"-\t";
				}else if(chess[i][j]==1){
					cout<<"q1\t";
				}else if(chess[i][j]==2){
					cout<<"q2\t";
				}else if(chess[i][j]==3){
					cout<<"q3\t";
				}else if(chess[i][j]==4){
					cout<<"q4\t";
				}
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(chess[i][j]==0){
				chess[i][j]=asf+1;
				queen_ch_permutation(n,asf+1);
				chess[i][j]=0;
			}
		}
	}

}

int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	queen_ch_permutation(n);
	return 0;
}
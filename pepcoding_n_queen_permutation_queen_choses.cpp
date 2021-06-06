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
using namespace std;
int chess[1000][1000];
    bool IsQueenSafe(int row, int col,int n) {
        /*
        //up
        for(int i=row,j=col;i>=0;i--){
        	if(chess[i][j]){
        		return false;
        	}
        }
        //down
        for(int i=row,j=col;i<n;i++){
        	if(chess[i][j]){
        		return false;
        	}
        }
        //left
        for(int i=row,j=col;j>=0;j--){
        	if(chess[i][j]){
        		return false;
        	}
        }
        //right
        for(int i=row,j=col;j<n;j++){
        	if(chess[i][j]){
        		return false;
        	}
        }
        //left up diagonal
        for(int i=row,j=col;i>=0 and j>=0;i--,j--){
        	if(chess[i][j]){
        		return false;
        	}
        }

        //left down diagonal
        for(int i=row,j=col;i<n and j>=0;i++,j--){
        	if(chess[i][j]){
        		return false;
        	}
        }
        //right up diagonal
        for(int i=row,j=col;i>=0 and j<n;i--,j++){
        	if(chess[i][j]){
        		return false;
        	}
        }
        //right down diagonal
        for(int i=row,j=col;i<n and j<n;i++,j++){
        	if(chess[i][j]){
        		return false;
        	}
        }*/
        int dir[100][100]={
            {-1,0},
            {-1,-1},
            {0,1},
            {1,1},
            {1,0},
            {1,-1},
            {0,-1},
            {-1,-1}
        };
        if(chess[row][col]){
            return false;
        }
        for(int r=1;r<=n;r++){
            for(int i=0;i<8;i++){
                int nr=row+dir[i][0]*r;
                int nc=col+dir[i][1]*r;
                if(nr>=0 and nr<n and nc>=0 and nc<n){
                    if(chess[nr][nc]){
                        return false;
                    }
                }
            }
        }
        return true;
}

void n_queen_permutation(int n,int asf=0){
	if(asf==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(chess[i][j]==0){
					cout<<"-\t";
					continue;
				}
				if(chess[i][j]==1){
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
			if(IsQueenSafe(i,j,n)){
				chess[i][j]=asf+1;
				n_queen_permutation(n,asf+1);
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
	n_queen_permutation(n);
	return 0;
}
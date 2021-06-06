#include<bits/stdc++.h>
#define IOS    ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int   long long
#define endl  "\n"
using namespace std;
//implementing the hashmap
//seperate chaining
class Node{
public:
	int val;
	string key;
	Node *next;
	Node(string key,int val){
    this->key=key;
    this->val=val;
    next=NULL;
	}
	~Node(){
		if(next!=NULL){
           delete next;
           //here entire linked list chain will be
           //deleted recursively
		}
	}
};
template<typename T>
class Hashtable{
	Node** table;//pointer to array of pointers
	int curr_size;
	int table_size;
public:
	Hashtable(int tb=7){
		this->table_size=tb;
		table=new Node*[table_size];
		curr_size=0;
		for(int i=0;i<table_size;i++){
            table[i]=NULL;
            //initializing the array of pointers
            //to null that means there is nothing
            //and no element is pointing to it
		}
	}
	//here this is the below method
	//for rehashing
	void rehash(){
    Node** oldtable=table;
    int oldtable_size=table_size;
    table_size=2*table_size+1;
    table=new Node*[table_size];
    for(int i=0;i<table_size;i++){
    	table[i]=NULL;
    }
    curr_size=0;
    //now here comes the most expensive operation
    //it is known as the shifting the values of the table
    for(int i=0;i<oldtable_size;i++){
      Node*temp=oldtable[i];
      while(temp){
         insert(temp->key,temp->val);
         curr_size++;
         temp=temp->next;
      }
      if(oldtable[i]!=NULL){
           delete oldtable[i];
      }
    }
    delete []oldtable;
	}
    int hashfun(string key){
           int res=0;
           int p=1;
           for(int j=0;j<key.length();j++){
              res=res+(key[j]*p)%table_size;
              res=res%table_size;
              p=(p*27)%table_size;
              //here we are doing mod again
              //and again because if the values
              //is very bigger and it would go out
              //of the range and no data type can hold 
              //that valu so we are using the mod
              //again and again
              //(a+b+c)%m=(a%m+b%m+c%m)%m
           }
           return res;
    }
    void print(){
    	for(int i=0;i<table_size;i++){
            cout<<"Bucket "<<i<<"->";
            Node*n=table[i];
            while(n){
               cout<<n->key<<" "<<n->val<<endl;
               n=n->next;
            }
            cout<<endl;
    	}
    }
       T* search(string key){
             int idx=hashfun(key);
              Node*temp=table[idx];
              while(temp){
              	if(temp->key==key){
                   return &temp->val;
              	}
              	temp=temp->next;

              }
              return NULL;

       }

       void erase(string key){
          Node<T>*temp=table[hashfun(key)],*p;
          p=temp->next;
          //in that case if the key is present in the
          //head it self
          if(temp->key==key){
          	table[hashfun(key)]=temp->next;
          }else{
          	while(p->key!=key){
          		temp=p;
          		p=p->next;
          	}
          	temp->next=p->next;

          	delete p;
          }         
       }

//here we are overloading the operator
       //just dont get confused here 
       //T is integer type and *T means interger pointer
       T& operator[](string key){
       	T* f=search(key);
       	if(f==NULL){
       		T garbage;
       		insert(key,garbage);
           f=search(key);
       	}
        return *f;
       }



	void insert(string key,int val){
		int idx=hashfun(key);
		Node<T>*n=new Node<T>(key,val);
		//below two statements are functional
		//and they are inserting at the head of the
		//table
		//not at the table
		//if confused trace by putting the different
		//value in the same index in the table with 
		//with different values
		n->next=table[idx];
		table[idx]=n;
		curr_size++;
		/*float loadfactor=(1.0*curr_size)/(1.0*table_size);
		if(loadfactor>0.75){
			//here we are rehashing the table
               rehash();
		}*/
	}
};


int32_t main(){
	#ifndef qubais_judge
	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
	#endif
	IOS;
	Hashtable<string> h;
	while(true){
		string s;
		cin>>s;
		if(s=="quit"){
			return 0;
		}
		if(s=="put"){
			string key;
			cin>>key;
			int val;
			cin>>val;
			h.insert(key,val);
			continue;
		}
		if(s=="display"){
			continue;
		}
		if(s=="remove"){
			continue;
		}
		if(s=="containsKey"){
			string key;
			cin>>key;
			if(h.search(key)){
				cout<<"true"<<endl;
			}else{
				cout<<"false";
			}
		}
	}
    return 0;     
}
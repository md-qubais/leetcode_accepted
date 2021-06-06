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

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
    if(!l1){
        return l2;
    }
    if(!l2){
        return l1;
    }
    ListNode*head=NULL;
    ListNode*tail=NULL;
    while(l1 and l2){
        if(l1->val<l2->val){
            ListNode*preserve=l1->next;
            if(!head){
                head=l1;
                tail=head;
            }else{
                tail->next=l1;
                tail=l1;
            }
            l1->next=l2;
            l1=preserve;
        }else{
            ListNode*preserve=l2->next;
            if(!head){
                head=l2;
                tail=head;
            }else{
                tail->next=l2;
                tail=l2;
            }
            l2->next=l1;
            l2=preserve;
        }
    }
    if(l1){
        tail->next=l1;
    }
    if(l2){
        tail->next=l2;
    }
    return head;
}
void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int32_t main(){
    qubais_judge;
    IOS;
    int n, m;
    cin >> n ;
    ListNode *h1 = createList(n);
    cin >> m;
    ListNode *h2 = createList(m);
    ListNode *head = mergeTwoLists(h1, h2);
    printList(head);
    return 0;
}
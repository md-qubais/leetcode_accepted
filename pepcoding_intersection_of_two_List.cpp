
#include <iostream>
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

int lengthOfLL(ListNode *node)
{
    if (node == nullptr)
        return 0;

    int len = 0;
    while (node != nullptr)
    {
        node = node->next;
        len++;
    }

    return len;
}

ListNode *IntersectionNodeInTwoLL(ListNode *head1, ListNode *head2){
    if(!head1 or !head2){
        return NULL;
    }
    ListNode*temp=head1;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=head2;
    ListNode*head=head1;
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast and fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            break;
        }
    }
    if(fast!=slow){
        return nullptr;
    }
    while(head!=fast){
        head=head->next;
        fast=fast->next;
    }
    return head;
}



ListNode *makeList(int n)
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

int main()
{
    int n,idx;
    cin >> n;
    ListNode *head1 = makeList(n);
    cin >> idx;
    
    int m;
    cin >> m;
    ListNode *head2 = makeList(m);

    if (idx >= 0)
    {
        ListNode *curr = head1;

        while (idx-- > 0)
            curr = curr->next;

        ListNode *prev = head2;
        while (prev->next != nullptr)
            prev = prev->next;

        prev->next = curr;
    }

    ListNode *ans = IntersectionNodeInTwoLL(head1, head2);
    cout << (ans != nullptr ? ans->val : -1) << endl;
    return 0;
}


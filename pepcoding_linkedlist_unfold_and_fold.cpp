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

ListNode *midNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        ListNode *forw = curr->next; // backup

        curr->next = prev; // link

        prev = curr; // move
        curr = forw;
    }

    return prev;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    l1 = reverseList(l1);
    l2 = reverseList(l2);

    ListNode *head = new ListNode(-1); //dummy.
    ListNode *itr = head;

    int borrow = 0;
    while (l1 != nullptr || l2 != nullptr)
    {
        int diff = borrow + (l1 != nullptr ? l1->val : 0) - (l2 != nullptr ? l2->val : 0);

        if (diff < 0)
        {
            diff += 10;
            borrow = -1;
        }
        else
            borrow = 0;

        itr->next = new ListNode(diff);
        itr = itr->next;

        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }

    return reverseList(head->next);
}

// Input_code===================================================

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

int main()
{
    int n;
    cin >> n;
    ListNode *head1 = makeList(n);

    int m;
    cin >> m;
    ListNode *head2 = makeList(m);

    ListNode *head = addTwoNumbers(head1, head2);
    printList(head);

    return 0;
}
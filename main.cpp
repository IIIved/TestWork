#include <iostream>

using namespace std;

struct ListNode {
    ListNode() {
    }

    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



void push(ListNode* &begin, int val)
{
    ListNode *lst = begin;
    if(begin == nullptr)
        begin = new ListNode(val);
    else
    {
        while(lst->next != nullptr)
            lst = lst->next;
        lst->next = new ListNode(val);
    }
}

void print(ListNode* &begin)
{
    ListNode *lst = begin;
    while(lst->next != nullptr)
    {
        cout << lst->val << ", ";
        lst = lst->next;
    }
    cout << lst->val << " ";
    cout << endl;
}

void pushFront(ListNode* &head, int value)
{

    ListNode *ptr = new ListNode();
    ptr -> val = value;

    ptr -> next = head;
    head = ptr;


}

class Solution {
public:
    ListNode* reverseList1(ListNode* head) {
        ListNode *prevNode = nullptr;
        ListNode *currentNode = head;
        ListNode *nextNode = head->next;

        while(nextNode != nullptr)
        {
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
            nextNode = currentNode->next;
        }
        currentNode->next = prevNode;
        head = currentNode;
        return head;
    }

    ListNode* reverseList2(ListNode* node) {
        if(node == nullptr) {
            return nullptr;
        }

        if (node->next == nullptr) {
            head = node;
            return node;
        }

        ListNode* node_ = reverseList2(node->next);
        node_->next = node;
        node->next = nullptr;

        return node;
    }

private:
    ListNode* head = nullptr;
};


int main()
{
    //В данном коде присутствует функция push и pushFront
    //Рекурсивную инверсию не получилось сделать, т.к. особо еще не понимаю, как его связать с классом.
    //Со структурами, без класса, все получается.

    ListNode* begin = nullptr;
    Solution solution;
    pushFront(begin,5);
    pushFront(begin,3);
    pushFront(begin,7);
    pushFront(begin,9);

    print(begin);

    begin = solution.reverseList1(begin);

    print(begin);

    return 0;
}

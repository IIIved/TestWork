#include <iostream>

using namespace std;

struct ListNode
{
    ListNode* next = nullptr;
    int value = 0;
};

class Solution {
public:
ListNode* head;
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

        if(node->next = nullptr) {
            head = node;
            return node;
        }

        ListNode* node_ = reverseList2(node->next);
        node_->next = node;
        node->next = nullptr;

        return node;
    }

    ListNode* push(ListNode* &head, int val)
    {
        ListNode *lst = head;
        if(head == nullptr)
        {
            head = new ListNode();
            head->value = val;
            return head;
        }
        else
        {
            while(lst->next != nullptr)
                lst = lst->next;
            lst->next = new ListNode();
            lst->next->value = val;
        }
        return lst->next;
    }

    void print(ListNode* &begin)
    {
        ListNode *lst = begin;
        while(lst->next != nullptr)
        {
            cout << lst->value << ", ";
            lst = lst->next;
        }
        cout << lst->value << " ";
        cout << endl;
    }
};



int main()
{
    Solution *head;
    head = nullptr;

    return 0;
}
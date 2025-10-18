
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
private:
    static bool isItemInSet(const std::unordered_set<ListNode*>& items, ListNode* item)
    {
        return items.find(item) != items.end();
    }
public:

    void PrintList(ListNode* list1)
    {
        ListNode* ptr = list1;
        while (ptr != nullptr)
        {
            std::cout << ptr->val << " ";
            ptr = ptr->next;
        }
    }

    ListNode* detectCycle(ListNode* head)
    {
        std::unordered_set<ListNode*> node_addresses;
        ListNode* ptr = head;
        while (ptr != nullptr)
        {
         
            if (isItemInSet(node_addresses, ptr))
                return ptr;
            node_addresses.insert(ptr);
            ptr = ptr->next;
        }
        return nullptr;
    }
};

int main()
{
    ListNode ln11(4);
    ListNode ln12(3, &ln11);
    ListNode ln13(2, &ln12);
    ListNode ln14(1, &ln13);

    //make cycle
    ln11.next = &ln14;

    ListNode ln21(1);
    ListNode ln22(2, &ln21);
    ListNode ln23(4, &ln22);
    ListNode ln24(4, &ln23);
    ListNode ln25(5, &ln24);

    Solution s;
    //s.PrintList(&ln14);
    std::cout << s.detectCycle(&ln14)->val;
    std::cout << std::endl;
    //s.PrintList(&ln25);
    if(s.detectCycle(&ln25))
        std::cout << s.detectCycle(&ln25)->val;
    std::cout << std::endl;

    //s.PrintList(s.mergeTwoLists(nullptr, nullptr));
}


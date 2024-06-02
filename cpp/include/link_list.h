#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <cstddef>
#include <vector>
#include <optional>
#include <nlohmann/json.hpp>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *create_linked_list(const vector<int> &vec)
{
    ListNode *head = nullptr;
    ListNode *current = nullptr;
    for (int i = 0; i < vec.size(); i++)
    {
        if (head == nullptr)
        {
            head = new ListNode(vec[i]);
            current = head;
        }
        else
        {
            current->next = new ListNode(vec[i]);
            current = current->next;
        }
    }
    return head;
}

#endif
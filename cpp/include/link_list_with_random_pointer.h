#ifndef LINK_LIST_WITH_RANDOM_POINTER_H
#define LINK_LIST_WITH_RANDOM_POINTER_H

#include <cstddef>
#include <vector>
#include <optional>
#include <nlohmann/json.hpp>

using namespace std;
using namespace nlohmann;

class Node
{
public:
    int val;
    int index;
    Node *next;
    Node *random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
    Node(int _val, int _index) : val(_val), index(_index), next(nullptr), random(nullptr) {}
};

Node *create_linked_list_with_random_pointer(
    const vector<int> &vec,
    const vector<optional<int>> &random_indices)
{
    Node *head = nullptr;
    Node *current = nullptr;
    vector<Node *> nodes;
    for (int i = 0; i < vec.size(); i++)
    {
        nodes.push_back(new Node(vec[i], i));
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if (head == nullptr)
        {
            head = nodes[i];
            current = head;
        }
        else
        {
            current->next = nodes[i];
            current = current->next;
        }
    }
    for (int i = 0; i < random_indices.size(); i++)
    {
        if (random_indices[i].has_value())
        {
            nodes[i]->random = nodes[random_indices[i].value()];
        }
    }
    return head;
}

Node *create_linked_list_with_random_pointer(
    const vector<vector<json::value_type>> &vec)
{
    vector<int> values;
    vector<optional<int>> random_indices;
    for (int i = 0; i < vec.size(); i++)
    {
        values.push_back(vec[i][0]);
        random_indices.push_back(vec[i][1].is_null() ? nullopt : optional<int>(vec[i][1]));
    }
    return create_linked_list_with_random_pointer(values, random_indices);
}

void rebuild_linked_list_with_random_pointer_index(Node *head)
{
    int index = 0;
    bool is_rebuilt = false;
    while (head != nullptr)
    {
        if (head->index != index)
        {
            is_rebuilt = true;
        }
        head->index = index;
        head = head->next;
        index++;
    }
    if (!is_rebuilt)
    {
        cout << "Linked list didn't need to be rebuilt, which is unexpected." << endl;
        cout << "It's very likely that nodes was not copied but a reference to the original one." << endl;
    }
}

vector<vector<json::value_type>>
get_linked_list_with_random_pointer_vector_json(Node *head)
{
    rebuild_linked_list_with_random_pointer_index(head);

    vector<vector<json::value_type>> result;
    while (head != nullptr)
    {
        vector<json::value_type> node;
        node.push_back(head->val);
        if (head->random == nullptr)
        {
            node.push_back(nullptr);
        }
        else
        {
            node.push_back(head->random->index);
        }
        result.push_back(node);
        head = head->next;
    }
    return result;
}

#endif
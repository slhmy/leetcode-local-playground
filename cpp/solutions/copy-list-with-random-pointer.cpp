// Source: https://leetcode.com/problems/copy-list-with-random-pointer/
// Tags: linked-list

#include <iostream>
#include <optional>

#include <json_input_helper.h>
#include <json_output_helper.h>
#include <nlohmann/json.hpp>

#include <link_list_with_random_pointer.h>

using namespace std;

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        // Create a new node between it's original node and following node
        // Node1 -> Node1' -> Node2 -> Node2' -> Node3 -> Node3' -> ...
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            Node *nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }

        // Set random pointer for the new nodes
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            Node *nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }

        // Separate the new nodes from the original nodes
        Node *headNew = head->next;
        for (Node *node = head; node != nullptr; node = node->next)
        {
            Node *nodeNew = node->next;
            node->next = node->next->next; // Restore the original list
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }

        return headNew;
    }
};

int main()
{
    cout << "copy-list-with-random-pointer" << endl;
    auto head_vec = read_vector_from_json_str<vector<nlohmann::json::value_type>>();
    auto head = create_linked_list_with_random_pointer(head_vec);

    Solution solution;
    auto new_head = solution.copyRandomList(head);

    auto new_head_vec = get_linked_list_with_random_pointer_vector_json(new_head);
    print_vector_as_json(new_head_vec);
}

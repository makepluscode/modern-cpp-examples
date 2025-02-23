#include <iostream>
#include <memory>

class Node {
public:
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;  // Use weak_ptr to prevent circular reference

    Node() {
        std::cout << "Node Constructor" << std::endl;
    }
    ~Node() {
        std::cout << "Node Destructor" << std::endl;
    }
};

int main() {
    // Create two nodes
    auto node1 = std::make_shared<Node>();
    auto node2 = std::make_shared<Node>();

    // Create a circular reference
    node1->next = node2;
    node2->prev = node1;  // Use weak_ptr to avoid circular reference

    // At this point, node1 and node2 can be properly destroyed
    return 0;
}

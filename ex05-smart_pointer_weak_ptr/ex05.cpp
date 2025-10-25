#include <iostream>
#include <memory>

class Node {
public:
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;  // Use weak_ptr to prevent circular reference
                                // weak_ptr을 사용하여 순환 참조 방지

    Node() {
        std::cout << "Node Constructor" << std::endl;
    }
    ~Node() {
        std::cout << "Node Destructor" << std::endl;
    }
};

int main() {
    // Create two nodes
    // 두 개의 node 생성
    auto node1 = std::make_shared<Node>();
    auto node2 = std::make_shared<Node>();

    // Create links between nodes
    // Node 간의 link 생성
    node1->next = node2;
    node2->prev = node1;  // Use weak_ptr to avoid circular reference
                          // weak_ptr을 사용하여 순환 참조 방지

    // At this point, node1 and node2 can be properly destroyed
    // When the function ends, both nodes will be correctly deallocated
    // 이 시점에서 node1과 node2는 올바르게 파괴될 수 있습니다
    // 함수가 종료되면 두 node 모두 올바르게 할당 해제됩니다
    return 0;
}

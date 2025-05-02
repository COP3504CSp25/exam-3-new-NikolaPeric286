#pragma once
#include <stack>
#include <queue>
struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    void addHead(const int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    
    LinkedList reverseList() const {
        if (head == nullptr){
            return LinkedList();
        }
        if(head->next == nullptr){
            return *this;
        }
        std::queue<Node*> node_queue; 
        LinkedList return_List;

        Node* search_head = head;
        size_t iter_count = 0;
        while( search_head != nullptr && iter_count < 100){
            node_queue.push(search_head);
            search_head = search_head->next;
            iter_count++;
        }
        iter_count = 0;
        while ( !node_queue.empty() && iter_count < 100){
            return_List.addHead( node_queue.front()->data);
            node_queue.pop();
            iter_count++;
        }
    
        return return_List;


    }

    Node* head = nullptr;
};

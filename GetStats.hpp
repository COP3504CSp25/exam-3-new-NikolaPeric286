#pragma once
#include <iostream>
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

    int* getStats() const{
        int* return_array = new int[3];

        if (head == nullptr){
            return_array[0] = 0;
            return_array[1] = 0;
            return_array[2] = 0;
            return return_array;
        }
        
        int node_count = 0;
        Node* search_head = head;
        int sum = 0;
        int min = head->data;
        int max = head->data;
        size_t iter_count = 0;
        while (search_head != nullptr && iter_count < 1000){
            
            sum += search_head->data;
            if (search_head->data > max){
                max = search_head->data;
            }
            if(search_head->data < min){
                min = search_head->data;
            }
            node_count++;
            search_head = search_head->next;
            iter_count++;
        }
        //[min, max, mean]
        std::cout << "Data collected\n";
        return_array[0] = min;
        return_array[1] = max;
        return_array[2] = sum/node_count;

        return return_array;
    }
    

private:
    Node* head = nullptr;
};

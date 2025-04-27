#pragma once
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
        int sum = 0;
        int min = 0;
        int max = 0;
        int node_count = 0;
        Node* search_head = head;

        while (search_head != nullptr){
            sum += search_head->data;
            if (search_head->data > max){
                max = search_head->data;
            }
            if(search_head->data < min){
                min = search_head->data;
            }
            node_count++;
            search_head = head->next;
        }
        //[min, max, mean]
        return_array[0] = min;
        return_array[1] = max;
        return_array[2] = sum/node_count;

    }
    

private:
    Node* head = nullptr;
};

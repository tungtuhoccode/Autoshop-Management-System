
#include "RepairList.h"

RepairList::RepairList(){
    head = NULL;
    tail = NULL;
}

RepairList::~RepairList(){
    while(head != NULL){
        Node* firstNode = head;
        head = head->next;
        delete firstNode->data;
        delete firstNode;
    }
}

void RepairList::add(Repair* repair){
    Node* nextNode = new Node; 
    nextNode->data = repair;
    nextNode->next = NULL;

    if(head == NULL){
        head = nextNode;
        tail = nextNode;
    }else{
        tail->next = nextNode;
        tail = nextNode;
    }   
}

Repair* RepairList::getNext(){
    if(head == NULL){
        return NULL;
    }else{
        Repair* repair = head->data;
        Node* firstNode = head;
        head = head->next;
        delete firstNode;
        return repair;
    }
        
}   

bool RepairList::isEmpty() const{
    return head == NULL;
}

int RepairList::size() const{
    int count = 0;
    Node* curNode = head;
    while(curNode != NULL){
        count++;
        curNode = curNode->next;
    }
    return count;
}

void RepairList::print() const{
    Node* curNode = head;
    while(curNode != NULL){
        curNode->data->print();
        curNode = curNode->next;
    }
}
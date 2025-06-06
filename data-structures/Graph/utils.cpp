#include<bits/stdc++.h>
#include "utils.h"

llNode::llNode(int x){
    val = x;
    next = NULL;
}

LinkedList::LinkedList(llNode* hp){
    head = hp;
}

void LinkedList::insert(int value){
    llNode* newNode = new llNode(value);
    llNode* curr = head;

    if(curr == NULL)
        head = newNode;

    else{
        while(curr->next != NULL){
            curr = curr->next;
        }

         curr->next = newNode;
    }
}

void LinkedList::del(int value){
    llNode* curr = head;
    llNode* prev = head;

    while(curr != NULL){
        if(curr->val == value)
            break;
                
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL)
        return;

    else if(prev == curr)
        head = NULL;
            
    else if(prev == head)
        head = curr;
            
    else{
        prev->next = prev->next->next;
        curr->next = NULL;
    }
}
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;

    while(curr != NULL && curr->val == val){
        head = head->next;
        free(curr);
        curr = head;
    }

    while(curr != NULL){
        if(curr->val == val){
            prev->next=curr->next;
            free(curr);
            curr = prev->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;  
    struct ListNode* current = head;  
    struct ListNode* next = NULL;  

    while (current != NULL) {
        next = current->next;  
        current->next = prev;   
        prev = current;  
        current = next;  
    }

    return prev;  
}



    
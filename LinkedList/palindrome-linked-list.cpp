/*
  Question : https://leetcode.com/problems/palindrome-linked-list/
  Palindrome Linked List
  Given the head of a singly linked list, return true if it is a palindrome.
  
  Solution :
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* reverseList(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *ptr = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ptr;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverseList(slow);
        while(slow != NULL){
            if(slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};

// https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1
// Delete N nodes after M nodes of a linked list


class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        Node* temp = head;
        
        while (temp) {
            for (int i = 1; i < m && temp; i++) {
                temp = temp->next;
            }
            if (!temp) break;
            
            Node* current = temp->next;
            for (int i = 0; i < n && current; i++) {
                Node* toDelete = current;
                current = current->next;
                delete toDelete;
            }
            
            temp->next = current;
            temp = current;
        }
        
        return head;
    }
};
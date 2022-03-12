/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node *ptr=head; 
        while(ptr)
        {
            Node *temp=new Node(ptr->val);
            temp->next=ptr->next;
            ptr->next=temp;
            ptr=temp->next;
        }
        Node *head1=head->next;
        ptr=head;
        Node *temp=head->next;
        while(ptr)
        {
            temp->random=ptr->random==NULL?NULL:ptr->random->next;
            ptr=temp->next;
            temp=ptr==NULL?NULL:ptr->next;
        }
        ptr=head;
        temp=ptr->next;
        while(ptr)
        {
            ptr->next=temp->next;
            if(ptr->next)
                temp->next=ptr->next->next;
            else
                temp->next=NULL;
            ptr=ptr->next;
            temp=temp->next;
        }
        return head1;
    }
};

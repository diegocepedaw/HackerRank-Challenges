/*
   Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

   A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
 */

bool has_cycle(Node* head) {
        // Complete this function
        // Do not write the main method
        Node * oneS = head;
        Node * twoS = head;
        if(head == NULL )
                return false;
        if(head->next == NULL)
                return false;
        if(head->next->next == NULL )
                return false;

        while(true)
        {
                oneS = oneS->next;
                twoS = twoS->next->next;

                if(twoS == oneS)
                        return true;
                if(twoS->next == NULL)
                        return false;
                if(twoS->next->next == NULL )
                        return false;



        }

}

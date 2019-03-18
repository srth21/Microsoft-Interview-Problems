#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *next;
};

typedef struct node Node;

void append(Node** head, int data) 
{ 
    Node* temp = (Node*) malloc(sizeof(Node)); 
  
    Node *last = *head;
  
    temp->data  = data; 
    temp->next = NULL; 
  
    if (*head == NULL) 
    { 
       *head = temp; 
       return; 
    } 
  
    while (last->next != NULL)
    {
    	last = last->next;
    } 
         
  
    last->next = temp; 
    
    return; 
} 

void printList(Node *head)
{
	Node *temp = head;

	while(temp)
	{
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("END\n");
}

Node * reverse(Node *head)
{
    Node *curr, *next, *prev;

    curr = head;
    next = NULL;
    prev = NULL;

    int i =0;

    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

        i++;
    }

    return prev;
}

Node * middleElement(Node *head)
{
    Node *slow, *fast;
    slow = head;
    fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next; 
    }

    return slow;
}


int main()
{
    Node *head = NULL;

    int n;

    printf("Enter the length of the linked list : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int ele;

        printf("Enter the element number %d  : ",(i+1));
        scanf("%d",&ele);

        append(&head,ele);
    }

    printList(head);

    Node *middle = middleElement(head);

    Node *temp = head;

    while(temp->next != middle)
    {
        temp = temp ->next;
    }
    temp ->next = NULL;

    //printList(middle);
    middle = reverse(middle);
    
    //printList(middle);
    //printList(head);

    Node *new_head = NULL;

    int i =0;
    
    while(head || middle)
    {
        if(i%2==0)
        {
            if(head)
            {
                append(&new_head,head->data);
                head = head->next;    
            }
           
        }

        else
        {
            append(&new_head,middle->data);
            middle = middle->next;
        }

        i++;
    }

    printList(new_head);


}
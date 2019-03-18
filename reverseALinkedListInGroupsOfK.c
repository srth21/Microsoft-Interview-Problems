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

Node * reverseInGroupsOfK(Node *head, int k)
{
	Node *curr, *next, *prev;

	curr = head;
	next = NULL;
	prev = NULL;

	int i =0;

	while(curr && i<k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;

		i++;
	}

	if(next)
	{
		head->next = reverseInGroupsOfK(next,k);
	}

	return prev;
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

	int k;

	printf("Enter the value of k : ");
	scanf("%d",&k);

	head = reverseInGroupsOfK(head,k);
	printList(head);

	return 1;
}
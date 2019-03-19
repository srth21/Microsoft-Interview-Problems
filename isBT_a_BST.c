#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node  
{ 
  int data; 
  struct node *left; 
  struct node *right; 
};

struct node* newNode(int data) 
{ 
  // Allocate memory for new node  
  struct node* node = (struct node*)malloc(sizeof(struct node)); 
  
  // Assign data to this node 
  node->data = data; 
  
  // Initialize left and right children as NULL 
  node->left = NULL; 
  node->right = NULL; 
  return(node); 
} 
 

void insert(struct node* temp, int key) 
{ 
    queue<struct node*> q; 
    q.push(temp); 
  
    // Do level order traversal until we find 
    // an empty place.  
    while (!q.empty()) { 
        struct node* temp = q.front(); 
        q.pop(); 
  
        if (!temp->left) { 
            temp->left = newNode(key); 
            break; 
        } else
            q.push(temp->left); 
  
        if (!temp->right) { 
            temp->right = newNode(key); 
            break; 
        } else
            q.push(temp->right); 
    } 
}

bool check(struct node *root, int min, int max)
{
	if(root == NULL)
	{
		return true;
	}

	if(root->data >= min and root->data<max)
	{
		return check(root->left,min,root->data) and check(root->right,root->data,max);
	}

	return false;

}

int main()
{
	int n;
	cin>>n;

	struct node *root = NULL;

	for(int i=0;i<n;i++)
	{
		int key;
		cin>>key;

		if(root == NULL)
		{
			root = newNode(key);
		}
		else
		{
			insert(root,key);
		}
	}

	bool isBst = check(root,INT_MIN,INT_MAX);

	if(isBst)
	{
		cout<<"Is a BST"<<endl;
	}
	else
	{
		cout<<"Not a BST"<<endl;
	}

	return 1;
}
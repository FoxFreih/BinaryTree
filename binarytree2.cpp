#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#define N 20
#define M 50

struct Bike {
	int id;
	char brand[N];
	int year;
	bool isRented;
	int size;
	int type;
	int pricePerHour;
};
struct Node {
	struct Bike bike;
	struct Node* left;
	struct Node* right;
};

struct Node* search(Node*root, int id)
{
	if (root == NULL)
	{
		printf("not found!!!\n");
		return NULL;
	}
	if (root->bike.id == id)
		return root;
	if (id > root->bike.id)
		 search(root->right, id);
	else
		 search(root->left, id);
}
bool arr[M];
int makeId()
{
	int id = rand() % 50;
	if (arr[id] == 0)
	{
		arr[id] = 1;
		return id;
	}
	else
		makeId();

	


}
struct Bike* createBike(const char brand [],int year,int size,int type,int priceprehour)
{

	struct Bike *bike = new Bike;
	bike->id = makeId();
	strcpy(bike->brand,brand);
	bike->year = year;
	bike->isRented = false;
	bike->size = size;
	bike->type = type;
	bike->pricePerHour = priceprehour;
	return bike;


}
struct Node* createTreeNode(struct Bike *bike) {
	struct Node *newNode = new Node;
	newNode->bike = *bike;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
};
/**
- Structure is user defined data type, that allows to combine data items in different kinds.

- left: Pointer to the left node of the current node
- right: Pointer to the right node of the current node
**/

/**
- Creates a new node with data value and returns the new node created

- data:e of type Integer and stores the value we save in the node.
**/
/**
- Insert a node to the tree and returns the new tree

- node: Head of the tree we want to insert to
- data: data of the new node we want to insert
*/
struct Node* insert(struct Node* node, struct Bike* bike)
{
	bool isParentEmpty = node == NULL;

	if (isParentEmpty) {
		struct Node* newNode = createTreeNode(bike);
		return newNode;
	}
	else {
		if (bike->id > node->bike.id)
			node->right=insert(node->right, bike);
		if (bike->id < node->bike.id)
			node->left=insert(node->left, bike);

	}
	return node;
}

void printNotRented(Node*root)
{

}
void printtree(Node* root)
{
	if (root == NULL)
		return;
		//printf("->NULL\n");
	printf("id: %d\n",root->bike.id);
	printf("brand: %s\n",root->bike.brand);
	printf("year: %d\n", root->bike.year);
	printf("size: %d\n", root->bike.size);
	printf("type: %d\n", root->bike.type);
	printf("pricePerHour: %d\n", root->bike.pricePerHour);
	printf("isRanted:%s\n", root->bike.isRented ? "ranted" : "available");
	printf("################\n");
	printtree(root->left);
	printtree(root->right);
}

int main()
{ 
	srand(time(0));
	int answer,flag,id;
	struct Node* root = NULL;
	struct Node *temp = new Node;
	root = insert(root,createBike("m7mood", 3,56,1,20));
	root = insert(root,createBike("fox",4,90, 5, 30));
	root = insert(root, createBike("foxy", 2, 100, 4, 70));
	root = insert(root, createBike("amal", 6, 610, 2, 900));

	printtree(root);
	printf("\n\n\nsearch:\n");
	do
	{
		printf("enter id to search:");
		scanf("%d", &id);
		temp = search(root, id);
		if (temp) 
		{
			temp->bike.isRented = true;
			printf("id: %d\n", temp->bike.id);
			printf("brand: %s\n", temp->bike.brand);
			printf("year: %d\n", temp->bike.year);
			printf("size: %d\n", temp->bike.size);
			printf("type: %d\n", temp->bike.type);
			printf("pricePerHour: %d\n", temp->bike.pricePerHour);
			printf("isRanted:%s\n", temp->bike.isRented ? "ranted" : "available");
		}
		//temp->left = NULL;
		//temp->right = NULL;
		//printtree(temp);
		flag = 0;
		printf("do you want to search another bike? press 1 for Yes, 0 for No:\n");
		scanf("%d", &answer);
		if (answer == 1)
		{
			flag = 1;
			printtree(root);
		}
	} while (flag);

		//root = insert(root, 1);
		//root = insert(root, 3);
}

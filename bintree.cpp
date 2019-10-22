#include <iostream>

struct node {
	int value;
	struct node *right;
	struct node *left;
};

struct node* createNewNode(int data)
{
	node* NewNode = new node;
	NewNode->left = NULL;
	NewNode->right = NULL;
	NewNode->value = data;
	return NewNode;
}

struct node* insert(struct node* node, int data)
{
	if (node == NULL)
		return(createNewNode(data));
	else
	{
		if (data <= node->value)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);
		return node;
	}
}

void printInorder(struct node* node)
{
	if (node != NULL)
	{
		printInorder(node->left);
		printf("%d\t ", node->value);
		printInorder(node->right);
	}

}
void printPostorder(struct node* node)
{
	if (node != NULL)
	{
		printPostorder(node->left);
		printPostorder(node->right);
		printf("%d\t ", node->value);
	}
}
void printPreorder(struct node* node)
{
	if (node != NULL)
	{
		printf("%d\t ", node->value);
		printPreorder(node->left);
		printPreorder(node->right);
	}
}

void search(struct node* node, int data)
{
	if (node != NULL)
	{
		if (data == node->value)
			printf("%d\n", data);
		else
		{
			if (data > node->value)
				search(node->right, data);
			else
				search(node->left, data);
		}
	}
	else
		printf("NULL\n");
}

int minValue(struct node* node)
{
	if (node->left != NULL)
		minValue(node->left);
	else
		return node->value;
}
int maxValue(struct node* node)
{
	if (node->right != NULL)
		maxValue(node->right);
	else
		return node->value;
}

int maxDepth(struct node* node)
{
	if (node == NULL)
		return 0;
	if (node != NULL)
	{
		int a = 1 + maxDepth(node->right);
		int b = 1 + maxDepth(node->left);
		if (a >= b)
			return a;
		else
			return b;
	}
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int height(node* leaf)
{
	if (leaf == NULL)
		return 0;
	else
	{
		int height_l = height(leaf->left);
		int height_r = height(leaf->right);
		return 1 + max(height_l, height_r);
	}
}

void printGivenLevel(node* leaf, int level)
{
	if (leaf != NULL)
	{
		if (level == 1)
		{
			for (int i = 0; i < maxDepth(leaf); i++)
				printf("   ");
			printf("%d", leaf->value);
			for (int i = 0; i < maxDepth(leaf); i++)
				printf("   ");
		}
		else //if (level > 1)
		{
			printGivenLevel(leaf->left, level - 1);
			printGivenLevel(leaf->right, level - 1);
		}

	}
}

void printLevelorder(node* leaf)
{
	for (int i = 1; i < maxDepth(leaf) + 1; i++)
	{
		printGivenLevel(leaf, i);
		printf("\n");
	}

}

bool full(node* node)
{
	if (node != NULL)
	{
		bool r = full(node->right);
		bool l = full(node->left);
		if (r != l)
			return false;
		return true;
	}


}

bool complete(node* node)
{
	if ((node != NULL)
	{
		if (height(node->right) != height(node->left))
			return false;
		return complete(node->right)*complete(node->left) * true;
	}

}

void Checktype(node *root) {
	if (full(root))
		if (completed(root))
			printf("Completed\n");
		else
			printf("Full\n");
	else
		printf("Not Full\n");
}




void main()
{
	node *root = NULL;
	root = insert(root, 11);
	root = insert(root, 8);
	root = insert(root, 14);
	root = insert(root, 1);
	root = insert(root, 25);
	root = insert(root, 12);
	root = insert(root, 2);
	root = insert(root, 0);
	root = insert(root, 9);
	root = insert(root, 4);
	root = insert(root, 10);
	printf("printInorder\n");
	printInorder(root);
	printf("\nprintPreorder\n");
	printPreorder(root);
	printf("\nprintPostorder\n");
	printPostorder(root);
	printf("\nsearch:\n");
	search(root, 12);
	search(root, 100);
	printf("the min value is :%d\n", minValue(root));
	printf("the max value is :%d\n", maxValue(root));
	printf("the max depth is :%d\n", maxDepth(root) - 1);
	printLevelorder(root);
	Checktype(root);


}
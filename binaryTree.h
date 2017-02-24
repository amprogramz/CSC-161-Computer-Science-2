//																		Alec McDaugale
//
//	This program is the base class to create a binary tree.

#ifndef H_binaryTree
#define H_binaryTree

template<class type>
struct bnode
{//struct to hold the binary node object
	type info;
	//var to hold the info
	bnode<type> *l;
	//left link pointer
	bnode<type> *r;
	//right link pointer
};


template<class type>
class binaryTreeType
{
public:
	int treeHeight();
		//returns the tree height
	bool emptyTree();
		//returns if the tree is empty
	
	void inorderTraversal();
		//calls inorder 
	binaryTreeType();
		//default constructor

protected:
	bnode<type> *root;
		//root pointer

private:
	int greater(int a, int b);
	//returns the greater element
	int findHeight(bnode<type> *a);
	//returns the height
	void inorder(bnode<type> *a);
	//returns the contents of the tree inorder
	

};

#endif // !H_binaryTree


//definitions

template<class type>
int binaryTreeType<type>::treeHeight()
{
	return findHeight(root);
	//retutn the results from the private function
}

template<class type>
bool binaryTreeType<type>:: emptyTree()
{
	return(root == NULL);
	//returns true if the list is equal to null
}

template<class type>
void binaryTreeType<type>::inorderTraversal()
{
	inorder(root);
	//prints the variables inorder starting at the root
}

template<class type>
int binaryTreeType<type>::greater(int a, int b)
{
	if (a > b)
	{
		return a;
		//if a is larger then return it
	}
	else
	{
		return b;
		//otherwise return b
	}
}

template<class type>
int binaryTreeType<type>:: findHeight(bnode<type> *a )
{
	//need to count the height
	if (a == NULL)
	{
		return 0;
		// if the root is null then the height is 0
	}
	else
	{
		return 1 + greater(findHeight(a->r), findHeight(a->l));
		//otherwise the height is the longer distance of the two sides
	}

}


template<class type>
void binaryTreeType<type>::inorder(bnode<type> *a)
{
	//prints data inorder untill the end has been reached
	if (a != NULL)
	{//if its not null
		inorder(a->l);
		//recursivly move down the right
		cout << a->info << " ";
		//print the info
		inorder(a->r);
		//recursively move through the righ
	}
}

template<class type>
binaryTreeType<type>::binaryTreeType()
{
	root = NULL;
	//initialise the root to null

}

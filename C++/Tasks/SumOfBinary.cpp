//Print Boundary Sum of a Binary Tree

#include <bits/stdc++.h>
using namespace std;
class tree{
	public:
		int data;
		tree *left;
		tree *right;
};


int findBoundarySum(tree* root){
if(root==NULL)
	return 0;
int sum=0;
sum+=root->data;


tree* temp=root, *store;
queue<tree*> q;

q.push(temp);
while(!q.empty()){
	store=q.front();
	q.pop();
	if(store->left==NULL && store->right==NULL)
		sum+=store->data;
	if(store->left)
		q.push(store->left);
	if(store->right)
		q.push(store->right);
}

temp=root->left;
while(!(temp->right==NULL && temp->left==NULL)){
	sum+=temp->data;
	if(temp->left)
		temp=temp->left;
	else
		temp=temp->right;
}

temp=root->right;
while(!(temp->right==NULL && temp->left==NULL)){
	sum+=temp->data;
	if(temp->right)
		temp=temp->right;
	else
		temp=temp->left;
}
return sum;
}

tree* newnode(int data)
{
	tree* node = (tree*)malloc(sizeof(tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

int main()
{

	cout<<"Tree is built like the example aforesaid"<<endl;
	tree *root=newnode(2);
	root->left= newnode(7);
	root->right= newnode(5);
	root->right->right=newnode(9);
	root->right->right->left=newnode(4);
	root->left->left=newnode(2);
	root->left->right=newnode(6);
	root->left->right->left=newnode(5);
	root->left->right->right=newnode(11);

	cout<<"finding boundary sum......"<<endl;
	cout<<"boundary sum is "<<findBoundarySum(root)<<endl;

	return 0;
}

//Find the level in a binary tree with given sum K
#include <bits/stdc++.h>
using namespace std;

// tree node is defined
class tree{
	public:
		int data;
		tree *left;
		tree *right;
};

int findLevel( tree *root,int K){
	queue<tree*> q;  // using stl
	tree* temp;
	//counting level no & initializing cur_sum
	int level=0,cur_sum=0;
	//EnQueue root
	q.push(root);
	//EnQueue NULL to inticate end of 0 level
	q.push(NULL);
	while(!q.empty()){
		//DeQueueing using STL
		temp=q.front();
		q.pop();
		if(temp==NULL){
			//if current level sum equals to K
			if(cur_sum==K)
				return level;//return level no
			//ifn't then set cur_sum to 0 for further levels
			cur_sum=0;
			if(!q.empty())
				q.push(NULL);
			level++;
		}
		else{
		//level order traversal
		cur_sum+=temp->data; //sum thd level
		if(temp->left)
			q.push(temp->left); //EnQueue
		if(temp->right)
			q.push(temp->right); //EnQueue
		}
	}
	return -1;
}

// creating new node
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
	//**same tree is builted as shown in example**
	int c,K;
	cout<<"Tree is built like the example aforesaid"<<endl;
	cout<<"input K....."<<endl;
	cin>>K;

	tree *root=newnode(2);
	root->left= newnode(7);
	root->right= newnode(5);
	root->right->right=newnode(9);
	root->right->right->left=newnode(4);
	root->left->left=newnode(2);
	root->left->right=newnode(6);
	root->left->right->left=newnode(5);
	root->left->right->right=newnode(11);

	cout<<"finding if any level exists......"<<endl;
	c=findLevel(root,K);
	if(c>=0)
		cout<<"level is found and it is level "<<c<<endl;
	else
		cout<<"level not found, no such tree level exists";

	return 0;
}

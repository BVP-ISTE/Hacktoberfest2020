//Print Boundary Sum of a Binary Tree

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// A binary tree node has data,
// pointer to left child
// and a pointer to right child
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// Utility function to create a node
Node* newNode(int data)
{
	Node* temp = new Node;

	temp->left = NULL;
	temp->right = NULL;
	temp->data = data;

	return temp;
}

// Function to sum up all the left boundary nodes
// except the leaf nodes
void LeftBoundary(Node* root, int& sum_of_boundary_nodes)
{
	if (root) {
		if (root->left) {
			sum_of_boundary_nodes += root->data;
			LeftBoundary(root->left, sum_of_boundary_nodes);
		}
		else if (root->right) {
			sum_of_boundary_nodes += root->data;
			LeftBoundary(root->right, sum_of_boundary_nodes);
		}
	}
}

// Function to sum up all the right boundary nodes
// except the leaf nodes
void RightBoundary(Node* root, int& sum_of_boundary_nodes)
{
	if (root) {
		if (root->right) {
			RightBoundary(root->right, sum_of_boundary_nodes);
			sum_of_boundary_nodes += root->data;
		}
		else if (root->left) {
			RightBoundary(root->left, sum_of_boundary_nodes);
			sum_of_boundary_nodes += root->data;
		}
	}
}

// Function to sum up all the leaf nodes
// of a binary tree
void Leaves(Node* root, int& sum_of_boundary_nodes)
{
	if (root) {
		Leaves(root->left, sum_of_boundary_nodes);

		// Sum it up if it is a leaf node
		if (!(root->left) && !(root->right))
			sum_of_boundary_nodes += root->data;

		Leaves(root->right, sum_of_boundary_nodes);
	}
}

// Function to return the sum of all the
// boundary nodes of the given binary tree
int sumOfBoundaryNodes(struct Node* root)
{
	if (root) {

		// Root node is also a boundary node
		int sum_of_boundary_nodes = root->data;

		// Sum up all the left nodes
		// in TOP DOWN manner
		LeftBoundary(root->left, sum_of_boundary_nodes);

		// Sum up all the
		// leaf nodes
		Leaves(root->left, sum_of_boundary_nodes);
		Leaves(root->right, sum_of_boundary_nodes);

		// Sum up all the right nodes
		// in BOTTOM UP manner
		RightBoundary(root->right, sum_of_boundary_nodes);

		// Return the sum of
		// all the boundary nodes
		return sum_of_boundary_nodes;
	}

	return 0;
}

// Driver code
int main()
{
	Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->left = newNode(8);
	root->left->right = newNode(14);
	root->right->left = newNode(11);
	root->right->right = newNode(3);
	root->left->right->left = newNode(12);
	root->right->left->right = newNode(1);
	root->right->left->left = newNode(7);

	cout << sumOfBoundaryNodes(root);

	return 0;
}

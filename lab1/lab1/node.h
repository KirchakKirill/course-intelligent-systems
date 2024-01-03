#pragma once
class node
{
public:
	int value;
	node* left;
	node* right;

	node(int value,node* left,node* right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
};
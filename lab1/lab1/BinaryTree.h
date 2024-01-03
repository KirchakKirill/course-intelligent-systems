#pragma once
#include <iostream>
#include "node.h"
#include "vector"
#include "queue"
using namespace std;

class BinaryTree
{

	
public:
	node* nd;
	BinaryTree() 
	{
		nd = nullptr;
	}

	void append(int value)
	{
		if (!nd)
		{
			 this->nd = new node(value,nullptr,nullptr);
		}
		else
		{
			node* cur = this->nd;
			node* parent = cur;
			
			while (cur != nullptr)
			{


				while (cur!=nullptr&&value >= cur->value)
				{
					parent = cur;
					cur = cur->right;
					
				}
				while (cur!=nullptr&&value <= cur->value)
				{
					parent = cur;
					cur = cur->left;
				}
			}
			if (value > parent->value)
			{
				parent->right = new node(value, nullptr, nullptr);
			}
			if (value < parent->value)
			{
				parent->left = new node(value, nullptr, nullptr);
			}
			
		}
	}
	~BinaryTree()
	{
		
	}
	
	void create_tree(int start,int last)
	{
		if (start>last)
		{
			return;
		}
		append(start);
		create_tree(start * 2, last);
		create_tree(start + 3, last);

	}

	void print()
	{
		vector<int> list_signed;
		queue<node*> q;

		q.push(nd);
		while (!q.empty())
		{
			node* cur = q.front();
			if (find(list_signed.begin(),list_signed.end(),cur->value)==list_signed.end())
			{
				list_signed.push_back(cur->value);
				if (cur->left != nullptr )
				{
					q.push(cur->left);
					
				}
				if (cur->right != nullptr)
				{
					q.push(cur->right);

				}
				
			}
			cout << q.front()->value << endl;
			q.pop();

		}

	}
};
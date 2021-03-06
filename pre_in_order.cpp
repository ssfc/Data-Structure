#include<iostream>
#include<vector>
using namespace std;


struct Node
{
	int key;
	Node* left;
	Node* right;	
};


vector<int> pre_order;
vector<int> in_order;
vector<int> post_order;

Node* build_tree(int inStart, int inEnd, int preStart, int preEnd)
{
	if (preStart > preEnd || inStart > inEnd)
	{
		return NULL;
	}


	Node* root = new Node;  

	int position = 0;
	for (int i = 0; i < in_order.size(); i++) 
	{
		if (in_order[i] == pre_order[preStart]) 
		{
			position = i;
			break;
		}
	}

	root->key = pre_order[preStart];
	root->left = build_tree(inStart, position-1, preStart+1, preStart-inStart+position);
	root->right = build_tree(position+1, inEnd, preStart-inStart+position+1, preEnd);

	post_order.push_back(root->key);

	return root;
}



int main()
{
// input process ////////////////////////////////////////
	int N;
	cin>>N;


	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		pre_order.push_back(temp);
	}

	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		in_order.push_back(temp);
	}


	build_tree(0, N-1, 0, N-1);


	for(int i=0;i<N;i++)
	{
		cout<<post_order[i]<<" ";
	}


	return 0;
}

/*
7
4 1 3 2 6 5 7
1 2 3 4 5 6 7
*/


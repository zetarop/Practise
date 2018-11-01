#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;


struct node
{
	int data;
	node* l;
	node* r;
};

node* newNode(int n)
{
	node* temp = new node;
	temp->data = n;
	temp->l = NULL;
	temp->r = NULL;
	return temp;
}

node* insert(node* root, int n)
{
	if(root == NULL)
		root = newNode(n);
	else if(n < root->data)
		root->l = insert(root->l,n);
	else
		root->r = insert(root->r,n);
}

void inOrder(node* root)
{
	if(root->l != NULL)
		inOrder(root->l);

	cout<<root->data<<" ";

	if(root->r != NULL)
		inOrder(root->r);
}

void preOrder(node* root)
{
	cout<<root->data<<" ";
	
	if(root->l != NULL)
		preOrder(root->l);

	if(root->r != NULL)
		preOrder(root->r);

}

void postOrder(node* root)
{
	if(root->l != NULL)
		postOrder(root->l);

	if(root->r != NULL)
		postOrder(root->r);

	cout<<root->data<<" ";
}

void lvlOrder(node* root)
{
	queue<node*> Q;
	Q.push(root);

	while(!Q.empty())
	{
		node* temp = Q.front();
		Q.pop();
		cout<<temp->data<<" ";
		if(temp->l != NULL)
			Q.push(temp->l);
		if(temp->r != NULL)
			Q.push(temp->r);
	}
}

void lvlByLvl(node* root)
{
	node* T = newNode(-1);

	queue<node*> Q;
	Q.push(root);
	Q.push(T);

	while(!Q.empty())
	{
		node* temp = Q.front();
		Q.pop();
		if(temp->data == -1)
		{
			Q.push(T);
			cout<<endl;
			if(Q.size() == 1)
				break;
		}
		else
		{
			cout<<temp->data<<" ";
			if(temp->l != NULL)
				Q.push(temp->l);
			if(temp->r != NULL)
				Q.push(temp->r);
		}
	}
}

int predecessor(node* root)
{
	node* temp = root->l;
	while(temp->r != NULL)
		temp = temp->r;
	return temp->data;
}

node* del(node* root, int n)
{
	if(root == NULL)
		return root;
	if(n < root->data)
		root->l = del(root->l, n);
	else if(n > root->data)
		root->r = del(root->r, n);
	else
	{
		if(root->l == NULL && root->r == NULL)
			root = NULL;
		else if(root->l != NULL && root->r == NULL)
			root = root->l;
		else if(root->l == NULL && root->r != NULL)
			root = root->r;
		else
		{
			// both left and right side exist

			int t = predecessor(root);
			root->data = t;
			root->l = del(root->l,t);
		}
	}
}


int lca(node* root, int a, int b)
{
	if(root->data > a && root->data > b)
		return lca(root->l, a, b);
	else if( root->data < a && root->data < b)
		return lca(root->r, a, b);
	else
		return root->data;
}


int main()
{
	ve<int> v{50,40,60,30,45,55,70,20,35,46,65,80,10,25,33,38,48,75,90,5,15,28,36,39,49,85,84,88,100};
	node* root = NULL;

	for(auto a:v)
		root = insert(root, a);

	inOrder(root);
	cout<<endl;

	int a,b;

	while(1)
	{
		cin>>a>>b;
		cout<<lca(root,a,b)<<endl;
	}

	return 0;
}

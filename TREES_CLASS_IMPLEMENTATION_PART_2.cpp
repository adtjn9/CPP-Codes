#include<iostream>
#include<math.h>
using namespace std;
struct node
{
	int data;
	node *right;
	node *left;
};
int flag=0;int p[20];int len=0;bool flag1=true;
class trees
{
	public:
	node *root;
	trees()
	{
		root=NULL;
	}
	node* create(node *);
	void indisplay(node *);
	void predisplay(node *);
	void postdisplay(node *);
	int height(node *);
	void tblr(node*,int);
	void print_nodes_in_a_level(node *,int);
	void compare(node *,node *);
	void path(node *,int[],int);
	void print(int[],int);
	void delt(node *);
	void check_bal(node *);
	int getlevel(node *,int,int);
	void sum_treemain(node  *);
	int sub_sum(node *);
	int sum_child(node *r);
	void child_sum(node *);
	void cirl(node *);
	void cirr(node *);
	void print_nodes_without_sibling(node *);
};
int main()
{
	trees t1,t2;int key;bool check=true;
	cout<<"CREATE FIRST TREE : "<<endl;
	t1.root=t1.create(t1.root);
	t1.indisplay(t1.root);
	cout<<endl;
	cout<<"CREATE SECOND TREE : "<<endl;
	t2.root=t2.create(t2.root);
	t2.indisplay(t2.root);
	cout<<endl;
	t1.compare(t1.root,t2.root);
	if(flag1)
	{
		cout<<"EQUAL !!  "<<endl;
	}
	else
	{
		cout<<"UNEQUAL : "<<endl;
	}
	//t1.path(t1.root,p,0);
	//t1.delt(t1.root);
	//t1.root=NULL;
	//t1.indisplay(t1.root);
	//cout<<t1.root;
	/*t1.check_bal(t1.root);
	cout<<"Enter the value of node whose level you want : "<<endl;
	cin>>key;
	int level=0;
	level=t1.getlevel(t1.root,key,0);
	t1.sum_treemain(t1.root);
	cout<<"LATEST CHECK : "<<endl;
	flag=0;
	t1.child_sum(t1.root);
	if(flag==0)
	{
		cout<<"Satisfied : "<<endl;
	}
	//cout<<t1.sum_child(t1.root);
	/*cout<<"The circumference of the tree is : "<<endl;
	t1.cirl(t1.root);
	t1.cirr(t1.root);
	cout<<endl;
	t1.print_nodes_without_sibling(t1.root);*/
}

node * trees::create(node *root)
{
	char ch;
	root=new node;
	cout<<"Enter data "<<endl;
	cin>>root->data;
	cout<<"Is there a left child to "<<root->data<<" "<<endl;
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		root->left=create(root->left);
	}
	else
	{
		root->left=NULL;
	}
	cout<<"Is there a right child to "<<root->data<<" "<<endl;
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		root->right=create(root->right);
	}
	else
	{
		root->right=NULL;
	}
	return root;
}


void trees::indisplay(node *root)
{
	if(root==NULL)
	{
		return;
	}
	indisplay(root->left);
	cout<<root->data<<" ";
	
	indisplay(root->right);
}


void trees::predisplay(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		predisplay(root->left);
		predisplay(root->right);
	}
}


void trees::postdisplay(node *root)
{
	if(root!=NULL)
	{
		postdisplay(root->left);
		postdisplay(root->right);
		cout<<root->data<<" ";
	}
}


int trees::height(node *root)
{
	if(root==NULL)
	{
		return(-1);
	}
	else
	{
		return(1+max(height(root->left),height(root->right)));
	}
}


void trees::tblr(node *root,int level)
{
	int i=0;
	for(i=0;i<=level;i++)
	{
		cout<<"Nodes in level "<<i<<" are : ";
		print_nodes_in_a_level(root,i);
		cout<<endl;
	}
}


void trees::print_nodes_in_a_level(node *root,int level)
{
	if(root==NULL)
	{
		return;
	}
	else if(level==0)
	{
		cout<<root->data<<" ";
	}
	else
	{
		print_nodes_in_a_level(root->left,level-1);
		print_nodes_in_a_level(root->right,level-1);
	}
}

void trees::compare(node *r1,node *r2)
{
	if(r1!=NULL||r2!=NULL)
	{
		if(r1!=NULL&&r2==NULL)
		{
			flag1=false;
		}
		else if(r2!=NULL&&r1==NULL)
		{
			flag1=false;
		}
		else if(r1!=NULL&&r2!=NULL)
		{
			if(r1->data!=r2->data)
			{
				flag1=false;
			}
		}
	}
	else
	{
		return;
	}
	compare(r1->left,r2->left);
	compare(r1->right,r2->right);
}

void trees::path(node *r,int p[],int len)
{
	if(r==NULL)
	{
		return;
	}
	p[len]=r->data;
	len++;
	if(r->left==NULL&&r->right==NULL)
	{
		print(p,len);
	}
	path(r->left,p,len);
	path(r->right,p,len);
}


void trees::print(int p[],int len)
{
	int i=0;
	cout<<"THE PATH IS : "<<endl;
	for(i=0;i<len;i++)
	{
		cout<<p[i]<<" ";
	}
	if(len-1==height(root))
	{
		cout<<"THIS WAS THE MAXIMUM PATH : "<<endl;
	}
	cout<<endl;
}


void trees::delt(node *r)
{
	if(r==NULL)
	{
		return ;
	}
	delt(r->left);
	delt(r->right);
	delete r;
}


void trees::check_bal(node *r)
{
	int l=height(r->left);
	cout<<"LEFT SUB-TRREE HEIGHT : "<<l<<endl;
	int ri=height(r->right);
	cout<<"RIGHT SUB-TRREE HEIGHT : "<<ri<<endl;
	if(abs(l-ri)<=1)
	{
		cout<<" BALANCED : "<<endl;
	}
	else
	{
		cout<<"UNBALANCED : "<<endl;
	}
}

int trees::getlevel(node *r,int key,int level)
{
	if(r==NULL)
	{
		return 0;
	}
	if(r->data==key)
	{
		cout<<"LEVEL IS : "<<level<<endl;
		return level;
	}
	return (getlevel(r->left,key,level+1));
	return(getlevel(r->right,key,level+1));
}


void trees::sum_treemain(node *r)
{
	int lsum=sub_sum(r->left);
	int rsum=sub_sum(r->right);
	cout<<"LEFT-SUB_TREE SUM IS : "<<lsum<<endl;
	cout<<"RIGHT-SUB_TREE SUM IS : "<<rsum<<endl;
	if(lsum+rsum==r->data)
	{
		cout<<"It is a sum tree : "<<endl;
	}
	else
	{
		cout<<"Not a sum tree : "<<endl;
	}
}

void trees::child_sum(node *r)
{
	if(r!=NULL)
	{
		child_sum(r->left);
		if(sum_child(r)==0)
		{
			cout<<"Not satisfied : "<<endl;
			flag=1;
			return;
		}
		child_sum(r->right);
	}
	else
	{
		return;
	}
}


int trees::sum_child(node *r)
{
	if((r->left!=NULL)&&(r->right!=NULL))
	{
		if(r->data==r->left->data+r->right->data)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(r->left==NULL&&r->right==NULL)
	{
		return 1;
	}
	else if(r->left==NULL)
	{
		if(r->data==r->right->data)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(r->data==r->left->data)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int trees::sub_sum(node *r)
{
	if(r==NULL)
	{
		return 0;
	}
	return(sub_sum(r->left)+r->data+sub_sum(r->right));
}
void trees::cirl(node *r)
{
	if(r==NULL)
	{
		return;
	}
	cirl(root->left);
	cout<<r->data<<" ";
}
void trees::cirr(node *r)
{
	if(r==NULL)
	{
		return;
	}
	cirr(r->right);
	cout<<r->data<<" ";
}
void trees::print_nodes_without_sibling(node *r)
{
	if(r==NULL)
	{
		return;
	}
	else
	{
		if(r->left==NULL&&r->right!=NULL)
		{
			cout<<r->right->data<<" ";
		}
		if(r->right==NULL&&r->left!=NULL)
		{
		cout<<r->left->data<<" ";
		}
	}
	print_nodes_without_sibling(r->left);
	print_nodes_without_sibling(r->right);
}

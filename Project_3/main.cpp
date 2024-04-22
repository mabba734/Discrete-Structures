
#include <iostream>
using namespace std;

struct Node{
char data;
Node *left;
Node *right;

//default constructors to initialize nodes
Node(char val):data(val),left(NULL),right(NULL) {}

};
//function declarations
void printPreorder(Node *node);
void printInorder(Node *node);
void printPostorder(Node *node);

int main() {

  //create tree
  Node *root=new Node('A');
  root->left=new Node('B');
  root->right=new Node('C');
  root->left->left=new Node('D');
  root->left->right=new Node('E');
  root->right->left=new Node('F');
  root->right->right=new Node('G');
  root->right->left->left=new Node('H');
  root->right->left->right=new Node('I');



  //print tree in preorder
  cout<<"Preorder:"<<endl;
  printPreorder(root);

  
  //print tree in InOrder
  cout<<"\nInorder:"<<endl;
  printInorder(root);
  



  //print tree in Postorder
  cout<<"\nPostorder: "<<endl;
  printPostorder(root);
  
	return 0;
}

//function for pre order
void printPreorder(Node *node)
{
  //if node is empty
  if(node==NULL)
    return;

  //print data of node
  cout<<node->data<<' ';
  
  //go through left tree
  printPreorder(node->left);

  //go through right tree;
  printPreorder(node->right);
}

//function for in order
void printInorder(Node *node)
{
  if(node==NULL)
    return;
  
  //go through the left tree
  printInorder(node->left);
  //print letters
  cout<<node->data<<' ';

  //go through right tree
  printInorder(node->right);
  
}

//function for post order
void printPostorder(Node *node)
{
  //if node is empty
  if(node==NULL)
    return;

  //go through left tree
  printPostorder(node->left);

  //go through right tree
  printPostorder(node->right);
  cout<<node->data<<' ';
  
}

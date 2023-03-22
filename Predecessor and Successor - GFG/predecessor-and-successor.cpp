//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively

// Why BST is used => As tree is separated in two hence we can hv space complexity equals to O(h) rather than
// O(n);


// Approach 1 => Find inorder and put in the vector. 
        // Predecessor -> i-1  & Successor -> i+1 for the current key at ith position.

// Approach 2 => Predecessor(Key) -> one left from key then , extreme right.
//            => Successor(Key)  -> one right then , extreme left.
// Corner case for leaf nodes only =>
//  if going towards left then update successor else update predecessor

Node* inpre(Node* root){
    Node* p = root->left;      // First left of the root
    while(p->right) p=p->right; // Extreme Right
    return p;
}
Node* insuc(Node* root){
    Node* p = root->right;    // First right of the root
    while(p->left) p=p->left; // Extreme left
    return p;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
   if(!root) return ;
   if(root->key == key){       // If key founds at the root then easy part
       if(root->left) pre = inpre(root);
       if(root->right) suc = insuc(root);
       return;
   }
   if(key>root->key){ // key exists in right subtree. // Corner cases
       pre = root;    // pre updates every time as we towards the right of root.  
       findPreSuc(root->right, pre, suc, key);
   }else if(key<root->key){
       suc = root;
       findPreSuc(root->left,pre, suc, key);
   }
}
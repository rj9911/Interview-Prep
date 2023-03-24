//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    // 1. Taking one by one elems from preorder.
    // 2. Getting left and right elems from inorder of that particular elem of preorder.
    // 3. and creating the new tree.
    // Time -> O(n) -> Simply Traversing in preorder
    // Space -> O(n) -> map
    
    public:
    int search(int in[],int start,int end,int cur){
        for(int i=start;i<=end;i++){
            if(in[i]==cur){
                return i;
            }
        }
        return -1;
    }
    
    Node*solv(int in[],int pre[],int &index,int start,int end){
        if(start>end){
            return NULL;
        }
        
        int cur=pre[index];
        index++;
        
        Node*node=new Node(cur);
        
        if(start==end){
            return node;
        }
        
        int pos=search(in,start,end,cur);
        node->left=solv(in,pre,index,start,pos-1);
        node->right=solv(in,pre,index,pos+1,end);
        
        return node;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int index=0;
        Node*ans=solv(in,pre,index,0,n-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
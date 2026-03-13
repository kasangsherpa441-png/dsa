#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int key;
	struct Node *left;
	struct Node  *right;
	
}Node;

int n;
Node* newNode(int key){
	Node *n=(Node*)malloc(sizeof(Node));
	if(!n){
		printf("Memory Allocation Failed\n");
		exit(EXIT_FAILURE);
	}
	n->key=key;
	n->left=n->right=NULL;
	return n;
}

int attach_to_immediate_child(Node *node, int key){
	if(node==NULL) return 0; ///nothing to attach to
	
	if(key<node->key){
		if(node->left==NULL){
			node->left=newNode(key);
			return 1; //attach to left
		}else
		{
			return -1; //left occupied
		}
	}
		else if(key>node->key){
			if(node->right==NULL){
				node->right=newNode(key);
				return 2; //attached to right
			}else{
				return -2; //right occupied
			}
		}
		else
			{
					return -3;    //duplicate
			}
		 
		}

		void insert(Node *root, int key){
			Node *current=root;
			while(1){
				int result=attach_to_immediate_child(current,key);

				if(result==1 || result==2){
					return;
				}else if(result==-1){
					current=current->left;
				}
				else if(result==-2){
					current=current->right;
				}
				else if(result==-3){
					printf("Duplicate key ignored:%d\n", key);
					return;
				}
			}
		}
		void inorder(Node *root){
			if(root==NULL) return;

			inorder(root->left);
			printf("%d ", root->key);
			inorder(root->right);
		}

		void preorder(Node *root){
			if(root==NULL) return;

			printf("%d ", root->key);
			preorder(root->left);
			preorder(root->right);
		}

		void postorder(Node *root){
			if(root==NULL) return;

			postorder(root->left);
			postorder(root->right);
			printf("%d ", root->key);
		}

		int main(){
			int keys[]={10,30, 80,40,20};
			int n=sizeof(keys)/sizeof(keys[0]);

			Node *root=newNode(keys[0]);

			for(int i=1;i<n;i++){
				insert(root,keys[i]);
			}

			printf("Inorder traversal of BST:\n");
			inorder(root);
			printf("\n");

			printf("preorder traversal of BSt:\n");
			preorder(root);
			printf("\n");

			printf("Postorder traversal of BST:\n");
			postorder(root);
			printf("\n");
			return 0;
		}
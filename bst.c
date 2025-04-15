#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * left;
    struct node * right;
}Node;

Node * createNode(int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;   
}

Node * insertNode(Node * root,int data){
    if(root == NULL){
        return createNode(data);
    } else {
        if(root->data == data){
            printf("Duplicate value\n");
            return root;
        } else if(data <root->data){
            root->left = insertNode(root->left,data);
        } else {
            root->right = insertNode(root->right,data);
        }
        return root;
    }    
}

void printInOrder(Node * root){ // Left+root+right
    if(root == NULL){
        return;
    } else {
        printInOrder(root->left);
        printf("%d ",root->data);
        printInOrder(root->right);
    }
}

void printPreOrder(Node * root){//Root+left+rigth
    if(root == NULL){
        return;
    } else {
        printf("%d ",root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(Node * root){//Left+right+root
    if(root == NULL){
        return;
    } else {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ",root->data);
    }
}

int getMin(Node * root){
    if(root->left == NULL){
        return root->data;
    } else {
        return getMin(root->left);
    }
}

int getMax(Node * root){
    if(root->right == NULL){
        return root->data;
    } else {
        return getMax(root->right);
    }
}

Node * deleteNode(Node * root,int data){
    if(root == NULL){
        return NULL;
    } else if(data <root->data){
        root->left = deleteNode(root->left,data);
    } else if(data>root->data){
        root->right = deleteNode(root->right,data);
    } else {
        if(root->left == NULL && root->right == NULL){
            return NULL;
        } else if(root->left == NULL){
            return root->right;
        } else if(root->right == NULL){
            return root->left;
        } else {
            int sucessor = getMax(root->left);
            root->data = sucessor;
            root->left = deleteNode(root->left,sucessor);
            return root;
        }

    }
    
}


int main(){
    Node * root = NULL;
    int val;
    int choice;
    do{
        printf("1. Insert\n");
        printf("2. Print InOrder\n");
        printf("3. Print PreOrder\n");
        printf("4. Print PostOrder\n");
        printf("5. getMin\n");
        printf("6. getMax\n");
        printf("7. Delete\n");
        printf("8. Exit\n");    
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&val);
                root = insertNode(root,val);
                break;
            case 2:
                printf("InOrder Traversal: ");
                printInOrder(root);
                printf("\n");
                break;
            case 3:
                printf("PreOrder Traversal: ");
                printPreOrder(root);
                printf("\n");
                break;
            case 4:
                printf("PostOrder Traversal: ");
                printPostOrder(root);
                printf("\n");
                break;
            case 5:
                if(root == NULL){
                    printf("Tree is empty\n");
                } else {
                    printf("Minimum value: %d\n",getMin(root));
                }
                break;
            case 6:
                if(root == NULL){
                    printf("Tree is empty\n");
                } else {
                    printf("Maximum value: %d\n",getMax(root));
                }
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d",&val);
                root = deleteNode(root,val);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice >=1 && choice <= 7);
    return 0;
}
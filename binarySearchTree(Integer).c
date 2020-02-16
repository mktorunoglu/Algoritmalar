#include <stdio.h>
#include <stdlib.h>
struct treeNode{
    int data;
    struct treeNode* leftTreeNode;
    struct treeNode* rightTreeNode;
};
typedef struct treeNode TreeNode;
void insertTreeNode(TreeNode** rootOfTree, int data){
    TreeNode* currentTreeNode = (*rootOfTree);
    if(currentTreeNode == NULL){
        TreeNode* newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
        if(newTreeNode == NULL){
            printf("There is no memory space for new tree node...\n");
            exit(EXIT_FAILURE);
        }else{
            newTreeNode->data = data;
            newTreeNode->leftTreeNode = NULL;
            newTreeNode->rightTreeNode = NULL;
            (*rootOfTree) = newTreeNode;
        }
    }else{
        if(data < (currentTreeNode->data)){
            insertTreeNode(&(currentTreeNode->leftTreeNode), data);
        }else if(data > (currentTreeNode->data)){
            insertTreeNode(&(currentTreeNode->rightTreeNode), data);
        }else{
            printf("Duplicate records are not allowed...\n");
        }
    }
}
void preorderTravelsal(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    if(currentTreeNode != NULL){
        printf("%-6d", currentTreeNode->data);
        preorderTravelsal(currentTreeNode->leftTreeNode);
        preorderTravelsal(currentTreeNode->rightTreeNode);
    }
}
void inorderTravelsal(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    if(currentTreeNode != NULL){
        inorderTravelsal(currentTreeNode->leftTreeNode);
        printf("%-6d ", currentTreeNode->data);
        inorderTravelsal(currentTreeNode->rightTreeNode);
    }
}
void postorderTravelsal(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    if(currentTreeNode != NULL){
        postorderTravelsal(currentTreeNode->leftTreeNode);
        postorderTravelsal(currentTreeNode->rightTreeNode);
        printf("%-6d ", currentTreeNode->data);
    }
}
void findTreeMinimum(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    while(currentTreeNode -> leftTreeNode != NULL){
        currentTreeNode = currentTreeNode -> leftTreeNode;
    }
    printf("%-d\n", currentTreeNode -> data);
}
void findTreeMaximum(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    while(currentTreeNode -> rightTreeNode != NULL){
        currentTreeNode = currentTreeNode -> rightTreeNode;
    }
    printf("%-d\n", currentTreeNode -> data);
}
int main(){
    TreeNode* rootOfTree = NULL; // Define root of tree
    insertTreeNode(&rootOfTree, 38);
    insertTreeNode(&rootOfTree, 83);
    insertTreeNode(&rootOfTree, 35);
    insertTreeNode(&rootOfTree, 593);
    insertTreeNode(&rootOfTree, -346);
    insertTreeNode(&rootOfTree, 38); //Duplicate
    printf("\nPreorder travelsal:\n");
    preorderTravelsal(rootOfTree);
    printf("\nInorder travelsal:\n");
    inorderTravelsal(rootOfTree);
    printf("\nPostorder travelsal:\n");
    postorderTravelsal(rootOfTree);
    printf("\n\nTree-Minimum: ");
    findTreeMinimum(rootOfTree);
    printf("Tree-Maximum: ");
    findTreeMaximum(rootOfTree);
    return 0;
}


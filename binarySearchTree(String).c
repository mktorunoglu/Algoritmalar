#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct treeNode{
    char* data;
    struct treeNode* leftTreeNode;
    struct treeNode* rightTreeNode;
};
typedef struct treeNode TreeNode;
void preorderTravelsal(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    if(currentTreeNode != NULL){
        printf("%-10s", currentTreeNode->data);
        preorderTravelsal(currentTreeNode->leftTreeNode);
        preorderTravelsal(currentTreeNode->rightTreeNode);
    }
}
void inorderTravelsal(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    if(currentTreeNode != NULL){
        inorderTravelsal(currentTreeNode->leftTreeNode);
        printf("%-10s", currentTreeNode->data);
        inorderTravelsal(currentTreeNode->rightTreeNode);
    }
}
void postorderTravelsal(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    if(currentTreeNode != NULL){
        postorderTravelsal(currentTreeNode->leftTreeNode);
        postorderTravelsal(currentTreeNode->rightTreeNode);
        printf("%-10s", currentTreeNode->data);
    }
}
void insertTreeNode(TreeNode** rootOfTree, char* data){
    TreeNode* currentTreeNode = ( *rootOfTree);
    if(currentTreeNode == NULL){
        TreeNode* newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
        if(newTreeNode == NULL){
            printf("There is no memory space for new tree node.");
            exit(EXIT_FAILURE);
        }
        else{
            newTreeNode->data = data;
            newTreeNode->leftTreeNode = NULL;
            newTreeNode->rightTreeNode = NULL;
            (*rootOfTree) = newTreeNode;

        }
    }
    else{
        if(strncmp(data, currentTreeNode->data, 6) < 0){
            insertTreeNode(&(currentTreeNode->leftTreeNode), data);
        }
        else if(strncmp(data, currentTreeNode->data, 6) > 0){
            insertTreeNode(&(currentTreeNode->rightTreeNode), data);
        }
        else{
            printf("Duplicate records are not allowed.");
        }
    }
}
void findTreeMinimum(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    while(currentTreeNode -> leftTreeNode != NULL){
        currentTreeNode = currentTreeNode -> leftTreeNode;
    }
    printf("%-s\n", currentTreeNode -> data);
}
void findTreeMaximum(TreeNode* rootOfTree){
    TreeNode* currentTreeNode = rootOfTree;
    while(currentTreeNode -> rightTreeNode != NULL){
        currentTreeNode = currentTreeNode -> rightTreeNode;
    }
    printf("%-s\n", currentTreeNode -> data);
}
int main(){
    TreeNode* rootOfTree = NULL;
    insertTreeNode(&rootOfTree, "Dogan");
    insertTreeNode(&rootOfTree, "Bastan");
    insertTreeNode(&rootOfTree, "Kaptan");
    insertTreeNode(&rootOfTree, "Ozcan");
    insertTreeNode(&rootOfTree, "Kalkan");
    insertTreeNode(&rootOfTree, "Canan");
    insertTreeNode(&rootOfTree, "Arslan");
    insertTreeNode(&rootOfTree, "Iyigun");
    insertTreeNode(&rootOfTree, "Aydin");
    printf("Preorder travelsal:\n");
    preorderTravelsal(rootOfTree);
    printf("\n\nInorder travelsal:\n");
    inorderTravelsal(rootOfTree);
    printf("\n\nPostorder travelsal:\n");
    postorderTravelsal(rootOfTree);
    printf("\n\nTree-Minimum: ");
    findTreeMinimum(rootOfTree);
    printf("Tree-Maximum: ");
    findTreeMaximum(rootOfTree);
    return 0;
}


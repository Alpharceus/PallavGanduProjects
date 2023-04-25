#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "binarytree.h"

struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertBST(struct TreeNode* root, char data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else {
        root->right = insertBST(root->right, data);
    }
    return root;
}

int removeBST(struct TreeNode** rootRef, char data) {
    struct TreeNode* root;
    if (rootRef == NULL || *rootRef == NULL) {
        return 0;
    }
    root = *rootRef;
    if (data < root->data) {
        return removeBST(&(root->left), data);
    } else if (data > root->data) {
        return removeBST(&(root->right), data);
    } else {
        if (root->left == NULL) {
            *rootRef = root->right;
            free(root);
            return 1;
        } else if (root->right == NULL) {
            *rootRef = root->left;
            free(root);
            return 1;
        } else {
            root->data = minValueBST(root->right);
            return removeBST(&(root->right), root->data);
        }
    }
}

char minValueBST(struct TreeNode* root) {
    struct TreeNode* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

int maxDepth(struct TreeNode* root) {
    int leftDepth, rightDepth;
    if (root == NULL) {
        return 0;
    }
    leftDepth = maxDepth(root->left);
    rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
}

int isBalanced(struct TreeNode* root) {
    int leftDepth, rightDepth;
    if (root == NULL) {
        return 1;
    }
    leftDepth = maxDepth(root->left);
    rightDepth = maxDepth(root->right);

    return abs(leftDepth - rightDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int isBSTUtil(struct TreeNode* root, char min, char max) {
    if (root == NULL) {
        return 1;
    }
    if (root->data < min || root->data > max) {
        return 0;
    }
    return isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data + 1, max);
}

int isBST(struct TreeNode* root) {
    return isBSTUtil(root, CHAR_MIN, CHAR_MAX);
}

void printTreeWithNewLine(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printTreeWithNewLine(root->left);
    printf("%c ", root->data);
    printTreeWithNewLine(root->right);
}

void printTree(struct TreeNode* root) {
    printTreeWithNewLine(root);
    printf("\n"); 
}

void printLeavesWithNewLine(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%c ", root->data);
    }
    printLeavesWithNewLine(root->left);
    printLeavesWithNewLine(root->right);
}

void printLeaves(struct TreeNode* root){
    printLeavesWithNewLine(root);
    printf("\n"); 
}

void printTreeVerboseWithNewLine(struct TreeNode* root) {
    int current_depth;
    static int depth = 1;
    if (root == NULL) {
        return;
    }
    current_depth = depth;
    printf("(%c,%d) ", root->data, current_depth);
    depth++;
    printTreeVerboseWithNewLine(root->left);
    depth--;
    depth++;
    printTreeVerboseWithNewLine(root->right);
    depth--;
}

void printTreeVerbose(struct TreeNode* root) {
    printTreeVerboseWithNewLine(root);
    printf("\n"); 
}
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
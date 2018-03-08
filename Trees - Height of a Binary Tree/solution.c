#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define scan(x) scanf(" %d", &x)
struct TreeNode {
   int x;
   struct TreeNode* L;
   struct TreeNode* R;
};
typedef struct TreeNode TreeNode;
TreeNode* newNode(int _x) {
   TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
   node->x = _x;
   node->L = node->R = NULL;
    return node;
}
TreeNode* insert(TreeNode* node, int val) {
   if (node == NULL) return newNode(val);
   if (val <= node->x) node->L = insert(node->L, val);
   else node->R = insert(node->R, val);
    return node;
}


int height(struct TreeNode*TreeNode)
{
   if (TreeNode==NULL)
       return 0;
   else
   {
       int lDepth = height(TreeNode->L);
       int rDepth = height(TreeNode->R);
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}

int main() {
   int val, N; scan(N);
   TreeNode* Root = NULL;
   for (int i = 1; i <= N; i++) {
      scan(val);
      Root = insert(Root, val);
   }
   printf("%d",height(Root)-1);
          return 0;
}

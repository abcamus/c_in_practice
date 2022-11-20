#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

/**
 * @brief 通过前序遍历和中序遍历重建二叉树
 *
 * @param preorder : 先序遍历顺序
 * @param inorder : 中序遍历顺序
 * @param n : 节点数量
 */
Node *build_binary_tree(int *preorder, int *inorder, int n)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (n == 1) {
        node->left = NULL;
        node->right = NULL;
        node->val = preorder[0];
        return node;
    }
    /* find root node and generate sub preorder and inorder */
    node->val = preorder[0];
    int i;
    for (i = 0; i < n; i++) {
        if (inorder[i] == preorder[0]) {
            break;
        }
    }
    node->left = build_binary_tree(preorder + 1, inorder, i);
    node->right = build_binary_tree(preorder + i + 1, inorder + i + 1, n - i - 1);

    return node;
}

void free_binary_tree(Node *root)
{
    if (root) {
        free_binary_tree(root->left);
        free_binary_tree(root->right);
        root->left = NULL;
        root->right = NULL;
        free(root);
    }
}

void print_tree_preorder(Node *root)
{
    if (root) {
        printf("%d ", root->val);
        print_tree_preorder(root->left);
        print_tree_preorder(root->right);
    }
}

// int main(int argc, char const *argv[])
// {
//     int preorder[] = {1, 2, 4, 5, 3};
//     int inorder[] = {4, 2, 5, 1, 3};
//     Node *tree = build_binary_tree(preorder, inorder, sizeof(preorder) / sizeof(int));
//     print_tree_preorder(tree);

//     printf("%s, %d\n", __func__, __LINE__);
//     free_binary_tree(tree);
//     printf("%s, %d\n", __func__, __LINE__);

//     return 0;
// }

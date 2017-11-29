// BST.cpp

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include "BST.h"

using namespace std;
void BST::load_f(void)
{
    puts("BST created!");
}

void BST::insert_f(void)
{
    char temp[4];
    int val;
    cout << "Enter node val: ";
    cin >> temp;
    while (getchar() != '\n') continue;
    val = atoi(temp);
    access(val);
}

void BST::access(int val)
{
    TreeNode *node, *prev;
    TreeNode *ptr = new TreeNode();
    ptr->val = val;

    if(search(val) != NULL)
    {
        puts("element already existed.");
        return;
    }
    if (root == NULL)
        root = ptr;
    else
    {
        node = root;
        while(node != NULL)
        {
            prev = node;
            if(ptr->val < node->val)
                node = node->llink;
            else
                node = node->rlink;
        }

        if(ptr->val < prev->val)
            prev->llink = ptr;
        else
            prev->rlink = ptr;
    }
}

void BST::delete_f(void)
{
    char temp[4];
    int val;
    if (root == NULL)
    {
        puts("No record!");
        return;
    }
    cout << "Enter delete node: ";
    cin >> temp;
    while (getchar() != '\n') continue;
    val = atoi(temp);
    removing(val);
}

void BST::removing(int val)
{
    TreeNode *del_node;
    if((del_node = search(val)) == NULL)
    {
        puts("no match.");
        return;
    }
    // del_node has at least one child
    if(del_node->llink != NULL || del_node->rlink != NULL)
        del_node = replace(del_node);
    else
        // del_node is root without child
        if(del_node == root)
            root = NULL;
        else
            connect(del_node, 'n');
    free(del_node);
}

TreeNode * BST::replace(TreeNode *node)
{
    TreeNode *re_node;
    if((re_node = search_re_r(node->rlink)) == NULL)
        re_node = search_re_l(node->llink);
    // replace node has right child
    if(re_node->rlink != NULL)
        connect(re_node, 'r');
    else
        if(re_node->llink != NULL)
            // replace node has left child
            connect(re_node, 'l');
        else
            // replace node has no child
            connect(re_node, 'n');
    node->val = re_node->val;
    return re_node;
}

void BST::connect(TreeNode *node, char link)
{
    // parent is the node to delete
    TreeNode *parent;
    parent = search_p(node);
    // replace node val less than it's parent val
    if(node->val < parent->val)
        if(link == 'r')
            parent->llink = node->rlink;
        else
            parent->llink = node->llink;
    // replace node val greater than it's parent val
    else
        if(link == 'l')
            parent->rlink = node->llink;
        else
            parent->rlink = node->rlink;
}

TreeNode * BST::search(int target)
{
    TreeNode *node;
    node = root;
    while(node != NULL)
    {
        if(target == node->val)
            return node;
        else
            if(target < node->val)
                node = node->llink;
            else
                node = node->rlink;
    }
    return node;
}

TreeNode * BST::search_re_r(TreeNode *node)
{
    TreeNode *re_node;
    re_node = node;
    while(re_node != NULL && re_node->llink != NULL)
        re_node = re_node->llink;
    return re_node;

}
TreeNode * BST::search_re_l(TreeNode *node)
{
    TreeNode *re_node;
    re_node = node;
    while(re_node != NULL && re_node->rlink != NULL)
        re_node = re_node->rlink;
    return re_node;
}
TreeNode * BST::search_p(TreeNode *node)
{
    TreeNode *parent;
    parent = root;
    while(parent != NULL)
    {
        // node val less than current node, move left
        if(node->val < parent->val)
            if(node->val == parent->llink->val)
                return parent;
            else
                parent = parent->llink;
        // node val greater than current node, move right
        else
            if(node->val == parent->rlink->val)
                return parent;
            else
                parent = parent->rlink;
    }
    return NULL;
}

void BST::minelement_f(void)
{
    // Create node to store threshold val
    TreeNode *thres = new TreeNode(-1000);
    if(root == NULL)
    {
        puts("No record!");
        return;
    }
    char temp[4];
    int val;
    int ans;
    cout << "Enter threshold val: ";
    cin >> temp;
    while (getchar() != '\n') continue;
    val = atoi(temp);
    inorder_v(root, thres, val);
    if(thres->val == -1000)
        puts("no such element.");
    else
        cout << thres->val << endl;
}

void BST::show_f(void)
{
    if(root == NULL)
    {
        puts("No record!");
        return;
    }
    puts("===== Show Data =====");
    inorder(root);
}

void BST::inorder(struct TreeNode *node)
{
    if(node != NULL)
    {
        inorder(node->llink);
        cout << left << setw(15) << node->val << endl;
        inorder(node->rlink);
    }
}

void BST::inorder_v(TreeNode *node, TreeNode *thres, int v)
{
    if(node != NULL)
    {
        inorder_v(node->llink, thres, v);
        if(v > 0 && v - node->val <= 0)
            thres->val = node->val;
        v -= node->val;
        inorder_v(node->rlink, thres, v);
    }
}

void BST::root_f()
{
    if(root == NULL)
    {
        puts("No record!");
        return;
    }
    cout << "root: " << root->val << endl;
}
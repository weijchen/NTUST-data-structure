// BST.cpp

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include "BST.h"

using namespace std;

// Operation (Ans)
int Ans::get_sum()
{
    return sum;
}
int Ans::get_num()
{
    return num;
}

// Operation(TreeNode)
void TreeNode::set_left(int l)
{
    leftsize = l;
}
void TreeNode::add_left()
{
    val++;
}

void TreeNode::set_rank(int r)
{
    rank = r;
}

// Operation (BST)
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

    if(search(val) != nullptr)
    {
        puts("element already existed.");
        return;
    }
    if (root == nullptr)
        root = ptr;
    else
    {
        node = root;
        while(node != nullptr)
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
    if (root == nullptr)
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
    if((del_node = search(val)) == nullptr)
    {
        puts("no match.");
        return;
    }
    // del_node has at least one child
    if(del_node->llink != nullptr || del_node->rlink != nullptr)
        del_node = replace(del_node);
    else
        // del_node is root without child
        if(del_node == root)
            root = nullptr;
        else
            connect(del_node, 'n');
    free(del_node);
}

void BST::adjust(void)
{
    leftCount(root);
    TreeNode *rank = new TreeNode(1);
    adjust_rank(root, rank);
}
void BST::leftCount(TreeNode *node)
{
    if(node != nullptr)
    {
        leftCount(node->llink);
        TreeNode *lc = new TreeNode(1);
        leftCount_run(node->llink, lc);
        node->set_left(lc->val);
        leftCount(node->rlink);
    }
}
void BST::leftCount_run(TreeNode* n, TreeNode* lc)
{
    if(n != nullptr)
    {
        leftCount_run(n->llink, lc);
        lc->add_left();
        leftCount_run(n->rlink, lc);
    }
}
void BST::adjust_rank(TreeNode *node, TreeNode *rank)
{
    if(node != nullptr)
    {

        adjust_rank(node->llink, rank);
        node->set_rank(rank->val);
        rank->val++;
        adjust_rank(node->rlink, rank);
    }
}

TreeNode * BST::replace(TreeNode *node)
{
    TreeNode *re_node;
    if((re_node = search_re_r(node->rlink)) == nullptr)
        re_node = search_re_l(node->llink);
    // replace node has right child
    if(re_node->rlink != nullptr)
        connect(re_node, 'r');
    else
        if(re_node->llink != nullptr)
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
    while(node != nullptr)
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
    while(re_node != nullptr && re_node->llink != nullptr)
        re_node = re_node->llink;
    return re_node;

}
TreeNode * BST::search_re_l(TreeNode *node)
{
    TreeNode *re_node;
    re_node = node;
    while(re_node != nullptr && re_node->rlink != nullptr)
        re_node = re_node->rlink;
    return re_node;
}
TreeNode * BST::search_p(TreeNode *node)
{
    TreeNode *parent;
    parent = root;
    while(parent != nullptr)
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
    return nullptr;
}

void BST::avg()
{
    char temp_l[4], temp_u[4];
    int l, u;
    cout << "Enter lower bound: ";
    cin >> temp_l;
    while (getchar() != '\n') continue;
    l = atoi(temp_l);
    cout << "Enter upper bound: ";
    cin >> temp_u;
    while (getchar() != '\n') continue;
    u = atoi(temp_u);
    
    int final;
    Ans *ans = new Ans();
    avg_run(root, l, u, ans);
    int s = ans->get_sum();
    int n = ans->get_num();
    final = s/n;
    cout << final << endl;
}

void BST::avg_run(TreeNode *node, int lower, int upper, Ans *ans)
{
    if(node != nullptr)
    {
        avg_run(node->llink, lower, upper, ans);
        if(node->rank >= lower && node->rank <= upper)
        {
            ans->sum += node->val;
            ans->num++;
        }
        avg_run(node->rlink, lower, upper, ans);
    }
}

void BST::show_f(void)
{
    if(root == nullptr)
    {
        puts("No record!");
        return;
    }
    puts("===== Show Data =====");
    inorder(root);
}
void BST::inorder(TreeNode *node)
{
    if(node != nullptr)
    {
        inorder(node->llink);
        cout << "Value: " << node->val;
        cout << "; Leftsize: " << node->leftsize;
        cout << "; Rank: " << node->rank << endl;
        inorder(node->rlink);
    }
}
void BST::root_f()
{
    if(root == nullptr)
    {
        puts("No record!");
        return;
    }
    cout << "root: " << root->val << endl;
}
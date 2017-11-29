// BST.h
#ifndef BST_H_
#define BST_H_ 

using namespace std;

class BST;
class TreeNode{
friend class BST;
private:
    TreeNode *llink;
    TreeNode *rlink;
    int val;
public:
    TreeNode(int i):llink(0),rlink(0),val(i){};
    TreeNode():llink(0),rlink(0),val(0){};
};

class BST
{
private:
    TreeNode *root, *ptr;
public:
    BST():root(0){};
    void load_f(void);
    void insert_f(void);
    void access(int);

    void delete_f(void);
    void removing(int);
    TreeNode *replace(TreeNode *);
    void connect(TreeNode *, char);

    TreeNode *search(int);
    TreeNode *search_re_r(TreeNode *);
    TreeNode *search_re_l(TreeNode *);
    TreeNode *search_p(TreeNode *);

    void minelement_f(void); // return element with the lowest rank
    void show_f(void);
    void inorder(TreeNode *);
    void inorder_v(TreeNode *, TreeNode *, int);
    void root_f(void);   
};
#endif

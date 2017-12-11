// BST.h
#ifndef BST_H_
#define BST_H_ 

using namespace std;

class Ans{
friend class TreeNode;
friend class BST;
private:
    int sum;
    int num;
public:
    Ans():sum(0),num(0){};
    int get_sum();
    int get_num();
};

class BST;
class TreeNode{
friend class BST;
private:
    TreeNode *llink;
    TreeNode *rlink;
    int val;
    int leftsize;
    int rank;
public:
    TreeNode(int i):llink(0),rlink(0),val(i),leftsize(0){};
    TreeNode():llink(0),rlink(0),val(0),leftsize(0){};
    void set_left(int);
    void add_left();
    void set_rank(int);
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
    void size(void);

    void adjust(void);
    void leftCount(TreeNode *);
    void leftCount_run(TreeNode*, TreeNode*);
    void adjust_rank(TreeNode *, TreeNode *);   // function to deduct leftsize from delete node

    TreeNode *replace(TreeNode *);
    void connect(TreeNode *, char);

    TreeNode *search(int);
    TreeNode *search_re_r(TreeNode *);
    TreeNode *search_re_l(TreeNode *);
    TreeNode *search_p(TreeNode *);

    void avg();
    void avg_run(TreeNode *, int, int, Ans *);

    void show_f(void);
    void inorder(TreeNode *);
    void root_f(void);   
};
#endif

/* AVL Tree Implementation in C++   */
/* Harish R                         */


#include<iostream>

using namespace std;

class BST
{
    struct node
    {
        int data;///Data member
        node* left;//left node
        node* right;//Right node
        int height;//Calculaate the height tree
    };

    node* root;///root node

    void makeEmpty(node* insertnode)
    {
        if(insertnode == NULL)
            return;
        makeEmpty(insertnode->left);///Emptying the tree using recursion
        makeEmpty(insertnode->right);//Erases right
        delete insertnode;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
        {
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }

    node* singleRightRotate(node* &t)
    {
        node* u = t->left;//U = the left of t
        node* m = u->right;
        t->left = u->right;//u->right == t->left
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;




    }











    node* singleLeftRotate(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }



















    node* doubleLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }



















    node* doubleRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node* findMin(node* minnode)
    {
        if(minnode == NULL)
            return NULL;
        else if(minnode->left == NULL)
            return minnode;
        else
            return findMin(minnode->left);//Finds the smallest number in the tree
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);//Finds the largest number tree
    }

    node* remove(int x, node* deletenode)
    {
        node* temp;

        // Element not found
        if(deletenode == NULL)
            return NULL;

        // Searching for element
        else if(x < deletenode->data)
            deletenode->left = remove(x, deletenode->left);
        else if(x > deletenode->data)
            deletenode->right = remove(x, deletenode->right);

        // Element found
        // With 2 children
        else if(deletenode->left && deletenode->right)
        {
            temp = findMin(deletenode->right);
            deletenode->data = temp->data;
            deletenode->right = remove(deletenode->data, deletenode->right);
        }
        // With one or zero child
        else
        {
            temp = deletenode;
            if(deletenode->left == NULL)
                deletenode = deletenode->right;
            else if(deletenode->right == NULL)
                deletenode = deletenode->left;
            delete temp;
        }
        if(deletenode == NULL)
            return deletenode;

        deletenode->height = max(height(deletenode->left), height(deletenode->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(deletenode->left) - height(deletenode->right) == 2)
        {
            // right right case
            if(height(deletenode->left->left) - height(deletenode->left->right) == 1)
                return singleLeftRotate(deletenode);
            // right left case
            else
                return doubleLeftRotate(deletenode);
        }
        // If right node is deleted, left case
        else if(height(deletenode->right) - height(deletenode->left) == 2)
        {
            // left left case
            if(height(deletenode->right->right) - height(deletenode->right->left) == 1)
                return singleRightRotate(deletenode);
            // left right case
            else
                return doubleRightRotate(deletenode);
        }
        return deletenode;
    }

    int height(node* getheight)
    {
        return (getheight == NULL ? -1 : getheight->height);
    }

    int getBalance(node* balancedboi)
    {
        if(balancedboi == NULL)
            return 0;
        else
            return height(balancedboi->left) - height(balancedboi->right);
    //Subtracts the left part of the tree to the right
    }

    void inorder(node* ordermetimbers)
    {
        if(ordermetimbers == NULL)
            return;
        inorder(ordermetimbers->left);
        cout << ordermetimbers->data << " ";
        inorder(ordermetimbers->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST t;
    t.insert(4);
    t.insert(6);
    t.insert(10);

    t.display();
}
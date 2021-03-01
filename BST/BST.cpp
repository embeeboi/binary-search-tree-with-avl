#include "BST.hpp"
using namespace std;


BST::BST(int x) : data(x) , right(nullptr) , left(nullptr) {}



BST* newnode(int x=0)
    {
        return new BST(x);
    }


 

BST* insertnode(BST* container,int element)
{
    if(container == nullptr)
    {
        return newnode(element);
    }
    else if(container->data > element)
    {
        container->left = insertnode(container->left,element);
    }
    else if(container->data< element)
    {
        container->right = insertnode(container->right,element);
    }
    

    return container;

}

bool deletenode(int x, BST* node)
{
    if(node->left== nullptr && node->right == nullptr)
    {
        return false;
   }
   deletenode(x,node);


}

bool show(BST* node)
    {
        if(node == nullptr)
        {
            return false;
        }
        show(node->left);
        cout << "{" << node->data << "} ";
        show(node->right);
        return true;
    }


#include "BST.cpp"
#include <vector>


int main()
{
    BST* firsttree = nullptr;
    BST* secondtree = nullptr;
    vector<int> tree1{1,2,3,4,5,6,7,8};
    vector<int> tree2{20,2,3,7,9,32,4,5,2,2};

   for(int x : tree1)
   {
       firsttree = insertnode(firsttree,x);
   }
   for(int x: tree2)
   {
       secondtree = insertnode(secondtree,x);
   }
  
  show(firsttree);
  cout << endl;
  show(secondtree);
  cout << endl;
    
    
}
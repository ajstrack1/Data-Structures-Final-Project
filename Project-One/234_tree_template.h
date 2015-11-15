

/******	I tried to change as much as I could to fit our need for 2-3-4 tree,
		though there's probably a lot we need to change here.				*****/



#include <iostream>

#ifndef 234_TREE
#define 234_TREE

template <typename DataType>
class tree
{
 public:
  /***** Function Members *****/
  tree();


  bool empty() const;
 

  bool search(const DataType & item) const; 
 
   
  void insert(const DataType & item);
  
  
  void remove(const DataType & item);

 
  void inorder(ostream & out) const;
  /*------------------------------------------------------------------------
    Inorder traversal of BST.
 ------------------------------------------------------------------------*/
 
  void graph(ostream & out) const;
  /*------------------------------------------------------------------------
    Graphic output of BST.

    Precondition:  ostream out is open.
    Postcondition: Graphical representation of BST has been output to out.
    Note: graph() uses private auxiliary function graphAux().
 ------------------------------------------------------------------------*/
 
 private:
  /***** Node class *****/
  class Node234 
  {
   public:
    DataType data [3];
    Node234 * child[4];

  
  };

  typedef Node234 * Pointer234; 
  
  /***** Private Function Members *****/		//Not Sure if we need all of these or not
  void search2(const DataType & item, bool & found,
              BinNodePointer & locptr, BinNodePointer & parent) const;
 /*------------------------------------------------------------------------
   Locate a node containing item and its parent.
 
   Precondition:  None.
   Postcondition: locptr points to node containing item or is null if 
       not found, and parent points to its parent.#include <iostream>
 ------------------------------------------------------------------------*/
 
  void inorderAux(ostream & out, 
                 BinNodePointer subtreePtr) const;
  /*------------------------------------------------------------------------
    Inorder traversal auxiliary function.

    Precondition:  ostream out is open; subtreePtr points to a subtree 
        of this BST.
    Postcondition: Subtree with root pointed to by subtreePtr has been
        output to out.
 ------------------------------------------------------------------------*/
 
  void graphAux(ostream & out, int indent,
                     BinNodePointer subtreeRoot) const;
  /*------------------------------------------------------------------------
    Graph auxiliary function.

    Precondition:  ostream out is open; subtreePtr points to a subtree 
        of this BST.
    Postcondition: Graphical representation of subtree with root pointed 
        to by subtreePtr has been output to out, indented indent spaces.
 ------------------------------------------------------------------------*/
}

#endif

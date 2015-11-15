 
/***************	All of these pertain to the BST example from chptr 12 source code
					Should contain all of the data members we need, though definitions
					must be rewritten to fit 2-3-4 tree.								***************/
				


/***** Data Members *****/
  BinNodePointer myRoot; 

}; // end of class template declaration

//--- Definition of constructor
template <typename DataType>
inline BST<DataType>::BST()
: myRoot(0)
{}

//--- Definition of empty()
template <typename DataType>
inline bool BST<DataType>::empty() const
{ return myRoot == 0; }

//--- Definition of search()
template <typename DataType>
bool BST<DataType>::search(const DataType & item) const
{
   BinNodePointer locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}

//--- Definition of insert()
template <typename DataType>
inline void BST<DataType>::insert(const DataType & item)
{
   BinNodePointer 
        locptr = myRoot,   // search pointer
        parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}

//--- Definition of remove()
template <typename DataType>
void BST<DataType>::remove(const DataType & item)
{
   bool found;                      // signals if item is found
   BinNodePointer 
      x,                            // points to node to be deleted
      parent;                       //    "    " parent of x and xSucc
   search2(item, found, x, parent);

   if (!found)
   {
      cout << "Item not in the BST\n";
      return;
   }
   //else
   if (x->left != 0 && x->right != 0)
   {                                // node has 2 children
      // Find x's inorder successor and its parent
      BinNodePointer xSucc = x->right;
      parent = x;
      while (xSucc->left != 0)       // descend left
      {
         parent = xSucc;
         xSucc = xSucc->left;
      }

     // Move contents of xSucc to x and change x 
     // to point to successor, which will be removed.
     x->data = xSucc->data;
     x = xSucc;
   } // end if node has 2 children

   // Now proceed with case where node has 0 or 2 child
   BinNodePointer 
      subtree = x->left;             // pointer to a subtree of x
   if (subtree == 0)
      subtree = x->right;
   if (parent == 0)                  // root being removed
      myRoot = subtree;
   else if (parent->left == x)       // left child of parent
      parent->left = subtree; 
   else                              // right child of parent
      parent->right = subtree;
   delete x;
}

//--- Definition of inorder()
template <typename DataType>
inline void BST<DataType>::inorder(ostream & out) const
{ 
   inorderAux(out, myRoot); 
}

//--- Definition of graph()
template <typename DataType>
inline void BST<DataType>::graph(ostream & out) const
{ graphAux(out, 0, myRoot); }

//--- Definition of search2()
template <typename DataType>
void BST<DataType>::search2(const DataType & item, bool & found,
                            BinNodePointer & locptr, 
                            BinNodePointer & parent) const
{
   locptr = myRoot;
   parent = 0;
   found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
      {
         parent = locptr;
         locptr = locptr->left;
      }
      else if (locptr->data < item)  // descend right
      {
         parent = locptr;
         locptr = locptr->right;
      }
      else                           // item found
         found = true;
   }
}

//--- Definition of inorderAux()
template <typename DataType>
void BST<DataType>::inorderAux(ostream & out, 
                               BinNodePointer subtreeRoot) const
{
   if (subtreeRoot != 0)
   {
      inorderAux(out, subtreeRoot->left);    // L operation
      out << subtreeRoot->data << "  ";      // V operation
      inorderAux(out, subtreeRoot->right);   // R operation
   }
}

//--- Definition of graphAux()
#include <iomanip>

template <typename DataType>
void BST<DataType>::graphAux(ostream & out, int indent, 
                             BinNodePointer subtreeRoot) const
{
  if (subtreeRoot != 0)
    {
      graphAux(out, indent + 8, subtreeRoot->right);
      out << setw(indent) << " " << subtreeRoot->data << endl;
      graphAux(out, indent + 8, subtreeRoot->left);
    }

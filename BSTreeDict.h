#include "BSTree.h"
#nclude "Dict.h"
#include "TableEntry.h"

template <typename V> class BSTreeDict.h{
 private:
  BSTree<TableEntry<V>>* tree;

 public:
  BSTreeDict(){
    tree = nullptr;
  }

  ~BSTreeDict(){
    delete tree;
  }

  friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){

  }

  V operator[](std::string key){

  }
};

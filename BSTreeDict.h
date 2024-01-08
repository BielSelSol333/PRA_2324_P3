#include "Dict.h"
#include "BSTree.h"
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
    out << "('" << bs.tree->key << "' => " << bs.tree->value << ") ";x
  }

  V operator[](std::string key){
    
  }

  void insert(std::string key, V value)override{

  }
  
  V search(std::string key)override{

  }
  
  V remove(std::string key)override{

  }
  
  int entries()override{

  }
};

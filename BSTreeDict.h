#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V> class BSTreeDict : public Dict<V>{
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
    if(bs.tree != nullptr){
      out << "('" << bs << "' => " << bs << ") ";
    }
    return out;
  }

  V operator[](std::string key){
    return search(key);
  }

  void insert(std::string key, V value)override{
    
  }
  
  V search(std::string key)override{
    if(tree == nullptr){
      throw std::runtime_error("El árbol está vacío");
    }else{

    }
  }
  
  V remove(std::string key)override{
    if(tree == nullptr){
      throw std::runtime_error("El árbol está vacío");
    }else{
      tree->remove();
    }
  }
  
  int entries()override{
    if(tree != nullptr){
      return tree->size();
    }else{
      return 0;
    }
  }
};

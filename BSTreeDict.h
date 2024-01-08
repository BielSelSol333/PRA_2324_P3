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
      out << bs.tree;
    }
    return out;
  }

  V operator[](std::string key){
    TableEntry<V> aux(key);

    return tree->search(aux).value;
  }

  void insert(std::string key, V value)override{
    TableEntry<V> aux(key, value);
    if(tree->size() == 0){
      tree = new BSTree<TableEntry<V>>;
    }else{
      tree->insert(aux);
    }
  }
  
  V search(std::string key)override{
    TableEntry<V> aux(key);
    
    if(tree == nullptr){
      throw std::runtime_error("El árbol está vacío");
    }else{
      tree->search(aux).value;
    }
  }
  
  V remove(std::string key)override{
    TableEntry<V> aux(key);
    
    if(tree == nullptr){
      throw std::runtime_error("El árbol está vacío");
    }else{
      V el = tree->search(aux).value;
      tree->remove(aux);
      return el;
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

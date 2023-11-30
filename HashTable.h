#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "../PRA_2324_P1/ListLinked.h"

template <typename V> class HashTable : public Dict<V>{
 private:
  int n;
  int max;
  ListLinked<TableEntry<V>>* table;
  int h(std::string key);

  
 public:
  HashTable(int size){
    table = new ListLinked<TableEntry<V>> [size];
    n = 0;
    max = size;
  }
  
  ~HashTable(){
    delete [] table;
    n = 0;
    max = 0;
  }
  
  int capacity(){
    return max;
  }
  
  friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
    out << "List => [";
    for(int i=0; i<th.max; i++){
      out << th.table->value << " ";
    }
    out << "]";
    return out;
  }
  
  V operator[](std::string key){
    if(key != key){
      throw std::runtime_error("No existe esa clave");
    }
    
  }
  
  void insert(std::string key, V value)override{
    
  }
  
  V search(std::string key)override{
    
  }
  
  V remove(std::string key)override{

  }
  
  int entries()override{
    return n;
  }
};

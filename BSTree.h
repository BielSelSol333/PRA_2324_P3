#include "BSNode.h"

template <typename T> class BSTree{
 private:
  int nelem;
  BSNode<T> *root;

  BSNode<T>* search(BSNode<T>* n, T e) const{
     if(n->elem = e){
      return n;
     }/*else if(n->left == nullptr && n->right == nullptr && n->elem != e){
       throw std::runtime_eror("El elemento no se encuentra en el arbol");
     }*/else{
       search(n->left, e);
       search(n->right, e);
    }
  }

  BSNode<T>* insert(BSNode<T>* n, T e){
    //throw std::runtime_eror("El elemento no se encuentra en el arbol");
  }

  void print_inorder(std::ostream &out, BSNode<T> n) const{
    out << 
  }

   BSNode<T>* remove(BSNode<T>* n, T e){
     //throw std::runtime_eror("El elemento no se encuentra en el arbol");
  }

   T max(BSNode<T>* n) const{
     do{
       n->right;
     }while(n != nullptr);
     
     return n->elem;
   }

   BSNode<T>* remove_max(BSNode<T>* n){

   }

   void delete_cascade(BSNode<T>* n){
     if(n == nullptr){
       delete n;
     }else{
       BNode<T> *aux = n;
       delete_cascade(n->left);
       delete_cascade(n->right);
       delete aux;
     }
   }
   
 public:
  BSTree(){
    nelem = 0;
    root = nullptr;
  }
  
  int size() const{
    return nelem;
  }

  T search(T e) const{
    BSNode<T> aux = search(root, e).elem;
    return aux->elem;
  }

  T operator[](T e) const{
    return search(e);
  }

  void insert(T e){
    insert(root, e);
  }

  friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
    return out << bst.print_inorder(out, bst.root) <<std::endl;
  }

  void remove(T e){
    remove(root, e);
  }

  ~BSTree(){
    delete_cascade(root);
  }
};

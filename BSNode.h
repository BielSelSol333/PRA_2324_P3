#include <ostream>

template <typename T> class BSNode{
 private:
  T elem;
  BSNode<T> *left;
  BSNode<T> *right;

 public:
  BSNode(T elem, BSNode<T>* left=nullptr, BSNode<T>* right=nullptr){
    this->elem = elem;
    this->left = left;
    this->right = right;
  }

  friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn){
    BSNode<T> *auxL = bsn.left, *auxR = bsn.right;
    do{
      auxL->bsn.left;
      auxR->bsn.right;
      out << auxL->elem << " " << auxR->elem << " "; 
    }while(auxL->bsn.left != nullptr || auxR->bsn.right != nullptr);
    return out;
  }
};

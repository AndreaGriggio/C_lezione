#include <iostream>
#include <sstream>
#include <string>
template < typename T>

struct Node{
    T value;
    Node<T>* left;
    Node<T>* right;

    Node();
    Node(const T& value);
    ~Node();

    std::string toString();
};
template <typename T>
Node <T>::Node() : value{}, left(nullptr), right(nullptr) {}

template <typename T>
Node<T>::Node(const T  &value){
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}
template <typename T>
Node<T>::~Node(){}


template <typename T>
std::string Node<T>::toString() {
    std::ostringstream s;
    s << ",(" << this->value << ")";
    return s.str();
}

template <typename T>
class BinaryTree{
    private:
        Node<T>* root;
    public:
        BinaryTree() : root(nullptr){}
        BinaryTree(Node<T>* root) : root(root) {}
        ~BinaryTree();
        void clear(Node<T>* n);

        //utility
        bool isEmpty()const { return this->root == nullptr;}
        int getSize(Node<T>* r );
        void insert(const T& value);
        void createNode(const T& value,Node<T> * n);
        bool search(const T& value,Node<T>* n);
        Node<T>* getRoot(){return this->root;}

        //max e min
        T& min(Node<T>* n);
        T& max(Node<T>* n);

        //viste dell'albero
        void preorder(Node<T>* r);
        void inorder(Node<T>* r);
        void postorder(Node<T>* r);
};

template <typename T>
int BinaryTree<T>::getSize(Node<T>* r){
    int count = 0;
    if(r->left != nullptr){
        count = count + getSize(r->left);
    }
    if(r->right != nullptr){
        count = count + getSize(r->right);
    }
    return count + 1 ;
}

template <typename T>
void BinaryTree<T>::insert(const T &value){


    if(!this->root){ //se la radice nulla allora la creo
        std::cout << "Radice creata" << std::endl;
        Node<T>* root = new Node<T>(value);
        root->value = value;
        this->root = root;
        return;
    }else{
        createNode(value,this->root);
    }
}

template <typename T>
void BinaryTree<T>::createNode(const T& value,Node<T>* n){
    if(n->value < value){

        if(!n->right)n->right = new Node<T>(value);

        else createNode(value,n->right);

    }else{

        if(!n->left )n->left = new Node<T>(value);

        else createNode(value,n->left);
       
    }

}

template <typename T>
BinaryTree<T>::~BinaryTree(){
    clear(this->root);
    root = nullptr;
}

template <typename T>
void BinaryTree<T>::clear(Node<T>* n){
    if(!n){return ;}
    clear(n->left);
    clear(n->right);
    delete n;
}
template <typename T>
bool BinaryTree<T>::search(const T& value,Node<T>* n){
    if(!n)return false;
    if(n->value == value)return true;
    if(n->value < value) return search(value,n->right);
    else return search(value,n->left);
}

template <typename T>
T& BinaryTree<T>::min(Node<T>* n){
    if(!n->left)return n->value;
    return min(n->left);
}

template <typename T>
T& BinaryTree<T>::max(Node<T>* n){
    if(!n->right)return n->value;
    return max(n->right);
}

template <typename T>

void BinaryTree<T>::preorder(Node<T>* r){
    if(!r){return ;}
    std::cout << r->toString() << " ";
    preorder(r->left);
    preorder(r->right);
}
template <typename T>
void BinaryTree<T>::inorder(Node<T>* r){
    if(!r){return ;}
    inorder(r->left);
    std::cout << r->toString() << " ";
    inorder(r->right);
}
template <typename T>

void BinaryTree<T>::postorder(Node<T>* r){
    if(!r){return ;}
    postorder(r->left);
    postorder(r->right);
    std::cout << r->toString() << " ";
}



int main(){

    BinaryTree<int> b;
    
    b.insert(1);
    b.insert(5);
    b.insert(2);
    b.insert(12);
    b.insert(17);


    b.insert(10);
    b.inorder(b.getRoot());
    std::cout << std::endl;
    std::cout << b.getSize(b.getRoot()) << std:: endl;
    b.insert(10);
    b.inorder(b.getRoot());
    std::cout << std::endl;
    std::cout << b.getSize(b.getRoot()) << std:: endl;
    b.insert(15);
    b.inorder(b.getRoot());
    std::cout << std::endl;
    std::cout << b.getSize(b.getRoot()) << std:: endl;
    b.insert(20);
    b.inorder(b.getRoot());
    std::cout << std::endl;
    std::cout << b.getSize(b.getRoot()) << std:: endl;

    std::cout << b.search(99,b.getRoot()) << std::endl;

    std::cout << b.min(b.getRoot()) << std::endl;
    std::cout << b.max(b.getRoot()) << std::endl;

    return 0;
}
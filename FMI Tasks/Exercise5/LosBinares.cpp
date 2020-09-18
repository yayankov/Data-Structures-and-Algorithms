#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ctr2 = -1;

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node() = default;
    
    Node(int value) {
        data = value;
    }

    ~Node() {
        delete left;
        delete right;
    }

    Node(const Node& rhs) {
        data = rhs.data;
        if (rhs.left) {
            left = new Node(*rhs.left);
        }
        if (rhs.right) {
            right = new Node(*rhs.right);
        }
    }

    Node& operator=(const Node& rhs) {
        if (this != &rhs) {
            delete left;
            delete right;

            data = rhs.data;
            if (rhs.left) {
                left = new Node(*rhs.left);
            }
            if (rhs.right) {
                right = new Node(*rhs.right);
            }
        }
        return *this;
    }
};

class BST {
private:
    Node* root = nullptr;

    int _exists(int value, Node* current) {
       
        if (current) {
            
            if (current->data == value) {
                ctr2++;
                return ctr2;
            } else if (value > current->data) {
                ctr2++;
                return _exists(value, current->right);
            } else { // value < data
                ctr2++;
                return _exists(value, current->left);
            }
            
        } else {
            return -1;
        }
    }

    Node* _insert(int value, Node* current) {
        if (!current) {
            return new Node(value);
        }
        
        if (value < current->data) {
            current->left = _insert(value, current->left);
        } else if (value > current->data) {
            current->right = _insert(value, current->right);
        }

        return current;
    }

public:
    BST() = default;
    BST(const BST& rhs) {
        root = new Node(*rhs.root);
    }
    BST& operator=(const BST& rhs) {
        if (this != &rhs) {
            delete root;
            root = new Node(*rhs.root);
        }
        return *this;
    }
    ~BST() {
        delete root;
    }
    int exists(int value) {
        ctr2 = -1;
        return _exists(value, root);
    }

    void insert(int value) {
        root = _insert(value, root);
    }

};

    
int main() {
    BST tree;
    int N, K;
    cin >> N >> K;
    int input;
    int ctr;
    for(int i=0; i<N; i++)
    {
        cin >> input;
        tree.insert(input);
    }
    for(int j=0; j<K; j++)
    {
        cin >> input;
        ctr = tree.exists(input);
        if(ctr > -1)
        {
            cout << ctr << endl;
        }
        else 
        {
            cout << ctr << endl;
        }
    }
    
    return 0;
}

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
	double value;
	Node *left;
	Node *right;
    int height = 0;
	Node(double value, Node *left, Node *right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
     void calculateHeight() {
        height = 0;
        if (left) {
            height = max(height, left->height + 1);
        }
        if (right) {
            height = max(height, right->height + 1);
        }
    }

    int leftHeight() const {
        if (left) {
            return left->height + 1;
        }
        return 0;
    }

    int rightHeight() const {
        if (right) {
            return right->height + 1;
        }
        return 0;
    }

    int balance() const {
        return leftHeight() - rightHeight();
    }

    void rotateRight() {
        if (!left) {
            return;
        }

        Node* leftRight = this->left->right;
        Node* oldRight = this->right;

        swap(this->value, this->left->value);
        this->right = this->left;
        this->left = this->left->left;
        this->right->left = leftRight;
        this->right->right = oldRight;
    }

    void rotateLeft() {
        if (!right) {
            return;
        }

        Node* rightLeft = this->right->left;
        Node* oldLeft = this->left;

        swap(this->value, this->right->value);
        this->left = this->right;
        this->right = this->right->right;
        this->left->left = oldLeft;
        this->left->right = rightLeft;
    }

    void recalculateHeights() {
        if (left) {
            left->calculateHeight();
        }
        if (right) {
            right->calculateHeight();
        }
        this->calculateHeight();
    }

    void fixTree() {
        if (balance() < -1) { // Right is heavier
            if (right->balance() <= -1) { // RR
                this->rotateLeft();
                recalculateHeights();
            }
            else if (right->balance() >= 1) { // RL
                right->rotateRight();
                this->rotateLeft();
                recalculateHeights();
            }
        }
        else if (balance() > 1) { // Left is heavier
            if (left->balance() >= 1) { // LL
                this->rotateRight();
                recalculateHeights();
            }
            else if (left->balance() <= -1) { // LR
                left->rotateLeft();
                this->rotateRight();
                recalculateHeights();
            }
        }
    }
};

class AVLTree
{
private:
	Node *root;

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}
    
    Node* addRec(double value,Node* current)
    {
        if(!current)
        {
            return new Node(value,nullptr, nullptr);
        }
        if(value > current->value)
        {
            current->right = addRec(value,current->right);
        }
        else if(value < current->value)
        {
            current->left = addRec(value,current->left);
        }
        current->calculateHeight();
        current->fixTree();
        return current;
    }
    
    Node* deleteRec(double value, Node* current)
    {
        if(!current)
        {
            return nullptr;
        }
        if(value > current->value)
        {
            current->right = deleteRec(value, current->right);
        }
        else if(value < current->value)
        {
            current->left = deleteRec(value, current->left);
        }
        else 
        {
            if(!current->left && !current->right)
            {
                free(current);
                return nullptr;
            } 
            else if(!current->left)
            {
                Node* temp = current->right;
                free(current);
                return temp;
            }
            else if(!current->right)
            {
                Node* temp = current->left;
                free(current);
                return temp;
            }
            else 
            {
                Node* tempSwap = current->right;
                while(tempSwap->left)
                {
                    tempSwap = tempSwap->left;
                }
                current->value = tempSwap->value;
                current->right = deleteRec(tempSwap->value, current->right);
            }
        }
        current->calculateHeight();
        current->fixTree();

        return current;
    }

public:
	AVLTree()
	{
		root = NULL;
	}

	void add(double value)
	{
        if(contains(value))
        {
           // cout << fixed << setprecision(6) << value << " already added"<<'\n';
            cout <<value << " already added"<<'\n';
        }
        else root = addRec(value, root);
       
	}

	void remove(double value)
	{
        if(!contains(value))
        {
            //cout << fixed << setprecision(6) << value << " not found to remove"<<'\n';
            cout << value << " not found to remove"<<'\n';
        }
        else
        {
            root = deleteRec(value, root); 
        }
       
	}

bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
        cout << endl;
	}
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
    cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}

	return 0;
}

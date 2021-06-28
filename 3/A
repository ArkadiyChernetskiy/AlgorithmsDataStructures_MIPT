#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node(int value) : h(1), k(value) {}
    unsigned char h;
    int k;
    Node* childLeft = NULL;
    Node* childRight = NULL;
    ~Node() {
        delete childLeft;
        delete childRight;
    }
};

class AVL {
public:
    void INSERT(int value) {
        root = insert(root, value);
    }
    void DELETE(int value) {
        root = del(root, value);
    }
    bool EXISTS(int value) {
        return find(root, value);
    }
    int NEXT(int value) {
        return next(root, value);
    }
    int PREV(int value) {
        return prev(root, value);
    }
private:
    Node* root = nullptr;
    Node* del(Node* p, int value);
    bool find(Node* helpNode_ptr, int value);
    int prev(Node* p, int value);
    int next(Node* p, int value);
    Node* findMin(Node* p);
    Node* delmMin(Node* p);
    Node* insert(Node* p, int value);
    unsigned char height(Node* p);
    int bCondition(Node* p);
    void updHeight(Node*& p);
    Node* rotateRight(Node* p);
    Node* rotateLeft(Node* p);
    Node* balance(Node* p);
};

Node *AVL::del(Node *p, int value) {
    if (!(p)) {
        return 0;
    }
    if (value >= p->k) {
        if (value > p->k) {
            p->childRight = del(p->childRight, value);
            p = balance(p);
            updHeight(p);
            return p;
        } else if (p->childRight == nullptr) {
            Node *left = p->childLeft;
            return left;
        } else {
            Node *minR = findMin(p->childRight);
            minR->childRight = delmMin(p->childRight);
            minR->childLeft = p->childLeft;
            minR = balance(minR);
            updHeight(minR);
            return minR;
        }
    } else {
        p->childLeft = del(p->childLeft, value);
        p = balance(p);
        updHeight(p);
        return p;
    }
}

bool AVL::find(Node *helpNode_ptr, int value) {
    while (helpNode_ptr && helpNode_ptr->k != value) {
        helpNode_ptr = value > helpNode_ptr->k ? helpNode_ptr->childRight : helpNode_ptr->childLeft;
    }
    return !(helpNode_ptr) ? false : true;
}

int AVL::prev(Node *p, int value) {
    int answer = value;
    while (p) {
        if (p->k >= value) {
            p = p->childLeft;
        } else {
            answer = p->k;
            p = p->childRight;
        }
    }
    return answer;
}

int AVL::next(Node *p, int value) {
    int answer = value;
    while (p) {
        if (p->k > value) {
            answer = p->k;
            p = p->childLeft;
        } else {
            p = p->childRight;
        }
    }
    return answer;
}

Node *AVL::findMin(Node *p) {
    Node* helpNode = p;
    while (helpNode->childLeft) {
        helpNode = helpNode->childLeft;
    }
    return helpNode;
}

Node *AVL::delmMin(Node *p) {
    if (p->childLeft) {
        p->childLeft = delmMin(p->childLeft);
        p = balance(p);
        updHeight(p);
        return p;
    } else {
        return p->childRight;
    }
}

Node *AVL::insert(Node *p, int value) {
    if (!(p)) {
        p = new Node(value);
    } else if (value > p->k) {
        p->childRight = insert(p->childRight, value);
        p = balance(p);
    } else {
        p->childLeft = insert(p->childLeft, value);
        p = balance(p);
    }
    updHeight(p);
    return p;
}

unsigned char AVL::height(Node *p) {
    return p ? p->h : 0;
}

int AVL::bCondition(Node *p) {
    return height(p->childLeft) - height(p->childRight);
}

void AVL::updHeight(Node *&p) {
    unsigned char height_left = height(p->childLeft);
    unsigned char height_right = height(p->childRight);
    p->h = (height_right > height_left ? height_right : height_left) + 1;
}

Node *AVL::rotateRight(Node *p) {
    Node* q = p->childLeft;
    p->childLeft = q->childRight;
    q->childRight = p;
    updHeight(p);
    updHeight(q);
    return q;
}

Node *AVL::rotateLeft(Node *p) {
    Node* q = p->childRight;
    p->childRight = q->childLeft;
    q->childLeft = p;
    updHeight(p);
    updHeight(q);
    return q;
}

Node *AVL::balance(Node *p) {
    updHeight(p);
    if (bCondition(p) != -2) {
        if (bCondition(p) == 2) {
            if (bCondition(p->childLeft) == -1) {
                p->childLeft = rotateLeft(p->childLeft);
            }
            p = rotateRight(p);
        }
    } else {
        if (bCondition(p->childRight) == 1) {
            p->childRight = rotateRight(p->childRight);
        }
        p = rotateLeft(p);
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    AVL tree;
    string command;
    int x;
    while (cin >> command) {
        cin >> x;
        if (!(command == "insert")) {
            if (command == "delete") {
                if (tree.EXISTS(x)) {
                    tree.DELETE(x);
                }
            } else if (command == "exists") {
                cout << (tree.EXISTS(x) ? "true" : "false") << endl;
            } else if (command == "prev") {
                if (tree.PREV(x) != x) {
                    cout << tree.PREV(x) << "\n";
                } else {
                    cout << "none" << "\n";
                }
            } else if (command == "next") {
                if (tree.NEXT(x) == x) {
                    cout << "none" << "\n";
                } else {
                    cout << tree.NEXT(x) << "\n";
                }
            }
        } else {
            if (!(tree.EXISTS(x))) {
                tree.INSERT(x);
            }
        }
    }
    return 0;
}

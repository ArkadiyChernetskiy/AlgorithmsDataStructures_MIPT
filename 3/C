#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node(long long value) : h(1), k(value), depth(1) {}
    unsigned char h;
    long long k;
    size_t depth;
    Node* childLeft = NULL;
    Node* childRight = NULL;
    ~Node() {
        delete childLeft;
        delete childRight;
    }
};

class AVL {
public:
    void INSERT(long long value) {
        root = insert(root, value);
    };

    void DELETE(long long value) {
        root = del(root, value);
    };

    long long FINDKEY(long long k){
        return findKey(root, k);
    };

private:
    Node* root = nullptr;
    Node* del(Node* p, long long value);
    Node* findMin(Node* p);
    Node* delMin(Node* p);
    Node* insert(Node* p, long long value);
    unsigned char height(Node* p);
    long long bCondition(Node* p);
    void updHeight(Node*& p);
    Node* rotateRight(Node* p);
    Node* rotateLeft(Node* p);
    Node* balance(Node* p);
    size_t depth(Node* p);
    long long findKey(Node*p, long long ki);
    void updDepth(Node*& p);
};

Node *AVL::del(Node *p, long long value) {
    if (!(p)) {
        return 0;
    }
    if (value >= p->k) {
        if (value > p->k) {
            p->childRight = del(p->childRight, value);
            p = balance(p);
            updHeight(p);
            updDepth(p);
            return p;
        } else if (p->childRight == nullptr) {
            Node *left = p->childLeft;
            return left;
        } else {
            Node *minR = findMin(p->childRight);
            minR->childRight = delMin(p->childRight);
            minR->childLeft = p->childLeft;
            minR = balance(minR);
            updHeight(minR);
            updDepth(minR);
            return minR;
        }
    } else {
        p->childLeft = del(p->childLeft, value);
        p = balance(p);
        updHeight(p);
        updDepth(p);
        return p;
    }
}

Node *AVL::findMin(Node *p) {
    Node* helpNode = p;
    while (helpNode->childLeft) {
        helpNode = helpNode->childLeft;
    }
    return helpNode;
}

Node *AVL::delMin(Node *p) {
    if (p->childLeft) {
        p->childLeft = delMin(p->childLeft);
        p = balance(p);
        updHeight(p);
        updDepth(p);
        return p;
    } else {
        return p->childRight;
    }
}

Node *AVL::insert(Node *p, long long value) {
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
    updDepth(p);
    return p;
}

unsigned char AVL::height(Node *p) {
    return p ? p->h : 0;
}

long long AVL::bCondition(Node *p) {
    return height(p->childLeft) - height(p->childRight);
}

void AVL::updHeight(Node *&p) {
    p->h = (height(p->childRight) >  height(p->childLeft) ? height(p->childRight) :  height(p->childLeft)) + 1;
}

Node *AVL::rotateRight(Node *p) {
    Node* q = p->childLeft;
    p->childLeft = q->childRight;
    q->childRight = p;
    updHeight(p);
    updDepth(p);
    updHeight(q);
    updDepth(q);
    return q;
}

Node *AVL::rotateLeft(Node *p) {
    Node* q = p->childRight;
    p->childRight = q->childLeft;
    q->childLeft = p;
    updHeight(p);
    updDepth(p);
    updHeight(q);
    updDepth(q);
    return q;
}

Node *AVL::balance(Node *p) {
    updHeight(p);
    updDepth(p);
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

size_t AVL::depth(Node *p) {
    return p ? p->depth : 0;
}

long long AVL::findKey(Node *p, long long int k) {
    if (k - 1 != depth(p->childRight)) {
        return k - 1 > depth(p->childRight) ? findKey(p->childLeft, k - depth(p->childRight) - 1) : findKey(
                p->childRight, k);
    } else {
        return p->k;
    }
}

void AVL::updDepth(Node *&p) {
    p->depth = depth(p->childLeft)+depth(p->childRight) + 1;
}

int main() {
    AVL tree;
    long long in;
    long long count;
    cin >> count;
    for(long long i=0; i<count;++i) {
        long long val;
        cin >> in >> val;
        if (in == 1) {
            tree.INSERT(val);
        } else if (in == -1) {
            tree.DELETE(val);
        } else {
            cout << tree.FINDKEY(val) << '\n';
        }
    }
    return 0;
}

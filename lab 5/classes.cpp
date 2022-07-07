#include "classes.h"
#include "math.h"
void space(int count) {
    for (int i = 0; i < count; i++) {
        cout << ' ';
    }
}

TNode::TNode(int number) {
    num = number;
}

BinaryTree::BinaryTree(int n) {
    top = new TNode(n);
    top->right = create(n-1, 0);
    top->left = create(n-1, 0);
}

TNode* BinaryTree::create(int n, int a) {
    TNode* p = new TNode(n - a);
    if (a == n - 1) {
        p->left = NULL;
        p->right = NULL;
    }
    else {
        p->left = create(n, a + 1);
        p->right = create(n, a + 1);
    }
    return p;
}
//вивід всіх рівнів
void BinaryTree::printLevelOrder(TNode* r, int height) {
    int h = height;
    width = pow(2, height);
    int fullWidth = (2 * width - 1) / 2;
    bool flag;

    for (int i = 0; i <= h; i++) {
        flag = true;
        printCurrentLevel(r, i, fullWidth, flag, i);
        fullWidth /= 2;
        cout << endl;
    }
}
//вивід поочного рівню
void BinaryTree::printCurrentLevel(TNode* r, int level, int width, bool& flag, int heigh) {
    if (r == NULL) {
        space(2 * width + 1);
        if (level != 0) flag = false;
        if (!k) k = width;
        return;
    }
    if (level == 0) {
        if (!flag) {
            space(heigh * k - heigh * 3 / 2);
            cout << r->num;
            flag = true;
        }
        else {
            space(width);
            cout << r->num;
            space(width);
        }
    }
    else if (level > 0) {
        printCurrentLevel(r->left, level - 1, width, flag, heigh);
        space(1);
        printCurrentLevel(r->right, level - 1, width, flag, heigh);
    }
}




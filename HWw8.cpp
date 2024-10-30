#include <bits/stdc++.h>
using namespace std;

struct nodeDT {
    int he_so;
    int so_mu;
    nodeDT *next;
};

struct List {
    nodeDT *firstnode;
    nodeDT *lastnode;
};

// Khoi tao danh sach da thuc
void List_init(List *list) {
    list->firstnode = NULL;
    list->lastnode = NULL;
}

// Tao mot node moi
nodeDT* callNode(int he_so, int so_mu) {
    if (he_so == 0) return NULL;
    nodeDT* p = new nodeDT;
    p->he_so = he_so;
    p->so_mu = so_mu;
    p->next = NULL;
    return p;
}

// Gan Node vao danh sach
void addNode(List* lDT, nodeDT* p) {
    if (p == NULL) return; // Khong them phan tu neu he so bang 0
    if (lDT->firstnode == NULL) { // Danh sach rong
        lDT->firstnode = lDT->lastnode = p;
    } else {
        lDT->lastnode->next = p; // Gan dia chi nut cuoi bang p
        lDT->lastnode = p; // Chuyen p thanh nut cuoi
    }
}

// Nhap da thuc
void nhapDT(List *lDT) {
    int hs, sm;
    cout << "Nhap da thuc (nhap he so 0 de ket thuc):" << endl;
    while (true) {
        cout << "Nhap he so: ";
        cin >> hs;
        if (hs == 0) break;
        cout << "Nhap so mu: ";
        cin >> sm;
        nodeDT* pDT = callNode(hs, sm);
        addNode(lDT, pDT);
    }
}

// In da thuc
void inDT(List lDT) {
    nodeDT* p = lDT.firstnode;
    cout << "f(x)= ";
    while (p != NULL) {
        cout << p->he_so << "x^" << p->so_mu;
        if (p->next != NULL) cout << " + ";
        p = p->next;
    }
    cout << endl;
}

// Giai phong bo nho
void clear(List* lDT) {
    nodeDT* p;
    while (lDT->firstnode != NULL) {
        p = lDT->firstnode;
        lDT->firstnode = lDT->firstnode->next;
        delete p;
    }
    lDT->lastnode = NULL;
}

int main() {
    List DT1;
    List DT2;

    //Khoi tao danh sach
    List_init(&DT1);
    List_init(&DT2);

    //Nhap da thuc
    nhapDT(&DT1);
    nhapDT(&DT2);

    //In da thuc
    inDT(DT1);
    inDT(DT2);

    //Giai phong bo nho
    clear(&DT1);
    clear(&DT2);

    return 0;
}

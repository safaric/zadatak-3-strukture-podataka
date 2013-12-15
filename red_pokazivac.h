#include<iostream>
#include<cstring>
using namespace std;

struct element{
    string ime,prezime,datum;
    char spol;
    int ai,bi,ci,di,ei;    
};

struct kocka{
    element pacijent;
    kocka *sljedeci;   
};

struct red{
    kocka *front,*rear;    
};

red *InitQ(red *r){
    r = new red;
    kocka *novi = new kocka;
    novi->sljedeci = NULL;
    r->front = novi;
    r->rear = novi;
    return r;
    }

bool IsEmptyQ(red *r){
    return r->rear==r->front;
    }
  
element FrontQ(red *r){
    if(IsEmptyQ(r)) cout << "Red je prazan!" << endl;
    else return r->front->sljedeci->pacijent;
    }
    
void EnQueueQ(element p, red *r){
    kocka *novi = new kocka;
    novi->pacijent = p;
    novi->sljedeci = NULL;
    r->rear->sljedeci = novi;
    r->rear = novi;
    }
    
void DeQueueQ(red *r){
    kocka *brisi = r->front;
    r->front = r->front->sljedeci;
    delete brisi;
    }

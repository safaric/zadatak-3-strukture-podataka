#include<iostream>
#include<cstring>
using namespace std;

struct element{
    string ime,prezime,datum;
    char spol;
    int ai,bi,ci,di,ei;    
};

struct red{
    element pacijent[100];
    int front,rear;
};

int AddOne(int n){
    return (n+1)%100;
    }

red *InitQ(red *r){
    r = new red;
    r->front = 0;
    r->rear = 99;
    return r;
    }

bool IsEmptyQ(red *r){
    if(AddOne(r->rear)==r->front) return true;
    else return false;
    }
    
element FrontQ(red *r){
    return r->pacijent[r->front];
    }

void EnQueueQ(element p, red *r){
    int n;
    if(r->rear==99) n=0;
    else n=r->rear+1;
    r->pacijent[n] = p;
    r->rear = n;
    }

void DeQueueQ(red *r){
    if(IsEmptyQ(r)) cout << "Red je prazan!" << endl;
    else{
        if(r->front==99) r->front=0;
        else r->front++;
        }
    }

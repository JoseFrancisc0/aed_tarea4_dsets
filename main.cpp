#include <iostream>
#include "disjoint_set.h"
using namespace std;

void arrayTest(){
    DisjointSetArray* set = new DisjointSetArray();

    set->MakeSet(1);
    set->MakeSet(2);
    set->MakeSet(3);
    set->MakeSet(4);
    set->MakeSet(5);

    set->Union(1,2);
    set->Union(3,4);

    cout << set->Find(1) << " : " << set->Find(2) << endl;
    cout << set->Find(3) << " : " << set->Find(4) << endl;
    cout << boolalpha << set->isConected(1,3) << endl;
    
    set->Union(1,3);
    cout << boolalpha << set->isConected(1,3) << endl;

    cout << set->Find(1) << " : " << set->Find(3) << endl;

    set->Union(1,5);
}

void treeTest(){
    DisjointSetTree* set = new DisjointSetTree();

    set->MakeSet(1);
    set->MakeSet(2);
    set->MakeSet(3);
    set->MakeSet(4);
    set->MakeSet(5);

    set->Union(1,2);
    set->Union(3,4);

    cout << set->Find(1) << " : " << set->Find(2) << endl;
    cout << set->Find(3) << " : " << set->Find(4) << endl;
    cout << boolalpha << set->isConected(1,3) << endl;
    
    set->Union(1,3);
    cout << boolalpha << set->isConected(1,3) << endl;

    cout << set->Find(1) << " : " << set->Find(3) << endl;

    set->Union(1,5);
}

int main(int, char**){
    //arrayTest();
    //treeTest();
}

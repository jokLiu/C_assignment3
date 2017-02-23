
#include <string>
#include <iostream>

using namespace std;

#include "evalobj.h"

int main(int argc, const char *argv[])
{
//    ExpList *l = nullptr;
//    l = new ExpList(new Constant(23), l);
//    l = new ExpList(new Constant(42), l);
//    l = new ExpList(new Constant(666), l);
//
//    Exp *e = new OpApp(plusop, l);
////    Exp *b = new Constant(5);
//    cout << e->eval(nullptr) << endl;



//    Exp *e1 ,*e2;
//    ExpList *l = nullptr;
//
//  l = nullptr;
//  l =  new ExpList(new Constant(5), l);
//  l =  new ExpList(new Constant(3), l);
//  l =  new ExpList(new Constant(2), l);
//  e1 = new OpApp(plusop, l);
//
//  l = nullptr;
//  l = new ExpList(new Var("x"), l);
//  l = new ExpList(new Var("x"), l);
//  l = new ExpList(new Var("x"), l);
//  e2 = new OpApp(timesop, l);
//
//  e1 = new Let("x", e1, e2);
//    cout << e1->eval(nullptr) << endl; //should print 1000


    //2

//    Exp *e1 ,*e2, *e3;
//    ExpList  *l;
//
//    l = nullptr;
//    l = new ExpList(new Constant(5), l);
//    l = new ExpList(new Constant(3), l);
//    l = new ExpList(new Constant(2), l);
//    e1 = new OpApp(plusop, l);
//
//    l = nullptr;
//    l = new ExpList(new Var("x"), l);
//    l = new ExpList(new Var("x"), l);
//    e3 =new OpApp(plusop, l);
//    l = nullptr;
//    l = new ExpList(e3, l);
//    l = new ExpList(new Var("x"), l);
//    l = new ExpList(new Var("x"), l);
//    e2 = new OpApp(timesop, l);
//
//    e1 = new Let("x", e1, e2);
//
//    cout << e1->eval(nullptr) << endl; // should print  2000

//    Exp *e1 ,*e2, *e3;
//    ExpList *l;
//
//    l = nullptr;
//    l = new ExpList(new Var("y"), l);
//    e2 = new Let("x",new Constant(10) , new Var("x"));
//    l = new ExpList(e2, l);
//    l = new ExpList(new Var("y"), l);
//    e3 = new OpApp(plusop, l);
//    e1 = new Let("y",new Constant(2) , e3);
//
//    cout << e1->eval(nullptr) << endl;// should print  14

//    Exp *e1 ,*e2;
//    ExpList *l, *l2;
//
//    l = nullptr;
//    l = new ExpList(new Constant(4), l);
//    l = new ExpList(new Constant(2), l);
//    l = new ExpList(new Constant(1), l);
//    e1 = new OpApp(timesop, l);
//
//    l = nullptr;
//    l = new ExpList(new Constant(3), l);
//    l = new ExpList(new Constant(3), l);
//
//    l2 = nullptr;
//    l2 = new ExpList(new Constant(2), l2);
//    l2 = new ExpList(new Constant(1), l2);
//    l2 = new ExpList(new Constant(3), l2);
//    e2 = new OpApp(timesop, l2);
//
//    l = new ExpList(e2, l);
//    l = new ExpList(new Constant(1), l);
//    e2 = new OpApp(plusop, l);
//
//    l2 = nullptr;
//    l2 = new ExpList(e1, l2);
//    l2 = new ExpList(e2, l2);
//    l2 = new ExpList(new Constant(2), l2);
//    l2 = new ExpList(new Constant(2), l2);
//    l2 = new ExpList(new Constant(5), l2);
//    e2 = new OpApp(plusop, l2);
//
//    cout << e2->eval(nullptr) << endl; //should print 30

//
    Exp *e1, *e2,*e3;
    ExpList *l;

    l = nullptr;
    l = new ExpList(new Var("x"), l);
    l = new ExpList(new Var("y"), l);
    e3 = new OpApp(plusop, l);

    e1 = new Let("x", new Constant(2), new Var("x"));
    e2 = new Let("y", new Var("x"),e3);
    e3 = new Let("x",e1,e2);

    cout << e3->eval(nullptr) << endl; // should print  4



    return 0;
}


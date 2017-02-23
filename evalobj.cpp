#include <string>
using namespace std;
#include "evalobj.h"
#include <iostream>
int evalExpList(op op, ExpList *list, env *env);
env *addEnvironment(env *env, string var, int value);
env *removeFirstEnvironmnet(env *env);
int getConstantFromEnvironment(env *env, string var);

env *addEnvironment(env *env, string var, int value)
{
    struct env *newEnv;
    newEnv = new struct env;
    newEnv->var = var;
    newEnv->value = value;
    newEnv->next = env;
    return newEnv;
}

env *removeFirstEnvironmnet(env *env)
{
    struct env *temp = nullptr;
    if(env)
    {
        temp = env->next;
        delete env;
    }
    return temp;
}

int getConstantFromEnvironment(env *env, string var)
{
    struct env *temp = env;
    while(temp)
    {
        if(temp->var == var) return temp->value;
        temp = temp->next;
    }
    //should never be reached
    return 0;
}

int Constant::eval(env *p)
{
    return n;
}
int Var::eval(env *p)
{
    return getConstantFromEnvironment(p, name);
}

int Let::eval(env *p)
{
    p = addEnvironment(p,bvar,bexp->eval(p));
    int result = body->eval(p);
    p = removeFirstEnvironmnet(p);
    return result;
}






int OpApp::eval(env *p) {
   return evalExpList(op, args, p);

}

int evalExpList(op op, ExpList *list, env *env)
{
    if(list)
    {
        if(op == plusop) return list->head->eval(env) + evalExpList(op, list->tail, env);
        return list->head->eval(env) * evalExpList(op, list->tail, env);
    }
    if(op == plusop) return 0;
    return 1;
}



//
//struct env {
//    string var;
//    int value;
//    env *next;
//};
//
//class Exp {
//public:
//    virtual int eval(env*) = 0;
//};
//
//class Constant : public Exp {
//    int n;
//public:
//    Constant(int n) {this->n = n; }
//    int eval(env*);
//};
//
//class Var : public Exp {
//    string name;
//public:
//    Var(string s) { this->name = s; }
//    int eval(env*);
//};
//
//class Let : public Exp {
//    string bvar;
//    Exp *bexp;
//    Exp *body;
//public:
//    Let(string v, Exp *e, Exp *b)
//    {
//        bvar = v; bexp = e; body = b;
//    }
//    int eval(env*);
//};
//
//class ExpList {
//public:
//    Exp *head;
//    ExpList *tail;
//    ExpList(Exp *h, ExpList *t) { head = h; tail = t; }
//};
//
//enum op { plusop, timesop };
//
//class OpApp : public Exp {
//    op op;
//    ExpList *args;
//public:
//    OpApp(enum op o, ExpList *a) { op = o; args = a; }
//    int eval(env*);
//};

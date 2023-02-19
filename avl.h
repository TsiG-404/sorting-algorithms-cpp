#ifndef avl_h
#define avl_h

#include <cstring>


#include<iostream>
#include<cstdio>
#include<time.h>

#define pow2(n) (1 << (n))
using namespace std;
struct avl {//same here i recommend to add the appearances but i dont know if it would work

   string d;
   int app=1;
   struct avl *l;
   struct avl *r;
}*r;
class avl_tree {
   public:
      int height(avl *);
      int difference(avl *);
      avl *rr_rotat(avl *);
      avl *ll_rotat(avl *);
      avl *lr_rotat(avl*);
      avl *rl_rotat(avl *);
      avl * balance(avl *);
      avl * insert(avl*, string);
      void show(avl*, int);
      void inorder(avl *);
      void preorder(avl *);
      void postorder(avl*);

      ~avl_tree();

      int rtimes(avl*, string);

      int search(avl*, string);

      avl_tree() {
         r = NULL;
      }
};


avl_tree::~avl_tree() //destructor for less ram
{
  
  r=NULL;

}

int avl_tree::height(avl *t) {//it returns the height of the avl tree

   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int avl_tree::difference(avl *t) {//it returns the difference between left and right

   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}
avl *avl_tree::rr_rotat(avl *parent) { //right right rotation

   avl *t;
   t = parent->r;  
   parent->r = t->l;
   t->l = parent;
  
   return t;
}
avl *avl_tree::ll_rotat(avl *parent) {  //left left rotation
   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   
   return t;
}
avl *avl_tree::lr_rotat(avl *parent) {  //left right rotation
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
  
   return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl *parent) {  //right left rotation
   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);
  
   return rr_rotat(parent);
}


avl *avl_tree::balance(avl *t) { //it balances the avl tree
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}
avl *avl_tree::insert(avl *r, string v) { //it inserts strs into the tree

   if (r == NULL) {
      r = new avl;
      r->d = v;
      r->app=1;
      r->l = NULL;
      r->r = NULL;
      return r;
   }
   else if (v == r->d) {
      r->app +=1 ;
      r = balance(r);
   }
   else if (v< r->d) {
      r->l = insert(r->l, v);
      r = balance(r);
   } 
   else if (v > r->d) {
      r->r = insert(r->r, v);
      r = balance(r);
   } return r;
}
void avl_tree::show(avl *p, int l) { //prints the tree
   int i;
   if (p != NULL) {
      show(p->r, l+ 1);
      cout<<" ";
      if (p == r)
         cout << "Root -> ";
      for (i = 0; i < l&& p != r; i++)
         cout << " ";
         cout << p->d;
         show(p->l, l + 1);
   }
}


//all printable ways
void avl_tree::inorder(avl *t) {
   if (t == NULL)
      return;
      inorder(t->l);
      
    
      cout << t->d << ", ";
      
      inorder(t->r);
}
void avl_tree::preorder(avl *t) {
   if (t == NULL)
      return;
      cout << t->d << ", ";
      preorder(t->l);
      preorder(t->r);
}
void avl_tree::postorder(avl *t) {
   if (t == NULL)
      return;
      postorder(t ->l);
      postorder(t ->r);
      cout << t->d << ", ";
}




int avl_tree :: rtimes( avl* rootPtr, string key)
{
  //it returns appearances of strs into the tree
   
    if (rootPtr->app == NULL || rootPtr->d == key)
       return rootPtr->app;
    
    
    if (rootPtr->d < key)
       return rtimes(rootPtr->r, key);
 
    
    return rtimes(rootPtr->l, key);
}

int avl_tree::search(avl *r, string v) { //it returns time of a search of a str into the tree

   clock_t tStart = clock();    // working

    if (v == r->d) {
      return ((clock() - tStart)/(CLOCKS_PER_SEC/1000));
   }
   else if (v< r->d) {
      r->l = insert(r->l, v);
      r = balance(r);
   } 
   else if (v > r->d) {
      r->r = insert(r->r, v);
      r = balance(r);
   } 
   return ((clock() - tStart)/(CLOCKS_PER_SEC/1000));
}




#endif
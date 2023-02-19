#ifndef unordered_h
#define unordered_h

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class unordered 
{
    private:
        string array[1024] ;
        int array2[1024];
        int t=0;
        int size1=0;
    public:
    
unordered();
~unordered();
void insert(string);
int search(string);
int rtimes(string);
void rwords(string);
void del(string);

};
#endif
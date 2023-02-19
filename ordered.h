#ifndef ordered_h
#define ordered_h

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class ordered 
{
    private:
        string array1[1024] ;
        int array2[1024];
        int size1=0;
        int pos=0;
        int right=pos;
    public: 
        ordered();
        ~ordered();
        int sizew(){return right;}
        void print();
        void insert(string);
        int search(string);
        int rtimes(string);
        void rwords(string);
        void sort();
        void del(string);
};
#endif
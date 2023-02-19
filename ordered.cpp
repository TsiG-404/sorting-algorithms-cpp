#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include "ordered.h"
using namespace std;


ordered::ordered()
{//creation of ordered arrays str and int

    int i=0;
    for(i=0;i<1024;i++)
    {
     array1[i]="";
     array2[i]=0;
    }
    size1=1023;
    //unordered::size(size1);
    
}

ordered::~ordered()
{
  for(int i=0;i<size1;i++)
  { 
  //delete array1[i];
  array1[i]="";
  array2[i]=NULL;
  //delete array2[(i)];
  }
  //delete array2[];
                
}


void ordered::insert(string w1)
{//it insert words in arrays and their appearances


     //sizea=size();
    int i=0;
    //struct words s[1024];
    for(i=0;i<size1;i++)
    {
        
        if(w1==array1[i])
        {
         array2[i]+=1;
         break;
        }
        
        else if (array1[i]=="")
        {
         array1[i]=w1;
         array2[i]=1;
         pos+=1;
         break;
        }
        
        /*
        else if (array1[i]>w1)  //this order algorithm has a problem 
        {


            if(pos=size1) //THIS HELPS TO ORDER THE MAP BUT IT HAS 1% CHANCE TO BREAK THE ORDER OF THEM AND LOSE SOME WORDS!!
            break;


            for (int j=pos;j>i;j--)
            {
               if(array1[j+1]=="") 
               {
              array1[j+1]=array1[j];
              array2[j+1]=array2[j];
              array1[j]="";
              array2[j]=0;
               }
            }
            array1[i]=w1;
            array1[i]=1;
            pos+=1;
            
        }
        
        */



        else if (array1[size1]!="")
        {//IT DOESNT WORK IN C++99 SO IT DOESNT WORK IN REPLIT!! DONT FORGET TO CHANGE IT BEFORE YOU SEND IT(YEAH THE DELETES AGAIN)
            
            
            string temp[(size1*2)];
            int temp2[(size1*2)];
            for(int i=0;i<=(size1*2);i++)
            {
                temp[i]=nullptr;
                temp2[i]=0;
                
            }
            
            memcpy(temp,array1,size1*sizeof( string));
            memcpy(temp,array2,size1*sizeof( int*));
            
            //delete[] array ;  //this one
            //delete[] array2;
            
            size1*=2;
            
            for (i=0;i<size1;i++)
            {
                array1[i]=temp[i];
                array2[i]=temp2[i];
            }
            array1[(size1/2)+1]=w1;
            array2[(size1/2)+1]=1;
            
            break;}
    }
    right=pos;
}

int ordered::rtimes(string w1)
{//return appearances
    
    for(int i=0;i<=size1;i++)
    {
     if(array1[i]==w1)
     {
         return array2[i];
         
         
        //break;
     }
    }
}

void ordered::rwords(string w1)
{//return the word useless
    
    for(int i=0;i<=size1;i++)
    {
     if(array1[i]==w1)
     {
         cout<<" "<<array1[i];
         
         
        break;
     }
    }
}


void ordered::print()
{//it print the ordered arrays "word : appearances"

    for (int i=0;i<pos;i++)
    {
        cout<<array1[i]<<" : "<<array2[i]<<endl;
    }
}

void ordered::sort()
{
  string temp1;
  int temp2;
  for (int i = 0; i < sizew()-1; i++){
    for (int j = 0; j < sizew()-i-1; j++){
        if (array1[j] > array1[j+1]){
          temp1=array1[j];
          array1[j]=array1[j+1];
          array1[j+1]=temp1;

          temp2=array2[j];
          array2[j]=array2[j+1];
          array2[j+1]=temp2;
        }
    }
  }
  return;
}

int ordered::search(string w1)
{//returns the time of search

    //struct words s[1024];
    clock_t tStart = clock();
    //sizea=size();
    int i=0;
    for(i=0;i<size1;i++)
    {
     if(array1[i]==w1)
     {
         //rwords(i);
         //rtimes(i);
         
         return ((clock() - tStart)/(CLOCKS_PER_SEC/100000));    
     }
    }
}

void ordered::del(string w1)
{//delete algorithm

    for (int i=0;i<size1;i++)
    {
        if((array1[i]==w1) &&(array2[i]>1))
        {
            array2[i]-=1;
            break;
        }
        else if((array1[i]==w1) && (array2[i]==1))  //afti i periptosi den doulebei sosta
        {
            array1[i]="";
            for (int j=i+1;j<size1;j++)
            {
                array1[j-1]=array1[j];
                array2[j-1]=array2[j];
                
            }
            array1[size1]="";
        }
    }
}


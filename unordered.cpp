#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include "unordered.h"
using namespace std;


unordered::unordered()
{//creation of unordered array which works with 2 arrays 1 with strs and 1 with int

    int i=0;
    for(i=0;i<1024;i++)
    {
     array[i]="";
     array2[i]=0;
     
    }
    size1=1023;
    
    
}



unordered::~unordered()
{
  for(int i=0;i<size1;i++)
  { 
 
  array[i]="";
  array2[i]=NULL;
  
  }
  
                
}



void unordered::insert(string w1)
{//working insert with deletes and realoctions


    
    int i=0;
    
    for(i=0;i<size1;i++)
    {
        if(w1==array[i])
        {
         array2[i]+=1;
         break;
        }
        else if (array[i]=="")
        {
         array[i]=w1;
         array2[i]=1;
         break;
        }
        else if (array[size1]!="")   //it works!
        {
            
            
            string temp[(size1*2)];
            int temp2[(size1*2)];
            for(int i=0;i<=(size1*2);i++)
            {
                temp[i]=nullptr;
                temp2[i]=0;
                
            }
            
            memcpy(temp,array,size1*sizeof( string));
            memcpy(temp,array2,size1*sizeof( int*));
            
            //delete[] array;
            //delete[] array2;           //it doesnt work in replit we have to check it also it doesnt work with the c++99 version so we have to move it to c++17 it is way better (yep in c++17 works without these deletes)

            size1*=2;
            
            for (i=0;i<size1;i++)
            {
                array[i]=temp[i];
                array2[i]=temp2[i];
            }
            array[(size1/2)+1]=w1;
            array2[(size1/2)+1]=1;
            
            
            break;
        }
    }
}

int unordered::rtimes(string w1)
{//it return the apearences of a word
    
    for(int i=0;i<=size1;i++)
    {
     if(array[i]==w1)
     {
       ofstream file1990;
         
         return array2[i];
           
         
         
        
     }
    }
}

void unordered::rwords(string w1)
{//it retrun a searched word TOTALY USELESS BECAUSE WE CAN GET IT FROM THE MAIN.CPP!!
    
    for(int i=0;i<=size1;i++)
    {
     if(array[i]==w1)
     {
        fstream file99;
         file99.open("results.txt");
         file99<<array[i];
         file99.close();
         
         
        break;
     }
    }
}

int unordered::search(string w1) 
{//it return the total time it took to search a word

   
    clock_t tStart = clock();
   
    int i=0;
    for(i=0;i<=size1;i++)
    {
     if(array[i]==w1)
     {
         
         
          return ((clock() - tStart)/(CLOCKS_PER_SEC/100000));     
          
     }
    }
}


void unordered::del(string w1)
{//delete algorithm

    for (int i=0;i<size1;i++)
    {
        if((array[i]==w1) &&(array2[i]>1))
        {
            array2[i]-=1;
            break;
        }
        else if((array[i]==w1) && (array2[i]==1))
        {
            array[i]="";
            for (int j=i+1;j<size1;j++)
            {
                array[j-1]=array[j];
                array2[j-1]=array2[j];
                
            }
            array[size1]="";
        }
    }
}



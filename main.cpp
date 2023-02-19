#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include <time.h>
#include<cstdio>

#define pow2(n) (1 << (n))

using namespace std;

unsigned long long int operator% (string s, int k)
{
    int sum = 0;
    for (int i=0;i<s.length();i++)
        sum+=s[i];
    
    return sum % k; 
}


#include "unordered.h"
#include "ordered.h"
#include "bst.h"
#include "avl.h"
#include "hashing.h"



int main() {
  //this is the project for csd-auth data structures 2020-2021
  //this is the main file which has 7 steps

  //step 1 replace specific characters with spaces and uppers with lowers
  string kim;
  int ewords=0; // this cout every word
    
	fstream file1;
	file1.open("f1.txt");
	if (!file1) 
	{
		cout << "No such file";
		return 404;
	}
	else {
	    
		char ch;// this character will be used to read the content of the txt file letter by letter

		while (1) {
		   
			file1 >> noskipws >>ch;//the >> noskipws doesnt skip spaces even if the file will get read letter by letter (took me 8 hours to find it)
			if(ch=='\n')
			  kim+="\n";// this string will be used to add the corrected content to the new file

			if (file1.eof())
				break;	
			if(ch>=65 && ch<=90) //if a letter is upper it turn it to lower 
		    {
		    ch+=32;
		    kim+=ch;
		    }
		    else if(ch<=47 || ch>=126)//if it find specific characters it trun them to spaces (mostly useless)
		    {
		        kim+=" ";
		    }
		    else//it copy every lower non space/spcific character to the string
		    {
		     kim+=ch;
		    }
		}
		//cout<<" "<< kim; //we dont need that it will have to go !!
		//file1<<kim;
	}
	
	ofstream file2;
	file2.open("input2.txt");
	if(file2.is_open())
	{
	    file2<<kim;
	}
	file1.close();
	file2.close();
  
  kim.erase (kim.begin(), kim.end()); //deletes the str
	//end of step 1
	
	// step 2 a list of strings to search in every data structure
	int words1=10; //this is the number of words we want to search
	string list[words1]; // this is the list with serchable words
	int i=0;
	fstream file3;
	file3.open("input2.txt");
	cout<<endl;  //we dont need that it will have to go !!
	for (i=0;i<words1;i++)
	{
	   file3>>list[i];
	}
  
	/*
  for (i=0;i<words1;i++)
	{
	   cout<<list[i]<<endl; // this will needs to be replaced !!
	}
  */
  
	file3.close();
	//end of step 2


//step 3 a list with every word in the txt file
fstream file4;
string tword=""; //a temporary str for every word of the txt file
	file4.open("input2.txt");
  while (1)
  {
    if (file4.eof())
				break;	
    file4>>tword;
    ewords+=1;
    tword="";
  }
  file4.close();
 
  string awords[ewords]; // a list that has every word of the txt file

  fstream file5;
  file5.open("input2.txt");
  for (i=0;i<ewords;i++)
    {
    file5>>awords[i]; //it put every word in the list
    }
  file5.close();
  //end of step 3


  //step 4 every word gets in unordered to get serched and output the results
  ofstream file98;
  ofstream file99;
  file99.open("results.txt");  //this is the output file
  file98.open("printables.txt");//this is the output for all prints


  
  file99<<"\n #--->>UNORDERED<<---# \n";
  file99<<"WORD   APPEARANCES   TIME\n";
  unordered a;
  clock_t tStart2=clock();
  for (i=0;i<ewords;i++)
    {
    a.insert(awords[i]); //it put every word in the list
    }


    clock_t tStart = clock(); //timer for total time of search
  for (i=0;i<words1;i++)
	{
     file99<<list[i]<<"   ";
     file99<<a.rtimes(list[i]);
     file99<<"   ";
	   file99<<a.search(list[i]);
     file99<<"\n";
	}
  file99<<"Total search time in unordered:"<<((clock() - tStart)/(CLOCKS_PER_SEC/100000))<<"\n";
  file99<<"Total time for creation and search in unordered:"<<((clock() - tStart2)/(CLOCKS_PER_SEC/100000))<<"\n";
//end of step 4


 //
 file98<<"\n\n"<<"Unordered array"<<"\n";
  for(i=0;i<ewords;i++)
  {
    file98<<awords[i]<<", ";
  }
   a.~unordered();
 //


//step 5 every word gets in ordered to get serched and output the results
file99<<"\n\n\n #--->>ORDERED<<---# \n";
file99<<"WORD   APPEARANCES   TIME\n";
  ordered b;
  clock_t tStart3=clock();
  for (i=0;i<ewords;i++)
    {
    b.insert(awords[i]); //it put every word in the list
    }
    b.sort();
    clock_t tStart4 = clock(); //timer for total time of search
  for (i=0;i<words1;i++)
	{
     file99<<list[i]<<"   ";
     file99<<b.rtimes(list[i]);
     file99<<"   ";
	   file99<<b.search(list[i]);
     file99<<"\n";
	}
  file99<<"Total search time in ordered:"<<((clock() - tStart4)/(CLOCKS_PER_SEC/100000))<<"\n";
  file99<<"Total time for creation and search in ordered:"<<((clock() - tStart3)/(CLOCKS_PER_SEC/100000))<<"\n";
//end of step 5


//
file98<<"\n\n"<<"Ordered array"<<"\n";
  for(i=0;i<ewords;i++)
  {
    file98<<awords[i]<<", ";
  }
  b.~ordered();
 //

//step 6 every word gets in binary tree to get serched and output the results
file99<<"\n\n\n #--->>BINARY TREE<<---# \n";
file99<<"WORD   APPEARANCES   TIME\n";
  BinaryTree c;
  Node* ptr;
  clock_t tStart5=clock();
  for (i=0;i<ewords;i++)
    {
    ptr = c.insertNode(c.getRoot(),awords[i] );  //it put every word in the list
    }


    clock_t tStart6 = clock(); //timer for total time of search
  for (i=0;i<words1;i++)
	{
     file99<<list[i]<<"   ";
     file99<<c.rtimes(c.getRoot(),list[i]);//same almost working
     file99<<"   ";
	   file99<<c.search(c.getRoot(),list[i]); //almost working but still doesnt work
     file99<<"\n";
	}
  file99<<"Total search time in binary tree:"<<((clock() - tStart6)/(CLOCKS_PER_SEC/1000000))<<"\n";
  file99<<"Total time for creation and search in binary tree:"<<((clock() - tStart5)/(CLOCKS_PER_SEC/1000000))<<"\n";
  //end of step 6

//
cout<<"\n\n"<<"Binary Tree Inorder"<<"\n";
    c.inOrder(c.getRoot());
    
cout<<"\n\n"<<"Binary Tree Preorder"<<"\n";
    c.preOrder(c.getRoot());
  
cout<<"\n\n"<<"Binary Tree Postorder"<<"\n";
    c.postOrder(c.getRoot());
    
  c.~BinaryTree();  
 //

//step 7 every word gets in avl tree to get serched and output the results
file99<<"\n\n\n #--->>AVL TREE<<---# \n";
file99<<"WORD   APPEARANCES   TIME\n";
  avl_tree d;
  clock_t tStart7=clock();
  for (i=0;i<ewords;i++)
    {
    r = d.insert(r, awords[i]); //it put every word in the list
    }


    clock_t tStart8 = clock(); //timer for total time of search
  for (i=0;i<words1;i++)
	{
     file99<<list[i]<<"   ";
     file99<<d.rtimes(r,list[i]);
     file99<<"   ";
	   file99<<d.search(r,list[i]);
     file99<<"\n";
	}
  file99<<"Total search time in avl tree:"<<((clock() - tStart8)/(CLOCKS_PER_SEC/100000))<<"\n";
  file99<<"Total time for creation and search in avl tree:"<<((clock() - tStart7)/(CLOCKS_PER_SEC/10000))<<"\n";
  //end of step 7


//
cout<<"\n\n"<<"AVL Tree Inorder"<<"\n";
    d.inorder(r);
    
cout<<"\n\n"<<"AVL Tree Preorder"<<"\n";
    d.preorder(r);
    
cout<<"\n\n"<<"AVL Tree Postorder"<<"\n";
    d.postorder(r);
    

   d.~avl_tree(); 
 //

//step 8 every word gets in hash table to get serched and output the results
file99<<"\n\n\n #--->>HASHING<<---# \n";
file99<<"WORD   APPEARANCES   TIME\n";
  hashTable<int, string> e(1024);
  int ww;
  clock_t tStart9=clock();
  
  for (i=0;i<ewords;i++)        //hashing has a big!! problem
    {
    e.insert(1,awords[i]);  //it put every word in the list
    }


    clock_t tStart10 = clock(); //timer for total time of search
  for (i=0;i<words1;i++)
	{
     file99<<list[i]<<"   ";
     file99<<e.search(list[i],ww);
     file99<<"   ";
     file99<<e.rtime(list[i],ww);
     file99<<"\n";
	}
  file99<<"Total search time in hashing table:"<<((clock() - tStart10)/(CLOCKS_PER_SEC/100000))<<"\n";
  file99<<"Total time for creation and search in hashing table:"<<((clock() - tStart9)/(CLOCKS_PER_SEC/10000))<<"\n";
  //end of step 7

//
cout<<"\n\n"<<"hashing"<<"\n";
    //e.inorder(r);
    

   e.~hashTable(); 
 //


  file99.close();
  file98.close();
	return 0;
}

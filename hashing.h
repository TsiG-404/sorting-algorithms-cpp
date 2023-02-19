#ifndef hashing_h
#define hashing_h

#include <time.h>

/*this hashing algorithm was originaly crated by D.Brakas and this algorithm works way better than mine and mine was a hashing with chaning not with open adresses. This project requires hashing with open adresses so thanks to professor who let us use it we will have a working complete algorithm for the data structures which at least will pass the compile/review point.*/


template <typename dataType, typename keyType>
class myPair
{
    public:
        myPair(dataType d, keyType k)
        {
            data=d;
            key=k;
        }
        dataType data;
        keyType key;
};

template <typename dataType, typename keyType>
class hashTable
{
    private:
        int size;
        int elements;
        myPair<dataType,keyType> **A;
        void *deleted;

        unsigned int hash(const keyType &);
        unsigned int hash2(unsigned int );
        myPair<dataType,keyType> *& search(const keyType &);
    public:
        hashTable();
        hashTable(int n);
        ~hashTable();
        bool insert(const dataType &, const keyType &);
        int search(const keyType &, dataType &data);
        int rtime(const keyType &, dataType &data);
        bool remove(const keyType &);
};
template <typename dataType, typename keyType>
hashTable<dataType,keyType>::hashTable()
{//creation of hashing 
    size=10; //size of hashing
    elements=0; //how many objs it has at the starting point

    deleted = this;//new int();

    A = new myPair<dataType,keyType> *[size];
    for(int i=0;i<size;i++)
    {

        A[i]=nullptr;
        //A[i]->d=1;
    }

}
template <typename dataType, typename keyType>
hashTable<dataType,keyType>::hashTable(int n)
{ //rehashing v1
    deleted = this;//new int();

    size=n;
    elements=0;
    A = new myPair<dataType,keyType> *[size];
    for(int i=0;i<size;i++)
    {
        A[i]=nullptr;
        
    }
}
template <typename dataType, typename keyType>
hashTable<dataType,keyType>::~hashTable()
{//destructor for less usage of ram after the end of hashing
    delete[] A;
    A=nullptr;
    elements=0;
    size=0;
}

template <typename dataType, typename keyType>
unsigned int hashTable<dataType,keyType>::hash(const keyType &d)
{//it turn strs to long long ints
    return d%size;
}

template <typename dataType, typename keyType>
unsigned int hashTable<dataType,keyType>::hash2(unsigned int d)
{//same as the previous
    return (d+1)%size;
}


template <typename dataType, typename keyType>
bool hashTable<dataType,keyType>::insert (const dataType &data, const keyType &key)
{//working insert with deletes
    if (search(key)!=nullptr)
    {
        search(key)->data+=1;
    
       
       
        return false;
    }




    if (elements>=size/2)
    {
        myPair<dataType,keyType> **temp;
        size*=2;
        temp = new myPair<dataType,keyType>*[size];
        for(int i=0;i<size;i++)
            temp[i]=nullptr;

        for (int i=0;i<size/2;i++)
        {
            


            if (A[i]!=nullptr && A[i]!=deleted)
            {
                A[i]->data+=1;
                unsigned int p = hash(A[i]->key);
                while (temp[p]!=nullptr)
                    p = hash2(p);
                temp[p]=A[i];
                A[i]=nullptr;
            }  

              
        }
        delete[]A;
        A=temp;
    }




    unsigned int p = hash(key);
    while (A[p]!=nullptr && A[p]!=deleted)
        p = hash2(p);
    A[p]=new  myPair<dataType,keyType> (data,key);
    A[p]->data+=1;
    elements++;
    return true;
}




template <typename dataType, typename keyType>
myPair<dataType,keyType> *& hashTable<dataType,keyType>::search(const keyType &key)
{ //searching for hashing
    unsigned int p = hash(key);
    while (A[p]==deleted || (A[p]!=nullptr && A[p]->key!=key))
        p = hash2(p);
    return A[p];
}


template <typename dataType, typename keyType>
int hashTable<dataType,keyType>::search(const keyType &key ,dataType &data)
{ //outputs the times a word appear in the txt
    
    myPair<dataType,keyType> *p = search(key);

    if (p==nullptr)
        return false;

    data = p->data;
    

     
    return data-=4;
}

template <typename dataType, typename keyType>
int hashTable<dataType,keyType>::rtime(const keyType &key ,dataType &data)
{ //results of time in search
    clock_t tStart = clock();
    myPair<dataType,keyType> *p = search(key);

    if (p==nullptr)
        return -1;

    data = p->data;

    return ((clock() - tStart)/(CLOCKS_PER_SEC/100000));   
    return true;
}


template <typename dataType, typename keyType>
bool hashTable<dataType,keyType>::remove(const keyType &key)
{ //delete algorithm
    myPair<dataType,keyType> * &p = search(key);
    if (p==nullptr)
        return false;

    elements--;
    delete p;
    p = (myPair<dataType,keyType> *) deleted;

    return true;
}


#endif
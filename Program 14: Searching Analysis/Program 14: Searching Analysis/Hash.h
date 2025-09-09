/*
---------------------------------------
                Hash
---------------------------------------
-buckets: int
-hashtable: list<int> *
---------------------------------------
+Hash (int):
+insert_element (int): void
+hashFunction (int): int
+search_element (int): int
---------------------------------------
 */

#ifndef Hash_h
#define Hash_h
#include <iostream>
#include <list>
using namespace std;

class Hash
{
    private:
        int buckets;           // # buckets
        list<int> *hashtable;  // container
    public:
        Hash (int a)           // constructor
        {
          buckets = a;
          hashtable = new list<int>[buckets];
        }

        void insert_element (int key)
        {
            //to get the hash index of key
            int indexkey = hashFunction(key);
            hashtable[indexkey].push_back(key);
        }

        // maps values to key
        int hashFunction (int a)
        {  return (a % buckets);  }

        int search_element (int key)
        {
            // add code for your count of key comparisons
            int count =0;
            int indexkey = hashFunction(key);
            list<int>::iterator i = hashtable[indexkey].begin();
            for (; i != hashtable[indexkey].end(); i++)
            {
                count++;
                if (*i == key)
                    break;
            }
            count++;
            return count;
         }

        ~Hash()//destructor
         {  delete [] hashtable;  }
};

#endif /* Hash_h */

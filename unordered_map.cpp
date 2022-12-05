#include <iostream>
#include <set>
#include <list>
using namespace std;

// Here are some of the resources I used when researching how to implement a hash table with separate chaining.
// I used these resources as a pseudocode and a basis for how to implement the hash table.
// Resources: https://www.geeksforgeeks.org/c-program-hashing-chaining/ , https://en.wikipedia.org/wiki/Hash_table#Separate_chaining
// https://www.geeksforgeeks.org/separate-chaining-collision-handling-technique-in-hashing/
// Used the hash PowerPoint slides, page 80, for reference and the list PowerPoint
class unordered_map{

private:

    // Declaring a size for the table
    static const int tableSize = 150000;

    // This is the actual hash table. I created a pair of string and a set of strings since each spot in the array should hold the books name
    // and its genres. I used the list stl in order to create a linked list when there is a collision
    // I used the Hash Table PowerPoint slide 80 and the module 2 list PowerPoint in order to create
    // the table
    list<pair<string, string>> table[tableSize];

public:
    int hash(string key);
    void insert(string key, string value);
    set<string> get_set(string key);
};

// This function gets the hash value of the book title
int unordered_map::hash(string key) {

    int index = 0;

    // This finds the total ASCII value of the book title
    for(int i = 0; i < key.size(); i++){
        index = index + int(key[i]);
    }

    // This next line will reduce the hash to get an index and the function will return that value
    return index%10;
}

void unordered_map::insert(string key, string value) {

    // Finds the hash value of the book title and reduces it to an index
    int index = hash(key);
    int counter = 0;

    // Goes through the length of the table and when it reaches the specific index it will insert the title and genre
    for(int i = 0; i < tableSize; i++){
        if(counter == index){
            table[i].push_back(make_pair(key,value));
        }
        counter++;
    }
    
}


set<string> unordered_map::get_set(string key) {
    set<string> s1;
    // This goes throughout the length of the table
    for(int i = 0; i < tableSize; i++){

        // Printing out i so that you know what index you are at
        //cout << i << " ";

        // Goes through the linked list at each index of the table and the book title is printed
        for(auto it = table[i].begin(); it != table[i].end(); ++it){
            //cout << it->first << " ";
            if(it->first == key){
                s1.insert(it->second);
            }
           
        }
        //cout << endl;
    }
    return s1;
}


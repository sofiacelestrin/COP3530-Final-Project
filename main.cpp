#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "dataScrapper.h"
#include <set>
using namespace std;

int main(){

   // map<string, set<string>> bg;
   // initialize ordered map 
    Ordered_Map bg;
    Ordered_Map gb;
    // initialize unordred map
    unordered_map bg1;
    unordered_map gb1;
    
    // open file
    ifstream inputFile;
    // windows file path
    //string filename = "C:\\Users\\mihir\\Downloads\\books1.csv";
    // mac file path
    string filename = "./books1.csv";
    cout<<"opening file"<<endl;
    // parse the csv file
    dataScrapper csv;
    csv.parseFile(inputFile,filename,bg,gb,bg1,gb1);

    vector<string> related_book;
    // test case 1 : find related book to The Hunger Games with a threshold of 3
    // soluton: Harry Potter, 

    string source_book = "The Hunger Games";
   // set<string> source_set = bg[source_book];
    set<string> source_set = bg1.get_set(source_book);
    set<string> visted;
    visted.insert(source_book);
    int threshold = 3;

// set intersection logic : 
    // for each genre in source
        // for each book in that genre
            // check if that book has not been visted
                // perform a set intersection with the source set
                    // if the result is >= 3 then add the book to the result vector
                // add that book to visited

    for( auto g : source_set){
       //set<string> s1 = gb[g];
       set<string> s1 = gb1.get_set(g);
       for(auto b : s1){
        if(visted.count(b) == 0){
            // perform a set intersection between the two books' genres
            int intersectCount = 0;
            //set<string>s2 = bg[b];
            set<string> s2 = bg1.get_set(b);
            for(auto g2 : s2){
                if(source_set.count(g2)>0){
                    intersectCount++;
                }
            }
            if(intersectCount>=threshold){
                related_book.push_back(b);
            }
            visted.insert(b);
        }
       }
    }

    // printing out the related books
    //cout<<"The books that are related to "<<source_book<<" are using ordered map: "<<endl;
    cout<<"The books that are related to "<<source_book<<" are using ordered map: "<<endl;
    for(int i = 0; i<related_book.size(); i++){
        cout<<related_book[i]<<endl;
    }

    return 0;
}
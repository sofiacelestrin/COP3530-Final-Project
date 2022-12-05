#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "BooksRelated.h"
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

    // start of user interface using the command line
    string source_book = "";
    int threshold;
    int menuOption;
    bool menu = true;

    while(menu){
        cout<<"Welcome to Book Finder !!!"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Plese enter a book title: ";
        cin>> source_book;
        cout<<endl;
        cout<<"Please enter a threshold of genre similiarity from 1-5: ";
        cin>>threshold;
        cout<<endl;

        cout<<"Menu:"<<endl;
        cout<<"1). Search with an Ordered Map"<<endl;
        cout<<"2). Search with an Unordered Map"<<endl;
        cout<<"3). Compare two map types"<<endl;
        cout<<"4). Insert a different book"<<endl;
        cout<<"5). Search with an Ordered Map"<<endl;

        switch (menuOption){
            case 1:
    
        }


    }
    
    

    BooksRelated finder; 

    finder.getBooks(source_book,3,1,bg,gb,bg1,gb1);
    finder.getBooks(source_book,3,2,bg,gb,bg1,gb1);
    



    return 0;
}
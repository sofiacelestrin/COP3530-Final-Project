#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "BooksRelated.h"
#include <set>
#include <chrono>
using namespace std;
using namespace std::chrono;


void menuFunction(string source_book,int threshold, int option,Ordered_Map& bg, Ordered_Map& gb,unordered_map& bg1, unordered_map& gb1){
        BooksRelated finder; 
        if(threshold>=1 && threshold<= 5){
            auto start = high_resolution_clock::now();
            finder.getBooks(source_book,threshold,option,bg,gb,bg1,gb1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            if( option ==1){
                cout<<"The time taken using an ordered map is :"<<duration.count()<<" microsecond"<<endl;
            }
            else if( option ==2){
                cout<<"The time taken using an unordered map is :"<<duration.count()<<" microsecond"<<endl;
            }
        }
        else{
            cout<<"Theshold is not valid Please try again."<<endl;
        }       

    }

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
    // file path
    string filename = "./updated_books (1).csv";
    cout<<"opening file"<<endl;
    // parse the csv file
    dataScrapper csv;
    csv.parseFile(inputFile,filename,bg,gb,bg1,gb1);

    // start of user interface using the command line
    cout<<endl;
    string source_book = "";
    string similarity;
    string menu_Option;
    int threshold;
    int menuOption;
    bool menu = true;

    while(menu){

        cout<<"Welcome to Book Finder !!!"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Plese enter a book title: ";
        getline(cin, source_book);
        cout<<"Please enter a threshold of genre similiarity from 1-5: ";
        getline(cin, similarity);
        threshold = stoi(similarity);

        cout<<"Menu:"<<endl;
        cout<<"1). Search with an Ordered Map"<<endl;
        cout<<"2). Search with an Unordered Map"<<endl;
        cout<<"3). Compare two map types"<<endl;
        cout<<"4). Insert a different book"<<endl;
        cout<<"5). Exit"<<endl;
        cout<<"Enter a menu option: ";
        getline(cin, menu_Option);
        menuOption = stoi(menu_Option);
        cout<<endl;

        switch (menuOption){
            case 1:
                menuFunction(source_book,threshold, 1,bg,gb,bg1,gb1);
                menu = false;
                break;
            case 2: 
                menuFunction(source_book,threshold, 2,bg,gb,bg1,gb1);

                menu = false;
                break;
            case 3:
                menuFunction(source_book,threshold, 1, bg,  gb, bg1,gb1);
                menuFunction(source_book,threshold, 2, bg,  gb, bg1, gb1);
                menu = false;
                break;
            case 4: 
                cout<<"You will be sent back to the main menu to insert a new book."<<endl;
                menu = false;
                break;
            case 5: 
                cout<<"Have a nice day!"<<endl;
                menu = false;
                break;
            default: 
                cout<<"Invalid menu selection, please try again."<<endl;
                break;
        }
        while(!menu){
            string userInput;
            cout<<"Do you want to look for more books? (Y/N): ";
            getline(cin,userInput);
            cout<<endl;
            if(userInput == "Y"){
                cout<<"Pulling up menu..."<<endl;
                menu = true;
            }
            else if(userInput == "N"){
                cout<<"Have a nice day!"<<endl;
                break;
            }
            else{
                cout<<"Invalid input!"<<endl;
                cout<<"Please check your input and try again."<<endl;
            }
            
        }

    }


    return 0;
}
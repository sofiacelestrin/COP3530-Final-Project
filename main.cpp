#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
using namespace std;

int main(){
    // open file
    ifstream inputFile;
    // windows file path
    //string filename = "C:\\Users\\mihir\\Downloads\\books1.csv";
    // mac file path
    string filename = "../books1.csv";
    cout<<"opening file"<<endl;
    inputFile.open(filename);

    // ordered map with the title as a key and a set of generes as the value
    map<string, set<string>> bg;
    // ordred map with genre as a key and a set of books as the value
    map<string, set<string>> gb;

    string line = "";
    // ignore the title of the column title of the csv file
    getline(inputFile, line);

    while(getline(inputFile,line)){
        string title = "";
        string genre = "";
        
        stringstream inputstring(line);
        getline(inputstring, title, ',');

        //cout<< title<<endl;

        getline(inputstring, genre, '[');
        getline(inputstring, genre, ']');

        //cout<< genre<<endl;

        stringstream genres(genre);

         // get first genre since there is no space before the comma
        getline(genres, genre, ',');
        genre = genre.substr(1,genre.length()-2);
        //cout<< genre<<endl;
        // add genre to map bg
        bg[title].insert(genre);
        cout<<"adding "<< title<<" : "<< genre<<endl;
        // add book title to gb
        gb[genre].insert(title);
        cout<<"adding "<< genre<<" : "<< title<<endl;
        // get remaining genres
        while(getline(genres, genre, ',')){

            genre = genre.substr(2,genre.length()-3);
            //cout<< genre<<endl;
            bg[title].insert(genre);
            cout<<"adding "<< title<<" : "<< genre<<endl;
            gb[genre].insert(title);
            cout<<"adding "<< genre<<" : "<< title<<endl;
        }

        line = "";
    }
    
    vector<string> related_book;
    // test case 1 : find related book to The Hunger Games with a threshold of 3
    // soluton: Harry Potter, 

    string source_book = "The Hunger Games";
    set<string> source_set = bg[source_book];
    set<string> visted;

    // for each genre in source
        // for each book in that genre
            // check if that book has been visted
                // perform a set union with the source set
                    // if the result is >= 3 then add the book to the result vector
                // add that book to visited

    

    return 0;
}
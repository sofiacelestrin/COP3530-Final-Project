#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    ifstream inputFile;
    string filename = "C:\\Users\\mihir\\Downloads\\books1.csv";
    inputFile.open(filename);

    string line = "";
    // ignore the title of the column title of the csv file
    getline(inputFile, line);

    while(getline(inputFile,line)){
        string title = "";
        string genre = "";
        
        stringstream inputstring(line);
        getline(inputstring, title, ',');

        cout<< title<<endl;

        getline(inputstring, genre, '[');
        getline(inputstring, genre, ']');

        cout<< genre<<endl;

        stringstream genres(genre);

         // get first genre since there is no space before the comma
        getline(genres, genre, ',');
        genre = genre.substr(1,genre.length()-2);
        cout<< genre<<endl;
        // get remaining genres
        while(getline(genres, genre, ',')){

            genre = genre.substr(2,genre.length()-3);
            cout<< genre<<endl;

        }

        line = "";
    }
    

   


    

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include "Ordered_Map.cpp"
#include "unordered_map.cpp"


class dataScrapper{
    public : 

        void parseFile(ifstream& inputFile, string filename, Ordered_Map& bg, Ordered_Map& gb,unordered_map& bg1,  unordered_map& gb1 ){
            inputFile.open(filename);
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
                bg1.insert(title,genre);
                //cout<<"adding "<< title<<" : "<< genre<<endl;
                // add to ordred map
                gb[genre].insert(title);
                // add to unordred map
                gb1.insert(genre,title);
                //cout<<"adding "<< genre<<" : "<< title<<endl;
                // get remaining genres
                while(getline(genres, genre, ',')){

                    genre = genre.substr(2,genre.length()-3);
                    //cout<< genre<<endl;
                    bg[title].insert(genre);
                    bg1.insert(title,genre);
                    //cout<<"adding "<< title<<" : "<< genre<<endl;
                    gb[genre].insert(title);
                    gb1.insert(genre,title);
                    //cout<<"adding "<< genre<<" : "<< title<<endl;
                }

                line = "";
            }
        }
};
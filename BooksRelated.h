#include "dataScrapper.h"
#include <vector>

class BooksRelated{

    public:

        void getBooks(
            string source_book, int threshold,int option, Ordered_Map& bg,Ordered_Map& gb,
            unordered_map& bg1,unordered_map& gb1){
            vector<string> related_book;
            string method = "";
            set<string> visted;
            visted.insert(source_book);

            // set intersection logic : 
                // for each genre in source
                    // for each book in that genre
                         // check if that book has not been visted
                            // perform a set intersection with the source set
                            // if the result is >= 3 then add the book to the result vector
                            // add that book to visited
            // need to copy the code twice for differed maps since the api calls for insert and search are different
            if(option==1){
                method = "ordered map";
                set<string> source_set = bg[source_book];
                for( auto g : source_set){
                set<string> s1 = gb[g];
                for(auto b : s1){
                    if(visted.count(b) == 0){
                        // perform a set intersection between the two books' genres
                        int intersectCount = 0;
                        set<string>s2 = bg[b];
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
            }
            else if(option==2){
                method = "unordered_map";
                set<string> source_set = bg1.get_set(source_book);
                for( auto g : source_set){
                set<string> s1 = gb1.get_set(g);
                for(auto b : s1){
                    if(visted.count(b) == 0){
                        // perform a set intersection between the two books' genres
                        int intersectCount = 0;
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
            }

         // printing out the related books
        cout<<"The books that are related to "<<source_book<<" using an "<<method<<" :"<<endl;
        if(related_book.size()==0){
            cout<<"There are no related books"<<endl;
        }
        else{
            for(int i = 0; i<related_book.size(); i++){
                cout<<related_book[i]<<endl;
             }
        }
        
        // empty the visted set and related book vector for future use with different source
        visted.clear();
        related_book.clear();

        }
};

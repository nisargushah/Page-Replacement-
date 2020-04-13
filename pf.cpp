#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>


using namespace std;


struct working_set{
    int frame1;
    int frame2;
    int frame3;
};
/*
 
 This Function just prints out the vectors that we passed through it
 Mainly a debugging tool to see if we correctly deleted certain elements.
 
 */

void PrintVectors(vector<int> x)
{
    for( int i =0; i<x.size();i ++)
    {
        cout<<x[i]<<endl;
    }
}


/*
 
 This Function will be used to count the number of Page Faults usign the FIFO algorithm
 
 */
void FIFO_page_faults(vector<int> pages_requested, int working_frame_set)
{
    //
    int page_faults;
    working_set FIFO_set;
    
    FIFO_set.frame1 = 10;
    FIFO_set.frame2 = 10;
    FIFO_set.frame3 = 10;
    int i=0;
    while(i<pages_requested.size())
    {
        if( pages_requested[i] != FIFO_set.frame1 && pages_requested[i] != FIFO_set.frame2 && pages_requested[i] != FIFO_set.frame3 )
        {
            FIFO_set.frame1 = FIFO_set.frame2;
            FIFO_set.frame2 = FIFO_set.frame3;
            FIFO_set.frame3 = pages_requested[i];
            page_faults++;
        }
        else if( pages_requested[i] == FIFO_set.frame1 )
    }
    

    
}

// MAIN Function.
int main()
{
    string myText;
    vector<int> trial;
    ifstream MyReadFile("filename.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
//      Output the text from the file
//      cout << myText;
//      cout<<" ";
//      cout<<endl;
        istringstream ss(myText);
        
        
// Traverse through all words
          do {
              // Read a word
              string word;
              ss >> word;
        
// Print the read word
// cout << word << endl;
              int a;
              istringstream(word)>>a;
              trial.push_back(a); // While there is more to read
          } while (ss);
//        PrintVectors(trial);
    }

    // Close the file
    MyReadFile.close();
    
//    PrintVectors(trial);
    
    int frame_size;
    frame_size = trial[0];
    trial.erase(trial.begin());
    PrintVectors(trial);
    cout<<endl<<endl<<endl<<frame_size;
    
}

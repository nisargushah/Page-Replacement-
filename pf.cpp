#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>


using namespace std;

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
int FIFO_page_faults(vector<int> pages_requested, int working_frame_number)
{
    int page_hits;
    int page_faults = 0 ;
    int q=0;
    int total_pages= pages_requested.size();
    vector<int> working_set;
    vector<int>::iterator it;
    
    while(!pages_requested.empty())
    {
        int ser = pages_requested[0];
        it = find (working_set.begin(), working_set.end(), ser);
        if (it != working_set.end())
        {
            
            page_hits++;
            pages_requested.erase(pages_requested.begin());
        }
        else
        {
            if(working_set.size()>=working_frame_number)
            {
                working_set.erase(working_set.begin());
            }
            
            working_set.push_back(pages_requested[0]);
            pages_requested.erase(pages_requested.begin());
            page_faults++;
            
        }
    }
    return page_faults;
    
}
int LRU_page_faults(vector<int> pages_requested, int working_frame_number)
{
    int page_hits;
    int page_faults;
    vector<int> working_set;
    vector<int>::iterator it;
    
    while(!pages_requested.empty())
    {
        int ser = pages_requested[0];
        it = find (working_set.begin(), working_set.end(), ser);
        if (it != working_set.end())
        {
            //Page Hits
        }
        else
        {
            //Page_faults
        }
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
    int x;
    frame_size = trial[0];
    trial.erase(trial.begin());
    PrintVectors(trial);
    cout<<endl<<endl<<endl<<frame_size;
    x=FIFO_page_faults(trial,frame_size);
    cout<<endl<<x;
    
}




//Working_frame_number is number of frames which we got from the first element of our input file.
            
//Working_set is an array with size (working_frame_number) which will store the frames that are supposed to be in memeory.

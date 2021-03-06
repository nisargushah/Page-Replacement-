
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>


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

struct Template
{
    int frame;
    int frequency;
};



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
    int page_hits=0;
    int page_faults=0;
    vector<int> working_set;
    vector<int> track;
    vector<int>::iterator it;
    vector<int>::iterator it2;
    
   while(!pages_requested.empty())
    {
        int ser = pages_requested[0];
        it = find (working_set.begin(), working_set.end(), ser);
        if (it != working_set.end())
        {
            //Page Hits
            page_hits++;
            track.push_back(pages_requested[0]);
            it = find(working_set.begin(), working_set.end(), pages_requested[0]);
            if( it2 != working_set.end())
            {
                int temp3  = it-working_set.begin();
                working_set.erase(working_set.begin()+temp3);
                working_set.push_back(pages_requested[0]);
            }
            else
            {
                //
            }
            
        }
        else
        {
            page_faults++;
            working_set.push_back(pages_requested[0]);
            if(working_set.size()>working_frame_number)
            {
                working_set.erase(working_set.begin());
            }
            
           //Page_faults*/
        }
        pages_requested.erase(pages_requested.begin());
    }
    return page_faults;
}

int MFU_page_faults(vector<int> pages_requested, int working_frame_number)
{
    int page_hits=0;
    int page_faults=0;
    int total_pages = pages_requested.size();
    vector<Template> data;
    vector<int>::iterator it;
    
    while(!pages_requested.empty())
    {
        vector<int> working_set;
        for(int i=0;i<data.size();i++)
        {
            working_set.push_back(data[i].frame);
        }
        int ser = pages_requested[0];
        it = find (working_set.begin(), working_set.end(), ser);
//        cout<<"Start:"<<endl;
        if (it != working_set.end())
        {
//            cout<<"PageHit!!"<<endl;
            //page_hits
            int s=0;
            while (s<data.size())
            {
                if(data[s].frame == ser)
                {
                    data[s].frequency+=1;
                }
                s++;
            }
            page_hits++;
            
        }
        else
        {
                //page_faults
            
            if(data.size()<working_frame_number)
            {
                Template t;
                t.frame = ser;
                t.frequency=1;
                data.push_back(t);
                page_faults++;
            }
            else
            {
                int index=0;
                int s=0;
                while(s<data.size())
                {
                    if(data[s].frequency > index)
                    {
                        index = s;
                    }
                    else
                    {
                     //
                    }
                    s++;
                }
                
                data.erase(data.begin()+index);
                
                Template t2;
                
                t2.frame = ser;
                t2.frequency = 1;
                data.push_back(t2);
                page_faults++;
            }
        }
        pages_requested.erase(pages_requested.begin());
        
    }
    return page_faults;

}

int Optimal_page_faults(vector<int> pages_requested, int working_frame_number)
{
    //Optimal Page Fault Algorithm
    int page_faults=0;
    int page_hits = 0;
    vector<int> working_set;
    int page_size = pages_requested.size();
    vector<int>::iterator it;
//    cout<<endl<<page_size<<endl;
    
    while(!pages_requested.empty())
    {
        int ser = pages_requested[0];
        it = find (working_set.begin(), working_set.end(), ser);
        if(it!=working_set.end())
        {
            //page hit
        }
        else
        {
                //page Faults
//            cout<<endl<<"It goes through here "<<endl;
            if(working_set.size()<working_frame_number)
            {
                working_set.push_back(ser);
                page_faults++;
//                cout<<endl<<working_set.size()<<endl;
            }
            else
            {
                //STEP 1: Search which frame to replace.
                //        Should be the one that is reuired the farthest.
                vector<int> test;
                int erase_element;
                
                for(int i =0 ;i < working_set.size();i++)
                {
                    test.push_back(working_set[i]);
                }
                for(int i=1;i<pages_requested.size();i++)
                {
                    if(test.size() == 1)
                    {
                        erase_element = test[0];
                     }
                    else
                    {
                        for(int j=0;j<test.size();j++)
                        {
                            if(test[j] == pages_requested[i])
                            {
                                test.erase(test.begin()+j);
                            }
                        }
                    }
                    
                }
                //Find index of that element ;
                
                int index2;
                for(int k=0;k<working_set.size();k++)
                {
                    if(working_set[k] == erase_element)
                    {
                        index2 = k;
                    }
                }
                working_set.erase(working_set.begin()+index2);
                working_set.push_back(ser);
                page_faults++;
            }
        }
        
        pages_requested.erase(pages_requested.begin());
        
    }
    
    return page_faults;
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
        int frame_size;
        int x,y,z,w;
        cout<<endl;
        frame_size = trial[0];
        trial.erase(trial.begin());
        x=FIFO_page_faults(trial,frame_size);
        cout<<"Page faults in FIFO : \t"<<x<<endl;
        y=LRU_page_faults(trial,frame_size);
        cout<<"Page faults in LRU : \t"<<y<<endl;
        z=MFU_page_faults(trial,frame_size);
        cout<<"Page faults in MFU : \t"<<z<<endl;
        w=Optimal_page_faults(trial,frame_size);
        cout<<"Page faults in Optimal: "<<w<<endl;
        trial.clear();
        cout<<endl<<endl;
        
    }

    // Close the file
    MyReadFile.close();
    
//    PrintVectors(trial);
    
    
//
//    PrintVectors(trial);
//    cout<<endl<<endl<<endl<<frame_size<<" Frame Size";
    
//    cout<<endl<<"Page size : "<<trial.size();
    
}

//Working_frame_number is number of frames which we got from the first element of our input file.
            
//Working_set is an array with size (working_frame_number) which will store the frames that are supposed to be in memeory.

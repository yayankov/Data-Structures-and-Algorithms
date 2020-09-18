#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct File{
    map<string, File*> subFiles;
    File* fileParent;
    string firstDirectory;
    
};

struct System{
    File* temp;
    System()
    {
        temp = new File();
        temp->firstDirectory = "/";
        temp->fileParent = nullptr;
    }
    
    void Mkdir(string _name);
    void Ls();
    void Pwd();
    void Cd(string input);
};

void System::Mkdir(string name)
{
    if(temp->subFiles.count(name))
    {
            cout<<"Directory already exists"<<endl;
    }
    else{
            File* temp2 = new File();
            temp2->fileParent = temp;
            temp2->firstDirectory = temp->firstDirectory + name+'/';
            temp->subFiles.insert({name,temp2});
    }
}

void System::Ls()
{
    for(auto itr : temp -> subFiles){
            cout << itr.first <<" ";
        }
        cout << endl;
}

void System::Pwd()
{
    cout<<temp->firstDirectory<<endl;
}
void System::Cd(string input)
{
    if(input == "..")
    {
            if(!temp->fileParent) 
                cout<<"No such directory"<<endl;
            else temp = temp->fileParent;
    }
    else
    {
            if(temp -> subFiles.count(input)) 
                temp = temp -> subFiles[input];
            else 
                cout<<"No such directory"<<endl;
    }
}

int main() {
    int N;
    cin >> N;
    System syst;
    cin.ignore();
    string rowStr;
    int k;
    string command;
    for(int i=0; i<N; i++)
    {
        getline(cin, rowStr);
        k = rowStr.find(" ");
        command = rowStr.substr(0, k);
         
        if(command == "mkdir")
        {
            syst.Mkdir(rowStr.substr(k + 1, rowStr.size() - k));
        }
        else if(command == "ls")
        {
            syst.Ls();
        }
        else if(command == "cd")
        {
            syst.Cd(rowStr.substr(k + 1, rowStr.size() - k));
        }
        else if(command == "pwd")
        {
            syst.Pwd();
        }                     
    }
    return 0;
}

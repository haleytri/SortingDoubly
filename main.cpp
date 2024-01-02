#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "ArgumentManager.h"
#include "doubly.h"

using namespace std;

int main(int argc, char *argv[])
{
    ArgumentManager am(argc, argv);

    string input = am.get("input");
    string output = am.get("output");

    //string input = "input7.txt";
    //string output = "OUT.txt";

    linked list;
    ifstream in(input);
    ofstream out(output);
    string nums = "";
    string numlist = "";
    string sortType = "";
    string sort = "";

    getline(in, nums);  //first line = numbers to sort!
    nums.erase(remove(nums.begin(), nums.end(), '\n'), nums.end());
    nums.erase(remove(nums.begin(), nums.end(), '\r'), nums.end());

    if(nums.empty())
    {
        cout << "Input is invalid.";
        out << "Input is invalid.";
        return 0;
    }

    stringstream ss(nums);

    while (ss >> numlist)
    {
        for(int i = 0; i < numlist.length(); i++)
        {
            if(!isdigit(numlist[i]))
            {
            cout << "Input is invalid.";
            out << "Input is invalid.";
            return 0;
            }
        }
        
        list.insertAtEnd(stoi(numlist));
    }
    //list.print();

    getline(in, sort);
    sort.erase(remove(sort.begin(), sort.end(), '\n'), sort.end());
    sort.erase(remove(sort.begin(), sort.end(), '\r'), sort.end());
    sort.erase(remove(sort.begin(), sort.end(), ' '), sort.end());

    if(sort.empty())
    {
        cout << "Input is invalid.";
        out << "Input is invalid.";
        return 0;
    }
    

    //need to check if file is empty and if numbers/sorting type in correct spot

    if(sort == "Insertion")
    {
        cout << "insertion!" << endl;
        list.insertion(out);
    }
    else if (sort == "Selection")
    {
        cout << "selection!" << endl;
        list.selection(out);
    }
    else if (sort == "Bubble")
    {
        cout << "bubble!" << endl;
        list.bubble(out);
    }
    else
    {
        cout << "Input is invalid.";
        out << "Input is invalid.";
    }
}
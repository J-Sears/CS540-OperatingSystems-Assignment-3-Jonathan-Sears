// CS540 OperatingSystems Assignment 3 Jonathan Sears.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip> // For std::hex

using namespace std;

const int PAGE_SIZE = 1024;  // Page siz
const int FRAME_SIZE = 1024; // Frame size
const int NUM_PAGES = 64;    // Number of pages in logical memory change if you want to have larger memory values
const int NUM_FRAMES = 8;    // Number of frames in physical memory

int main()
{
    vector<int> pageFrameTable(NUM_PAGES, -1); //creates the frametable for the pages
    vector<int> physicalMemory(NUM_FRAMES, -1); //creates the physical memory vector that is empty
    for (int i = 0; i < NUM_PAGES; ++i) //for loop that fills the frametable vector with values
    {
        pageFrameTable[i] = i % NUM_FRAMES;
    }

    int userHex;
    cout << "Please input a logical memory value (input 0 to exit): ";
    cin >> hex >> userHex; //Takes in user hex memory input and stores it
    if (userHex == 0) //checks if the user input is valid and exits the program if it is not
    {
        cout << "Either input was entered 0 or a not valid hex value was entered";
    }
    else 
    {
        int pageNum = (userHex / 1024.0); //Find the page number for the logical memory address
        int offset = (userHex % 1024); //Finds the offest for the logical memory address
        if (pageNum < NUM_PAGES)
        {
            int frameNum = pageFrameTable[pageNum]; // gets the frame number using the pagenum gotten from the user input
            int physicalAddress = frameNum * FRAME_SIZE + offset; // find the physical address by adding offset to the base address in the frame
            cout << "Logical Address: 0x" << hex << userHex << " ==> " << "Page Number : 0x" << hex << pageNum << " ==> "; //Prints the logical memory address input by the user and the page number
            cout << "Offset: 0x" << hex << offset << " = > Physical Address : 0x" << physicalAddress << endl; // Prints the offest and physical memory addresses
        }
        else
        {
            cout << "Invalid Page Number: " << pageNum << endl; //error message when page number isn't in bounds
        }
    }
    while (userHex != 0) //while loop that allows the user to enter as many memory values they might want
    {
        cout << "Please input a logical memory value (input 0 to exit): ";
        cin >> hex >> userHex; 
        if (userHex == 0) 
        {
            cout << "Either input was entered 0 or a not valid hex value was entered";
            break; //breaks out of the loop if the user enters 0 or an invalid hex number
        }
        int pageNum = (userHex / 1024.0);
        int offset = (userHex % 1024); 
        if (pageNum < NUM_PAGES)
        {
            int frameNum = pageFrameTable[pageNum]; 
            int physicalAddress = frameNum * FRAME_SIZE + offset; 
            if (userHex != physicalAddress) 
            {
                cout << "Logical Address: 0x" << hex << userHex << " ==> " << "Page Number : 0x" << hex << pageNum << ", " << "Offset: 0x" << hex << offset << " =+> Physical Address : 0x" << physicalAddress << endl;
            }
        }
        else 
        {
            cout << "Invalid Page Number: " << pageNum << endl;
        }
    }

    return 0;
}
/*
Name: Giovanni Martinez
Date: 12/07/2019
Program: Structs
Description: Work with structs
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>													// Clock()
#include "myfunctions.h"											// Header File

using namespace std;

const int NUM_METHODS = 4;

/* Main Function */
int main()
{
	// Variables
	ofstream outFS;													// Output data streamer
	string fileName;
	double t1, t2, times[NUM_METHODS];										// Time function
	string sortTimeMethod[NUM_METHODS] = { "Counting", "Heap", "Comb",
		"Cartesian Tree" };
	int size = sizeof(studentList);

	// Initial Data File Duplication
	cout << "File Name: ";											// Ask for file name
	getline(cin, fileName);
	fillVector(studentList, fileName);								// Call fillVector()
	displayStudents(studentList, 1, " ");							// Call displayStudents()

	// Selection Sort
	t1 = clock();													// Start Time
	sortSelection(studentList);										// Call selectionSort();
	t2 = clock();													// End Time
	times[0] = getMilliSeconds(t2 - t1);							// Append time to array
	cout << "Time = " << getMilliSeconds(t2 - t1) <<				// Output returned value of getMilliSeconds();
		" milliseconds." << endl;
	displayStudents(studentList, 2, "Selection");					// Call displayStudents()

	// Counting Sort
	/*
	t1 = clock();													// Start Time
	countingSort(studentList);										// Call selectionSort();
	t2 = clock();													// End Time
	times[1] = getMilliSeconds(t2 - t1);							// Append time to array
	cout << "Time = " << getMilliSeconds(t2 - t1) <<				// Output returned value of getMilliSeconds();
		" milliseconds." << endl;
	displayStudents(studentList, 2, "Counting");					// Call displayStudents()
	*/

	// Heap Sort
	t1 = clock();													// Start Time
	heapSort(studentList, size);									// Call heapSort();
	t2 = clock();													// End Time
	times[2] = getMilliSeconds(t2 - t1);							// Append time to array
	cout << "Time = " << getMilliSeconds(t2 - t1) <<				// Output returned value of getMilliSeconds();
		" milliseconds." << endl;
	displayStudents(studentList, 2, "Heap");						// Call displayStudents()

	//Information Table
	cout << right << setfill('*');
	cout << "\n" << setw(80) << "*" << endl;
	cout << right << setfill(' ');
	cout << setw(12) << left << "Sort Method:         " << setw(8) << left << "Time Taken:" << endl << endl;

	for (int i = 0; i < NUM_METHODS; i++)
		cout << setw(21) << left << sortTimeMethod[i] << times[i] << " miliseconds" << endl;

	//Save Table to file
	outFS << endl << setw(12) << left << "Sort Method:         " << setw(8) << left << "Time Taken:" << endl << endl;

	for (int i = 0; i < NUM_METHODS; i++)
		outFS << setw(21) << left << sortTimeMethod[i] << times[i] << " miliseconds" << endl;

	outFS.close();													//Close File

	system("pause");												// Pause system
	return 0;														// Terminate program - no errors
}
/*
Name: Giovanni Martinez
Date: 12/07/2019
Program: Structs
Description: Work with structs
*/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>				// Clock()
#include <algorithm>
#define RANGE 100

// Struct Declarations
struct Student {
	std::string name;
	double score;
};

// Vector Declaration
std::vector<Student> studentList;

/* Get Time in Milliseconds */
double getMilliSeconds(clock_t c) {
	double time;
	time = (double(c) / CLOCKS_PER_SEC) * 10000;
	return time;
}

/* Fill Array */
void fillVector(std::vector<Student>& studentList,
	std::string fileName) {
	std::ifstream inFs;
	int index = 0;
	std::string name;
	double score;
	Student newStudent;

	inFs.open(fileName);												// Open/Read from file

	if (!inFs.is_open()) {												// Check if file is not open
		std::cout << "Could not open file " << fileName << std::endl;
		std::cout << "Press <ENTER> to exit" << std::endl;
		std::cin.get();													// Any key terminates program
		exit(0);														// Terminate program - no error
	}

	while (!inFs.eof()) {												// While not at end-of-file
		inFs >> name >> score;											// Assign file data to variables
		newStudent.name = name;											// Append string-type variable to object
		newStudent.score = score;										// Append double-type variable to object
		studentList.push_back(newStudent);								// Append object to vector

		index++;														// Increment value
	}

	inFs.close();														// Close file
}

/* Display Array */
void displayStudents(std::vector<Student> studentList,
	int selection, std::string method) {
	if (selection == 1) {
		std::ofstream outFs;

		outFs.open("Output.txt");										// Create/Write-to file

		std::cout << "Data of students found in the text file:" <<
			std::endl;

		for (int i = 0; i < studentList.size(); i++) {					// Iterate through struct
			std::cout << studentList[i].name << " " <<					// Output struct data to CLI
				studentList[i].score << std::endl;

			outFs << studentList[i].name << " " <<						// Output vector data to file
				studentList[i].score << std::endl;
		}

		std::cout << std::endl;

		outFs.close();													// Close file
	}
	else if (selection == 2) {
		std::ofstream outFs;

		outFs.open(method + "Sort.txt");								// Create/Write-to file

		std::cout << method + " Sort Algorithm:" << std::endl;

		for (int i = 0; i < studentList.size(); i++) {					// Iterate through struct
			std::cout << studentList[i].name << " " <<					// Output struct data to CLI
				studentList[i].score << std::endl;

			outFs << studentList[i].name << " " <<						// Output vector data to file
				studentList[i].score << std::endl;
		}

		std::cout << std::endl;

		outFs.close();													// Close file
	}
}

/* Sort Selection Algorithm */
void sortSelection(std::vector<Student>& studentList) {
	double tempScore;
	std::string tempName;

	// My Solution
	/*
	for (int i = 0; i < studentList.size(); i++) {
		for (int j = 0; j < studentList.size(); j++) {
			if (studentList[i].score < studentList[j].score) {			// If value of first iteration is less than value of second iteration
				tempScore = studentList[i].score;						// Assign value to variable
				studentList[i].score = studentList[j].score;			// Append value of second iteration to index of first iteration
				studentList[j].score = tempScore;						// Assign variable value to index of second iteration

				tempName = studentList[i].name;							// Assign value to variable
				studentList[i].name = studentList[j].name;				// Append value of first iteration to index of second iteration
				studentList[j].name = tempName;							// Assign variable value to index of second iteration
			}
		}
	}
	*/

	// Professor's Solution
	for (int i = 0; i < studentList.size(); i++) {
		int minIndex = i;
		for (int j = i + 1; j < studentList.size(); j++) {
			if (studentList[j].score < studentList[minIndex].score) {
				minIndex = j;
			}
		}
		tempScore = studentList[i].score;
		studentList[i].score = studentList[minIndex].score;
		studentList[minIndex].score = tempScore;

		tempName = studentList[i].name;
		studentList[i].name = studentList[minIndex].name;
		studentList[minIndex].name = tempName;
	}
}

/* Counting Sort Algorithm */
/*
void countingSort(std::vector<Student>& studentList) {
	int size = studentList.size();
	std::vector<int> out(size);

	int count[RANGE + 1], i;
	memset(count, 0, sizeof(count));

	for (i = 0; size; i++)													// Store count of each character
		count[studentList[i]]++;

	for (i = 1; i <= RANGE; i++)											// count[i] now contains actual position if this charracter
		count[i] += count[i - 1];

	for (i = 0; size; i--) {												// Build the output character array
		out[count[studentList[i]]-1] = studentList[i];
		count[studentList[i]]--;
	}

	for (i = 0; i < size; i++) {											// Copy out[] to studentList[]
		studentList[i].score = out[i];
	}
}
*/

/* Heap Sort Algorithm */
/* Heapify Subtree */
void heapify(std::vector <Student>& studentList, int n, int i)
{
	int largest = i;														// Initialize largest as root 
	int left = 2 * i + 1;													// left = 2*i + 1 
	int right = 2 * i + 2;													// right = 2*i + 2 

	if (left < n && studentList[left].score > studentList[largest].score)	// If left child is larger than root 
		largest = left;

	if (right < n && studentList[right].score > studentList[largest].score)	// If right child is larger than largest so far 
		largest = right;

	if (largest != i)														// If largest is not root 
	{
		std::swap(studentList[i], studentList[largest]);
		heapify(studentList, n, largest);									// Recursively heapify the affected sub-tree 
	}
}

/* Heap Sort Algorithm */
void heapSort(std::vector <Student>& studentList, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)									// Build heap (rearrange array)
		heapify(studentList, n, i);

	for (int i = n - 1; i >= 0; i--)										// One by one extract an element from heap
	{
		std::swap(studentList[0], studentList[i]);							// Move current root to end
		heapify(studentList, i, 0);											// Call max heapify on the reduced heap
	}
}
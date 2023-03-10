//Prog07.cpp
//Boncers
//Program 7
//March 8, 2023
//This Program pulls information about employee hours from the data files and writes them to an output file.
//Great example of how to use an input file to get data for classes and structures.

#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::string;
using std::getline;

bool done = false, error = false;
string input, output;
ifstream inputFile;
ofstream outputFile;

//This structure is what everything is being sorted into
struct employee {
	int id;
	char department[25];
	float hours;
};

int main() {
	//This loop really only needs to be here until the bool done is set to true. It doesn't affect
	//anything else in the code though so it doesn't matter if the rest of the code is in it or not.
	while (!done) {
		//Process of obtaining the input and output files.
		cout << "Please give the name of your input file: ";
		cin >> input;
		cout << "Please give the name of the output file: ";
		cin >> output;

		//Opens the input and output file. If either file fails to open, then the error boolean
		//is set to true. This will trigger an if statement later.
		inputFile.open(input);
		outputFile.open(output, std::ios_base::app); //This line ensures that the file is in append mode
		if (!inputFile) {
			cout << "Can't open " << input << "\n";
			inputFile.clear();
			error = true;
		}
		if (!outputFile) {
			cout << "Can't open " << output << "\n";
			outputFile.clear();
			error = true;
		}

		//This if statement ensures that the failed file will close after the boolean is set off
		//Unsure why this doesn't work in the first if statement, but weird things will happen if 
		//I don't write it this way. 
		//
		//An example of the "weird things" is if you were to input an incorrect name and then
		//a correct one. It will properly prompt you again, but when you then type in the correct
		//names it will prompt you once again. The only way I got it to work is putting in this 
		//seperate if statement with an error boolean.
		if (error)
		{
			if (inputFile)
			{
				inputFile.close();
			}
			if (outputFile)
			{
				outputFile.close();
			}
			error = false;
			continue; //Apparently this key word  tells the program to go back to the beginning of
					  //the while loop
		}
		done = true;
		employee obj; //This line declares the class as a variable to be used in the file read later
		double totalHours = 0;
		int totalEmployees = 0;
		float averageHours = 0;
		
		//This loop grabs individual pieces of information as objects and formats them into the
		//previously declared structure
		inputFile.read(reinterpret_cast<char*>(&obj), sizeof(obj));
		while (!inputFile.eof()) {
			totalHours = totalHours + obj.hours;
			totalEmployees++;
			inputFile.read(reinterpret_cast<char*>(&obj), sizeof(obj));
		}
		
		//This is the writing to the files. 
		outputFile << totalEmployees << " employees." << "\n";
		averageHours = totalHours / totalEmployees;
		outputFile << "Total hours: " << totalHours << "\n";
		outputFile << "Average per employee: " << averageHours << "\n \n";
		inputFile.close();
		outputFile.close();
		cout << "\ndone reading and writing!";
	}
	return 0;
}
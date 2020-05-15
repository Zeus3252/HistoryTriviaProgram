#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "CSVReader.h"
#include <string>
#include <fstream>

using namespace std;

class Question{ 
	private:
		string difficulty;
		int chapter;
		int number;
		string question;
	public:
		void printInfo();
		
Question(){ //constructor that gives these default values to all Questions
	number=0;
	difficulty="";
	chapter=0;
	question="";	
}

Question(int number2, string difficulty2, int chapter2, string question2){ //stores data from CSV in number difficulty chapter quesion
		number=number2;
		difficulty=difficulty2;
		chapter=chapter2;
		question=question2;
}
};

void Question::printInfo(){ //member function to print question
	cout<<"_______________________________________________________________________________________"<<endl<<"#"<<number<<"  "<<setw(6)<<difficulty<<"   "<<setw(6)<<chapter<<" "<<question<<endl;
}
	
	



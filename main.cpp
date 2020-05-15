#include <iostream>
#include <vector>
#include "Question.h"
#include "Options.h"
#include "CSVReader.h"
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <fstream>	

/*
<project firstname="Jayson" Lastname="Brown" projectname="Final Project" />
Purpose: This is a history trivia quiz. User has 3 attempts. The user is rewarded with points for answering correctly. The program keeps a record of each passing player and their score.
The user can add their own players and scores to the record as an extra feature.
*/

using namespace std;
	
int main(){
	cout<<"***************************************************************************************"; //main menu
	cout<<endl<<"Welcome to Jayson's History Trivia Quiz"<<endl<<"***************************************************************************************"; 
	cout<<endl<<"                MENU                  |"<<endl<<"---------------------------------------"<<endl;
    cout<<"Press 1 to start the quiz."<<endl<<"Press 2 to add to the records."<<endl<<"Press 3 to view the records."<<endl<<"Enter anything else to exit."<<endl;
    Options myObj;
	cin>>myObj.menuOption; //allows user to browse main menu
	if(myObj.menuOption==1){
		cin.ignore(); //ignores /n character in buffer
		system("CLS"); //clears screen
		myObj.OptionOne(); 
	}
	if(myObj.menuOption==2){ //accessing data member
		cin.ignore();
		system("CLS");
		myObj.OptionTwo(); //accessing member function
	}
	if(myObj.menuOption==3){ 
		cin.ignore();
		system("CLS");
		myObj.OptionThree(); 
	}else{
		exit(0);
	}
	system("pause");
	return 0;
}

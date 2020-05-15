#include <iostream>
#include <iomanip>
#include <algorithm> 
#include "CSVReader.h"
#include "Question.h"
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

class Options{
	private:
		
	public:
		int points; //starting by declaring variables so I can use them for any function
		int pointsadd;
		string choice1;
		string choice2;
		string choice3;
		string choice4;
		string choice5;
		string choice6;
		string choice7;
		string choice8;
		string choice9;
		string choice10;
		int attempts;
		string firstName;
		string lastName;
		string after;
		int menuOption; 
		void OptionOne();	//member function for beginning quiz
		void OptionTwo();	//member function for adding to past players
		void OptionThree(); //member function for showing past players 
		void Quiz(); //member function for quiz itself
		void Greeting(); //member function for saving user name in variable
		
	Options(){ //making each variable start at 0
	points=0;
	pointsadd=0;
	attempts=0;
	menuOption=0;	
}
};



void Options::Greeting(){ //member function for saving user name in variable
	cout<<"Please enter your first name: "<<endl;
		getline(cin,firstName);
		cout<<"Please enter your last name: "<<endl;	
		getline(cin,lastName);
		cout<<"Your name has been recorded successfully."<<endl;
	}

void Options::Quiz(){ //member function for quiz itself
	Greeting();
	system("CLS");
	points=0;
	cout<<"***************************************************************************************";   
	cout<<endl<<"Welcome to Jayson's History Trivia Quiz"<<endl<<"***************************************************************************************"; 
	cout<<endl<<"   Difficulty"<<"|"<<"  Chapter"<<"  |"<<"  Question"<<endl;
	cout<<endl<<"Answer each question and press enter after each entry."<<endl;
		vector<Question> vec_Questions;
	CSVReader tmp_csvReader ("questions.csv", ',');
		for(int i=0; i<tmp_csvReader.getRowsCount();i++){
			Question s = Question(
			tmp_csvReader.getCellAsInt(i,0), //gets numbers for each question
			tmp_csvReader.getCellAsString(i,1), //gets difficulty for each question
			tmp_csvReader.getCellAsInt(i,2), //gets chapter for each question
			tmp_csvReader.getCellAsString(i,3) //gets each question
			);
			vec_Questions.push_back(s); //stores info in vector
			}
		vec_Questions[0].printInfo(); //prints first line of vector 
		getline(cin,choice1);
		transform(choice1.begin(), choice1.end(), choice1.begin(), ::toupper); //changes inputted text to uppercase
		if(choice1 == "MAYFLOWER"){
			points += 300; //gives the user points
			cout<<"Correct! + 300 points."<<" Next is question #2..."<<"            Total: "<<points<<endl<<endl; //displays user's current points
		}else{
			cout<<"Incorrect. No points awarded. Next is question #2..."<<"     Total: "<<points<<endl<<endl;
			attempts += 1; //user gains 1 attempt
		}
			if(attempts==3){ //user fails if attempts reach 3
			cout<<endl<<"Please go study a bit more first."<<endl<<"Points: "<<points<<endl;
			system("pause");
			exit(0);	
		}
		vec_Questions[1].printInfo(); //same thing as above
		getline(cin,choice2);
		if(choice2 == "1914"){
			points += 200;
			cout<<"Correct! + 200 points. Next is question #3..."<<"            Total: "<<points<<endl<<endl;
		}else{
			cout<<"Incorrect. No points awarded. Next is question #3..."<<"     Total: "<<points<<endl<<endl;
			attempts += 1;
		}if(attempts==3){
			cout<<endl<<"Please go study a bit more first."<<endl<<"Points: "<<points<<endl;
			system("pause");
			exit(0);
		}
		vec_Questions[2].printInfo();
		getline(cin,choice3);
		if(choice3 == "1776"){
			points += 300;
			cout<<"Correct! + 300 points. Next is question #4..."<<"            Total: "<<points<<endl;
		}else{
			cout<<"Incorrect. No points awarded. Next is question #4..."<<"     Total: "<<points<<endl;
			attempts += 1;
		}if(attempts==3){
			cout<<endl<<"Please go study a bit more first."<<endl<<"Points: "<<points<<endl;
			system("pause");
			exit(0);
		}
		vec_Questions[3].printInfo();
		getline(cin,choice4);
		transform(choice4.begin(), choice4.end(), choice4.begin(), ::toupper);
		if(choice4 == "PLYMOUTH"){
			points += 100;
			cout<<"Correct! + 100 points. Next is question #5..."<<"            Total: "<<points<<endl;		
		}else{
			cout<<"Incorrect. No points awarded. Next is question #5..."<<"     Total: "<<points<<endl;
			attempts += 1;
		}if(attempts==3){
			cout<<endl<<"Please go study a bit more first."<<endl<<"Points: "<<points<<endl;
			system("pause");
			exit(0);
		}
		vec_Questions[4].printInfo();
		getline(cin,choice5);
		transform(choice5.begin(), choice5.end(), choice5.begin(), ::toupper);
		if(choice5 == "AUSTRIA"){
			points += 200;
			cout<<"Correct! + 200 points. Next is question #6..."<<"            Total: "<<points<<endl;		
		}else{
			cout<<"Incorrect. No points awarded. Next is question #6..."<<"     Total: "<<points<<endl;
			attempts += 1;
		}if(attempts==3){
			cout<<endl<<"Please go study a bit more first."<<"Points "<<points<<endl;
			system("pause");
			exit(0);
		}
		vec_Questions[5].printInfo();
		getline(cin,choice6);
		transform(choice6.begin(), choice6.end(), choice6.begin(), ::toupper);
		if(choice6 == "FRANCE"){
			points += 300;
			cout<<"Correct! + 300 points. Next is question #7..."<<"            Total: "<<points<<endl;		
		}else{
			cout<<"Incorrect. No points awarded. Next is question #7..."<<"     Total: "<<points<<endl;
			attempts += 1;
		}if(attempts==3){
			cout<<endl<<"Please go study a bit more first."<<endl<<"Points: "<<points<<endl;
			system("pause");
			exit(0);
		}
		vec_Questions[6].printInfo();
		getline(cin,choice7);
		if(choice7 == "1783"){
			points += 100;
			cout<<"Correct! + 100 points. Next is question #8..."<<"            Total: "<<points<<endl;
		}else{
			cout<<"Incorrect. No points awarded. Next is question #8..."<<"     Total: "<<points<<endl;
			attempts += 1;
		}if(attempts==3){
			cout<<endl<<"Please go study a bit more first."<<endl<<"Points: "<<points<<endl;
			system("pause");
			exit(0);
		}
		vec_Questions[7].printInfo();
		getline(cin,choice8);
		if(choice8 == "1492"){
			points += 200;
			cout<<"Correct! + 200 points. Next question is question #9..."<<"   Total: "<<points<<endl;	
		}else{
			cout<<"Incorrect. No points awarded. Next is question #9..."<<"     Total: "<<points<<endl;
			attempts += 1;
		}if(attempts==3){
			cout<<endl<<"Please go study a bit more first."<<endl<<"Points: "<<points<<endl;
			system("pause");
			exit(0);
		}	
		vec_Questions[8].printInfo();
		getline(cin,choice9);
		transform(choice9.begin(), choice9.end(), choice9.begin(), ::toupper);
		if(choice9 == "ENGLAND"){
			points += 300;
			cout<<"Correct! + 300 points. Next is question #10..."<<"           Total: "<<points<<endl;
		}else{
			cout<<"Incorrect. No points awarded. Next is question #10..."<<"     Total: "<<points<<endl;
			attempts += 1;
		}if(attempts==3){
			cout<<endl<<"Please go study a bit more first."<<endl<<"Points: "<<points<<endl;
			system("pause");
			exit(0);
		}
		vec_Questions[9].printInfo();
		getline(cin,choice10);
		transform(choice10.begin(), choice10.end(), choice10.begin(), ::toupper);
		if(choice10 == "13" || choice10 == "THIRTEEN"){
			points += 300;
			cout<<"Correct! + 300 points. End of quiz."<<"                      Total: "<<points<<endl;
		}else{
			cout<<"Incorrect. No points awarded. End of quiz."<<"         Total: "<<points<<endl;
			attempts += 1;
		}if(attempts==3){
			cout<<endl<<"Please go study a bit more first."<<endl<<"Points: "<<points<<endl;
			exit(0);
		}
		
		fstream fout; 
		fout.open("names.csv", ios::out | ios::app);
		int i;
		for (i = 0; i < 1; i++) {
		fout << firstName << " " << lastName << " " << points << endl; //writes user name and points to csv file
	}
		cout<<"Enter 'Next' to continue to Menu and display your final score. Enter anything else to exit the program. "; 
		cout<<"Enter: ";
		getline(cin,after);
		transform(after.begin(), after.end(), after.begin(), ::toupper);
		if(after == "NEXT"){
		cout<<endl<<firstName<<" "<<lastName<<" earned "<<points<<" points!"<<endl<<"Thanks for playing!"<<endl; //displays user name and score 
		cout<<"***************************************************************************************"; //menu
		cout<<endl<<"Welcome to Jayson's History Trivia Quiz"<<endl<<"***************************************************************************************"; 
		cout<<endl<<"                MENU                  |"<<endl<<"---------------------------------------"<<endl;
        cout<<"Press 1 to start the quiz again."<<endl<<"Press 2 to add to the records again."<<endl<<"Press 3 to view the records."<<endl<<"Enter anything else to exit.";
		cin>>menuOption;
		if(menuOption==1){ //lets user start quiz again
			cin.ignore(); //ignores /n character in buffer
			system("CLS");
			OptionOne(); //allows the user to begin the quiz
		}
		if(menuOption==2){ //lets user add a new record after game
		cin.ignore();
		system("CLS");
		OptionTwo();
	}
		if(menuOption==3){ 
		cin.ignore();
		system("CLS");
		OptionThree();
		}else{
			exit(0);
		}			
}
}

void Options::OptionOne(){ //function for when user selects 1	
		Quiz(); //begins quiz
}


void Options::OptionTwo(){ //fuction for when user selects 2
	if(menuOption==2){ 
		fstream fout; 
		fout.open("names.csv", ios::out | ios::app);
		int i;
		cout<<"Please enter your first name: "<<endl;
		getline(cin,firstName);
		cout<<"Please enter your last name: "<<endl;
		getline(cin,lastName);	
		cout<<"Please enter your points: "<<endl;
		cin>>pointsadd;
		for (i = 0; i < 1; i++) {
		fout << firstName << " " << lastName << " " << pointsadd << endl; //writes username and points to csv file
		cout<<"Your information has been recorded successfully."<<endl;
}
	cout<<"***************************************************************************************"; //menu
	cout<<endl<<"Welcome to Jayson's History Trivia Quiz"<<endl<<"***************************************************************************************"; 
	cout<<endl<<"                MENU                  |"<<endl<<"---------------------------------------"<<endl;
    cout<<"Press 1 to start the quiz."<<endl<<"Press 2 to add to the records again."<<endl<<"Press 3 to view the records."<<endl<<"Enter anything else to exit.";
		cin>>menuOption;
		}
		if(menuOption==1){ 
			cin.ignore(); //ignores /n character in buffer
			system("CLS");
			OptionOne(); //allows the user to begin the quiz
		}
		if(menuOption==2){ //lets user add a new record
		cin.ignore();
		system("CLS");
		OptionTwo();
		}if(menuOption==3){ //lets user view record again
		cin.ignore();
		system("CLS");
		OptionThree();
	}else{
		exit(0);
	}
}

void Options::OptionThree(){ //function for when user selects 3
	if(menuOption==3){
  	ifstream f("names.csv");
  	string line;
  	cout<<"Past players:"<<endl<<"------------------"<<endl;
  while(getline(f, line))
    cout << line << endl; //shows record
    cout<<"***************************************************************************************"; //menu
	cout<<endl<<"Welcome to Jayson's History Trivia Quiz"<<endl<<"***************************************************************************************"; 
	cout<<endl<<"                MENU                  |"<<endl<<"---------------------------------------"<<endl;
    cout<<"Press 1 to start the quiz."<<endl<<"Press 2 to add to the records."<<endl<<"Press 3 to view the records again."<<endl<<"Enter anything else to exit."<<endl;
		cin>>menuOption;
	}	
		if(menuOption==1){ //lets user start quiz again
		cin.ignore();
		system("CLS");	
		OptionOne();
	}
	if(menuOption==2){ //lets user add a new record
		cin.ignore();
		system("CLS");
		OptionTwo();
	}
	if(menuOption==3){ //lets user view record again
		cin.ignore();
		system("CLS");
		OptionThree();
	}else{
		exit(0);
	}
}

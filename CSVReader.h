///////////////////////////////////////////////////////////////////////////////////
//Name: Dr. Sunmonu
//Date: 3/1/2019, improved slightly 2/13/2020
//PLEASE DO NOT CHANGE ANYTHING IN THIS FILE, UNLESS YOU KNOW WHAT YOU ARE DOING!!/
///////////////////////////////////////////////////////////////////////////////////
#ifndef CSVREADER_H
#define CSVREADER_H


#include <iostream>
#include <fstream> //for reading from file
#include <sstream> //used to store lines from file and tokenize a line read
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;


// trim from left. This is not part of the class, just a utility function
inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from right. This is not part of the class, just a utility function
inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from left & right. This is not part of the class, just a utility function
inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
{
    return ltrim(rtrim(s, t), t);
}

////Split a given string using given delimiter. This is not part of the class, just a utility function
vector<string> split( string s, const char del) 
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (std::getline(tokenStream, token, del))
   {
      if(trim(token) != "") tokens.push_back(trim(token));
   }
   return tokens;
};

class CSVReader
{
	public:
		CSVReader(string filepath,char del=',');
		vector<string> getRow(int row) const;//returns a row of the CSV
		string getCellAsString(int row, int col) const;//returns element at row, col
		char getCellAsChar(int row, int col) const;//returns element at row, col as char
		int getCellAsInt(int row, int col) const;//returns element at row, col as int
		vector<int> getCellAsIntVector(int row, int col,char del) const;//returns element at row, col as vector<int>
		vector<double> getCellAsDoubleVector(int row, int col,char del) const;//returns element at row, col as vector<double>
		vector<string> getCellAsStringVector(int row, int col,char del) const;//returns element at row, col as vector<string>
		double getCellAsDouble(int row, int col) const;//returns element at row, col as double
		int getRowsCount() const{ return Rows.size();}; //returns how many rows were read in
		int getColsCount() const{ return ColsLength;};//returns how many cols in the csv
		void printRow(int row) const;//prints the content of a given row
		
	private:
		vector<string>Rows;//contains the rows of data in the csv
		char del;//delimiter used to separate csv	
		int ColsLength;//number of columns	
};


//implementation of the functions
CSVReader::CSVReader(string filepath,char del)
	{
		ColsLength=0;
		this->del=del;
		//declare the file
	    ifstream csvfile;
	    csvfile.open(filepath.c_str());
	    if(csvfile.good())
	    {
	    	string line;
	    	cout<<line.c_str()<<endl;
		    while ( getline(csvfile, line) ){
		        if (line.find(del) != std::string::npos && !line.empty()) //make sure the delimiter is in the line we are reading
				 {
				     Rows.push_back(trim(line));
		           //set the number of columns if necessary
		           if(ColsLength==0)
		              ColsLength = (split(line,del)).size();
			    }
		      }//end of while
	    }
	    else cout<<"\nCSVReader ERROR--> I had trouble opening the file["<<filepath<<"]\n";
	    
	    csvfile.close();
	};


///get an entire row as vector
vector<string> CSVReader::getRow(int row) const
	{		
		if(row>=0 && row<Rows.size())	
		{
			return split(Rows[row],del);
		}
	//return empty list		
	vector<string> v;			
		return v; 
	};

///get content in location (row, col)
string CSVReader::getCellAsString(int row, int col) const
	{		
	vector<string> v = getRow(row);			
		return v[col];
	};

///get content in location (row, col) as char
char CSVReader::getCellAsChar(int row, int col) const
	{		
	vector<string> v = getRow(row);			
		return v[col][0]; //only interested in the first character 
	};

///get content in location (row, col) as int
int CSVReader::getCellAsInt(int row, int col) const
	{		
	vector<string> v = getRow(row);	
	string s = 	v[col];
		return atoi(s.c_str()); 
	};
	
///get content in location (row, col) as double
double CSVReader::getCellAsDouble(int row, int col) const
	{		
	vector<string> v = getRow(row);	
	string s = 	v[col];		
		return atof(s.c_str()); 
	};

///get content in location (row, col) as vector<int>
vector<int> CSVReader::getCellAsIntVector(int row, int col,char del) const
	{
	  vector<string> v = getRow(row);
	  //split the col using del
	  vector<string> cols =split(v[col],del);
	  vector<int> res;
	  for(int i=0;i<cols.size();i++)
	   {
         string s = cols[i];
		 res.push_back(atoi(s.c_str()));
	   }    
		return res;
	};

///get content in location (row, col) as vector<double>
vector<double> CSVReader::getCellAsDoubleVector(int row, int col,char del) const
	{
	  vector<string> v = getRow(row);
	  //split the col using del
	  vector<string> cols =split(v[col],del);
	  vector<double> res;
	  for(int i=0;i<cols.size();i++)
	   {
         string s = cols[i];
		 res.push_back(atof(s.c_str()));
	   }    
		return res;
	};

///get content in location (row, col) as vector<string>
vector<string> CSVReader::getCellAsStringVector(int row, int col,char del) const
	{
	  vector<string> v = getRow(row);
	  //split the col using del
	  vector<string> cols =split(v[col],del);
		return cols;
	};
		
/// print content of a given row
void CSVReader::printRow(int row) const
{
	 vector<string> vrow= getRow(row);
	 cout<<"["<<row<<"] ";
	 for(int j=0;j<ColsLength;j++)
	  {
	  cout<<vrow[j];
	  if(j<ColsLength-1)cout<<",";
	  }
	  cout<<endl;	
};

#endif

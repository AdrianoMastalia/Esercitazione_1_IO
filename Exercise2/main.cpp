#include<iostream>
#include<fstream>
#include<iomanip>
#include "map_point.hpp"
using namespace std;

int main()
{
	ifstream filein("data.txt");
	if (filein.fail())
	{
		cout<<"Errore nell'apertura del file di input"<<endl;
		return 1;
	}
	double val; /* Variable where to put the lines of the file */
	double mean; 
	double sum = 0;
	int i = 1;
	ofstream fileout("output.txt");
	if(fileout.fail())
	{
		cout<<"Errore nell'apertura del file di output"<<endl;
	}
	fileout<<"# N mean"<<"\n";
	while(filein>>val){
		sum += map_point(val); /* Updating the sum with the values mapped in [-1,2] */
		fileout<<scientific<<setprecision(16)<<sum/i<<"\n";
		i++;
	}
	fileout.close();
    return 0;
}

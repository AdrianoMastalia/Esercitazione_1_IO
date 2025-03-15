#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
double map_point(double x)
{
	return 0.75*x-1.75; /* this is the homeomorphism that maps [1,5] into [-1,2] */
}
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
		mean = sum/i; /* Calculation of the mean */
		i++;
		fileout<<scientific<<setprecision(16)<<mean<<"\n";
	}
	fileout.close();
    return 0;
}

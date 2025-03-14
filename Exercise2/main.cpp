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
	int N = 0;/* Number of rows in the file */
	while(filein>>val) /*Calculation of the number of rows in the file */
		N++;
	ofstream fileout("output.txt");
	if(fileout.fail())
	{
		cout<<"Errore nell'apertura del file di output"<<endl;
	}
	double values[N];
	fileout<<"# N mean"<<"\n";
	filein.clear();
	filein.seekg(0); /* restarting from the first row of the file */
	int i = 0;
	while(filein>>val){ /*memorizing all the values of the file inside an array , so 
						I don't have to access the file at every iteration*/
		values[i] = val;
		i++;
	}
	for(int i =1; i<N+1;i++){ /*index i counts the number of numbers */
		double sum = 0;
		for(int j = 0; j<i; j++){ /*j is used to sum the first i numbers in the array*/
			sum += map_point(values[j]);
		}
		mean = sum/(i);
		fileout<<scientific<<setprecision(16)<<mean<<endl;
	}
	fileout.close();
    return 0;
}

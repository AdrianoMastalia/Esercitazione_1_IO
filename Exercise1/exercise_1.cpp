#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
int main(void){
	cout<<"Inserire il valore N fino al quale si vogliono sommare numeri";
	int N;
	cin >> N;
	std::string filename = "data.txt";
	std::ifstream ifs(filename);
	numbers_in_file = 0;
	if(ifs.isopen()){
		while(!ifs.isopen()){
		++numbers_in_file;
		}
	}
	cout<<numbers_in_file<<endl;
}
#include<iostream>
#include<fstream>
using namespace std;
int sum_of_squares(int N){
	int sum;
	sum = (N*(N+1)*(2*N+1)/6);
	return sum;
}
int main(void){
	std::ifstream infile("data.txt");
	if(infile.fail()){
		std::cerr<<"Errore nell'apertura del file"<<std::endl;
	}
	std::string header;
	std::getline(infile,header);
	int sum = 0;
	int val;
	int N;
	int count = 0;
	std::cout<<"Inserisci il numero fino al quale vuoi fare la somma"<<std::endl;
	std::cin >> N;
	count = 0;
	while(infile>>val)
		if(count<N){
			sum = sum + val*val;
			count++;
		}
		else
			break;
	std::cout<<sum<<std::endl;
	int exact_value = sum_of_squares(N);
	std::cout<<exact_value<<std::endl;
	return 0;
}
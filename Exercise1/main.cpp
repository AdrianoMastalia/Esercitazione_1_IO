#include<iostream>
#include<fstream>

unsigned int sum_of_squares(const unsigned int &N){ 
/*cosi è una chiamata per referenza, migliore in termini di memoria*/
	int sum;
	sum = (N*(N+1)*(2*N+1)/6.0);
	return sum;
}
int main(void){
	std::ifstream infile("data.txt");
	if(infile.fail())
	{
		std::cerr<<"Errore nell'apertura del file"<<std::endl;
		return 1;
	}
	std::string header;
	std::getline(infile,header);
	int sum = 0;
	unsigned int val; /*così viene raddoppiato il numero di interi positivi che posso memorizzare */
	int count = 0;
	count = 0;
	while(infile>>val)
	{		/* se avessi usato getline, avrei avuto anche la stringa vuota */
		sum += val*val; /*non usare pow perché è più costoso*/
		count++;
	}
	std::cout << "La somma vale "<< sum << std::endl;
	int exact_value = sum_of_squares(count);
	std::cout << "L'output della funzione è " << exact_value << std::endl;
	return 0;
}
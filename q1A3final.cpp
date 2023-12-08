#include <iostream>
using namespace std;

int main() {
	string first, second;

	int added[21] = {0};

    
	int carry = 0;
	// Get the values
	cout << "Enter the first number:";
	cin  >> first;
	cout << "Enter the second number:";
	cin  >> second;	

	// Convert digits to ints
	int x[20] = {0}, y[20] = {0};


	for (int i=0 ; i<=(first.length()-1) ; i++){
		x[20-first.length()+i] = first[i] - '0';
	}

	for (int j=0 ; j<=(second.length()-1) ; j++){
		y[20-second.length()+j] = second[j] - '0';
	}


	// add arrays
	signed int counter = 20;
	do {
		if (counter == 0){
			added[counter] = carry;
			counter = counter - 1;
		}
		else{
			added[counter] = carry + ((x[counter-1]+y[counter-1])%10);
			carry = ((x[counter-1]+y[counter-1])/10);
			counter = counter-1;
		}
	}
	while(counter>=0);

	cout << "This result is: ";

	for (int l=0; l<=20; l++){
		if (added[l] != 0){
		cout << added[l];
		}
	}
	

	return 0;
}

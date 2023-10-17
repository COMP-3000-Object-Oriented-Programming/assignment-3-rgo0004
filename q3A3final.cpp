#include <iostream>
#include <iomanip>
using namespace std;

void readArray(int inpArr[50], int &last);
void sortInts(int inpArr[50], int &last);
void printResults(int inpArr[50], int &last);

int main(){

    int last = 1;
    int inpArr[50] = {0};
    readArray(inpArr, last);
    sortInts(inpArr, last);
    printResults(inpArr, last);

}

void readArray(int inpArr[50], int &last){

    int inp;
    cout << "Enter the number of integers to be sorted." << endl;
    cin >> last;

    for(int i=0; i<=last-1; i++){
        cout << "Enter number " << (i+1) << " out of " << last <<"." << endl;
        cin >> inp;
        inpArr[i] = inp;  
    }

}

void sortInts(int inpArr[50], int &last){

    int tempArr[50] = {0};

    for(int i=0; i<=last-1; i++){
        for(int j=0; j<=last-1; j++){
            if(inpArr[i] > tempArr[j]){
                for(int k=last-1; k>=j+1; k--){
                    tempArr[k] = tempArr[k-1];
                }
                tempArr[j] = inpArr[i];
                break;
            }
        }
    }

    for(int m=0; m<=last-1; m++){
        inpArr[m] = tempArr[m];
    }
}

void printResults(int inpArr[50], int &last){

    int unique[50][2] = {0};

    for(int i=0; i<=last-1; i++){
        for(int j=0; j<=last-1; j++){
            if(inpArr[i] == unique[j][1]){
                unique[j][2] = unique[j][2] + 1;
                break;
            }
            else if(inpArr[i] > unique[j][1]){
                unique[j][1] = inpArr[i], unique[j][2] = 1;
                break;
            }  
        }
    }
    
    cout << "The results are:" << endl;
    cout << "Number       Frequency " << endl << "----------   ----------" << endl;

    int numUnique = 0;
    for(int o=0; o<=last-1; o++){
        if(unique[o][2]>0)
        numUnique = numUnique + 1;
    }
    
    for(int k=0; k<=numUnique-1; k++){
        double r = log10(unique[k][1]) + 1;
        int digits = (int) r;
        cout << unique[k][1];
        for(int m=1; m<=10-digits; m++){
            cout << " ";
        }
        cout<< "   " << unique[k][2] << "         " << endl;
    }

}
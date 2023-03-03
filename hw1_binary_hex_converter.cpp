#include <iostream>

using namespace std;

int dec_num = -1; // initialize the input to -1 (not in the range 0 - 255)
string bin_num = ""; // var to store the answer of bin number
string hex_num = ""; // var to store the answer of hexa number

void decToBin(int n)
{
    // convert dec to bin
    
    int bin_num_rev[64]; // array to store binary number
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
        // storing remainder in binary array (reversed)
        bin_num_rev[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // printing binary array in correct order
    for (int j = i - 1; j >= 0; j--)
    {
        cout << bin_num_rev[j];
    }
    cout << "(2)" << endl;
}

void decToHex(int n)
{
    // function to convert decimal to hexadecimal
    
    while (n != 0) {
        
        int rem = 0; // remainder variable to store remainder  
        char ch; // ch variable to store each character

        rem = n % 16; // storing remainder in rem variable.
        // check if temp < 10
        if (rem < 10) {
            ch = rem + 48; // ASCII convertion for digits 0 - 10
        }
        else {
            ch = rem + 55; // ASCII convertion for digits A - F
        }  
        
        // update the ans string with the character variable
        hex_num += ch;
        n = n / 16;
    }

    // reverse the ans string to get the final result
    int i = 0, j = hex_num.size() - 1;
    while(i <= j)
    {
      swap(hex_num[i], hex_num[j]);
      i++;
      j--;
    }
    cout << hex_num << "(16)" << endl;
}


int main() {
    //Driver
    cout << "A small CLI tool helping convert a dec to bin and hex" << endl;
    cout << "Please input a decimal number (0 - 255): ";
    cin >> dec_num;
    cout << endl;
    decToBin(dec_num);
    decToHex(dec_num);
    getchar(); // pause so the user can monitor the result w/o crash

    return 0; // return code 0 to system and exit the program
}

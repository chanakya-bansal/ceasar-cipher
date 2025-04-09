#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>

using namespace std;

//character database
string letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                  'n','o','p','q','r','s','t','u','v','w','x','y','z',
                  ' ','.',',','!','%','?','&','1','2','3','4','5','6',
                  '7','8','9','0','A','B','C','D','E','F','G','H','I',
                  'J','K','L','M','N','O','P','Q','R','S','T','U','V',
                  'W','X','Y','Z'};
                  
string encrypt(string message,int key) {
   
    // using vector instead of list as it is dynamically resizeable
    vector<int> Nmessage;
    vector<int> Emessage;
    string Fmessage = "";

    // Convert each character to its corresponding index in the letters vector.
    for (char c : message) {
        // using the find algorithm to search throught the vector
        size_t pos = find(letters.begin(), letters.end(), c) - letters.begin();
        // appends the value at the end of the vector
        Nmessage.push_back(pos);
    }

    // Add the key to each number and storing it in another vector
    for (size_t i = 0; i < Nmessage.size(); i++) {
        Emessage.push_back(Nmessage[i] + key);
    }

    // Wrap around if the number exceeds the index of letters.
    for (size_t i = 0; i < Emessage.size(); i++) {
        if (Emessage[i] > letters.size()-1) {
            Emessage[i] -= letters.size();
        }
        // forming the encrypted message by convertting ascii into characters corresponding
        // to the database letters
        Fmessage += letters[Emessage[i]];
    }

    return Fmessage;
}

string decrypt(string message,int key) {
   
    vector<int> Nmessage;
    vector<int> Dmessage;
    string Fmessage = "";

    // Convert each character in the encrypted message to its index.
    for (char c : message) {
        size_t pos = find(letters.begin(), letters.end(), c) - letters.begin();
        Nmessage.push_back(pos);
    }

    // Subtract the key from each number resulting in "reversing of encryption" or 
    // decryption
    for (size_t i = 0; i < Nmessage.size(); i++) {
        Dmessage.push_back(Nmessage[i] - key);
    }

    // Handle negative indices by wrapping around.
    for (size_t i = 0; i < Dmessage.size(); i++) {
        if (Dmessage[i] < 0) {
            Dmessage[i] += letters.size();
        }
        Fmessage += letters[Dmessage[i]];
    }

    return Fmessage;
}

int main() {
   
    //taking the input output file name
    string name_in,name_out;
    cout<<"enter input file name : ";
    cin>>name_in;
    cout<<"enter output file name : ";
    cin>>name_out;

    // setting up file connections
    ifstream file_inp(name_in);  
    ofstream file_out(name_out);

    // throwing an error is the input txt file is not found
    if (!file_inp) {
        cout << "Error , file does not exist" << endl;
        return 1;
    }
    
    // asking the user what to do
    string state;
    cout << "Would you like to encrypt or decrypt? ";
    cin >> state;

    
    if (state == "encrypt") {

        // setting the seed for the random number generator to the current time
        srand(time(0));
        // setting the key between 1 and size of letters database
        int key = rand() % (letters.size()-2)+1;
        string raw;

        // getting the raw line from input file
        while (getline(file_inp, raw)) { 
           //encrypting it
           string encrypted=encrypt(raw,key);
           // adding the encrypted line to output file
           file_out << encrypted;
           // adding newline character after every line
           file_out<<"\n"; 
        }
        
        //giving the key to the user
        cout << "Key: " << key << endl;
        cout<<"file encrypted"<<endl;

    } else if (state == "decrypt") {
       
        //taking the key
        int key;
        cout<<"enter key :";
        cin>>key;

        string raw;
        while (getline(file_inp, raw)) { 
           // decrypting the line with the provided key 
           string decrypted=decrypt(raw,key);
           // adding the decrypted line to the output file
           file_out<<decrypted;
           // adding newline character after every line
           file_out<<"\n";
        }
        cout<<"file decrypted"<<endl;

    } else {
        // hadling invalid input
        cout << "Invalid input" << endl;
    }
    
    //closing the files
    file_inp.close();
    file_out.close();

     return 0;
}

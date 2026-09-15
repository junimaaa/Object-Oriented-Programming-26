#include<iostream>
#include<fstream>

/** added <vector>, <string>, <cstdlib>, <ctime>, and <random> for modern C++ random generation and other to dos */

#include <vector> 
#include <cstdlib>
#include <ctime> 
#include <random> 
#include <string>

using namespace std;

//------------------------PROTOTYPE-------------------------------------------
void promptFile(vector<string> &); 
void printVec(vector<string>);

/** added prototypes and put in bool for later declarations and const added as well for later declarations */

bool readFile(string filename, vector<string> & vec);
bool writeFile(string, const vector<string> &, const vector<string> &);
int ranGen(int size); 

/**to do for int questionSize and random generation using <random> so that it's not a fixed number */

int ranGen(int questionSize){
    random_device randomDevice;
    mt19937 generator(randomDevice());
    uniform_int_distribution<int> distribution(0, questionSize - 1);

    return distribution(generator);
}

/**
 * @brief reads contents of filename and populates into vec
 * 
 * @param filename :string 
 * @param vec: vector<string> & */

/**changed to bool to read as whether or not it succeeded */

bool readFile(string filename, vector<string> & vec) {

   ifstream inputFile(filename);

    //error handling
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file\n";
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    inputFile.close();
    return true;
}
/**
 * @brief writes to filename with the first column from v0, second column from v1
 * 
 * @param filename: string
 * @param v0: vector<string> (for students names)
 * @param v1: vector<string> (for questions)
 */

/**added const reference from the prototype and return bool as it's notified if succeeded or not */

bool writeFile(string filename, const vector<string> & v0, const vector<string> & v1){

    ofstream outputFile(filename);
     if (!outputFile) {
        cout << "Error: Could not create data.csv" << endl;
        return false;
    }

    if (v1.empty()) {
        cout << "Error: Question bank is empty" << endl;
        return false;
    }

    // write under the structure:
    // Student_Name, Question_#
    for(int i = 0; i < v0.size(); i++){
        outputFile << v0[i] << "," << v1[ranGen(v1.size())] << endl;
    }
    outputFile.close();
    return true;
}

/**return 1 added to make sure our results from the bool actually show up*/
int main()
{
    vector<string> roster;
    vector<string> qBank;

if (!readFile("2310_F26_Rosters.csv", roster)) {
    return 1;
}

if (!readFile("Questions.csv", qBank)) {
    return 1;
}

if (!writeFile("Student_question_bank.csv", roster, qBank)) {
    return 1;
}

cout << "Student_question_bank.csv created successfully!" << endl;
    // printVec(roster);
    // printVec(qBank);

    // cout << "Size of roster: " << roster.size() << endl; 
    // cout << "Size of qBank: " << qBank.size() << endl;
    return 0;
}

//------------------------DECLARATIONS-------------------------------------------
/**
 * @brief prompts the user to give a file to read
 * 
 */
void promptFile(vector<string> & v){
    cout << "file to read?\n";
    string myFile = "";
    cin >> myFile;
    readFile(myFile, v);
}

/**
 * @brief prints out the elements in v
 * 
 * @param v: vector<string>
 */
void printVec(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}
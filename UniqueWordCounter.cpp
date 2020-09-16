//Author: Jordan Tioe
#include <bits/stdc++.h>
#include <string>
#include <fstream>
using namespace std;
//This program can do the following:
//1. Read a file
//2. Remove punctuation in the file
//3. Output the frequency of each unique word
//4. Displays the total of unique words in the file.

//Structure to store the frequency and the word as a record
struct Record {
	int freq;
	string word;
};
const int var = 1000;
//Add one word to the array of the record
//For each unique word, the word is added to the next record
//If the word already exists, then the word frequency is incremented by 1
void addWord(string input, struct Record uword[var]) {
	int wordCount = 0;
	while (!uword[wordCount].word.empty()) {
		wordCount++;
	}
//	cout << "@addWord - Word Count: " << wordCount << endl;
	for (int i=0; i<=wordCount; i++) {
		if (uword[i].word.empty()) { //add word to array if the spot in array is empty
			uword[i].word = input;
			uword[i].freq = 1; //word frequency is set to 1
		}
		else {
			if (uword[i].word == input) { //if word in array equals next word being added
				uword[i].freq++; //increment frequency
				break;
			}
		}
	}
}

//Displays all the words that are added to the array, along with their frequencies for each word
//Total unique words is also displayed
void displayWordFreq(struct Record uword[var]) {
	int wordCount = 0;
	while (!uword[wordCount].word.empty()) {
		wordCount++;
	}
//	cout << "@displayWordFreq Total Word Count: " << wordCount << endl;
	cout << endl;
	cout.width(20); cout << left << "Word";
	cout.width(20); cout << right << "Frequency" << endl;
	for (int i=0; i<wordCount; i++) {
		cout.width(20); cout << left << uword[i].word;
		cout.width(20); cout << right << uword[i].freq << endl;
	}
	cout << "\nTotal unique words: " << wordCount << endl;
}

int main() {
	Record uword[var] = { 0 }; //initialize to 0, so internal function empty() can be used
	string sentence;
		
	ifstream inputFile("filename.txt"); //file
	while (getline(inputFile, sentence)) { //read all contents from file
		string inputWord;
		for (int i=0, len=sentence.size(); i<len; i++) { //remove all punctuation from file
			if (ispunct(sentence[i])) {
				sentence.erase(i--,1);
				len = sentence.size();
			}
		}
		stringstream getWord(sentence); //extracts all the words from the file
		while (getWord >> inputWord) {
			addWord(inputWord, uword);
		}
	}
	displayWordFreq(uword);
	inputFile.close(); //Close file
}

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>
using namespace std;

string convert(string word){
	string new_choice;
	for(char c: word){
		new_choice += tolower(c);
	}
	return new_choice;
}


string comp_choice(){
	random_device rd;
	mt19937 generator(rd());
	
	vector<string> options = {"rock", "paper", "scissors"};
	uniform_int_distribution<int> index(0, options.size()-1);
	int rand_ind = index(generator);
	
	string choice = options[rand_ind];
	
	return choice;
		
}

string my_choice(){
	string choice;
	cout << "Select:\nRock\nPaper\nScissors" << endl;
	cout << "Insert your choice: ";
	cin >> choice;
	choice = convert(choice);
	for(string c: {"rock", "paper", "scissors"}){
		if (c == choice){
			return choice;
		}
	}
	return my_choice();
}

string check_winner(string human, string ai){
	unordered_map<string, string> checks;
	checks["rock"] = "paper"; checks["scissors"] = "rock";
	checks["paper"] = "scissors";
	
	string win_ai = checks[human]; string win_h = checks[ai];
	if(ai == win_ai){
		return "Computer Wins...";
	}
	else if(human == win_h){
		return "Human Wins...";
	}
	else{
		return "Draw!";
	}
	
	
}
int main(){
	string ai_choice = comp_choice();
	string human_choice = convert(my_choice());	
	
	cout << "Computer's choice: " << ai_choice << endl;
	cout << check_winner(human_choice, ai_choice);
	 
	return 0;
}
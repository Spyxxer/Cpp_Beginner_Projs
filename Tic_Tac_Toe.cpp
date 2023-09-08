#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

unordered_map<int, char> Pos;




void draw_board(){
	/* 
		|	|	|	|
		| 	| 	| 	|
	   ===============
		|	|	|	|
		| 	| 	| 	|
	   ===============
		|	|	|	|
		| 	| 	| 	|

	*/
	cout<< endl;
	for(int i = 0; i < 3; i++){
		for(int j=0; j < 2; j++){
			for(int k=0; k < 4; k++){
				cout << "    |";
			}
			cout << endl;
		}
		int m = 0;
		cout << "    |";
		for (int f=0; f < 3; f++){
			f == 0 ? cout<< "  " << board[i][f] <<" |" : cout << " " << board[i][f] << "  |";
		}

		cout<<endl;
		if (i != 2){
			cout << "==========================" << endl;
		}
	}

}
bool check_space(){
	for(auto p: Pos){
		if(p.second == ' '){
			return true;
		}
	}
	return false;
}

string instrct(){
	return "The Number in the Board Represents the Position To Play\nPress the number in the Terminal to play in that Postion";
}

void play(char letter){
	int p;
	cout << endl;
	cout<<"Enter the position you want to play in: ";
	cin >> p;
	cout << "You chose postion: "<<p << endl;
	if(Pos[p] != ' '){
		cout << "\nPosition is already occupied, Choose another spot!" << endl;
		play(letter);
	}
	else{
		if(p >= 1 && p <= 3){
			board[0][p-1] = (Pos[p] == ' ') ? letter : board[0][p-1]; 
		}
		else if(p >= 4 && p <= 6){
			board[1][(p-1)-3] = (Pos[p] == ' ') ? letter : board[1][(p-1)-3];
		}
		else if(p >= 7 && p <= 9){
			board[2][(p-1)-6] = (Pos[p] == ' ') ? letter : board[2][(p-1)-6];
		}
		else{
			cout<< "Invalid Letter" << endl;
			play(letter);
		}
		Pos[p] = letter;
	}
}

template <typename StringBool>
StringBool check_winner(){
	/*
		1 2 3, 4 5 6, 7 8 9, 1 4 7, 2 5 8, 3 6 9, 1 5 9, 3 5 7

	*/
	int win_pos[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {3, 6, 9}, 
	{1, 4, 7}, {2, 5, 8}, {1, 5, 9}, {3, 5, 7}};

	string winA = "XXX"; string winB = "OOO"; string win = "";
	for(int i=0; i < 8; i++){
		for(int j=0; j < 3; j++){
			int p = win_pos[i][j];  win += Pos[p];
		}
		if(win == winA){
			return "\nPlayer X emerges as Winner\n";
		}
		else if(win == winB){
			return "\nPlayer O emerges as Winner\n"; 
		}
		else{
			win = "";
		}
	}
	return StringBool();
}

int main(){
	for(int i = 1; i <= 9; i++){
		Pos.insert(make_pair(i, ' '));
	}
	cout <<"Welcome To The Game Of Tic_Tac_Toe" << endl;
	int turn = 0;
	char letter;
	
	while(check_space()){
		cout<< instrct() << endl;
		draw_board();
		letter = (turn % 2) == 0 ? 'X' : 'O';
		cout<< endl;
		cout << "It is " << letter << "'s turn" << endl; 
		play(letter);
		if(check_winner<bool>() != false){
			break;
		}
		cout << endl;
		turn++;
	}
	draw_board();
	//Check for winner....
	check_winner<bool>() == false ? cout << "\nGame Ended in a Draw!\n" : cout << "\n" << check_winner<string>() << endl;


	return 0;
}
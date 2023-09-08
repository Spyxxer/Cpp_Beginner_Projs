#include <iostream>
using namespace std;
#include <unordered_map>
#include <string>
#include <cmath>



int main(){
	string course_code;
	int unit;
	char grade;
	
	
	unordered_map<char, int> Grades;
	char grades[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	for(int i=5; i >= 0; i--){
		Grades[grades[i]] = abs(i-5);

	}
	
	float tcp = 0, tnu = 0;
	float gpa = 0;
	 
	int no_of_course;
	string entities [no_of_course][3];
	cout << "Insert number of course: ";
	cin >> no_of_course;
	
	for(int i=0; i < no_of_course; i++){
	
		cout<<"What is the course code: ";
		cin>> course_code;
	
		cout<<"What is the unit of the course: ";
		cin>> unit;
	
		cout<<"Insert Grade: ";
		cin>> grade;
		entities[i][0] = course_code; 
		entities[i][1] = to_string(unit);
		entities[i][2] = to_string(grade);
		tnu += unit; tcp += Grades[grade] * unit;
		
	}
	cout << endl;
	
	gpa = tcp / tnu;
	cout << "Total number of units: "<< tnu << endl;
	cout << "Total number of cumulative points: " << tcp << endl;
	cout << "Grade Point Average: " << gpa; 
	return 0;
}
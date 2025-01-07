#include<bits/stdc++.h>
using namespace std;

struct Student{
	string id;
	string name;
	int birthYear;
	float grade;
};

void init(vector<Student>& students){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		Student student;
		cout << "Nhap thong tin sinh vien thu " << i+1 << ":\n";
		cout << "Ma sinh vien: ";
		cin >> student.id;
		
		cin.ignore();
		cout << "Ho va ten: ";
		getline(cin, student.name);
		
		cout << "Nam sinh: ";
		cin >> student.birthYear;
		cout << "Diem tong ket: ";
		cin >> student.grade;
		
		students.push_back(student);
	}
}

void display(vector<Student>& students){
	cout << "Danh sach hoc sinh la: \n";
	for( auto student : students){
		cout << student.id << " - " << student.name << " - " << student.birthYear << " - " << student.grade << endl;
	}
}

//ham tim kiem theo ten den chua tu khoa
void findByMiddleName(vector<Student>& students, string middleName){
	bool kq = false;
	cout << "Danh sach sinh vien co ten dem " << middleName << "\n";
	for(auto student : students){
		//neu tim thay
		if(student.name.find(middleName) != string::npos){
			cout << student.id << " - " << student.name << " - " << student.birthYear << " - " << student.grade << "\n";
			kq = true;
		}
	}
	if(!kq){
		cout << "Khong tim thay sinh vien nao co ten dem " << middleName << "\n";
	}
}

bool compareGrade(Student& a, Student& b){
	return a.grade > b.grade; //diem cao hon dung truoc
}

//sap xep theo diem giam dan
void sortStudents(vector<Student>& students){
	sort(students.begin(), students.end(), compareGrade);
}

//hien thi sinh vien xep hang 2 theo diem tong ket
void displaySecondRank(vector<Student>& students){
	if(students.size() < 2){
		cout << "Danh sach sinh vien qua it de xep hang \n";
		return;
	}
	float secondRank = students[1].grade;
	cout << "Danh sach sinh vien xep hang 2 la: \n";
	for(auto student : students){
		if(student.grade == secondRank){
			cout << student.id << " - " << student.name << " - " << student.birthYear << " - " << student.grade << "\n";
		}
	}
}

int main(){
	vector<Student> students;
	init(students);
	cout << "Danh sach sinh vien ban dau la: \n";
	display(students);
	
	string middleName;
	cout << "Nhap ten dem can tim: ";
	cin >> middleName;
	findByMiddleName(students, middleName);
	sortStudents(students);
	cout << "Danh sach sinh vien sau khi sap xep la: \n";
	display(students);
	displaySecondRank(students);
	return 0;
}

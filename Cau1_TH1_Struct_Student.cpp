#include<bits/stdc++.h>
using namespace std;

struct Student{
	string name;
	string firtName;
	int birthYear;
	string address;
};

void init(vector<Student>& students){
	Student st1 = {"Huong", "Le Thi Mai", 2004, "Nguyen xa"};
	Student st2 = {"Hang", "Nguyen Thi Thu", 2004, "ngo 34, nguyen xa"};
	Student st3 = {"Ninh", "Nguyen Thi My", 2003, "ngo 134, nguyen xa"};
	Student st4 = {"Trang", "Dang Thu", 2004, "ngo 134, nguyen xa"};
	Student st5 = {"Phuong", "Luong Thi", 2004, "ngo 134, nguyen xa"};
	students.push_back(st1);
	students.push_back(st2);
	students.push_back(st3);
	students.push_back(st4);
	students.push_back(st5);
}

void display(vector<Student>& students){
	cout << "---------Danh sach sinh vien la-----------\n";
	for(auto s : students){
		cout << s.firtName << " " << s.name << " - " << s.birthYear << " - " << s.address << "\n";
	}
}

void merge(vector<Student>& students, int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	vector<Student> leftStudents(n1), rightStudents(n2);
	for(int i = 0; i < n1; i++ ){
		leftStudents[i] = students[left + i];
	}
	for(int i = 0; i < n2; i++ ){
		rightStudents[i] = students[mid + i + 1];
	}
	
	int i = 0, j = 0, k = left;
	while(i < n1 && j < n2){
		if(leftStudents[i].name <= rightStudents[j].name){
			students[k] = leftStudents[i];
			i++;
		}else{
			students[k] = rightStudents[j];
			j++;
		}
		k++;
	}
	
	while( i < n1){
		students[k] = leftStudents[i];
		i++;
		k++;
	}
	
	while(j < n2){
		students[k] = rightStudents[j];
		j++;
		k++;
	}
}

void mergeSort(vector<Student>& students, int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		
		mergeSort(students, left, mid);
		mergeSort(students, mid + 1, right);
		
		merge(students, left, mid, right);
	}
}

void sortByName(vector<Student>& students){
	mergeSort(students, 0, students.size() - 1);
	cout << "--------Danh sach sinh vien sau khi sap xep la--------\n";
	display(students);
}

void binarySearch(vector<Student>& students, int left, int right, string name){
	if(left <= right){
		int mid = (left + right) / 2;
		if(students[mid].name == name){
			cout << "Hoc sinh co ten la "<< name << " o vi tri " << mid + 1 << "\n";
			cout << "Thong tin hoc sinh: \n";
			cout << students[mid].firtName << " " << students[mid].name << " - " << students[mid].birthYear << " - " << students[mid].address << "\n";
		}else{
			if(students[mid].name < name) {
				binarySearch(students, mid+1, right, name);
			}else{
				binarySearch(students, left, mid-1, name);
			}
		}
	}else{
		cout << "Khong tim thay hoc sinh nao ten la " << name << " trong danh sach. \n";
	}
}

int main(){
	vector<Student> students;
	init(students);
	display(students);
	sortByName(students);
	binarySearch(students, 0, students.size() - 1, "Trang");
	return 0;
}

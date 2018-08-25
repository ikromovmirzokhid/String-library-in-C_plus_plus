#include <iostream>
#include<fstream>
#include <string>
using namespace std;
class Marks
{
	protected:
	float calculus2, physics2, AE2, CED, OOP2;
	public:
	void setMarks()
	{
		cout<<"Enter your marks from (calculus2, physics2, AE2, CED, OOP2)"<<endl;
		cout<<"Calculus2 ";
		cin>>calculus2;
		cout<<"Physics2 ";
		cin>>physics2;
		cout<<"AE2 ";
		cin>>AE2;
		cout<<"Creative Engineering Design ";
		cin>>CED;
		cout<<"Object Oriented Programming ";
		cin>>OOP2;
	} 
	void showMarks()
	{
		
		cout<<"Physics2: "<<physics2<<endl;
		cout<<"Calculus2: "<<calculus2<<endl;
		cout<<"Creative Engineering Design: "<<CED<<endl;
		cout<<"Object Oriented Programming2: "<<OOP2<<endl;
		cout<<"AE2: "<<AE2<<endl<<endl;
	}
};
class Student: public Marks
{
private:
	string name, surname, id, group, bdate;
public:
	friend void operator >>(istream&in, Student &st);
	void showInfo()
	{
		cout <<name << " " << surname<< " " << id << endl;
	}
	string checkByName()
	{
		return this->name;
	}
	void showFullInfo()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Surname: "<<surname<<endl;
		cout<<"Birth of date: "<<bdate<<endl;
		cout<<"ID: "<<id<<endl;
		cout<<"Group: "<<group<<endl;
	}
	void showMarks()
	{
		cout<<name<<"'s all Marks"<<endl;
		Marks::showMarks();
	}
	string checkById()
	{
		return this->id;
	}
};
	Student student;
class Socie
{
public:
	static void showStudentsInfo()
	{

		ifstream fin;
		fin.open("students.dat",ios::binary);
		cout<<"List of Students of SOCIE faculty"<<endl;
		while (fin.read((char*)&student,sizeof(student)))
		{
			cout<<"* ";
			student.showInfo();
		}
		fin.close();
	}
};
void operator>>(istream&in, Student &st)
{
	ofstream fout;
	fout.open("Students.txt", ios::app);
	cout << "Enter your name ";
	in >> st.name;
	fout << "Name: ";
	fout<< st.name << endl;
	cout << "Enter your Surname ";
	in >> st.surname;
	fout << "Surname: ";
	fout << st.surname << endl;
	cout << "Enter your date of birth ";
	in >> st.bdate;
	fout << "Date of Birth: "; 
	fout<< st.bdate << endl;
	cout << "Enter your ID ";
	in >> st.id;
	fout << "ID: ";
	fout << st.id << endl;
	cout << "Enter your group ";
	in >> st.group;
	fout << "Group: ";
	fout << st.group << endl;
	fout << endl;
	fout.close();
}
int main()
{
	fstream file;
	bool want=true;
	char choose;
	file.open("students.dat",ios::binary|ios::app|ios::out);
	cin >> student;
	cout<<endl;
	student.setMarks();
	file.write((char*)&student,sizeof(student));
	while(want)
		{
		cout<<"Do you want to enter new one? ('y'/'n') ";
		cin>>choose;
		switch(choose)
		{
			case 'y':
			want=true;
			cin >> student;
			student.setMarks();
			file.write((char*)&student,sizeof(student));
			break;
			case 'n':
			want=false;
			break;
		}
	}
	file.close();
	start:
	cout<<endl;
	cout<<"What operation do you want to use? "<<endl;
	cout<<"[1] List of all students of SOCIE"<<endl;
	cout<<"[2] Find student by his/her name"<<endl;
	cout<<"[3] Find student by his/her ID"<<endl;
	cout<<"[4] Stop program"<<endl;
	int tasktype;
	cin>>tasktype;
	if(tasktype==1)
	{
	Socie::showStudentsInfo();
	goto start;
	}
	else if(tasktype==2)
	{
		cout<<"Enter student's name in order to check whether exists in Student's data base"<<endl;
		string name;
		cin>>name;
		file.open("students.dat",ios::binary|ios::in);
		while(file.read((char*)&student,sizeof(student)))
		{
			if(student.checkByName()==name)
			{
				
				cout<<"This Name exists!"<<endl;
				information:
				cout<<"[1] Student Information: "<<endl;
				cout<<"[2] Student marks: "<<endl;
				cout<<"[3] Back "<<endl;
				cin>>tasktype;
				if(tasktype==1)
				{
					student.showFullInfo();
				}
				else if(tasktype==2)
				{
					student.showMarks();
				}
				else if(tasktype==3)
				{
				file.close();
				goto start;
				}
				goto information;
			}
		}
			cout<<"This Name does not Exist"<<endl;
			cout<<"Do you want to register this Student (y/n) "<<endl;
			cin>>choose;
			switch(choose)
			{
				case 'y':
				file.close();
				file.open("students.dat",ios::binary|ios::app|ios::out);
				cin >> student;
				student.setMarks();
				file.write((char*)&student,sizeof(student));
				file.close();
				cout<<endl<<"Saved Successfully!"<<endl;
				goto start;
				break;
				case 'n':
				goto start;
				break;
			}
	}
	else if(tasktype==3)
	{
		cout<<"Enter student's id in order to check whether exists in Student's data base"<<endl;
		string id;
		cin>>id;
		file.open("students.dat",ios::binary|ios::in);
		while(file.read((char*)&student,sizeof(student)))
		{
			if(student.checkById()==id)
			{
				
				cout<<"This ID exists!"<<endl;
				information1:
				cout<<"[1] Student Information: "<<endl;
				cout<<"[2] Student marks: "<<endl;
				cout<<"[3] Back "<<endl;
				cin>>tasktype;
				if(tasktype==1)
				{
					student.showFullInfo();
				}
				else if(tasktype==2)
				{
					student.showMarks();
				}
				else if(tasktype==3)
				{
				file.close();
				goto start;
				}
				goto information1;
			}
		}
			cout<<"This ID does not Exist"<<endl;
			cout<<"Do you want to register this Student (y/n) "<<endl;
			cin>>choose;
			switch(choose)
			{
				case 'y':
				file.close();
				file.open("students.dat",ios::binary|ios::app|ios::out);
				cin >> student;
				student.setMarks();
				file.write((char*)&student,sizeof(student));
				file.close();
				cout<<endl<<"Saved Successfully!"<<endl;
				goto start;
				break;
				case 'n':
				goto start;
				break;
			}
	}
	else 
	return 0;

	return 0;
}

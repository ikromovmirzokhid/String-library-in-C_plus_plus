#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
int main()
{
	String1 *str;
	String str1;
	int tasktype;
	cout<<"Enter a string: ";
	cin>>str1;
	str=&str1;
	cout<<"Be careful, your every action will be logged!!!"<<endl;
start:
	cout<<"String: ";
	cout<<str1;
	cout<<endl;
	cout<<"[1] Length finding"<<endl;
	cout<<"[2] Concatenation"<<endl;
	cout<<"[3] Erasing string"<<endl;
	cout<<"[4] String replace"<<endl;
	cout<<"[5] Check whether the string ends with given string"<<endl;
	cout<<"[6] Check whether the string starts with given string"<<endl;
	cout<<"[7] Check whether the string equals to given string"<<endl;
	cout<<"[8] To Uppercase"<<endl;
	cout<<"[9] To Lowercase"<<endl;
	cout<<"[10] Find string from file"<<endl;
	cout<<"[11] Exit from program"<<endl;
	cout<<endl;
	cout<<"Enter String Operation: ";
	cin>>tasktype;
	cout<<endl;
	if (tasktype==1){
		cout<<"Length:"<<str->length()<<endl<<endl;
		goto start;
		}
	if (tasktype==2){
			
		cout<<"[1] Attach chars to the end (String, function overloading)"<<endl;
		cout<<"[2] Attach chars to the given position (String, function overloading)"<<endl;
		cout<<"[3] Attach string to the end (chars, operator overloading)"<<endl;
		cout<<"[4] Entered string + chars (operator overloading)"<<endl;
		cout<<"[5] Chars + Entered string (operator overloading)"<<endl;
		cout<<"Enter Concatenation Operation: ";
		cin>>tasktype;
		if (tasktype==1){
			char chars[100];
			cout<<"Enter chars: ";
			cin>>chars;
			str->concat(chars);
			cout<<"Concatenation result: ";
			cout<<str1;
			cout<<endl<<endl;
		}
		else if (tasktype==2){
			char chars[100];
			int pos;
			cout<<"Enter chars: ";
			cin>>chars;
			cout<<"Enter position < "<<str1.length()<<": ";
			cin>>pos;			
			str->concat(chars, pos);
			cout<<"Concatenation result: ";
			cout<<str1;
			cout<<endl<<endl;
			}
		else if (tasktype==3){
			String str2;
			cout<<"Enter a string: ";
			cin>>str2;
			str1=str1+str2;
			cout<<"Concatenation result: ";
			cout<<str1;
			cout<<endl<<endl;
		}
		else if (tasktype==4){
			char chars[100];
			cout<<"Enter chars: ";
			cin>>chars;
			str1=str1+chars;
			cout<<"Concatenation result: ";
			cout<<str1;
			cout<<endl<<endl;
		}
		else if (tasktype==5){
			char chars[100];
			cout<<"Enter chars: ";
			cin>>chars;
			str1=chars+str1;
			cout<<"Concatenation result: ";
			cout<<str1;
			cout<<endl<<endl;
		}
		goto start;
		}
	else if(tasktype==7)
	{
		cout<<"[1] Checks whether string equals to given String(String, function overloading)"<<endl;
		cout<<"[2] Checks whether chars equals to given String(chars, function overloading"<<endl;
		cout<<"[3] Checks whether string equals to given String ignoring Capital letters"<<endl;
		cout<<"Enter Equils Operation: ";
		cin>>tasktype;
		cout<<endl;
		if (tasktype==1){
			String str2;
			cout<<"Enter a string: ";
			cin>>str2;
			cout<<"Is entered string equals to given string? ";
			cout<<str->equals(str2);;
			cout<<endl<<endl;
		}
		else if (tasktype==2){
			char chars[100];
			cout<<"Enter chars: ";
			cin>>chars;
			cout<<"Is entered chars equals to given string? ";
			cout<<str->equals(chars);;
			cout<<endl<<endl;
		}
		else if (tasktype==3){
			String str2;
			cout<<"Enter a string: ";
			cin>>str2;
			cout<<"Is entered string equals to given string(If consider A-Z to be the same as a-z)? ";
			cout<<str->equalsIgnoreUpperCase(str2);
			cout<<endl<<endl;
		}
		goto start;
	}
	else if (tasktype==8){
		str->toUpperCase();
		cout<<"String after changing to Uppercase:";
		cout<<str1;
		cout<<endl<<endl;
		goto start;
		}
	else if (tasktype==9){
		str->toLowerCase();
		cout<<"String after changing to Lowercase:";
		cout<<str1;
		cout<<endl<<endl;
		goto start;
		}
	else if (tasktype==10){
		// 1-usul
		cout<<"How many string elements you want to enter? ";
		int num;
		cin>>num;
		cout<<endl;
		String *str2;
		str2=new String[num];
		cout<<"Enter "<<num<<" string"<<endl;
		ofstream fout;
		fout.open("string.txt",ios::binary);
		for(int i=0; i<num; i++)
		{
			cin>>str2[i];
			fout.write((char*)&str2,sizeof(str2));
		}
		
		fout.close();
		cout<<"Enter string in order to check whether it exixts or not in file String.txt"<<endl;
		String str3;
		cin>>str3;
		ifstream fin;
		fin.open("string.dat",ios::binary|ios::app);
		int i=0;
		while(fin.read((char*)&str2,sizeof(str2)))
		{
			if(str2[i].equals(str3))
			{
			cout<<"It exists in file!"<<endl<<endl;
			fin.close();
			goto start;
			}
			i++;
		}
		cout<<"It does Not exist in file!"<<endl<<endl;
		fin.close();
		goto start;
		}
		
		/* 2-usul
		cout<<"How many string elements you want to enter? ";
		int num;
		cin>>num;
		cout<<endl;
		cout<<"Enter "<<num<<" string"<<endl;
		String str2[num];
		ofstream fout;
		fout.open("String.txt");
		fout<<str1;
		fout<<endl;
		for(int i=0; i<num; i++)
		{
			cin>>str2[i];
			fout<<str2[i];
			fout<<endl;
		}
		fout.close();
		cout<<"Enter string in order to check whether it exixts or not in file String.txt"<<endl;
		String str3;
		cin>>str3;
		ifstream fin;
		char f[100];
		fin.open("String.txt");
		while(fin.good()!=0)
		{
			fin>>f;
			if(str3.equals(f))
			{
			cout<<"It exists in file!"<<endl<<endl;
			fin.close();
			goto start;
			}
		}
		cout<<"It does Not exist in file!"<<endl<<endl;
		fin.close();
		goto start;*/
	else if (tasktype==11){
		cout<<"You exited from program :( Return back Soon!";
		return 0;
		}
	return 0;
}

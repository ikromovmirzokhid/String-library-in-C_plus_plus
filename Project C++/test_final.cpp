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
	cout<<"Be careful, your every last action will be logged!!!"<<endl;
	fstream out;
	out.open("log.dat", ios::binary | ios::out);
start:
	cout<<"String: ";
	cout<<str1;
	out.write((char*)&str1, sizeof(str1));
	cout<<endl;
	cout<<"[1] Length finding"<<endl;
	cout<<"[2] Concatenation"<<endl;
	cout<<"[3] Erasing string"<<endl;
	cout<<"[4] String replace"<<endl;
	cout<<"[5] Check whether the string starts with given chars"<<endl;
	cout<<"[6] Check whether the string ends with given chars"<<endl;
	cout<<"[7] Check whether the string equals to given chars"<<endl;
	cout<<"[8] To Uppercase"<<endl;
	cout<<"[9] To Lowercase"<<endl;
	cout<<"[10] Find string from file"<<endl;
	cout<<"[11] Read Log and Truncate Log File"<<endl;
	cout<<"[12] Save Log and Exit from program"<<endl;
	cout<<endl;
	cout<<"Enter String Operation: ";
	cin>>tasktype;
	cout<<endl;
	if (tasktype==1){
		cout<<"Length:"<<str->length()<<endl<<endl;
		goto start;
		}
	else if (tasktype==2){
			
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
	else if (tasktype==3){
		cout<<"[1] Erases given position from string (Integer, function overloading)"<<endl;
		cout<<"[2] Erases from starting position given number of chars from string (Integer, Integer, function overloading)"<<endl;
		cout<<"[3] Erases one occurence of char from string (char, function overloading)"<<endl;
		cout<<"[4] Erases all occurences of char from string (char)"<<endl;
		cout<<"Enter Concatenation Operation: ";
		cin>>tasktype;
		if (tasktype==1){
			int pos;
			cout<<"Enter position < "<<str1.length()<<": ";
			cin>>pos;
			str->erase(pos);			
			cout<<"Erase result: ";
			cout<<str1;
			cout<<endl<<endl;
		}
		else if (tasktype==2){
			int pos, numChars;
			cout<<"Enter starting position < "<<str1.length()<<": ";
			cin>>pos;
			cout<<"Enter numChars < "<<str1.length()-pos<<": ";
			cin>>numChars;
			str->erase(pos, numChars);			
			cout<<"Erase result: ";
			cout<<str1;
			cout<<endl<<endl;
		}
		else if (tasktype==3){
			char c;
			cout<<"Enter one character: ";
			cin>>c;
			str->erase(c);			
			cout<<"Erase result: ";
			cout<<str1;
			cout<<endl<<endl;
		}
		else if (tasktype==4){
			char c;
			cout<<"Enter one character: ";
			cin>>c;
			str->eraseAll(c);			
			cout<<"Erase result: ";
			cout<<str1;
			cout<<endl<<endl;
		}
		goto start;
	
	} 
	else if (tasktype==4){
		cout<<"[1] Replaces the first occurence of char with another char in the string (char, char)"<<endl;
		cout<<"[2] Replaces all occurences of char with another char in the string (char, char)"<<endl;
		cout<<"Enter Replace Operation: ";
		cin>>tasktype;
		if (tasktype==1){
			char oldchar, newchar;
			cout<<"Enter old character: ";
			cin>>oldchar;
			cout<<"Enter new character: ";
			cin>>newchar;
			str->replace(oldchar, newchar);			
			cout<<"Replace result: ";
			cout<<str1;
			cout<<endl<<endl;
		}	
		if (tasktype==2){
			char oldchar, newchar;
			cout<<"Enter old character: ";
			cin>>oldchar;
			cout<<"Enter new character: ";
			cin>>newchar;
			str->replaceAll(oldchar, newchar);			
			cout<<"Replace result: ";
			cout<<str1;
			cout<<endl<<endl;
		}
	goto start;
	}
	else if (tasktype==5){
		char chars[100];
		cout<<"Enter chars: ";
		cin>>chars;
		if (str->startsWith(chars))
			cout<<"The string starts with "<<chars<<"!";
		else
			cout<<"The string does not start with "<<chars<<"!";		
		cout<<endl<<endl;
		goto start;
	}
	else if (tasktype==6){
		char chars[100];
		cout<<"Enter chars: ";
		cin>>chars;
		if (str->endsWith(chars))
			cout<<"The string ends with "<<chars<<"!";
		else
			cout<<"The string does not end with "<<chars<<"!";		
		cout<<endl<<endl;
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
		cout<<"String after changing to Uppercase: ";
		cout<<str1;
		cout<<endl<<endl;
		goto start;
		}
	else if (tasktype==9){
		str->toLowerCase();
		cout<<"String after changing to Lowercase: ";
		cout<<str1;
		cout<<endl<<endl;
		goto start;
		}
	else if (tasktype==10){
		cout<<"How many string elements you want to enter? ";
		int num;
		cin>>num;
		cout<<endl;
		String str2;
		cout<<"Enter "<<num<<" string(s): "<<endl;
		for(int i=0; i<num; i++)
		{
			cin>>str2;
		}
		ofstream fout;
		fout.open("string.dat",ios::binary);
		fout.write((char*)&str2,sizeof(str2));
		fout.close();
		cout<<"Enter string in order to check whether it exixts or not in file String.txt"<<endl;
		String str3;
		cin>>str3;
		ifstream fin;
		fin.open("string.dat",ios::binary);
		int i=0;
		while(fin.read((char*)&str2,sizeof(str2)))
		{
			if(str2.equals(str3))
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
		
	else if (tasktype==11){
		out.close();
		out.open("log.dat", ios::binary | ios::in);
		cout<<"Log: "<<endl;
		if (out.read((char*)&str1, sizeof(str1))){
			cout<<str1;
			cout<<endl;
		}
		cout<<endl;
		out.close();
		out.open("log.dat", ios::binary | ios::out);
		goto start;
	}
	out.close();
	cout<<"You exited from program :( Return back Soon!";
	return 0;
}

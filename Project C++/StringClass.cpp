#include <iostream>
#include <fstream>
using namespace std;
class String;
class String1
{
	public:
	virtual int length()=0;
	virtual bool equals(String &)=0;
	virtual bool equalsIgnoreUpperCase(String &)=0;
	virtual bool equals(const char *)=0;
	virtual void concat(const char [], int)=0;
	virtual void concat(const char *)=0;
	virtual bool replace(char, char)=0;
	virtual bool replaceAll(char, char)=0;
 	virtual bool toUpperCase()=0;
 	virtual bool toLowerCase()=0;
 	virtual bool erase(int)=0;
 	virtual bool erase(char)=0;
 	virtual bool eraseAll(char)=0;
 	virtual void erase(const char *)=0;
 	virtual bool startsWith(const char *)=0;
 	virtual bool endsWith(const char *)=0;
};
class String: public String1
{
private:
	char *c;
	int len;
public:
	String()//default constructor
	{
	}
	String(const char chars[])//constructor receives char
	{
		int j=0;
		while (chars[j])
			j++;
		c=new char[j];
		for(int i=0; i<j; i++)
		c[i]=chars[i];
	}
	String(const char chars[], int startIndex, int numChars)//constructor receives char and starts from starting Index and takes numChars amount of characters
	{
		int j=0;
		while (chars[j])
			j++;
		c=new char[j];
		for(int i=0; i<numChars; i++)
		c[i]=chars[startIndex+i];
	}
	String(String &str)//copy constructor
	{
		c=new char[str.length()];
		for(int i=0; i<str.length(); i++)
		c[i]=str[i];
	}
	friend void operator<<(ostream &out, String &str);//1.shows String
	friend void operator>>(istream &in, String &str);//2.insertion of String
	friend String operator +(String &a, String &b);//3.(a)receives two objects and result will be addition of two Strings and returns object
	friend String operator +(String &a, const char *ch);//3.(b)receives one object and one char array and result will be addition of two Strings and returns object
	friend String operator +(const char *ch, String &a);//3.(c)the same with above but order is reversed of object and char array
	void operator =(const char chars[])//4.receives char array and equals it with String object
	{
		int j=0;
		while(chars[j])
		{
			j++;
		}
		c=new char[j];
		for(int i=0; i<j; i++)
		c[i]=chars[i];
	}
	int length()//5.identifies length of the String and returns integer(length of object's data member)
	{
		len=0;
		int i=0;
		while(c[i++])
		len++;
		return len;
	}

	char operator[](int position)//6.identifies String's character according to its position and returns character
	{
		return c[position];
	}
	bool equals(String &obj)//7.compares two object's data member and identifies whether its true or false
	{
		if(length()!=obj.length())
		return false;
		for(int i=0; i<length(); i++)
		{
			if(c[i]!=obj.c[i])
			return false;
		}
		return true;
	}
	bool equalsIgnoreUpperCase(String &obj)//7.(a) compares two object and ignores capital letters
	{
		String alt, alt1;
		alt.c=new char[length()];
		alt1.c=new char[obj.length()];
		for(int i=0; i<length(); i++)
		{
			alt.c[i]=c[i];
		}
		for(int i=0; i<obj.length(); i++)
		{
			alt1.c[i]=obj.c[i];
		}
		alt1.toLowerCase();
		alt.toLowerCase();
		if(alt.length()!=alt1.length())
		return false;
		for(int i=0; i<alt.length(); i++)
		{
			if(alt.c[i]!=alt1.c[i])
			return false;
		}
		return true;
	}
	bool equals(const char *ch)//7.(b) compares object's data member with chars array
	{
		int j=0;
		while(ch[j])
		j++;
		if(j!=length())
		return false;
		for(int i=0; i<j;i++)
		{
			if(ch[i]!=c[i])
			return false;
		}
		return true;
	}
	void concat(const char chars[], int where)//8. receives array of chars and adds these chars to object data member from start index of this member
	{
		int j=0;

		while(chars[j])
		j++;
		char subChars[j+length()];
		for(int i=0; i<where; i++)
		{
			subChars[i]=c[i];

		}
		for(int i=0; i<j; i++)
		{
			subChars[i+where]=chars[i];
		}

		for(int i=where; i<length(); i++)
		{
			subChars[i+j]=c[i];

		}
		int k=length();

		for(int i=0; i<j+k; i++)
		{
			c[i]=subChars[i];

		}

	}
	void concat(const char *chars)//9. receives chars and adds them to the end of object's data member
	{
		int j=0, size;
		while(chars[j])
		j++;
		size=length();
		for(int i=0; i<j; i++)
		c[size+i]=chars[i];
	}
	bool replace(char ch, char replacedch)//10. replaces the exists char with receiven char(only one element) and returns true if this char exists in object's elements else returns false
	{
		for(int i=0; i<length(); i++)
		{
			if(c[i]==ch)
			{
				c[i]=replacedch;
				return true;
			}
		}
		return false;
	}
	bool replaceAll(char ch, char replacedch)//11. replaces all wanted elements with receiven element and returns true if this char exists in object's elements else returns false
	{
		bool check;
		for(int i=0; i<length(); i++)
		{
			if(c[i]==ch)
			{
				check=true;
				break;
			}
			else check=false;
		}
		for(int i=0; i<length(); i++)
		{
			if(c[i]==ch)
			{
				c[i]=replacedch;
		    }
		}
		return check;
	}
	bool toUpperCase()//12. changes letters by capital letters
	{
		for(int i=0; i<length(); i++)
		{
			if(int(c[i])>=97 && c[i]!=' ' && c[i]<=122)
			replace(c[i],c[i]-32);
		}
		return true;
	}
	bool toLowerCase()//13. changes Capital leters by small letters
	{
		for(int i=0; i<length(); i++)
		{
			if(int(c[i])<91 && c[i]!=' ' && c[i]>64)
			replace(c[i],c[i]+32);
		}
		return true;
	}
	bool erase(int which)//14. erases given index element of data member
	{
		int size=length();
		for(int i=which; i<size; i++)
		{
			if(i==size-1)
			{
				c[i]='\0';
			}
			c[i]=c[i+1];
		}
		return true;
	}
	bool erase(int startIndex, int numChars)//14(a). erases numChars amount of chars starting from StartIndex
	{
		if(startIndex<length()-1 && startIndex+numChars<=length())
		{
		int size=length(), sizeOfChars=size-numChars, j;
		char chars[sizeOfChars];
		for(j=0; j<startIndex; j++)
		{
			chars[j]=c[j];
		}
		for(int i=startIndex+numChars; i<size; i++)
		{
			chars[j]=c[i];
			j++;
		}
		for(int i=0; i<sizeOfChars; i++)
		{
			c[i]=chars[i];
		}
		for(int i=sizeOfChars; i<size; i++)
		{
			erase(sizeOfChars);
		}
		
	}
		return true;
	}
	bool erase(char ch)// 14(b). erases receiven char from object's data member
	{
		int size=length();
		for(int i=0; i<size; i++)
		{
			if(c[i]==ch)
			{
				erase(i);
				return true;
			}
		}
		return false;
	}
	bool eraseAll(char ch)//14(c). erases all receiven char from object's data member
	{
		int size=length();
		bool check;
		for(int i=0; i<length(); i++)
		{
			if(c[i]==ch)
			{
				check=true;
				break;
			}
			else check=false;
		}
		for(int i=0; i<size; i++)
		{
			if(c[i]==ch)
			{
				erase(i);
				eraseAll(ch);
			}
		}
		return check;
	}
	void erase(const char *chars)//14(d). erases receiven chars array from object's data member
	{
		int k=0;
		while(chars[k])
		k++;
		int size=length();
		for(int i=0; i<k; i++)
		{
			for(int j=0; j<size; j++)
			{
				if(chars[i]==c[j])
				{
					erase(j);
				}
			}
		}
	}
	bool startsWith(const char *chars)//15. identifies whether object's data member starts with receiven chars array
	{
		int j=0;
		while(chars[j])
		j++;
		for(int i=0; i<j; i++)
		{
			if(chars[i]==c[i]);
			else
				return false;
		}
		return true;
	}
	bool endsWith(const char *chars)//16. identifies whether object's data member ends with receiven chars array
	{
		int j=0, size=length();
		while(chars[j])
		j++;
		for(int i=0; i<j; i++)
		{
			if(c[size-j+i]==chars[i]);
			else return false;
		}
		return true;
	}
};
void operator<<(ostream &out, String &str)//->1.
{
	out << str.c;
}
void operator>>(istream &in, String &str)//->2.
{
	str.c = new char[100];
	in >> str.c;
}
String operator +(String &a, String &b)//->3.(a)
	{
		int j=0;
		String d;
		d.c=new char[a.length()+b.length()];
		for(int i=0; i<a.length(); i++)
		d.c[i]=a.c[i];
		for(int i=a.length(); i<a.length()+b.length(); i++)
		{
			d.c[i]=b.c[j];
			j++;
		}
		return d;
	}
String operator +(String &a, const char *ch)//->3.(b)
{
	int j=0;
	while(ch[j])
	j++;
	String d,b;
	b.c=new char[100];
	b=ch;
	d.c=new char[a.length()+j];
	int len1=a.length(), k=0;
	for(int i=0; i<len1; i++)
		d.c[i]=a.c[i];
		for(int i=len1; i<len1+j; i++)
		{
			d.c[i]=b.c[k];
			k++;
		}
		return d;
}
String operator +(const char *ch, String &a)//3.(c)
{
	int j=0;
	while(ch[j])
	j++;
	String d,b;
	b.c=new char[j];
	b=ch;
	d.c=new char[a.length()+j];
	int len1=a.length(), k=0;
	for(int i=0; i<j; i++)
		d.c[i]=b.c[i];
		for(int i=j; i<len1+j; i++)
		{
			d.c[i]=a.c[k];
			k++;
		}
		return d;
}
int main()
{
	String a,b,d;
	a="Facebook";
	b="Hello";
	d=b;
	cout<<"value of b: ";
	cout<<b;//binary operator
	cout<<endl<<"1.Copy of b by d! "<<endl;
	cout<<"value of d: ";
	cout<<d;
	char chars[]={'a','b','c','d','e','f'};
	String c(chars);
	cout<<endl<<"chars="<<chars<<endl;
	cout<<"2.Constructor initializes string object with the chars!"<<endl;
	cout<<"value of c: ";
	cout<<c;
	String f(chars,1,3);
	cout<<endl<<"3.Constructor initializes string object with the chars which the subrange begins from 1 index of chars and takes 3 characters from starting index!"<<endl;
	cout<<"value of f: ";
	cout<<f;
	String e(a);
	cout<<endl<<"4.Copy Constructor!"<<endl;
	cout<<"value of e copied from object a: ";
	cout<<e;
	String g;
	g=b+a;
	cout<<endl<<"5.Value of g as a result of addition of b and a objects!"<<endl;
	cout<<"value of g: ";
	cout<<g;
	g=g+" and Telegram";
	cout<<endl<<"6.Value of new g as a result of addition of g and array of chars that we gave(' and Telegram')!"<<endl;
	cout<<"value of new g: ";
	cout<<g;
	String h;
	cout<<endl<<"6.Enter value of object of String-h! ";
	cin>>h;//binary operator
	cout<<"value of h inputted by the binary stream operator: ";
	cout<<h;
	cout<<endl<<"7.The length of h String: "<<h.length()<<endl;
	cout<<"8. 4th index of h String: "<<h[4]<<endl;
	cout<<"9. Equals function!"<<endl<<"Value of a: ";
	cout<<a;
	cout<<endl<<"Value of b: ";
	cout<<b;
	cout<<endl<<"Is a and b equal? "<<a.equals(b)<<endl;
	cout<<"10. Equals Ignores UpperCase function! "<<endl;
	String w;
	w="HEllo";
	cout<<"Value of w: ";
	cout<<w;
	cout<<endl<<"Is w and b equal if we ignore UpperCase letters? "<<b.equalsIgnoreUpperCase(w)<<endl;
	cout<<"11. Compare String with chars of Array function!"<<endl;
	cout<<"Is b and 'hello' equal? "<<b.equals("hello")<<endl;
	cout<<"12. Concatenation: "<<endl;
	cout<<"Before changing value of object a"<<endl;
	cout<<a;
	cout<<endl<<"After adding 'And' to a from 4 index position"<<endl;
	a.concat("And", 4);
	cout<<a;
	cout<<endl<<"13. Concatenation from end:"<<endl;
	cout<<"Before changing value of object a"<<endl;
	cout<<a;
	cout<<endl<<"After adding 'And' to the end of object"<<endl;
	a.concat("And");
	cout<<a;
	cout<<endl<<"14. Replace method:"<<endl;
	cout<<"Before changing value of object a"<<endl;
	cout<<a;
	cout<<endl<<"After replacing 'b' with 'h' "<<endl;
	a.replace('b', 'h');
	cout<<a;
	cout<<endl<<"15. ReplaceAll method:"<<endl;
	cout<<"Before changing value of object a"<<endl;
	cout<<a;
	cout<<endl<<"After replacing all 'o' with 'e' "<<endl;
	a.replaceAll('o', 'e');
	cout<<a;
	cout<<endl<<"16. ToUpperCase method:"<<endl;
	cout<<"Before changing value of object a"<<endl;
	cout<<a;
	cout<<endl<<"After changing letters of object by capital letters"<<endl;
	a.toUpperCase();
	cout<<a;
	cout<<endl<<"17. ToLowerCase method:"<<endl;
	cout<<"Before changing value of object a"<<endl;
	cout<<a;
	cout<<endl<<"After changing letters of object by lower letters"<<endl;
	a.toLowerCase();
	cout<<a;
	cout<<endl<<"18. Erase method:"<<endl;
	cout<<"Before changing value of object a"<<endl;
	cout<<a;
	cout<<endl<<"After erasing 5th element from object's data member"<<endl;
	a.erase(5);
	cout<<a;
	cout<<endl<<"19. Erase method:"<<endl;
	cout<<"Before changing value of object a"<<endl;
	cout<<a;
	cout<<endl<<"After erasing 'f' element from object's data member"<<endl;
	a.erase('f');
	cout<<a;
	cout<<endl<<"20. Erase method:"<<endl;
	cout<<"Before changing value of object a"<<endl;
	cout<<a;
	cout<<endl<<"After erasing 3 elements starting from 9th index"<<endl;
	a.erase(9,3);
	cout<<a;
	cout<<endl<<"21. EraseAll method:"<<endl;
	cout<<"Before changing value of object a"<<endl;
	cout<<a;
	cout<<endl<<"After erasing all 'e' elements from object's data member"<<endl;
	a.eraseAll('e');
	cout<<a;
	cout<<endl<<"22. Erase method:"<<endl;
	cout<<"Before changing value of object b"<<endl;
	cout<<b;
	cout<<endl<<"After erasing 'Hel' from object b"<<endl;
	b.erase("Hel");
	cout<<b;
	cout<<endl<<"23. StartsWith method:"<<endl;
	cout<<"Before changing value of object w"<<endl;
	cout<<w;
	cout<<endl<<"Does data member of w object start with 'HEl'? ";
	cout<<w.startsWith("HEl")<<endl;
	cout<<endl<<"23. StartsWith method:"<<endl;
	cout<<"Before changing value of object w"<<endl;
	cout<<w;
	cout<<endl<<"Does data member of w object end with 'lo'? ";
	cout<<w.endsWith("lo")<<endl;
	//system("pause");*/
	/*ofstream file;
	char f[100];
	file.open("String.txt");
	file<<b;
	file<<endl;
	file<<a;
	file.close();
	ifstream check;
	check.open("String.txt");
	while(check.good()!=0)
	{
		check>>f;
		if(d.equals(f))
		{
		cout<<"It exists!"<<endl;
		}
	}
	cout<<"It Not exists!"<<endl;
	check.close();*/
	//example erases free spaces and remains only one free space between letters.
	
	/*String str;
	str="         Hello         World        C++   ";
	int size = str.length();
	cout<<size<<endl;
	cout<<str;
	for(int j = 0; j<=size; j++)
	{
		for(int i = 0; i <=j; i++)
        {
            if(str[i] == ' ' && str[i+1] == ' ')
            {
                str.erase(i);
            }
        }
	}
	cout<<endl<<str.length()<<endl;
	cout<<str;*/
	
	return 0;
}

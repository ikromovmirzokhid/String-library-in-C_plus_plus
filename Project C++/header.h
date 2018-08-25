#include <iostream>
#include "String1.h"
using namespace std;
class String: public Erase, public Replace, public Concatination, public Equals
{
private:
	int len;
public:
	char *c;
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
	int length();//5.identifies length of the String and returns integer(length of object's data member)
	

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
int String::length()//5.identifies length of the String and returns integer(length of object's data member)
	{
		len=0;
		int i=0;
		while(c[i++])
		len++;
		return len;
	}

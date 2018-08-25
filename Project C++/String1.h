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
 	virtual bool erase(int,int)=0;
 	virtual bool eraseAll(char)=0;
 	virtual bool startsWith(const char *)=0;
 	virtual bool endsWith(const char *)=0;
};
class Replace: virtual public String1
{
	virtual bool replace(char, char)=0;
	virtual bool replaceAll(char, char)=0;
};
class Concatination: virtual public String1
{
	virtual void concat(const char [], int)=0;
	virtual void concat(const char *)=0;
};
class Equals: virtual public String1
{
	virtual bool equals(String &)=0;
	virtual bool equalsIgnoreUpperCase(String &)=0;
	virtual bool equals(const char *)=0;
};
class Erase: virtual public String1
{
	virtual bool erase(int)=0;
 	virtual bool erase(char)=0;
 	virtual bool eraseAll(char)=0;
};

#include "jlike.h"

int main()
{
	String str;
	Handle fh = HANDLE();
	fh.makef("t1.txt");
	fh.writef("its about the habit","t1.txt");
}

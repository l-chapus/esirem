#include <iostream>
#include "basicencrypt.h"

int main()
{
	BasicEncrypt mot1("test");
	std::cout << mot1.plain() << "     " << mot1.cipher() << std::endl;
	mot1.encode();
	std::cout << mot1.plain() << "     " << mot1.cipher() << std::endl;
	

	return 0;
}
#pragma once
#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <iostream>

class Encrypt{
public:
	
	std::string plain();
	std::string cipher();
private:

protected:
	std::string _plain;
	std::string _cipher;
}

#endif
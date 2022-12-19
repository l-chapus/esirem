#pragma once
#ifndef BASICENCRYPT_H
#define BASICENCRYPT_H

#include <iostream>

class BasicEncrypt{
public:
	BasicEncrypt(std::string plain = "", std::string cipher = "");
	std::string plain();
	std::string cipher();
	void encode();
	void decode();
protected:
	std::string _plain;
	std::string _cipher;
};

#endif
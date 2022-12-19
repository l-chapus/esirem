#include "basicencrypt.h"
#include <iostream>

BasicEncrypt::BasicEncrypt(std::string plain, std::string cipher) : _plain(plain) , _cipher(cipher){
}
void BasicEncrypt::encode(){
	_cipher = _plain;
}
void BasicEncrypt::decode(){
	_plain = _cipher;
}
std::string BasicEncrypt::plain(){
	return _plain;
}
std::string BasicEncrypt::cipher(){
	return _cipher;
}

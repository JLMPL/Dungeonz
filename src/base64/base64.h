#ifndef base64_hpp
#define base64_hpp

#include <string>
#include <vector>

std::string base64_encode(unsigned char const* , unsigned int len);
std::string base64_decode(std::string const& s);

#endif
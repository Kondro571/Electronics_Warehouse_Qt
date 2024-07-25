#include "myexception.h"

MyException::MyException(std::string message): msg(message) {}

std::string MyException::what()
{
    return msg;
}

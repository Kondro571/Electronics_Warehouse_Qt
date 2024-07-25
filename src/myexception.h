/**
 *  \file MyException.h
 *  \brief A custom exception class
 *
 *  This class is used to handle custom exceptions in the program
 *
 *  \author John Doe
 *  \date Jan 1, 2020
 */

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<iostream>

class MyException: public _exception {
   std::string msg;

public:
    /**
     *  \brief Constructor
     *
     *  \param message The message to be stored in the exception
     */
    MyException(std::string message);

    /**
     *  \brief Returns the message stored in the exception
     *
     *  \return std::string The message stored in the exception
     */
   std::string what();
};

#endif // MYEXCEPTION_H

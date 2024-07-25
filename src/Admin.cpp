#include <iostream>
#include "Admin.h"
using namespace std;

Admin::Admin()
{
    this->Email = "";
    this->password = "";
}

Admin::Admin(string mail, string password)
{
    this->Email = mail;
    this->password = password;

}
Admin::~Admin(){}
string Admin::getEmail()
{
    return Email;
}

string Admin::getPasswd()
{
    return password;
}

void Admin::setEmail(string email)
{
    this->Email = email;
}

void Admin::setPassword(string passwd)
{
    this->password = passwd;
}

void Admin::saveToFile(ofstream & outputUsers)
{
    size_t emailSize = Email.size();
    size_t passwordSize = password.size();

    if (outputUsers.good())
    {
        outputUsers.write((char*) &emailSize, sizeof(emailSize));
        outputUsers.write((char*) &Email[0], emailSize);

        outputUsers.write((char*) &passwordSize, sizeof(passwordSize));
        outputUsers.write((char*) &password[0], passwordSize);
    }
}

void Admin::readFromFile(ifstream & inputAdmin)
{
    size_t emailSize;
    size_t passwordSize;

    inputAdmin.read((char*) &emailSize, sizeof(emailSize));

    Email.resize(emailSize);
    inputAdmin.read((char*) &Email[0], emailSize);

    inputAdmin.read((char*) &passwordSize, sizeof(passwordSize));
    password.resize(passwordSize);
    inputAdmin.read((char*) &password[0], passwordSize);

}

ostream &operator<<(ostream &out, const Admin &c)
{
    out << c.Email << endl;
    return out;
}

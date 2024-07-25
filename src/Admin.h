#pragma once
#include "Product.h"
#include <string>
#include <vector>
using namespace std;

/**
 * @class Admin
 * @brief Represents an admin user.
 *
 * This class is derived from the Product class and represents an admin user. It includes
 * information such as the admin's email and password, as well as methods for adding and
 * removing products, setting and getting email and password, saving to file, and reading from file.
 */
class Admin : public Product {
    private:
        /**
         * @var Email
         * @brief The admin's email address.
         */
        string Email;
        /**
         * @var password
         * @brief The admin's password.
         */
        string password;

    public:
        /**
         * @brief Default constructor for Admin class.
         *
         * Initializes an empty admin object.
         */
        Admin();

        /**
         * @brief Constructor for Admin class.
         *
         * Initializes an admin object with the provided email and password.
         *
         * @param mail The admin's email address.
         * @param password The admin's password.
         */
        Admin(string mail, string password);

        /**
         * @brief Sets the admin's email address.
         *
         * @param email The admin's email address.
         */
        ~Admin();
        void setEmail(string email);
        /**
         * @brief Sets the admin's password.
         *
         * @param passwd The admin's password.
         */
        void setPassword(string passwd);

        /**
         * @brief Gets the admin's email address.
         *
         * @return The admin's email address.
         */
        string getEmail();
        /**
         * @brief Gets the admin's password.
         *
         * @return The admin's password.
         */
        string getPasswd();

        /**
         * @brief Saves the admin's information to a file.
         *
         * @param outputUsers An output file stream.
         */
        void saveToFile(ofstream& outputUsers) override;
        /**
         * @brief Reads the admin's information from a file.
         *
         * @param inputUsers An input file stream.
         */
        void readFromFile(ifstream& inputUsers) override;

        /**
         *  Overloads the += operator for the class.
         *
         *  @param rhs The value that is being added to the current object.
         *
         */
        friend ostream& operator<<(ostream& out, const Admin& lh);
};

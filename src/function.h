/**
 *@file
 *@brief This file contains all the functions and templates that are used in the program.
 */
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <regex>
#include <conio.h>
#include "Product.h"
#include "Ram.h"
#include "Cpu.h"
#include "Admin.h"
#include "Motherboard.h"

#include "myexception.h"
#include <vector>
#include <fstream>
using namespace std;

/**
 *@brief Global variable to store the current id of the product
 */
extern int id;

/**
 *@brief Global vector to store all products in the storage
 */
extern vector<Product*> ProductInStorage;

/**
 *@brief Global vector to store all admin of the shop
 */
extern vector<Admin> Adm;

/**
 *@brief Global variable to store the file name for admin
 */
extern string fileAdmin;

/**
 *@brief Global variable to store the file name for products
 */
extern string fileProduct;

/**
 *@brief Global variable to store the number of admin
 */
extern int AdminNumber;

/**
 *@brief Function to login as admin
 *@param email The email address of the admin
 *@param passwd The password of the admin
 *@return true if the login is successful, false otherwise
 */
bool loginAdmin(string email, string passwd);

/**
 *@brief Function to handle the login process
 */
void login();

/**
 *@brief Function to add a new product of type RAM
 *@param model The model of the product
 *@param type The type of the product
 *@param capacity The capacity of the product
 *@param timing The timing of the product
 *@param tension The tension of the product
 *@param prize The prize of the product
 *@param amount The amount of the product
 *@return true if the product is successfully added, false otherwise
 */
bool addProduct(string model, string type, int capacity, int timing, double tension, double prize, int amount);

/**
 *@brief Function to add a new product of type CPU
 *@param model The model of the product
 *@param type The type of the product
 *@param socked The socked of the product
 *@param coreNumber The number of cores of the product
 *@param coreTiming The core timing of the product
 *@param prize The prize of the product
 *@param amount The amount of the product
 *@return true if the product is successfully added, false otherwise
 */
bool addProduct(string model, string type, string socked, int coreNumber, int coreTiming, double prize, int amount);

/**
 *@brief Function to add a new product of type Motherboard
 *@param model The model of the product
 *@param chipset The chipset of the product
 *@param familiSupport The family support of the product
 *@param socked The socked of the product
 *@param prize The prize of the product
 *@param amount The amount of the product
 *@return true if the product is successfully added, false otherwise
 */
bool addProduct(string model, string chipset, string familiSupport, string socked, double prize, int amount);

/**
 *@brief Function to read the admin data from file
 *@param file The file name to read from
 */
void readAdmin(string file);

/**
 *@brief Function to save the admin data to file
 *@param file The file name to save to
 */
void saveAdmin(string file);

/**
 *@brief Function to remove a product from the shop
 *@param id The id of the product to remove
 *@return true if the product is successfully removed, false otherwise
 */
bool removeFromShop(int id);

/**
 *@brief Function to check if an email address is valid
 *@param email The email address to check
 *@return true if the email address is valid, false otherwise
 */
bool checkEmail(string email);

/**
 *@brief Function to add a new admin
 *@param email The email address of the admin
 *@param password The password of the admin
 *@return true if the admin is successfully added, false otherwise
 */
bool addAdmin(string email, string password);

/**
 *@brief Function to edit a product's price and amount
 *@param chosenId The id of the product to edit
 *@param price The new price of the product
 *@param amount The new amount of the product
 *@return true if the product is successfully edited, false otherwise
 */
bool editProduct(int chosenId, double price, int amount);

/**
 *@brief Function to edit a product's amount
 *@param chosenId The id of the product to edit
 *@param amount The new amount of the product
 *@return true if the product is successfully edited, false otherwise
 */
bool editProduct(int chosenId, int amount);

/**
 *@brief Template function to save a vector of products to a file
 *@param fileName The file name to save to
 *@param products The vector of products to save
 */
template < typename T>
    void saveProductToFile(const string &fileName, const vector<T> &products);

/**
 *@brief Template function to read products from a file to a vector
 *@param fileName The file name to read from
 *@param products The vector to store the products
 */
template < typename F>
    void readProductFromFile(const string &fileName, vector<F> &products)
    {
        ifstream fd;
        int ProductCount;
        string category;
        size_t categorySize;
        fd.open(fileName, ios::binary | ios:: in);
        if (!fd.good() || !fd.is_open())
        {
            throw MyException("Error opening file Productk");
        }

        fd.seekg(0, std::ios::end);
        if (fd.tellg() != 0)
        {
            fd.seekg(0, std::ios::beg);

            fd.read((char*) &ProductCount, sizeof(int));

            if (ProductCount > 0)
            {
                for (int i = 0; i < ProductCount; i++)
                {
                    fd.read((char*) &categorySize, sizeof(categorySize));
                    category.resize(categorySize);
                    fd.read((char*) &category[0], categorySize);

                    if (category == "Ram")
                    {
                        Product *p = new Ram();
                        p->readFromFile(fd);
                        ProductInStorage.push_back(p);
                    }
                    else if (category == "Cpu" || category == "cpu")
                    {
                        Product *p = new Cpu();
                        p->readFromFile(fd);
                        ProductInStorage.push_back(p);
                    }
                    else if (category == "Motherboard")
                    {
                        Product *p = new Motherboard();
                        p->readFromFile(fd);
                        ProductInStorage.push_back(p);
                    }
                }
                if(ProductInStorage.size()>0)
                id = ProductInStorage[ProductCount - 1]->getId();
            }
        }

        fd.close();

    }

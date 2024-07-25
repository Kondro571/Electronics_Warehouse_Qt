#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/**
 *  @class Product
 *  @brief A class representing a Product
 *
 *  The Product class has properties like id, category, model, prize, amount and methods like getters and setters for each property,
 *  a virtual method doesExist, virtual method saveToFile,virtual method readFromFile, virtual method Show, virtual operator += and also a ostream operator
 *
 */
class Product {
protected:
    /**
        *  The id of the product
        */
       int id;
       /**
        *  The category of the product
        */
       string category="";
       /**
        *  The model of the product
        */
       string Model = "";
       /**
        *  The prize of the product
        */
       double prize=0;
       /**
        *  The amount of the product
        */
       int amount=0;
	
public:
     /**
     *  Default constructor for class Product
     */
	Product();
    /**
         *  Constructor for class Product
         *  @param id an integer representing the id of the product
         *  @param name a string representing the name of the product
         *  @param model a string representing the model of the product
         *  @param prize a double representing the prize of the product
         *  @param amount an integer representing the amount of the product
         */
	Product(int id,string name,string model, double prize, int amount);
    /**
    * Destructor for Product class
    */
    virtual ~Product();
    /**
    * Getter for the unique identifier of the product
    * @return the unique identifier of the product
    */
	int getId();
    /**
    * Getter for the category of the product
    * @return the category of the product
    */
	string getCategory();
    /**
    * Getter for the prize of the product
    * @return the prize of the product
    */
	double getPrize();
    /**
    * Getter for the amount of the product
    * @return the amount of the product
    */
	int getAmount();


    /**
    * @brief Set the id of the product
    * @param id The id of the product
    */
    void setId(int id);

    /**
    * @brief Set the category of the product
    * @param category The category of the product
    */
    void setCategory(string category);

    /**
    * @brief Set the prize of the product
    * @param prize The prize of the product
    */
    void setPrize(double prize);

    /**
    * @brief Set the amount of the product
    * @param amount The amount of the product
    */
    void setAmount(int amount);

    /**
    * @brief Check if the product exist
    * @param model The model of the product
    * @param Type The type of the product
    * @param capacity The capacity of the product
    * @param Timing The timing of the product
    * @param tension1 The tension of the product
    * @param socked The socked of the product
    * @param corNumber The corNumber of the product
    * @return true if the product exist, false otherwise
    */
    virtual bool doesExist(string model, string Type, int capacity, int Timing, double tension1, string socked, int corNumber);
    /**
    * @brief Check if the product exist
    * @param model The model of the product
    * @param chipset The chipset of the product
    * @param faliliSupport The CpuFamiliSupport of the product
    * @param socked The socked of the product
    * @param price The price of the product
    * @param amount The amount of the product
    */
    virtual bool doesExist(string model, string chipset, string familiSupport, string socked, double prize, int amount);
    /**
    * @brief Save the product to a file
    * @param output The output stream to save the product to
    */
    virtual void saveToFile(ofstream& output);

    /**
    * @brief Read the product from a file
    * @param input The input stream to read the product from
    */
    virtual void readFromFile(ifstream& input);

    /**
    * @brief Show the product
    */
    virtual void Show();

    /**
    * @brief Get the model of the product
    * @return The model of the product
    */
    string getModel();

    /**
    * @brief Set the model of the product
    * @param model The model of the product
    */
    void setModel(string model);

    /**
    * @brief Overload the += operator for the product
    * @param rhs The value to add to the product
    */
    virtual void operator +=(int rhs);

    /**
    * @brief Overload the << operator for the product
    * @param out The output stream to write the product to
    * @param p The product to write
    */
    friend ostream& operator<<(ostream& out, const Product& p);
  };


/**
 * @file Ram.h
 * @brief The header file for the Ram class
 * @author John Doe
 * @date 01/01/2023
 */
#pragma once
#include "Product.h"
#include <string>
#include <vector>
using namespace std;
/**
 * @class Ram
 * @brief A class representing a Ram product
 * @extends Product
 */
class Ram : public Product {
private:
        /** @brief the type of memory */
        string TypeOfMemory;
        /** @brief total capacity */
        int TotalCapacity;
        /** @brief Ram timing */
        int RamTiming;
        /** @brief Tension */
        double Tension;

public:
    /**
     * @brief Constructs a new Ram object with default values
     */
	Ram();
    /**
         * @brief Constructs a new Ram object
         * @param id id of the product
         * @param name name of the product
         * @param model model of the product
         * @param prize prize of the product
         * @param amount amount of the product
         * @param TypeOfMemory type of memory
         * @param TotalCapacity total capacity
         * @param RamTiming Ram timing
         * @param Tension tension
         */
	Ram(int id,string name, string model, double prize, int amount,string TypeOfMemory, int TotalCapacity, int RamTiming, double Tension);
    /**
     * @brief Destroys the Ram object
     */
    ~Ram();
    /**
     * @brief get the type of memory
     * @return type of memory
     */
	string getMemory() ;
    /**
     * @brief get the total capacity
     * @return total capacity
     */
	int getTotalCapacity();
    /**
     * @brief get the Ram timing
     * @return Ram timing
     */
    int getRamTiming();
    /**
     * @brief get the tension
     * @return tension
     */
	double getTension();
    /**
     * @brief set the type of memory
     * @param memory type of memory
     */
	void setMemory(string memory);
    /**
     * @brief set the total capacity
     * @param Capacity total capacity
     */
	void setTotalCapacity(int Capacity);
    /**
     * @brief set the Ram timing
     * @param timing Ram timing
     */
    void setRamTiming(int timing);
    /**
     * @brief set the tension
     * @param tension tension
     */
	void setTension(double tension);
    /**
        * @brief Check if exists product
        * @param model product model
        * @param Type product type
        * @param capacity product capacity
        * @param Timing product timing
        * @param tension1 product tension
        * @param socked product socket
        * @param corNumber product core number
        * @param chipset product chipset
        * @param familiSupport product family support
        * @return returns true if exists
        */
    bool doesExist(string model, string Type, int capacity, int Timing, double tension1, string socked, int corNumber) override;

    /**
     * @brief Show the product's details
     */
	void Show() override;
    /**
     * @brief Save the product to a file
     * @param output the output stream
     */
	void saveToFile(ofstream& output) override;
    /**
     * @brief Read the product from a file
     * @param intput the input stream
     */
	void readFromFile(ifstream& intput) override;
    /**
    * @brief Add the value to the amount of the product
    * @param rhs the value to be added
    */
    void operator +=(int rhs) override;
    /**
     * @brief Overloading the operator <<
     * @param out the output stream
     * @param l the product
     */
	friend ostream& operator<<(ostream& out, const Ram& l);

	

};


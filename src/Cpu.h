#pragma once
#include "Product.h"
#include <string>
#include <vector>
using namespace std;

/**
 * @class Cpu
 * @brief Represents a CPU product.
 *
 * This class is derived from the Product class and represents a CPU product. It includes
 * information such as the type of processor, the socket, the number of cores and the core timing.
 * It also includes methods for setting and getting product's properties, saving and reading from file,
 * displaying product's information and checking if product exist in the database.
 */
class Cpu : public Product {
private:
    /**
     * @var TypeOfProcessor
     * @brief The type of processor of the CPU.
     */
	string TypeOfProcessor;
    /**
     * @var Socked
     * @brief The socket of the CPU.
     */
	string Socked; 
    /**
     * @var NumberOfCors
     * @brief The number of cores of the CPU.
     */
	int NumberOfCors; 
    /**
     * @var CoreTiming
     * @brief The core timing of the CPU.
     */
	int CoreTiming; 

public:
    /**
     * @brief Default constructor for Cpu class.
     *
     * Initializes an empty CPU object.
     */
	Cpu();
    /**
     * @brief Constructor for Cpu class.
     *
     * Initializes a CPU object with the provided properties.
     *
     * @param id The product's id.
     * @param name The product's name.
     * @param model The product's model.
     * @param prize The product's prize.
     * @param amount The product's amount in stock.
     * @param type The type of processor of the CPU.
     * @param core The number of cores of the CPU.
     * @param socked The socket of the CPU.
     * @param timing The core timing of the CPU.
     */
	Cpu(int id,string name,string model, double prize, int amount, string type, int core,string socked,int timing);
    /**
    * @brief The destructor of the Cpu class
    */
    ~Cpu();
    /**
     * @brief Displays the product's information.
     */
	void Show() override;
    /**
     * @brief Sets the type of processor of the CPU.
     *
     * @param type The type of processor of the CPU.
     */
	void setTypeOfProcessor(string type);
    /**
     * @brief Sets the number of cores of the CPU.
     *
     * @param core The number of cores of the CPU.
     */
	void setNumberOfCors(int core);
    /**
     * @brief Sets the socket of the CPU.
     *
     * @param socked The socket of the CPU.
     */
	void setSocked(string socked);
    /**
     * @brief Sets the core timing of the CPU.
     *
     * @param core The core timing of the CPU.
     */
	void setCoreTiming(int core);
    /**
     * @brief Gets the type of processor of the
     * @return The type of processor of the CPU.
     */
	string getTypeOfProcessor();
    /**
     * @brief Gets the number of cores of the CPU.
     *
     * @return The number of cores of the CPU.
     */
	int getNumberOfCors();
    /**
     * @brief Gets the socket of the CPU.
     *
     * @return The socket of the CPU.
     */
	string getSocked();
    /**
     * @brief Gets the core timing of the CPU.
     *
     * @return The core timing of the CPU.
     */
	int getCoreTiming();
    /**
     * @brief Check if product exist in the database.
     *
     * @param model The product's model.
     * @param Type The type of processor of the CPU.
     * @param capacity The number of cores of the CPU.
     * @param Timing The core timing of the CPU.
     * @param tension1 The socket of the CPU.
     * @param socked The socket of the CPU.
     * @param corNumber The number of cores of the CPU.
     * @return true if the product exist otherwise false.
     */
    bool doesExist(string model, string Type, int capacity, int Timing, double tension1, string socked, int corNumber) override;

    /**
     * @brief Saves the CPU's information to a file.
     *
     * @param output An output file stream.
     */
	void saveToFile(ofstream& output) override;
    /**
     * @brief Reads the CPU's information from a file.
     *
     * @param intput An input file stream.
     */
    void readFromFile(ifstream& intput) override;
    /**
     *  Overloads the += operator for the class.
     *
     *  @param rhs The value that is being added to the current object.
     *
     */
    void operator +=(int rhs) override;
    /**
     * @brief Overloads the << operator for Cpu class.
     *
     * @param out The output stream.
     * @param l The CPU object.
     *
     * @return The output stream.
     */
	friend ostream& operator<<(ostream& out, const Cpu& l);
};

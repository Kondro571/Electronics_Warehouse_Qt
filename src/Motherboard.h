#pragma once

#include <string>
#include <vector>
#include "Product.h"

using namespace std;

/**
 * @class Motherboard
 * @brief Represents a motherboard product.
 */
class Motherboard : public Product {
private:
    /**
     * @brief Processor socket type.
     */
    string ProcesorSocked;
    /**
     * @brief Motherboard chipset.
     */
    string Chipset;
    /**
     * @brief CPU family support.
     */
    string CpuFamiliSupport;

public:
    /**
     * @brief Default constructor.
     */
    Motherboard();
    /**
     * @brief Constructor.
     *
     * @param id Product ID.
     * @param name Product name.
     * @param model Product model.
     * @param prize Product price.
     * @param amount Product quantity.
     * @param socked Processor socket type.
     * @param chipset Motherboard chipset.
     * @param family CPU family support.
     */
    Motherboard(int id, string name, string model, double prize, int amount, string socked, string chipset, string family);
    /**
    * @brief The destructor of the Motherboard class
    */
    ~Motherboard();
    /**
     * @brief Shows the product information.
     */
    void Show() override;
    /**
     * @brief Sets the processor socket type.
     *
     * @param socked Processor socket type.
     */
    void setProcesorSocked(string socked);
    /**
     * @brief Sets the motherboard chipset.
     *
     * @param chipset Motherboard chipset.
     */
    void setChipset(string chipset);
    /**
     * @brief Sets the CPU family support.
     *
     * @param famili CPU family support.
     */
    void setCpuFamiliSupport(string famili);
/**
     * @brief Gets the processor socket type.
     *
     * @return Processor socket type.
     */
	string getProcesorSocked();
    /**
     * @brief Gets the motherboard chipset.
     *
     * @return Motherboard chipset.
     */
	string getChipset();
    /**
     * @brief Gets the CPU family support.
     *
     * @return CPU family support.
     */
	string getCpuFamiliSupport();	

    /**
     * @brief Saves the product information to a file.
     *
     * @param output Output file stream.
     */
	void saveToFile(ofstream& output) override;
    /**
     * @brief Reads the product information from a file.
     *
     * @param intput Input file stream.
     */
	void readFromFile(ifstream& intput) override;
    /**
    * @brief Check if the product exist
    * @param model The model of the product
    * @param chipset The chipset of the product
    * @param faliliSupport The CpuFamiliSupport of the product
    * @param socked The socked of the product
    * @param price The price of the product
    * @param amount The amount of the product
    */
    bool doesExist(string model, string chipset, string familiSupport, string socked, double prize, int amount) override;
    /**
     *  Overloads the += operator for the class.
     *
     *  @param rhs The value that is being added to the current object.
     *
     */
    void operator +=(int rhs) override;
   
};


#include "Motherboard.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;



Motherboard::Motherboard()
{
    this->CpuFamiliSupport = "";
    this->Chipset = "";
    this->ProcesorSocked = "";
}


Motherboard::Motherboard(int id, string name, string model, double prize, int amount, string socked, string chipset, string family): Product(id, name, model, prize, amount)
{
    this->CpuFamiliSupport = family;
    this->Chipset = chipset;
    this->ProcesorSocked = socked;
}

Motherboard::~Motherboard() {}

void Motherboard::setProcesorSocked(string socked)
{
    this->ProcesorSocked = socked;
}


void Motherboard::setChipset(string chipset)
{
    this->Chipset = chipset;
}


void Motherboard::setCpuFamiliSupport(string famili)
{
    this->CpuFamiliSupport = famili;
}


string Motherboard::getProcesorSocked()
{
    return this->ProcesorSocked;
}


string Motherboard::getChipset()
{
    return this->Chipset;
}


string Motherboard::getCpuFamiliSupport()
{
    return this->CpuFamiliSupport;
}

void Motherboard::Show()
{
    cout << Product::id << setw(15) << Product::Model << setw(9) << CpuFamiliSupport << setw(20) << Chipset<< setw(9) << ProcesorSocked << setw(16) << Product::prize << setw(5) << Product::amount << endl;

}


void Motherboard::saveToFile(ofstream & output)
{
    size_t prize;
    size_t amount;
    size_t categorySize;
    size_t modelSize;
    size_t sockedSize;
    size_t familiSize;
    size_t chipsetSize;

    if (output.good())
    {
        string category = Product::category;
        categorySize = category.size();

        output.write((char*) &categorySize, sizeof(categorySize));
        output.write((char*) &category[0], categorySize);

        string Model = Product::Model;
        modelSize = Model.size();

        output.write((char*) &modelSize, sizeof(modelSize));
        output.write((char*) &Model[0], modelSize);

        int id = Product::id;
        output.write((char*) &id, sizeof(id));

        double prize = Product::prize;
        output.write((char*) &prize, sizeof(prize));

        int amount = Product::amount;
        output.write((char*) &amount, sizeof(amount));

        familiSize = CpuFamiliSupport.size();
        output.write((char*) &familiSize, sizeof(familiSize));
        output.write((char*) &CpuFamiliSupport[0], familiSize);

        chipsetSize = Chipset.size();
        output.write((char*) &chipsetSize, sizeof(chipsetSize));
        output.write((char*) &Chipset[0], chipsetSize);

        sockedSize = ProcesorSocked.size();
        output.write((char*) &sockedSize, sizeof(sockedSize));
        output.write((char*) &ProcesorSocked[0], sockedSize);
    }
}

void Motherboard::readFromFile(ifstream & intput)
{
    size_t modelSize;
    size_t cpuSize;
    size_t sockedSize;
    size_t familiSize;
    size_t chipsetSize;
    string model;

    Product::category = "Motherboard";
    try
    {
        intput.read((char*) &modelSize, sizeof(modelSize));
        model.resize(modelSize);
        intput.read((char*) &model[0], modelSize);
        Product::Model = model;

        int id;
        intput.read((char*) &id, sizeof(id));
        Product::id = id;

        double prize;
        intput.read((char*) &prize, sizeof(prize));
        Product::prize = prize;

        int amount;
        intput.read((char*) &amount, sizeof(amount));
        Product::amount = amount;

        intput.read((char*) &familiSize, sizeof(familiSize));
        CpuFamiliSupport.resize(familiSize);
        intput.read((char*) &CpuFamiliSupport[0], familiSize);

        intput.read((char*) &chipsetSize, sizeof(chipsetSize));
        Chipset.resize(chipsetSize);
        intput.read((char*) &Chipset[0], chipsetSize);

        intput.read((char*) &sockedSize, sizeof(sockedSize));
        ProcesorSocked.resize(sockedSize);
        intput.read((char*) &ProcesorSocked[0], sockedSize);
    }

    catch (const std::ifstream::failure &e)
    {
        std::cerr << "Error reading file: " << e.what() << std::endl;
    }
}

bool  Motherboard::doesExist(string model, string chipset, string familiSupport, string socked, double prize, int amount){
    if(Product::Model==model && this->Chipset ==chipset && CpuFamiliSupport==familiSupport && ProcesorSocked==socked){
        return true;
    }
    return false;
}

void Motherboard::operator+=(int rhs)
{
    Product::amount += rhs;
}

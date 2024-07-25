#include "Product.h"
#include <iostream>
#include <fstream>
using namespace std;

Product::Product()
{
    this->category = "";
    this->Model = "";
    this->amount = 0;
    this->prize = 0;
    this->id = 0;
}

Product::Product(int id, string category, string model, double prize, int amount)
{
    this->category = category;
    this->amount = amount;
    this->prize = prize;
    this->Model = model;
    this->id = id;
}

Product::~Product() {}

int Product::getId()
{
    return id;
}

string Product::getCategory()
{
    return category;
}

double Product::getPrize()
{
    return prize;
}

int Product::getAmount()
{
    return amount;
}

string Product::getModel()
{
    return Model;
}

void Product::setId(int id)
{
    this->id = id;
}

void Product::setCategory(string category)
{
    this->category = category;
}

void Product::setPrize(double prize)
{
    this->prize = prize;
}

void Product::setAmount(int amount)
{
    this->amount = amount;
}

bool Product::doesExist(string model, string Type, int capacity, int Timing, double tension1, string socked, int corNumber)
{
    return false;
}

bool  Product::doesExist(string model, string chipset, string familiSupport, string socked, double prize, int amount){
    return false;
}

void Product::setModel(string model)
{
    this->Model = model;
}

void Product::saveToFile(ofstream & output)
{
    size_t categorySize;

    if (output.good())
    {
        string category = Product::category;
        categorySize = category.size();

        output.write((char*) &categorySize, sizeof(categorySize));
        output.write((char*) &category[0], categorySize);

        int prize = Product::prize;
        output.write((char*) &prize, sizeof(prize));

        int amount = Product::amount;
        output.write((char*) &amount, sizeof(amount));
    }
    else
    {
        throw "bad file";
    }
}

void Product::readFromFile(ifstream & intput)
{
    int prize;
    intput.read((char*) &prize, sizeof(prize));
    Product::prize = prize;

    int amount;
    intput.read((char*) &amount, sizeof(amount));
    Product::amount = amount;
}

void Product::Show()
{
    cout << "Category: " << category << endl;
    cout << "Model: " << Model << endl;
    cout << "Price: " << prize << endl;
    cout << "Quantity: " << amount << endl;
}

bool doesExist(string model, string MemoryType, int capacity, int ramTiming, double tension, string Socked, int NumberOfCors)
{
    return false;
}

void Product::operator+=(int rhs)
{
    amount += rhs;
}

ostream &operator<<(ostream &out, const Product &p)
{
    out << "Name: " << p.category << endl;
    out << "Price: " << p.prize << endl;
    out << "Quantity: " << p.amount << endl;
    return out;
}

#include "Ram.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Ram::Ram()
{
    this->TypeOfMemory = "";
    this->TotalCapacity = 0;
    this->RamTiming = 0;
    this->Tension = 0;
}

Ram::Ram(int id, string name, string model, double prize, int amount, string memory, int capacity, int RamTiming, double Tension): Product(id, name, model, prize, amount)
{
    this->TypeOfMemory = memory;
    this->TotalCapacity = capacity;
    this->RamTiming = RamTiming;
    this->Tension = Tension;
}

Ram::~Ram() {}

string Ram::getMemory()
{
    return this->TypeOfMemory;
}

int Ram::getTotalCapacity()
{
    return this->TotalCapacity;
}

int Ram::getRamTiming()
{
    return this->RamTiming;
}

double Ram::getTension()
{
    return this->Tension;
}

void Ram::setMemory(string memory)
{
    this->TypeOfMemory = memory;
}

void Ram::setTotalCapacity(int capacity)
{
    this->TotalCapacity = capacity;
}

void Ram::setRamTiming(int timing)
{
    this->RamTiming = timing;
}

void Ram::setTension(double tension)
{
    this->Tension = tension;
}

void Ram::Show()
{
    cout << Product::id << setw(12) << Product::Model << setw(8) << TypeOfMemory << setw(16) << TotalCapacity << setw(17) << RamTiming << setw(13) << Tension << setw(10) << Product::prize << setw(7) << Product::amount << endl;
}

void Ram::saveToFile(ofstream & output)
{
    size_t categorySize;
    size_t modelSize;
    size_t typeMemorySize;

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

        typeMemorySize = TypeOfMemory.size();
        output.write((char*) &typeMemorySize, sizeof(typeMemorySize));
        output.write((char*) &TypeOfMemory[0], typeMemorySize);

        output.write((char*) &TotalCapacity, sizeof(TotalCapacity));

        output.write((char*) &RamTiming, sizeof(RamTiming));

        output.write((char*) &Tension, sizeof(Tension));
    }
}

void Ram::readFromFile(ifstream & intput)
{
    size_t modelSize;
    size_t typeMemorySize;

    string model;
    Product::category = "Ram";

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

    intput.read((char*) &typeMemorySize, sizeof(typeMemorySize));
    TypeOfMemory.resize(typeMemorySize);
    intput.read((char*) &TypeOfMemory[0], typeMemorySize);

    intput.read((char*) &TotalCapacity, sizeof(TotalCapacity));

    intput.read((char*) &RamTiming, sizeof(RamTiming));

    intput.read((char*) &Tension, sizeof(Tension));

}

bool Ram::doesExist(string model, string Type, int capacity, int Timing, double tension1, string Socked, int NumberOfCors)
{
    if (model == Product::Model && TypeOfMemory == Type && TotalCapacity == capacity && RamTiming == Timing && Tension == tension1)
    {
        return true;
    }

    return false;
}

void Ram::operator+=(int rhs)
{
    Product::amount += rhs;
}

ostream &operator<<(ostream &out, const Ram &l)
{
    cout << l.Product::Model << setw(8) << l.TypeOfMemory << setw(16) << l.TotalCapacity << setw(17) << l.RamTiming << setw(13) << l.Tension << setw(10) << l.Product::prize << setw(7) << l.Product::amount << endl;

    return out;
}

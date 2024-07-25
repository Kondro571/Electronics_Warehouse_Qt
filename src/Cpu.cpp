#include "Cpu.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Cpu::Cpu()
{
    this->TypeOfProcessor = "";
    this->NumberOfCors = 0;
    this->Socked = "";
    this->CoreTiming = 0;
}

Cpu::Cpu(int id, string name, string model, double prize, int amount, string type, int core, string socked, int timing): Product(id, name, model, prize, amount)
{
    this->TypeOfProcessor = type;
    this->NumberOfCors = core;
    this->Socked = socked;
    this->CoreTiming = timing;
}

Cpu::~Cpu() {}

void Cpu::setTypeOfProcessor(string model)
{
    this->TypeOfProcessor = model;
}

void Cpu::setSocked(string socked)
{
    this->Socked = socked;
}

void Cpu::setCoreTiming(int core)
{
    this->CoreTiming = core;
}

void Cpu::setNumberOfCors(int Screen)
{
    this->NumberOfCors = Screen;
}

string Cpu::getTypeOfProcessor()
{
    return this->TypeOfProcessor;
}

int Cpu::getNumberOfCors()
{
    return this->NumberOfCors;
}

string Cpu::getSocked()
{
    return this->Socked;
}

int Cpu::getCoreTiming()
{
    return this->CoreTiming;
}

void Cpu::Show()
{
    cout << Product::id << setw(12) << Product::Model << setw(7) << TypeOfProcessor << setw(20) << Socked << setw(9) << NumberOfCors << setw(17) << CoreTiming << setw(16) << Product::prize << setw(5) << Product::amount << endl;

}

void Cpu::saveToFile(ofstream & output)
{
    size_t typeSize;
    size_t categorySize;
    size_t modelSize;
    size_t sockedSize;

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

        typeSize = TypeOfProcessor.size();
        output.write((char*) &typeSize, sizeof(typeSize));
        output.write((char*) &TypeOfProcessor[0], typeSize);

        output.write((char*) &NumberOfCors, sizeof(NumberOfCors));

        sockedSize = Socked.size();
        output.write((char*) &sockedSize, sizeof(sockedSize));
        output.write((char*) &Socked[0], sockedSize);

        output.write((char*) &NumberOfCors, sizeof(NumberOfCors));

}

void Cpu::readFromFile(ifstream & intput)
{
    size_t modelSize;
    size_t sockedSize;
    string model;

    Product::category = "Cpu";

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

    intput.read((char*) &modelSize, sizeof(modelSize));
    TypeOfProcessor.resize(modelSize);
    intput.read((char*) &TypeOfProcessor[0], modelSize);

    intput.read((char*) &CoreTiming, sizeof(CoreTiming));

    intput.read((char*) &sockedSize, sizeof(sockedSize));
    Socked.resize(sockedSize);
    intput.read((char*) &Socked[0], sockedSize);

    intput.read((char*) &NumberOfCors, sizeof(NumberOfCors));

}

bool Cpu::doesExist(string model, string Type, int capacity, int Timing, double tension1, string socked, int corNumber)
{
    if (model == Product::Model && TypeOfProcessor == Type && CoreTiming == Timing && NumberOfCors == corNumber && Socked == socked)
    {
        return true;
    }

    return false;
}

ostream &operator<<(ostream &out, const Cpu &l)
{
    out << l.Product::Model << setw(7) << l.TypeOfProcessor << setw(20) << l.Socked << setw(9) << l.NumberOfCors << setw(17) << l.CoreTiming << setw(16) << l.Product::prize << setw(5) << l.Product::amount << endl;

    return out;
}

void Cpu::operator+=(int rhs)
{
    Product::amount += rhs;
}

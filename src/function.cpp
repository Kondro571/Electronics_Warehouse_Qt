#include "function.h"

bool loginAdmin(string email, string passwd)
{
    bool loginSucces = false;
    for (int i = 0; i < Adm.size(); i++)
    {
        if (Adm[i].getEmail() == email && Adm[i].getPasswd() == passwd)
        {
            AdminNumber = i;
            loginSucces = true;
            break;
        }
    }

    return loginSucces;

}

bool addProduct(string model, string type, int capacity, int timing, double tension, double prize, int amount)
{
    for (int i = 0; i < ProductInStorage.size(); i++)
    {
        if (ProductInStorage[i]->doesExist(model, type, capacity, timing, tension, "", 0))
        {
            return false;
        }
    }

    id++;
    ProductInStorage.push_back(new Ram(id, "Ram", model, prize, amount, type, capacity, timing, tension));

    return true;

}

bool addProduct(string model, string type, string socked, int coreNumber, int coreTiming, double prize, int amount)
{
    for (int i = 0; i < ProductInStorage.size(); i++)
    {
        if (ProductInStorage[i]->doesExist(model, type, 0, coreTiming, 0, socked, coreNumber))
        {
            return false;
        }
    }

    id++;
    ProductInStorage.push_back(new Cpu(id, "Cpu", model, prize, amount, type, coreNumber, socked, coreTiming));

    return true;

}

bool addProduct(string model, string chipset, string familiSupport, string socked, double prize, int amount)
{
    for (int i = 0; i < ProductInStorage.size(); i++)
    {
        if (ProductInStorage[i]->doesExist(model,chipset, familiSupport, socked, prize, amount))
        {
            return false;
        }
    }
    id++;


    ProductInStorage.push_back(new Motherboard(id, "Motherboard", model, prize, amount, socked, chipset, familiSupport));

    return true;

}

template < typename T>
    void saveProductToFile(const string &fileName, const vector<T> &products)
    {
        ofstream fd;
        int ProductCount = ProductInStorage.size();
        fd.open(fileName, ios::binary);
        if (!fd.good())
        {
            throw MyException("Error opening file Product");
        }

        fd.write((char*) &ProductCount, sizeof(int));
        for (const auto &prod: products)
        {
            prod->saveToFile(fd);
        }

        fd.close();
    }

bool removeFromShop(int idNumber)
{
    int i = 0;
    bool toRemove = false;
    for (const auto &prod: ProductInStorage)
    {
        if (prod->getId() == idNumber)
        {
            toRemove = true;
            break;
        }

        i++;
    }

    if (toRemove)
    {
        delete ProductInStorage[i];
        ProductInStorage.erase(ProductInStorage.begin() + (i));
        saveProductToFile(fileProduct, ProductInStorage);
        return toRemove;
    }
    else
    {
        return toRemove;
    }
}

bool editProduct(int chosenId, double price, int amount)
{
    for (const auto &prod: ProductInStorage)
    {
        if (prod->getId() == chosenId)
        {
            if (price != 0)
            {
                prod->setPrize(price);
            }

            if (amount != 0)
            {
                prod->setAmount(amount);
            }

            return true;
            break;
        }
    }

    return false;
}

bool editProduct(int chosenId, int amount)
{
    int i = 0;
    for (const auto &prod: ProductInStorage)
    {
        if (prod->getId() == chosenId)
        {
            if (prod->getAmount() <= abs(amount) && amount<0)
            {
                delete ProductInStorage[i];
                ProductInStorage.erase(ProductInStorage.begin() + (i));
                saveProductToFile(fileProduct, ProductInStorage);
                return true;
            }

            *(prod) += amount;

            return true;
            break;
        }

        i++;
    }

    return false;
}

bool checkEmail(string email)
{
    regex pattern("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    if (!regex_match(email, pattern))
    {
        return false;
    }

    return true;
}

bool addAdmin(string email, string passwd)
{
    for (int i = 0; i < Adm.size(); i++)
    {
        if (Adm[i].getEmail() == email)
        {
            return false;
        }
    }

    Adm.push_back(Admin(email, passwd));

    return true;

}

void readAdmin(string file)
{
    ifstream inputAdmin = ifstream(file, ios::binary);
    if (!inputAdmin.good())
    {
        throw MyException("Error opening file Admin");
    }

    inputAdmin.seekg(0, std::ios::end);
    if (inputAdmin.tellg() != 0)
    {
        inputAdmin.seekg(0, std::ios::beg);
        int AdminCount;
        inputAdmin.read((char*) &AdminCount, sizeof(int));

        Admin a;
        for (int i = 0; i < AdminCount; i++)
        {
            Adm.push_back(a);
            Adm[i].readFromFile(inputAdmin);
        }
    }

    inputAdmin.close();
}

void saveAdmin(string file)
{
    ofstream outputAdmin;
    int numberOfAdmin;
    outputAdmin = ofstream(file, ios::binary);
    if (!outputAdmin.good())
    {
        throw std::ios_base::failure("Error opening file Admin");
    }

    numberOfAdmin = Adm.size();

    outputAdmin.write((char*) &numberOfAdmin, sizeof(int));
    for (int i = 0; i < numberOfAdmin; i++)
    {
        Adm[i].saveToFile(outputAdmin);
    }

    outputAdmin.close();
}

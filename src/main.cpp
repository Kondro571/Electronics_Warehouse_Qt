#include "mainwindow.h"
#include <fstream>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "Product.h"
#include "Admin.h"
#include "function.h"

vector<Product*> ProductInStorage;
vector<Admin> Adm;
string fileAdmin, fileProduct;
int AdminNumber = 0;
int id = 0;
int i = 0;
using namespace std;
int main(int argc, char *argv[])
{
    if (argc >= 3)
    {
        fileAdmin = argv[1];
        fileProduct = argv[2];
    }
    else if (argc == 2)
    {
        fileAdmin = argv[1];
        fileProduct = "Product.bin";
    }
    else
    {
        fileAdmin = "Admin.bin";
        fileProduct = "Product.bin";
    }

    try
    {
        readAdmin(fileAdmin);
        readProductFromFile(fileProduct, ProductInStorage);

        QApplication a(argc, argv);

        QTranslator translator;
        const QStringList uiLanguages = QLocale::system().uiLanguages();
        for (const QString &locale: uiLanguages)
        {
            const QString baseName = "Project_jipp_" + QLocale(locale).name();
            if (translator.load(":/i18n/" + baseName))
            {
                a.installTranslator(&translator);
                break;
            }
        }

        MainWindow w;
        w.show();

        return a.exec();
    }
    catch (std::exception &e)
    {
        cerr << "file reading" << e.what() << endl;
        return -1;
    }
    catch (MyException & e)
    {
        cerr << "file reading" << e.what() << endl;
        return -1;
    }
}

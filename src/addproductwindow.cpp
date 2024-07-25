#include "addproductwindow.h"
#include "ui_addproductwindow.h"
#include <QMessageBox>

AddProductWindow::AddProductWindow(QWidget *parent):
    QDialog(parent),
    ui(new Ui::AddProductWindow)
    {
        ui->setupUi(this);
    }

AddProductWindow::~AddProductWindow()
{
    delete ui;
}

void AddProductWindow::on_goBackButton_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

void AddProductWindow::on_addRamButton_clicked()
{
    try
    {
        if ((ui->model1->text()) == "" || (ui->memoryType->text()) == "" || (ui->totalCapacity->value()) <= 0 || (ui->ramTiming->value()) <= 0 || (ui->tension->value()) <= 0 || (ui->prize1->value()) <= 0 || (ui->amount1->value()) <= 0)
        {
            throw MyException("Error: Any argument cannot be empty");
        }

        QString model = ui->model1->text();
        QString memoryType = ui->memoryType->text();
        int totalCapacity = ui->totalCapacity->value();
        int ramTiming = ui->ramTiming->value();
        double tension = ui->tension->value();
        double price = ui->prize1->value();
        int amount = ui->amount1->value();

        if (addProduct(model.toStdString(), memoryType.toStdString(), totalCapacity, ramTiming, tension, price, amount))
        {
            QMessageBox::information(this, "Add Ram", "Succes");
            ui->model1->clear();
            ui->memoryType->clear();
            ui->totalCapacity->setValue(0);
            ui->ramTiming->setValue(0);
            ui->tension->setValue(0);
            ui->prize1->setValue(0);
            ui->amount1->setValue(0);
            saveProductToFile(fileProduct, ProductInStorage);
        }
        else
        {
            throw MyException("This product alredy exist");
        }
    }

    catch (std::ios_base::failure &e)
    {
        QMessageBox::warning(this, "Product", e.what());
    }

    catch (MyException &e)
    {
        QMessageBox::warning(this, "Dane ", QString::fromStdString(e.what()));
    }
}

void AddProductWindow::on_addCpuButton_clicked()
{
    try
    {
        if ((ui->model2->text()) == "" || (ui->processorType->text()) == "" || (ui->socked->text()) == "" || (ui->coreNumber->value()) <= 0 || (ui->coreTiming->value()) <= 0 || (ui->prize2->value()) <= 0 || (ui->amount2->value()) <= 0)
        {
            throw MyException("Error: Any argument cannot be empty");
        }

        QString model = ui->model2->text();
        QString processorType = ui->processorType->text();
        QString socked = ui->socked->text();
        int coreNumber = ui->coreNumber->value();
        int coreTiming = ui->coreTiming->value();
        double price = ui->prize2->value();
        int amount = ui->amount2->value();

        if (addProduct(model.toStdString(), processorType.toStdString(), socked.toStdString(), coreNumber, coreTiming, price, amount))
        {
            QMessageBox::information(this, "Add Cpu", "Succes");
            ui->model2->clear();
            ui->processorType->clear();
            ui->socked->clear();
            ui->coreNumber->setValue(0);
            ui->coreTiming->setValue(0);
            ui->prize2->setValue(0);
            ui->amount2->setValue(0);
            saveProductToFile(fileProduct, ProductInStorage);
        }
        else
        {
            throw MyException("This product alredy exist");
        }
    }

    catch (std::ios_base::failure &e)
    {
        QMessageBox::warning(this, "File writing product", e.what());
    }

    catch (MyException &e)
    {
        QMessageBox::warning(this, "Product", QString::fromStdString(e.what()));
    }
}

void AddProductWindow::on_addMotherboardButton_clicked()
{
    try
    {
        if ((ui->model3->text()) == "" || (ui->chipset->text()) == "" || (ui->cpuFamili->text()) == "" || (ui->procesorSocked->text()) == "" || (ui->prize3->value()) <= 0 || (ui->amount3->value()) <= 0)
        {
            throw MyException("Error: Any argument cannot be empty");
        }

        QString model = ui->model3->text();
        QString chipset = ui->chipset->text();
        QString famili = ui->cpuFamili->text();
        QString socked = ui->procesorSocked->text();
        double price = ui->prize3->value();
        int amount = ui->amount3->value();

        if (addProduct(model.toStdString(), chipset.toStdString(), famili.toStdString(), socked.toStdString(), price, amount))
        {
            QMessageBox::information(this, "Add Motherboard", "Succes");
            ui->model3->clear();
            ui->chipset->clear();
            ui->cpuFamili->clear();
            ui->procesorSocked->clear();
            ui->prize3->setValue(0);
            ui->amount3->setValue(0);
            saveProductToFile(fileProduct, ProductInStorage);
        }
        else
        {
            throw MyException("This product alredy exist");
        }
    }

    catch (std::ios_base::failure &e)
    {
        QMessageBox::warning(this, "File writing product", e.what());
    }

    catch (MyException &e)
    {
        QMessageBox::warning(this, "Product", QString::fromStdString(e.what()));
    }
}

void AddProductWindow::closeEvent(QCloseEvent *event)
{
    QWidget *parent = this->parentWidget();
    parent->show();

}

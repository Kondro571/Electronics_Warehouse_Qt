#include "RemoveFromStoreWindow.h"
#include "ui_RemoveFromStoreWindow.h"
#include <QMessageBox>

RemoveFromStoreWindow::RemoveFromStoreWindow(QWidget *parent):
    QDialog(parent),
    ui(new Ui::RemoveFromStoreWindow)
    {
        ui->setupUi(this);
        for (Product *product: ProductInStorage)
        {
            ui->idToRemove->addItem(QString::number(product->getId()));
        }

        ui->categoryProduct->addItem("Ram");
        ui->categoryProduct->addItem("Cpu");
        ui->categoryProduct->addItem("Motherboard");
    }

RemoveFromStoreWindow::~RemoveFromStoreWindow()
{
    delete ui;
}

void RemoveFromStoreWindow::on_goBack_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

void RemoveFromStoreWindow::on_removeButton_clicked()
{
    try
    {
        if ((ui->idToRemove->currentText()).toInt() < 0)
        {
            throw MyException("Enter id");
        }

        int id = (ui->idToRemove->currentText()).toInt();
        if (removeFromShop(id))
        {
            ui->idToRemove->clear();

            for (Product *product: ProductInStorage)
            {
                ui->idToRemove->addItem(QString::number(product->getId()));
            }
            set_TableWidget((ui->categoryProduct->currentText()).toStdString());
        }
        else
        {
            throw MyException("Wrong id");
        }
    }

    catch (MyException &e)
    {
        QMessageBox::warning(this, "Add Admin account",QString::fromStdString(e.what()));
    }

    catch (std::ios_base::failure &e)
    {
        QMessageBox::warning(this, "File writing", e.what());
    }
}

void RemoveFromStoreWindow::set_TableWidget(std::string arg)
{
    try
    {
        int i = 0;
        int AmountOfRam = 0, AmountOfCpu = 0, AmountOfMotherboard = 0;

        for (const auto &prod: ProductInStorage)
        {
            if (prod->getCategory() == "Ram")
            {
                AmountOfRam++;
            }
            else if (prod->getCategory() == "Cpu")
            {
                AmountOfCpu++;
            }
            else if (prod->getCategory() == "Motherboard")
            {
                AmountOfMotherboard++;
            }
        }

        if (arg == "Ram")
        {
            ui->tableWidget->setRowCount(AmountOfRam);
        }
        else if (arg == "Cpu")
        {
            ui->tableWidget->setRowCount(AmountOfCpu);
        }
        else if (arg == "Motherboard")
        {
            ui->tableWidget->setRowCount(AmountOfMotherboard);
        }

        for (const auto &prod: ProductInStorage)
        {
            if (prod->getCategory() == arg)
            {
                ui->tableWidget->model()->setData(ui->tableWidget->model()->index(i, 0), prod->getId());
                ui->tableWidget->model()->setData(ui->tableWidget->model()->index(i, 1), QString::fromStdString(prod->getModel()));
                ui->tableWidget->model()->setData(ui->tableWidget->model()->index(i, 2), prod->getPrize());
                ui->tableWidget->model()->setData(ui->tableWidget->model()->index(i, 3), prod->getAmount());
                i++;
            }
        }
    }

    catch (std::bad_cast &e)
    {
        QMessageBox::warning(this, "Error: Invalid dynamic cast", e.what());
    }
}

void RemoveFromStoreWindow::on_categoryProduct_currentTextChanged(const QString &arg1)
{
    set_TableWidget((ui->categoryProduct->currentText()).toStdString());
}

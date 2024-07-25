#include "editproductwindow.h"
#include "ui_editproductwindow.h"
#include <QMessageBox>

EditProductWindow::EditProductWindow(QWidget *parent):
    QDialog(parent),
    ui(new Ui::EditProductWindow)
    {
        ui->setupUi(this);

        for (Product *product: ProductInStorage)
        {
            ui->id1->addItem(QString::number(product->getId()));
            ui->id2->addItem(QString::number(product->getId()));
        }

        ui->categoryProduct->addItem("Ram");
        ui->categoryProduct->addItem("Cpu");
        ui->categoryProduct->addItem("Motherboard");
    }

EditProductWindow::~EditProductWindow()
{
    delete ui;
}

void EditProductWindow::on_goBack_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

void EditProductWindow::on_changeButton1_clicked()
{
    try
    {
        if ((ui->id1->currentText()).toInt() < 0)
        {
            throw MyException("need Id");
        }

        if (ui->price->value() <= 0 && ui->amount1->value() <= 0)
        {
            throw MyException("Add at last one pool");
        }

        int id = (ui->id1->currentText()).toInt();
        double price = ui->price->value();
        int amount = ui->amount1->value();
        if (editProduct(id, price, amount))
        {
            QMessageBox::information(this, "Edit product", "Product was change");
            saveProductToFile(fileProduct, ProductInStorage);

            ui->price->setValue(0);
            ui->amount1->setValue(0);
            set_TableWidget("Ram");
        }
        else
        {
            throw MyException("Product witch this id don't exist");
        }
    }

    catch (MyException &e)
    {
        QMessageBox::warning(this, "Add Admin account", QString::fromStdString(e.what()));
    }

    catch (std::ios_base::failure &e)
    {
        QMessageBox::warning(this, "File writing", e.what());
    }
}

void EditProductWindow::on_changeButton2_clicked()
{
    try
    {
        if ((ui->id2->currentText()).toInt() < 0)
        {
            throw MyException("how the hel you manage to give number below 0");
        }

        if (ui->amount2->value() <= 0)
        {
            throw MyException("Enter amount to add");
        }

        int id = (ui->id2->currentText()).toInt();
        int amount = ui->amount2->value();
        if (editProduct(id, amount))
        {
            QMessageBox::information(this, "Edit product", "Product was change");

            ui->amount2->setValue(0);
            set_TableWidget((ui->categoryProduct->currentText()).toStdString());
        }
        else
        {
            throw MyException("Product witch this id don't exist");
        }
    }

    catch (MyException &e)
    {
        QMessageBox::warning(this, "Add Admin account", QString::fromStdString(e.what()));
    }

    catch (std::ios_base::failure &e)
    {
        QMessageBox::warning(this, "File writing", e.what());
    }
}

void EditProductWindow::set_TableWidget(std::string arg)
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

void EditProductWindow::on_categoryProduct_currentTextChanged(const QString &arg1)
{
    set_TableWidget((ui->categoryProduct->currentText()).toStdString());
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QCloseEvent>

int l = 0;
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    try
    {
        if ((ui->lineEdit_email->text()) == "" || (ui->lineEdit_passwd->text()) == "")
        {
            throw MyException("Every pool need to be filed");
        }

        l = 0;
        QString email = ui->lineEdit_email->text();
        QString passwd = ui->lineEdit_passwd->text();

        if (loginAdmin(email.toStdString(), passwd.toStdString()))
        {
            ui->lineEdit_email->clear();
            ui->lineEdit_passwd->clear();

            l = 1;
            this->hide();
            AdminOptionWindow adminn;
            adminn.setModal(true);
            adminn.exec();
        }
        else
        {
            throw MyException("wrong email or password");
        }
    }

    catch (MyException & e)
    {
        QMessageBox::warning(this, "Add Admin account", QString::fromStdString(e.what()));
    }

    catch (std::ios_base::failure &e)
    {
        QMessageBox::warning(this, "File writing", e.what());
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (l == 0)
    {
        ProductInStorage.erase(std::remove_if(ProductInStorage.begin(), ProductInStorage.end(), [](Product *product)
        {
            return !product;
}), ProductInStorage.end());
        for (Product *product: ProductInStorage)
        {
            try
            {
                delete product;
            }

            catch (std::exception &e)
            {
                QMessageBox::warning(this, "Delete", e.what());
            }
        }
    }

    event->accept();
}

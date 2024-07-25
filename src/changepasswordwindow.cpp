#include "changepasswordwindow.h"
#include "ui_changepasswordwindow.h"
#include <QMessageBox>

ChangePasswordWindow::ChangePasswordWindow(QWidget *parent):
    QDialog(parent),
    ui(new Ui::ChangePasswordWindow)
    {
        ui->setupUi(this);
    }

ChangePasswordWindow::~ChangePasswordWindow()
{
    delete ui;
}

void ChangePasswordWindow::on_goBack_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

void ChangePasswordWindow::on_changePasswordButton_clicked()
{
    try
    {
        if ((ui->oldPassword->text() == "" || ui->newPassword1->text() == "" || ui->newPassword2->text() == ""))
        {
            throw MyException("Some pool are empty");
        }

        QString oldPassword = ui->oldPassword->text();
        if (Adm[AdminNumber].getPasswd() == oldPassword.toStdString())
        {
            QString newPassword1 = ui->newPassword1->text();
            QString newPassword2 = ui->newPassword2->text();

            if (newPassword1 == newPassword2)
            {
                Adm[AdminNumber].setPassword(newPassword1.toStdString());
                QMessageBox::information(this, "Add Admin account", "Password succesfuly changed");
                ui->newPassword1->clear();
                ui->newPassword2->clear();
                ui->oldPassword->clear();
                saveAdmin(fileAdmin);
            }
            else
            {
                throw MyException("Two passwords are not the same");
            }
        }
        else
        {
            throw MyException("You enter Wrong password");
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

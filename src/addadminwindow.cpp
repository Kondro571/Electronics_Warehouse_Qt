#include "addadminwindow.h"
#include "ui_addadminwindow.h"
#include <QMessageBox>

AddAdminWindow::AddAdminWindow(QWidget *parent):
    QDialog(parent),
    ui(new Ui::AddAdminWindow)
    {
        ui->setupUi(this);
    }

AddAdminWindow::~AddAdminWindow()
{
    delete ui;
}

void AddAdminWindow::on_addAdminButton_clicked()
{
    try
    {
        if ((ui->email->text()) == "" || (ui->password1->text()) == "" || (ui->password1->text()) == "")
        {
            throw MyException("Error: Any argument cannot be empty");
        }

        QString email = ui->email->text();
        QString password1 = ui->password1->text();
        QString password2 = ui->password2->text();
        if (checkEmail(email.toStdString()))
        {
            if (password1 != password2)
            {
                throw MyException("Passwords are different");

                ui->password2->clear();
            }
            else
            {
                if (addAdmin(email.toStdString(), password1.toStdString()))
                {
                    QMessageBox::information(this, "Add Admin account", "New acount was added");

                    saveAdmin(fileAdmin);

                    ui->password1->clear();
                    ui->password2->clear();
                    ui->email->clear();
                }
                else
                {
                    throw MyException("This email is used by someon else");
                }
            }
        }
        else
        {
            throw MyException("Wrong email structure");
        }
    }
    catch(MyException &e){
        QMessageBox::warning(this, "Dane ", QString::fromStdString(e.what()));
    }
}

void AddAdminWindow::on_goBack_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

#include "adminoptionwindow.h"
#include "ui_adminoptionwindow.h"
#include <QCloseEvent>
#include <QMessageBox>

AdminOptionWindow::AdminOptionWindow(QWidget *parent, Qt::WindowType type):
    QDialog(parent, type),
    ui(new Ui::AdminOptionWindow)
    {
        ui->setupUi(this);
        this->setWindowTitle("Admin Option");
    }

AdminOptionWindow::~AdminOptionWindow()
{
    delete ui;
}

void AdminOptionWindow::on_AddToStoreButton_clicked()
{
    //this->hide();

    AddProductWindow *addProduct = new AddProductWindow(this);
    addProductWindows.push_back(addProduct);
    addProduct->show();
}

void AdminOptionWindow::on_RemoveFromStoreButton_clicked()
{
    //hide();

    RemoveFromStoreWindow *removeProduct = new RemoveFromStoreWindow(this);
    removeProductWindows.push_back(removeProduct);
    removeProduct->show();
}

void AdminOptionWindow::on_ShowMagazineButton_clicked()
{
    //hide();

    DisplayProductWindow *displayProduct = new DisplayProductWindow(this);
    displayProductWindows.push_back(displayProduct);
    displayProduct->show();

}

void AdminOptionWindow::on_AddAdminButton_clicked()
{
    //hide();

    AddAdminWindow *addAdmin = new AddAdminWindow(this);
    addAdminWindows.push_back(addAdmin);
    addAdmin->show();

}

void AdminOptionWindow::on_ChangePasswordButton_clicked()
{
    // hide();

    ChangePasswordWindow *changePassword = new ChangePasswordWindow(this);
    changePasswordWindows.push_back(changePassword);
    changePassword->show();
}

void AdminOptionWindow::on_editButton_clicked()
{
    //hide();

    EditProductWindow *editProduct = new EditProductWindow(this);
    editProductWindows.push_back(editProduct);
    editProduct->show();
}

void AdminOptionWindow::on_exitButton_clicked()
{
    close();
}

void AdminOptionWindow::closeEvent(QCloseEvent *event)
{
    for (DisplayProductWindow *displayProduct: displayProductWindows)
    {
        delete displayProduct;
    }

    displayProductWindows.clear();

    for (AddProductWindow *addPr: addProductWindows)
    {
        delete addPr;
    }

    addProductWindows.clear();

    for (RemoveFromStoreWindow *remPr: removeProductWindows)
    {
        delete remPr;
    }

    removeProductWindows.clear();

    for (AddAdminWindow *addAdm: addAdminWindows)
    {
        delete addAdm;
    }

    addAdminWindows.clear();

    for (ChangePasswordWindow *changePass: changePasswordWindows)
    {
        delete changePass;
    }

    changePasswordWindows.clear();

    for (EditProductWindow *edit: editProductWindows)
    {
        delete edit;
    }

    editProductWindows.clear();

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
            QMessageBox::warning(this, "qweqwe", e.what());
        }
    }

    ProductInStorage.clear();

    event->accept();
}

#include "displayproductwindow.h"
#include "ui_displayproductwindow.h"
#include <QMessageBox>

DisplayProductWindow::DisplayProductWindow(QWidget *parent):
    QDialog(parent),
    ui(new Ui::DisplayProductWindow)
    {
        ui->setupUi(this);
        set_TableWidget();
    }

DisplayProductWindow::~DisplayProductWindow()
{
    delete ui;
}

void DisplayProductWindow::set_TableWidget()
{
    try
    {
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

        ui->tableWidgetRam->setRowCount(AmountOfRam);
        ui->tableWidgetCpu->setRowCount(AmountOfCpu);
        ui->tableWidgetMotherboard->setRowCount(AmountOfMotherboard);

        int ramI = 0, cpuI = 0, boardI = 0;
        for (const auto &prod: ProductInStorage)
        {
            if (prod->getCategory() == "Ram")
            {
                Ram *r = dynamic_cast<Ram*> (prod);
                ui->tableWidgetRam->model()->setData(ui->tableWidgetRam->model()->index(ramI, 0), prod->getId());
                ui->tableWidgetRam->model()->setData(ui->tableWidgetRam->model()->index(ramI, 1), QString::fromStdString(prod->getModel()));
                ui->tableWidgetRam->model()->setData(ui->tableWidgetRam->model()->index(ramI, 2), QString::fromStdString(r->getMemory()));
                ui->tableWidgetRam->model()->setData(ui->tableWidgetRam->model()->index(ramI, 3), r->getTotalCapacity());
                ui->tableWidgetRam->model()->setData(ui->tableWidgetRam->model()->index(ramI, 4), r->getRamTiming());
                ui->tableWidgetRam->model()->setData(ui->tableWidgetRam->model()->index(ramI, 5), r->getTension());
                ui->tableWidgetRam->model()->setData(ui->tableWidgetRam->model()->index(ramI, 6), prod->getPrize());
                ui->tableWidgetRam->model()->setData(ui->tableWidgetRam->model()->index(ramI, 7), prod->getAmount());
                r = nullptr;
                delete r;
                ramI++;
            }
            else if (prod->getCategory() == "Cpu")
            {
                Cpu *c = dynamic_cast<Cpu*> (prod);
                ui->tableWidgetCpu->model()->setData(ui->tableWidgetCpu->model()->index(cpuI, 0), prod->getId());
                ui->tableWidgetCpu->model()->setData(ui->tableWidgetCpu->model()->index(cpuI, 1), QString::fromStdString(prod->getModel()));
                ui->tableWidgetCpu->model()->setData(ui->tableWidgetCpu->model()->index(cpuI, 2), QString::fromStdString(c->getTypeOfProcessor()));
                ui->tableWidgetCpu->model()->setData(ui->tableWidgetCpu->model()->index(cpuI, 3), QString::fromStdString(c->getSocked()));
                ui->tableWidgetCpu->model()->setData(ui->tableWidgetCpu->model()->index(cpuI, 4), c->getNumberOfCors());
                ui->tableWidgetCpu->model()->setData(ui->tableWidgetCpu->model()->index(cpuI, 5), c->getCoreTiming());
                ui->tableWidgetCpu->model()->setData(ui->tableWidgetCpu->model()->index(cpuI, 6), prod->getPrize());
                ui->tableWidgetCpu->model()->setData(ui->tableWidgetCpu->model()->index(cpuI, 7), prod->getAmount());
                c = nullptr;
                delete c;
                cpuI++;
            }
            else if (prod->getCategory() == "Motherboard")
            {
                Motherboard *m = dynamic_cast<Motherboard*> (prod);
                ui->tableWidgetMotherboard->model()->setData(ui->tableWidgetMotherboard->model()->index(boardI, 0), prod->getId());
                ui->tableWidgetMotherboard->model()->setData(ui->tableWidgetMotherboard->model()->index(boardI, 1), QString::fromStdString(prod->getModel()));
                ui->tableWidgetMotherboard->model()->setData(ui->tableWidgetMotherboard->model()->index(boardI, 2), QString::fromStdString(m->getCpuFamiliSupport()));
                ui->tableWidgetMotherboard->model()->setData(ui->tableWidgetMotherboard->model()->index(boardI, 3), QString::fromStdString(m->getChipset()));
                ui->tableWidgetMotherboard->model()->setData(ui->tableWidgetMotherboard->model()->index(boardI, 4), QString::fromStdString(m->getProcesorSocked()));
                ui->tableWidgetMotherboard->model()->setData(ui->tableWidgetMotherboard->model()->index(boardI, 5), prod->getPrize());
                ui->tableWidgetMotherboard->model()->setData(ui->tableWidgetMotherboard->model()->index(boardI, 6), prod->getAmount());
                m = nullptr;
                delete m;
                boardI++;
            }
        }
    }

    catch (std::bad_cast &e)
    {
        QMessageBox::warning(this, "Error: Invalid dynamic cast", e.what());
    }
}

void DisplayProductWindow::on_goBack_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

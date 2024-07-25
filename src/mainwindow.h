/**
 * @file MainWindow.h
 * @brief The header file for the MainWindow class
 * @author John Doe
 * @date 01/01/2023
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adminoptionwindow.h"
#include "function.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief A QMainWindow subclass for the main application window
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new MainWindow object
     * @param parent The parent widget
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the MainWindow object
     */
    ~MainWindow();

private slots:
    /**
     * @brief Handles the pushButton_login's clicked signal
     */
    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
    AdminOptionWindow *AdminOption;
    /**
     * @brief Handles the close event
     */
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H

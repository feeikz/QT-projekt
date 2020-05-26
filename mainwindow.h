#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QButtonGroup>
#include <QRadioButton>
#include <QSpinBox>
#include <QGroupBox>
#include <QPushButton>
#include <QMessageBox>
#include <QCheckBox>
#include <QComboBox>
#include <QPixmap>
#include <QTabWidget>
#include <QTextEdit>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QMainWindow>
#include <QMessageBox>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    QMenu* filemenu;
    QAction* exit_act,*about_act;
    //QFormLayout* formlayout;
    QFrame* main_frame;
    QGridLayout *layout;
    QLabel *moveF, *moveL, *moveR, *moveB, *jump, *tactical,
    *ultimate,*zoom,*shoot,*reload, *AA ,*vol_light_e,*ds,*fow,*sprint,
    *crouch,*resolution,*master,*effects,*volume,*voice;
    QLineEdit * moveF_edit, *moveL_edit, *moveR_edit,*moveB_edit,*jump_edit,
    *tactical_e,*ultimate_e,*zoom_e,*shoot_e,*reload_e,*sprint_e,*crouch_e;
    QTabWidget *tab();
    QTextEdit *textArea;
    QWidget *friends(), *game(), *poznamka(), *others();
    QGroupBox *movementGroup(), *abilitiesGroup(), *screenGroup(), *sounds();
    QRadioButton *vol_light, *rUcet,*r1,*r2,*r3,*r4,*r5,*r6, *ds_e;
    QCheckBox *c1;
    QSlider *slider,*master_s,*volume_s,*voice_s,*effects_s;
    QComboBox *resolutionBox;
    ~MainWindow();
    QWidget *options();

private:
   void fillTable(QTableView* table);
   void createMenu();



};

#endif // MAINWINDOW_H

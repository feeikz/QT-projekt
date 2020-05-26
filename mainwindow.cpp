#include "mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QHeaderView>
#include <QMenuBar>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMenu();

    setWindowTitle(tr("Môj projekt"));
    resize(640, 480);
    layout = new QGridLayout;
    layout->addWidget(tab(), 0,0);
    main_frame=new QFrame();
    main_frame->setLayout(layout);
    setCentralWidget(main_frame);


}

void MainWindow::createMenu()
{
    filemenu = new QMenu("&Súbor");
    exit_act = new QAction("&Koniec", this);
    about_act = new QAction("&About",this);
    filemenu->addAction(exit_act);
    filemenu->addAction(about_act);

    connect(exit_act, SIGNAL(triggered()), this, SLOT(close()));
   // connect(about_act, SIGNAL(triggered()), this, SLOT(about()));
    menuBar()->addMenu(filemenu);
}




QTabWidget *MainWindow::tab()
{
    QTabWidget *tabWidget = new QTabWidget;
    tabWidget->addTab(options(), tr("Options"));
    tabWidget->addTab(poznamka(), tr("Others"));
    tabWidget->addTab(others(), tr("Game"));

    return tabWidget;
}

QWidget *MainWindow::options()
{
    QGridLayout *optionsLayout = new QGridLayout;
    QGroupBox *groupBox = new QGroupBox();
    groupBox->setFlat(true);

    optionsLayout->addWidget(movementGroup(),0,0);

    optionsLayout->addWidget(abilitiesGroup(),0,1);
    optionsLayout->addWidget(screenGroup(),1,0);
    optionsLayout->addWidget(sounds(),1,1);




    groupBox->setLayout(optionsLayout);

    return groupBox;
}



QGroupBox * MainWindow::movementGroup()
{
    QGridLayout *receiverLayout = new QGridLayout;
    QGroupBox * groupBox = new QGroupBox(tr("Movement"));
    groupBox->setFlat(true);

    moveF = new QLabel("Move Forward :");
    moveL = new QLabel("Move left :");
    moveR = new QLabel("Move right :");
    moveB = new QLabel("Move back :");
    jump = new QLabel("Jump :");


    moveF_edit = new QLineEdit();
    moveF_edit->setPlaceholderText("W");
    moveL_edit = new QLineEdit();
    moveL_edit->setPlaceholderText("A");
    moveR_edit = new QLineEdit();
    moveR_edit->setPlaceholderText("D");
    moveB_edit = new QLineEdit();
    moveB_edit->setPlaceholderText("S");
    jump_edit = new QLineEdit();
    jump_edit->setPlaceholderText("Space");


    receiverLayout->addWidget(moveF, 0, 0);
    receiverLayout->addWidget(moveF_edit, 0, 1);

    receiverLayout->addWidget(moveL, 1, 0);
    receiverLayout->addWidget(moveL_edit, 1, 1);

    receiverLayout->addWidget(moveR, 2, 0);
    receiverLayout->addWidget(moveR_edit, 2, 1);

    receiverLayout->addWidget(moveB, 3, 0);
    receiverLayout->addWidget(moveB_edit, 3, 1);

    receiverLayout->addWidget(jump, 4, 0);
    receiverLayout->addWidget(jump_edit, 4, 1);
    groupBox->setLayout(receiverLayout);


    return groupBox;

}

QGroupBox * MainWindow::abilitiesGroup()
{
    QGridLayout *receiverLayout = new QGridLayout;
    QGroupBox * groupBox = new QGroupBox(tr("Weapon Abilities"));
    groupBox->setFlat(true);

    tactical = new QLabel("Tactical Ability :");
    ultimate = new QLabel("Ultimate Ability :");
    zoom = new QLabel("Zoom :");
    shoot = new QLabel("Shoot :");
    reload = new QLabel("Reload :");


    tactical_e = new QLineEdit();
    tactical_e->setPlaceholderText("Q");
    ultimate_e = new QLineEdit();
    ultimate_e->setPlaceholderText("R");
    zoom_e = new QLineEdit();
    zoom_e->setPlaceholderText("Z");
    reload_e = new QLineEdit();
    reload_e->setPlaceholderText("R");



    receiverLayout->addWidget(tactical, 0, 0);
    receiverLayout->addWidget(tactical_e, 0, 1);

    receiverLayout->addWidget(ultimate, 1, 0);
    receiverLayout->addWidget(ultimate_e, 1, 1);

    receiverLayout->addWidget(zoom, 2, 0);
    receiverLayout->addWidget(zoom_e, 2, 1);

    receiverLayout->addWidget(reload, 3, 0);
    receiverLayout->addWidget(reload_e, 3, 1);

    groupBox->setLayout(receiverLayout);


    return groupBox;

}

QGroupBox * MainWindow::screenGroup()
{
    QGridLayout *receiverLayout = new QGridLayout;
    QGroupBox * groupBox = new QGroupBox(tr("Screen"));
    groupBox->setFlat(true);

    resolution = new QLabel(tr("Resolution:"));
    QComboBox *resolutionBox = new QComboBox();
    resolutionBox->addItem(tr("720x480"));
    resolutionBox->addItem(tr("1280x720"));
    resolutionBox->addItem(tr("1920x1080"));
    resolutionBox->addItem(tr("3840x2160"));


    AA = new QLabel("Anti Aliasing :");;
    r1 = new QRadioButton("2x",this);
    r2 = new QRadioButton("4x",this);
    r3 = new QRadioButton("8x",this);
    r4 = new QRadioButton("16x",this);


    QHBoxLayout *hbox = new QHBoxLayout;
        hbox->addWidget(AA);
        hbox->addWidget(r1);
        hbox->addWidget(r2);
        hbox->addWidget(r3);
        hbox->addWidget(r4);
        hbox->addStretch(1);


     QHBoxLayout *hbox2 = new QHBoxLayout;
     vol_light_e =new QLabel(tr("Volumetric Lightening:"));
     vol_light = new QRadioButton(this);

     hbox2->addWidget(vol_light_e);
     hbox2->addWidget(vol_light);

     QHBoxLayout *hbox3 = new QHBoxLayout;
     ds = new QLabel(tr("Dynamic Shadows:"));
     ds_e = new QRadioButton(this);

     hbox3->addWidget(ds);
     hbox3->addWidget(ds_e);

    QHBoxLayout *hbox4 = new QHBoxLayout;
     fow = new QLabel(tr("Field of view:"));
     slider = new QSlider(Qt::Horizontal);

     hbox4->addWidget(fow);
     hbox4->addWidget(slider);

     receiverLayout->addLayout(hbox,0,0);
     receiverLayout->addLayout(hbox2,1,0);
     receiverLayout->addLayout(hbox3,2,0);
     receiverLayout->addLayout(hbox4,3,0);
     receiverLayout->addWidget(resolution,4,0);
     receiverLayout->addWidget(resolutionBox,4,1);

     groupBox->setLayout(receiverLayout);
     return groupBox;

}

QGroupBox * MainWindow::sounds()
{
    QGridLayout *receiverLayout = new QGridLayout;
    QGroupBox *groupBox = new QGroupBox(tr("Sounds"));
    groupBox->setFlat(true);

    QHBoxLayout *hbox = new QHBoxLayout;
    QHBoxLayout *hbox2 = new QHBoxLayout;
    QHBoxLayout *hbox3 = new QHBoxLayout;
    QHBoxLayout *hbox4 = new QHBoxLayout;
     master = new QLabel(tr("Master Sounds:"));
     master_s = new QSlider(Qt::Horizontal);

     effects = new QLabel(tr("Effects Sounds:"));
     effects_s = new QSlider(Qt::Horizontal);

     volume = new QLabel(tr("Music Volume:"));
     volume_s = new QSlider(Qt::Horizontal);

     voice = new QLabel(tr("Voice Volume:"));
     voice_s = new QSlider(Qt::Horizontal);


     hbox->addWidget(master);
     hbox->addWidget(master_s);

     hbox2->addWidget(effects);
     hbox2->addWidget(effects_s);

     hbox3->addWidget(volume);
     hbox3->addWidget(volume_s);

     hbox4->addWidget(voice);
     hbox4->addWidget(voice_s);


    receiverLayout->addLayout(hbox,0,0);
    receiverLayout->addLayout(hbox2,1,0);
    receiverLayout->addLayout(hbox3,2,0);
    receiverLayout->addLayout(hbox4,3,0);
    groupBox->setLayout(receiverLayout);
    return groupBox;
}


QWidget *MainWindow::poznamka()
{
    QGroupBox *groupBox = new QGroupBox(tr("Priatelia"));
    groupBox->setFlat(true);

    textArea = new QTextEdit();
    QPushButton *button = new QPushButton("Uložiť", this);

    QGridLayout *balikLayout = new QGridLayout;
    balikLayout->addWidget(textArea, 0, 0);
    balikLayout->addWidget(button, 1, 0);
    groupBox->setLayout(balikLayout);
    return groupBox;
}

QWidget *MainWindow::others()
{
    QGroupBox *groupBox = new QGroupBox(tr("Informácie o dobierke"));
    groupBox->setFlat(true);

    sprint = new QLabel(tr("Sprint:"));
    sprint_e = new QLineEdit;
    sprint_e->setPlaceholderText("Shift");


    crouch = new QLabel(tr("Crouch:"));
    crouch_e = new QLineEdit;
    crouch_e->setPlaceholderText("CTRL");

    QGridLayout *balikLayout = new QGridLayout;

    balikLayout->addWidget(sprint, 0, 0);
    balikLayout->addWidget(sprint_e, 0, 1);
    balikLayout->addWidget(crouch, 1, 0);
    balikLayout->addWidget(crouch_e, 1, 1);

    groupBox->setLayout(balikLayout);
    return groupBox;
}

QWidget *MainWindow::game()
{
    QGridLayout *receiverLayout = new QGridLayout;
    QGroupBox * groupBox = new QGroupBox(tr("Game"));
    groupBox->setFlat(true);

    return groupBox;
}



MainWindow::~MainWindow()
{

}

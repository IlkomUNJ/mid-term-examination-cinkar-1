#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create a central widget to hold the layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *subLayout = new QHBoxLayout();

    // Create and add the drawing canvas to the top of the layout
    DrawingCanvas *m_canvas = new DrawingCanvas(this);
    mainLayout->addWidget(m_canvas);

    // Create a button and a layout for the bottom of the window
    m_clearButton = new QPushButton("Clear Canvas", this);
    m_detectButton = new QPushButton("Detect Segment", this);
    m_drawButton = new QPushButton("Draw Lines", this);

    mainLayout->addLayout(subLayout, 1);
    subLayout->addWidget(m_drawButton, 0);
    subLayout->addWidget(m_detectButton, 0);
    subLayout->addWidget(m_clearButton, 0);

    // Connect the button's clicked signal to the slot that clears the canvas
    connect(m_clearButton, &QPushButton::clicked, m_canvas, &DrawingCanvas::clearPoints);
    connect(m_drawButton, &QPushButton::clicked, m_canvas, &DrawingCanvas::paintLines);
    connect(m_detectButton, &QPushButton::clicked, m_canvas, &DrawingCanvas::segmentDetection);


    // Set the layout for the central widget and set it as the main window's central widget
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    setWindowTitle("Drawing Canvas");
    // setFixedSize(300, 300);

    // 🔹 Set ukuran awal window
    resize(800, 800); // atau bisa pakai setFixedSize() kalau kamu mau fix
    qDebug() << "Constructor: Ukuran awal window =" << width() << "x" << height();


    m_canvas->addMatchedWindow(QRect(0, 0, 800, 800));

}

MainWindow::~MainWindow()
{
}

#include <QApplication>
#include <QPainter>
#include <QSlider>
#include <QWidget>
#include <QPaintEvent>
#include <QLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QGradient>
#include <iostream>
#include <QObject>

class Widget : public QWidget{
//Q_OBJECT
public:

    Widget(QWidget *parent):QWidget(parent) {
        slider->setMaximum(100);
        slider->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        slider->setFixedSize(200,20);
        Grid->addWidget(slider,0,0,Qt::AlignBottom);
        slider->show();
        connect(slider, &QSlider::valueChanged, this, &Widget::changeColor);
        update();
    };

    void paintEvent(QPaintEvent *event){
        Q_UNUSED(event)
        // QColor red(255,0,0);
        // QColor yellow(255,255,0);
        // QColor green(0,255,0);
        QPainter circle(this);
        circle.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
        circle.setBrush(QBrush(*currentColor));
        circle.drawEllipse(50,25,150,150);
    }

    ~Widget(){};

public slots:
    void changeColor() {
        int value = slider->value();
        std::cout << value << std::endl;
        if(value < 50){
            g = 255;
            r=value*5.1;}
        if(value == 50)
            g = r = 255;
        if(value > 50){
            r = 255;
            g=255-(value-50)*5.1;}
        currentColor->setRgb(r,g,0);
        update();
    }

private:
    int r{0};
    int g{255};
    QSlider* slider = new QSlider(Qt::Horizontal, this);
    QGridLayout* Grid = new QGridLayout(this);
    QColor* currentColor = new QColor();
};

// Widget::Widget(QWidget *parent):QWidget(parent) {
//     slider->setMaximum(99);
//     slider->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
//     slider->setFixedSize(200,20);
//     Grid->addWidget(slider,0,0,Qt::AlignBottom);
//     slider->show();
//     //connect(slider, &QSlider::valueChanged, this, &Widget::changeColor);
// }

// void Widget::changeColor() {
//     std::cout << slider->value() << std::endl;
//     update();
// }


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget* w = new Widget(nullptr);
    w->setMinimumSize(250,300);
    w->setMaximumSize(250,300);

    // QSlider* s = new QSlider;
    // s->setMaximum(99);
    // s->setMinimumSize(200,50);
    // s->setOrientation(Qt::Horizontal);
    // QGridLayout* layout = new QGridLayout(w);
    // layout->addWidget(s,0,0,Qt::AlignBottom);
    // QObject::connect(s, &QSlider::valueChanged, w, &Widget::changeColor);

    w->show();
    return a.exec();
}

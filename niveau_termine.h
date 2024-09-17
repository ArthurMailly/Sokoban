#ifndef NIVEAU_TERMINE_H
#define NIVEAU_TERMINE_H

#include <QDialog>

namespace Ui {
class niveau_termine;
}

class niveau_termine : public QDialog
{
    Q_OBJECT

public:
    explicit niveau_termine(QWidget *parent = nullptr);
    ~niveau_termine();

private:
    Ui::niveau_termine *ui;
};

#endif // NIVEAU_TERMINE_H

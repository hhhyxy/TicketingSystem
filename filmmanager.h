#ifndef FILMMANAGER_H
#define FILMMANAGER_H

#include <QWidget>
#include <QSqlTableModel>
#include <QBitArray>

namespace Ui {
class FilmManager;
}

class FilmManager : public QWidget
{
    Q_OBJECT

public:
    explicit FilmManager(QWidget *parent = nullptr);
    ~FilmManager();
    void init();

private slots:
    void on_pushButton_insertMovie_clicked();

    void on_pushButton_updateMovie_clicked();

    void on_pushButton_deleteMovie_clicked();

    void on_pushButton_commitMovie_clicked();

    void on_pushButton_cancelMovie_clicked();

    void on_pushButton_insertPlace_clicked();

    void on_pushButton_updatePlace_clicked();

    void on_pushButton_deletePlace_clicked();

    void on_pushButton_commitPlace_clicked();

    void on_pushButton_cancelPlace_clicked();

private:
    Ui::FilmManager *ui;

    QSqlTableModel *m_movieModel = nullptr;
    QSqlTableModel *m_placeModel = nullptr;
};

#endif // FILMMANAGER_H

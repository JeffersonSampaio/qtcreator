#ifndef VIEWDEFINICAORECUPERANOTAFISCAL_H
#define VIEWDEFINICAORECUPERANOTAFISCAL_H

#include <QWidget>
#include <QWebEngineView>

namespace Ui {
class ViewDefinicaoRecuperaNotaFiscal;
}

class ViewDefinicaoRecuperaNotaFiscal : public QWidget
{
    Q_OBJECT

public:
    explicit ViewDefinicaoRecuperaNotaFiscal(QWidget *parent = nullptr);
    ~ViewDefinicaoRecuperaNotaFiscal();

public:
    QString cnpjFilial;
    QString produto;

private:
    void doNota(QString html);
    void carregaHtml();

private slots:
        void on_pbConfirma_clicked();

private:
    QWebEngineView* view;
    Ui::ViewDefinicaoRecuperaNotaFiscal *ui;
};

#endif // VIEWDEFINICAORECUPERANOTAFISCAL_H

#include "viewdefinicaorecuperanotafiscal.h"
#include "ui_viewdefinicaorecuperanotafiscal.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>


//Autor: Jefferson Sampaio
//Data: 02/07/2019



const QString link_fazenda = "http://www.nfe.fazenda.gov.br/portal/consultaRecaptcha.aspx?tipoConsulta=completa&tipoConteudo=XbSeqxE8pl8=";

ViewDefinicaoRecuperaNotaFiscal::ViewDefinicaoRecuperaNotaFiscal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewDefinicaoRecuperaNotaFiscal)
{
    ui->setupUi(this);

    view = new QWebEngineView;

    QUrl url;

    QNetworkRequest request;
    url.setScheme("http"); //https also applicable
    url.setHost("http://www.nfe.fazenda.gov.br");
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");
    url = QUrl(link_fazenda);

    view->load(url);
    ui->horizontalLayout_4->addWidget(view);
}

ViewDefinicaoRecuperaNotaFiscal::~ViewDefinicaoRecuperaNotaFiscal()
{
    delete ui;
}

void ViewDefinicaoRecuperaNotaFiscal::doNota(QString html)
{
    qDebug() << "doNota " <<html;
    qDebug() << "this->view->page()->url().toString()" << this->view->page()->url().toString();
    /*
    QString caminhoArquivo = "/tmp/htmportalnotafiscal.txt";
    QFile* arquivo = new QFile(caminhoArquivo);

    if (!arquivo->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"ERRO","Ocorreu um erro ao tentar salvar o arquivo.");
    }
    else
    {
        arquivo->write(html.toLatin1());
        arquivo->close();
    }

    // 43180691389460000109550000000517831117748480
    // Variaveis usadas para buscar os campos no html
    QString quebraCnpjFilial = "<legend>Destinatário</legend><table class=\"box\"><tbody><tr><td class=\"col-5\"><label>CNPJ</label><span>";
    QString quebraProduto    = "</td><td class=\"fixo-prod-serv-descricao\"><span>";
    if (arquivo->open(QIODevice::ReadOnly))
    {
        QTextStream buffer(arquivo);
        buffer.setCodec("ISO-8859-1");
        buffer.seek(0);

        while (!buffer.atEnd())
        {
            QString linha = buffer.readLine();

            if (linha.contains(quebraCnpjFilial))
            {
                cnpjFilial = linha.split(quebraCnpjFilial).at(1).mid(0, 18);
                qDebug() << "cnpjFilial " << cnpjFilial;
            }

            if (linha.contains(quebraProduto))
            {
                produto = linha.split(quebraProduto).at(1);
                produto = produto.split("</span>").at(0);

                qDebug() << "Produto " << produto;
            }

        }
    }
    */


}

void ViewDefinicaoRecuperaNotaFiscal::carregaHtml()
{
    qDebug() << "carregaHtml ";
    auto self = this;
    auto texto =[self](const QString result){
        self->doNota(result);
    };
    view->page()->toHtml(texto);
}

void ViewDefinicaoRecuperaNotaFiscal::on_pbConfirma_clicked()
{
    carregaHtml();
}

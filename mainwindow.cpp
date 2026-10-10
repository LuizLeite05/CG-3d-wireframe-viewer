#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shapes.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. Aumenta os limites para permitir coordenadas infinitas nos spin boxes
    ui->spinDx->setRange(-99999.99, 99999.99);
    ui->spinDy->setRange(-99999.99, 99999.99);
    ui->spinSx->setRange(-99999.99, 99999.99);
    ui->spinSy->setRange(-99999.99, 99999.99);
    ui->spinAngle->setRange(-360.00, 360.00);

    // 2. Define o valor padrão da Escala para 1.0 (para o objeto não colapsar)
    ui->spinSx->setValue(1.0);
    ui->spinSy->setValue(1.0);

    // 3. Inicializa o DisplayFile e conecta à área de desenho
    displayFile = new DisplayFile();
    ui->frameDrawArea->setDisplayFile(displayFile);

    // 4. Cria um triângulo básico de teste na inicialização
    QPointF p1(50, 50);
    QPointF p2(300, 50);
    displayFile->addObject(new Line("Linha Horizontal", p1, p2));

    // 2. Adicionar um Ponto
    QPointF ponto(200, 200);
    displayFile->addObject(new Point("Ponto Central", ponto));

    // 3. Adicionar um Quadrado (Polígono de 4 lados)
    QList<QPointF> pontosQuadrado = { QPointF(300, 300), QPointF(400, 300), QPointF(400, 400), QPointF(300, 400) };
    displayFile->addObject(new Polygon("Quadrado", pontosQuadrado));

    // Por fim, não se esqueça de atualizar a lista da interface
    updateObjectList();
}

MainWindow::~MainWindow()
{
    delete displayFile;
    delete ui;
}

// Atualiza os itens visíveis na interface
void MainWindow::updateObjectList() {
    ui->listObejcts->clear();
    for (Object* obj : displayFile->getObjects()) {
        ui->listObejcts->addItem(obj->getName());
    }
}

// --- Evento da Lista (Quando clicas num objeto) ---
void MainWindow::on_listObejcts_currentRowChanged(int currentRow)
{
    if (currentRow < 0) return;

    Object* obj = displayFile->getObjects().at(currentRow);
    QPointF center = obj->getCenter();

    // Atualiza as caixas de translação com a posição atual (centro) do objeto
    ui->spinDx->setValue(center.x());
    ui->spinDy->setValue(center.y());

    // Restaura a escala e rotação para valores neutros prontos a usar
    ui->spinSx->setValue(1.0);
    ui->spinSy->setValue(1.0);
    ui->spinAngle->setValue(0.0);
}

// --- Eventos de Transformação ---

void MainWindow::on_btnTranslate_clicked()
{
    int index = ui->listObejcts->currentRow();
    if (index < 0) return;

    Object* obj = displayFile->getObjects().at(index);

    // As novas coordenadas absolutas que estão na interface
    double destX = ui->spinDx->value();
    double destY = ui->spinDy->value();

    QPointF center = obj->getCenter();

    // Calcula a distância necessária para mover o objeto da posição atual até ao destino
    double dx = destX - center.x();
    double dy = destY - center.y();

    // Aplica a matriz de translação e atualiza o ecrã
    obj->translate(dx, dy);
    ui->frameDrawArea->update();
}


void MainWindow::on_btnAngle_clicked()
{
    int index = ui->listObejcts->currentRow();
    if (index < 0) return;

    Object* obj = displayFile->getObjects().at(index);
    double angle = ui->spinAngle->value();

    // Pega o centro, aplica a matriz de rotação ao redor dele e atualiza o ecrã
    QPointF center = obj->getCenter();
    obj->rotate(angle, center);
    ui->frameDrawArea->update();

    // Restaura o valor do ângulo para 0.0 após rodar
    ui->spinAngle->setValue(0.0);
}
void MainWindow::on_btnScale_clicked()

{
    int index = ui->listObejcts->currentRow();
    if (index < 0) return;

    Object* obj = displayFile->getObjects().at(index);
    double sx = ui->spinSx->value();
    double sy = ui->spinSy->value();

    // Aplica a matriz de escala e atualiza o ecrã
    obj->scale(sx, sy);
    ui->frameDrawArea->update();

    // Restaura o valor para 1.0 após escalar para o utilizador não clicar acidentalmente de novo
    ui->spinSx->setValue(1.0);
    ui->spinSy->setValue(1.0);
}


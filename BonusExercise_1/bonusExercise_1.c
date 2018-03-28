/**
Descrição:
Autora:
Data de Criação: 27/03/2018.
Datas de Modificação: 28/03/2018.
*/

#include <stdio.h>
#include <GL/glut.h>

/*p animação, eu posso colocar na função display:
    var globais: double tx = 0, ty = 0;
    display(){
        ...
        gltranslatef(tx, ty,0);
    }

    teclado(int key, int x, int y){ //tecla pressionada
        if(tecla=="GLUT_KEY_RIGHT")
            tx = tx+1; //eixo x
        glutPostRedisplay();
    }

    calcular na mão o centroide: no inicio ele é 5,5
*/
double tx = 0, ty = 0;

int init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);     //define a cor de fundo

    glMatrixMode(GL_PROJECTION);          //carrega a matriz de projeção
    gluOrtho2D(0.0,100.0,0.0,100.0);      //define projeção ortogonal 2D
    //mudar essa linha de cima para ficar proporcional a 500x500

}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);         //desenha o fundo (limpa a janela)

    glColor3f(1.0,0.0,0.0);               //altera o atributo de cor
    glBegin(GL_POLYGON);                    //desenha uma linha
        glVertex2f(0,0);
        glVertex2f(10,0);
        glVertex2f(10,10);
        glVertex2f(0,10);
    glEnd();

    glFlush();                            //desenha os comandos não executados
}

int main(int argc, char** argv) {

    glutInit(&argc,argv);                                     //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);               //configura o modo de display
    glutInitWindowSize(500,500);                              //configura a largura e altura da janela de exibição
    glutInitWindowPosition(200,0);
    glutCreateWindow("Exercicio Bonus 1");           //cria a janela de exibição

    init();                          //executa função de inicialização
    glutDisplayFunc(display);        //estabelece a função "display" como a função callback de exibição.
    glutMainLoop();                  //mostre tudo e espere
    return 0;
}


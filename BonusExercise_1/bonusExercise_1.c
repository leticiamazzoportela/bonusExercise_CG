/**
Descrição: Programa em C que usa a API OpenGL. O programa possibilita que sejam feitas duas transformações
           geométricas (translação e rotação) em um quadrado vermelho de lado 10.
Autora: Letícia Mazzo Portela.
Data de Criação: 27/03/2018.
*/

#include <stdio.h>
#include <GL/glut.h>


/*Cabeçalho das funções*/
void display();
int init();
void keyboardControl(unsigned char key, int x, int y);
void arrowKeysControl(int key, int x, int y);
void draw();

float tx = 0, ty = 0, theta; //Variaveis para controle dos eixos x e y e para o controle do angulo de rotacao
unsigned char key_op = 't'; //controle das opções: translação (t) e rotação (r). Inicia na translação.

int main(int argc, char** argv) {

    glutInit(&argc,argv);                                     
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);               
    glutInitWindowSize(500,500);                              
    glutInitWindowPosition(200,0);
    glutCreateWindow("Exercicio Bonus 1");          

    init();                            //executa função de inicialização
    glutDisplayFunc(display);          //estabelece a função "display" como a função callback de exibição.
    glutKeyboardFunc(keyboardControl); //estabelece a função "keyboardControl" como a função callback de teclado
    glutSpecialFunc(arrowKeysControl); //estabelece a função "arrowKeysControl" como a função callback para teclas especiais
    glutMainLoop();  
                    
    return 0;
}

/*Função de inicialização*/
int init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);     
    glMatrixMode(GL_PROJECTION);          
    gluOrtho2D(0.0,100.0,0.0,100.0);      
}

/*Função responsável por desenhar um quadrado de lado 10*/
void draw(){
    glBegin(GL_POLYGON);                  
        glVertex2f(0,0);
        glVertex2f(10,0);
        glVertex2f(10,10);
        glVertex2f(0,10);
    glEnd();
}

/*Função para exibição*/
void display(){
    glClear(GL_COLOR_BUFFER_BIT);         
    glColor3f(1.0,0.0,0.0);               
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tx + 5, ty + 5, 0); //centroide do quadrado = 5,5 
    glRotatef(theta, 0, 0, 1); //rotaciona o quadrado em um angulo theta usando centroide 5,5 como ponto de rotação
    glTranslatef(-tx - 5, -ty - 5, 0); 
    glTranslatef(tx, ty, 0); //faz a translação do quadrado
    draw();
    glFlush();                            
}

/*Função que controla as teclas normais do teclado*/
void keyboardControl(unsigned char key, int x, int y){
    switch(key){
        case 'R':
        case 'r': key_op = 'r';
                  break;
        case 'T':
        case 't': key_op = 't';
                  break;
    }

    glutPostRedisplay();
}

/*Função que controla as teclas especiais do teclado (Setas, no caso)*/
void arrowKeysControl(int op, int x, int y){
    if(key_op == 't'){
        if(op == GLUT_KEY_RIGHT) //deslocada no eixo x à direita
            tx = tx + 1;

        if(op == GLUT_KEY_LEFT) //desloca no eixo x à esquerda
            tx = tx - 1;

        if(op == GLUT_KEY_UP) //desloca no eixo y para cima
            ty = ty + 1;

        if(op == GLUT_KEY_DOWN) //desloca no eixo y para baixo
            ty = ty - 1;
    }
    if(key_op == 't'){
        if(op == GLUT_KEY_RIGHT)
            theta = theta - 1; //theta > 0: rotação anti-horaria
        if(op == GLUT_KEY_LEFT)
            theta = theta + 1; //theta < 0: rotação horária
    }
    
    glutPostRedisplay();
}
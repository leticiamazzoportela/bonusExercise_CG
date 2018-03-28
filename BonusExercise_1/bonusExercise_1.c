/**
Descrição:
Autora: Letícia Mazzo Portela.
Data de Criação: 27/03/2018.
*/

#include <stdio.h>
#include <GL/glut.h>

//    calcular na mão o centroide: no inicio ele é 5,5

/*Cabeçalho das funções*/
void display();
int init();
void keyboardControl(unsigned char key, int x, int y);
void arrowKeysControl(int key, int x, int y);
void draw();

/*Variaveis para controle dos eixos x e y*/
double tx = 0, ty = 0;

int main(int argc, char** argv) {

    glutInit(&argc,argv);                                     
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);               
    glutInitWindowSize(500,500);                              
    glutInitWindowPosition(200,0);
    glutCreateWindow("Exercicio Bonus 1");          

    init();                          //executa função de inicialização
    glutDisplayFunc(display);        //estabelece a função "display" como a função callback de exibição.
    glutKeyboardFunc(keyboardControl); 
    glutSpecialFunc(arrowKeysControl);
    glutMainLoop();                  
    return 0;
}

int init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);     
    glMatrixMode(GL_PROJECTION);          
    gluOrtho2D(0.0,100.0,0.0,100.0);      
}

void draw(){
    glBegin(GL_POLYGON);                  
        glVertex2f(0,0);
        glVertex2f(10,0);
        glVertex2f(10,10);
        glVertex2f(0,10);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);         
    glColor3f(1.0,0.0,0.0);               
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tx, ty, 0);
    //glRotatef();
    //Falta fazer a rotação e pronto :)
    
    draw();
    glFlush();                            
}

/*Função que controla as teclas normais do teclado*/
void keyboardControl(unsigned char key, int x, int y){
    switch(key){
        case 'R':
        case 'r': //add rotacao
                  break;
        case 'T':
        case 't': //add translacao
                  break;
    }

    glutPostRedisplay();
}

/*Função que controla as teclas especiais do teclado (Setas, no caso)*/
void arrowKeysControl(int key, int x, int y){
    if(key == GLUT_KEY_RIGHT){
        tx = tx + 1;
    }
    if(key == GLUT_KEY_LEFT){
        tx = tx - 1;
    }
    if(key == GLUT_KEY_UP){
        ty = ty + 1;
    }
    if(key == GLUT_KEY_DOWN){
        ty = ty + 1;
    }
    
    glutPostRedisplay();
}
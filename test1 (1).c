#include<stdio.h>
#include<GL/glut.h>
#include<string.h>
#define TEXTID      3
float i,j;
int f=0;
static int c=0;
GLfloat body[][2]={{2,2},{4,2},{5,2.5},{6,3},{9,6},{9.5,7},{10,8},{10.5,8.5},{11,9},{11.5,9.5},{12,10},{11,10.5},{10,11},{9,11.5},{8,11},{7,10.8},{6,10.5},{5,10},{4,9.9},{3,9.3},{2.5,9},{1.5,8},{1,7},{0.5,6},{0.5,4},{1,3}};
GLfloat arm[][2]={{6,4},{7,3.5},{8,3},{8.5,3},{9.5,2.5},{9,3},{10,3.5},{9,3.5},{9.5,4.5},{8.5,3.5},{7.5,4.5},{8,5},{8,6},{7,7},{6,6}};
GLfloat leg[][2]={{2,0},{5.5,0},{5,0.5},{5.5,1},{4.5,1},{5,1.5},{4,1},{3.5,2},{3.5,2.5},{3,3},{2,4},{0,4},{0,2}};
GLfloat eye[][2]={{8.25,10},{8.5,9.7},{9.1,9.7},{9.6,10},{9.1,10.25},{8.5,10.25}};
GLfloat mouth[][2]={{12,10},{11.5,9.6},{11,9.3},{10,9.1},{9.8,9},{9.5,8.5},{9,8}};
GLfloat colors[][3]={{0.0,1.0,0.0},{0.0,1.0,1.0}};
static float scale = 1.0;
static float translatex=6.0,translatey=37.0,translatez=10.0;
static float rotateAngle = 0.0;
void frog()
{
	int i;

	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glColor3f(0.60,0.0,0.0);//leg
	glBegin(GL_POLYGON);
	for(i=0;i<13;i++)
	glVertex2f(leg[i][0],leg[i][1]);
	glEnd();
	glColor3f(0.0,0.0,0.0);//eye
	glBegin(GL_POLYGON);
	for(i=0;i<6;i++)
	glVertex3f(eye[i][0],eye[i][1],2.0);
	glEnd();
	glColor3f(0.0,0.0,0.0);//mouth
	glLineWidth(2.0);
	glBegin(GL_LINE_STRIP);
	for(i=0;i<7;i++)
	glVertex3f(mouth[i][0],mouth[i][1],2.0);
	glEnd();
	glColor3f(0.70,0.0,0.0);//body
	glBegin(GL_POLYGON);
	for(i=0;i<26;i++)
	glVertex2f(body[i][0],body[i][1]);
	glEnd();
	//glFlush();
}
void frogArm()
{
	int i;
	glColor3f(0.50,0.0,0.0);//arm
	glBegin(GL_POLYGON);
	for(i=0;i<15;i++)
	glVertex2f(arm[i][0],arm[i][1]);
	glEnd();
}
void grass()
{
	glBegin(GL_POLYGON);
	glColor3fv(colors[c]);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glVertex3f(2.0,0.0,0.0);
	glVertex3f(2.0,0.0,3.0);
	glVertex3f(0.0,3.0,0.0);
	glVertex3f(0.0,3.0,3.0);
	glVertex3f(2.5,1.0,0.0);
	glVertex3f(2.5,1.0,3.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(4.0,4.0,3.0);
	glVertex3f(5.0,1.5,0.0);
	glVertex3f(5.0,1.5,3.0);
	glVertex3f(7.5,3.0,0.0);
	glVertex3f(7.5,3.0,3.0);
	glVertex3f(6.0,0.0,0.0);
	glVertex3f(6.0,0.0,3.0);
	glEnd();
}
void leaf()
{	glPushMatrix();
	glRotatef(rotateAngle,0.0,0.0,1.0);
	glutSolidSphere(8,10,10);
	glPopMatrix();


}

void idleFunction()
{ 	rotateAngle+=1.0;
  	if(rotateAngle>360.0)rotateAngle-=360.0;
	glutPostRedisplay();
}
void grassland()
{
	glColor3fv(colors[c]);
	for(i=0.0;i<100;i+=8.0){
	for(j=0.0;j<25;j+=5.0){
	glPushMatrix();
 	glTranslatef(i,j,0.0);
 	grass();
   	glPopMatrix();
   	glutPostRedisplay();
   	}}
   	for(i=0.0;i<100;i+=8.0){
	for(j=75.0;j<100;j+=5.0){
	glPushMatrix();
 	glTranslatef(i,j,0.0);
 	grass();
   	glPopMatrix();
   	glutPostRedisplay();
   	}}
   	glColor3f(0.0,0.30,0.0);
   	for(i=10;i<100;i+=50){
   	glPushMatrix();
	glTranslatef(i,40,0.0);
	leaf();
	glPopMatrix();
	glutPostRedisplay();
	}
	for(i=35;i<100;i+=50){
   	glPushMatrix();
	glTranslatef(i,60,0.0);
	leaf();
	glPopMatrix();
	glutPostRedisplay();
	}

}
void moveFrog()
{
	glPushMatrix();
	glTranslatef(translatex,translatey,translatez);//6,37,10//56,37,10//32,57,10
	glScalef(scale,scale,0.0);
	frogArm();
	frog();
	glPopMatrix();
	glutPostRedisplay();
}
// functrion to display text
void DrawTextXY(double x,double y,char *s)
{
   	int i;
   	glRasterPos2f(x,y);
   	for (i=0;i < strlen(s);i++)
  	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
}

void cover()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glClearColor(0,0,0,0.0);
	glColor3f(1.00,0.20,0.10);
	glLoadName(TEXTID);
	DrawTextXY(30,95,"   GRAPHICAL IMPLEMENTATION OF  ");

	glColor3f(0.6,0.8,0.7);
	DrawTextXY(35,90,"    THE FROG ");

	glColor3f(0.7,0.6,0.1);
	DrawTextXY(30,70,"     Submitted by :- ");

	glColor3f(1.0,0.5,0.0);
	DrawTextXY(40,60,"     ASHIM KHUSHBOO ");
	glColor3f(0.7,0.8,0.6);
	DrawTextXY(40,55,"     (1BI14CS031) ");
	glColor3f(0.7,0.6,0.1);
	DrawTextXY(30,45,"     Under the guidance of : ");
	glColor3f(1.0,0.8,0.4);
	DrawTextXY(15,35,"     PROF. MAYA B S");
	DrawTextXY(15,30,"     Assistant Professor ");
	DrawTextXY(65,35,"     PROF. PRIYA SRINIVASA");
	DrawTextXY(65,30,"     Assistant Professor ");
	DrawTextXY(30,20,"       Bangalore Institute of Technology");
	glColor3f(0.3,0.3,0.3);
	DrawTextXY(35,10,"     Press any key... ");

	glFlush();			//Finish rendering
	glutSwapBuffers();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0,0.0,0.4,1.0);
	grassland();
	moveFrog();
	glFlush();
}
void disp()
{
	if(f==0)
		cover();
	else
		display();
}
void keys(unsigned char key,int x,int y)
{
	if(f==0)
	{	f=1;
	}
	else {
		switch(key)
		{
		case 'o':glutIdleFunc(NULL);
			 break;
		case 'p':glutIdleFunc(idleFunction);
			 break;
		case 'm':scale=scale+0.50;
			 break;
		case 'n':scale=scale-0.50;
			 break;
		case ' ':translatex=translatex+50;
			 if(translatex>100){
			 translatex=6.0;
			 translatey=37.0;}
			 break;
		case 'j':if(translatey<=37.0){
			 translatey=translatey+20;}
			 else if(translatey<=57.0){
			 translatey=translatey-20;}
			 translatex=translatex+25;
			 if(translatex>100){
			 translatex=6.0;
			 translatey=37.0;}
			 break;
		}
	}
	glutPostRedisplay();//display();
}
void init()
{
	glClearColor(0.0,0.0,0.4,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,-10.0,20.0);
	glMatrixMode(GL_MODELVIEW);
}
void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
}
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;
void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
    switch(value)
		{
		case 9:glutIdleFunc(NULL);
			 break;
		case 8:
		// glutIdleFunc(idleFunction);
			 break;
		case 4:scale=scale+0.50;
			 break;
		case 5:scale=scale-0.50;
			 break;
		case 7:
		// translatex=translatex+50;
		// 	 if(translatex>100){
		// 	 translatex=6.0;
		// 	 translatey=37.0;}
			 break;
		case 6:
		// if(translatey<=37.0){
		// 	 translatey=translatey+20;}
		// 	 else if(translatey<=57.0){
		// 	 translatey=translatey-20;}
		// 	 translatex=translatex+25;
		// 	 if(translatex>100){
		// 	 translatex=6.0;
		// 	 translatey=37.0;}
			 break;
		case 1:
		// c=0;
			break;
		case 2:
		// c=1;
			break;
		}
  }
  glutPostRedisplay();
}
void createMenu(void)
{
	int sub_menu=glutCreateMenu(menu);
	//glutAddMenuEntry("RANDOM",3);
        glutAddMenuEntry("GREEN",1);
        glutAddMenuEntry("BLUE",2);

	int sub_menu1=glutCreateMenu(menu);//ZOOM
	glutAddMenuEntry("IN",4);
        glutAddMenuEntry("OUT",5);
        int sub_menu2=glutCreateMenu(menu);//JUMP
	glutAddMenuEntry("SHORT",6);
        glutAddMenuEntry("LONG",7);
        int sub_menu3=glutCreateMenu(menu);//ROTATE
	glutAddMenuEntry("START",8);
        glutAddMenuEntry("STOP",9);

	int sub_menu4=glutCreateMenu(menu);
		glutAddMenuEntry("KEYBOARD CONTROLS:",0);
		glutAddMenuEntry("Zoom in:  m",4);
		glutAddMenuEntry("Zoom out:  n",5);
		glutAddMenuEntry("Jump short:  j",6);
		glutAddMenuEntry("Jump long:  space",7);
		glutAddMenuEntry("Rotate leaves 360:  p",8);
		glutAddMenuEntry("Rotate leaves stop:  o",9);
		glutAddMenuEntry("EXIT",0);

	glutCreateMenu(menu);
	glutAddSubMenu("Colors",sub_menu);
	glutAddSubMenu("Zoom",sub_menu1);
	glutAddSubMenu("Jump",sub_menu2);
	glutAddSubMenu("Rotate leaves",sub_menu3);
	glutAddSubMenu("Help",sub_menu4);
	glutAddMenuEntry("Quit", 0);
        glutAttachMenu(GLUT_RIGHT_BUTTON);//attached to right click
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1280,720);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Structure of frog");
	glutDisplayFunc(disp);
	glutKeyboardFunc(keys);
	glutReshapeFunc(myReshape);
	init();
	  createMenu();
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}

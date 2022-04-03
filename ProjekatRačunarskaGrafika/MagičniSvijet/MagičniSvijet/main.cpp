#include <GL/glut.h>
#include <math.h>
#include<string.h>
# define PI 3.14159265358979323846


double rotacija_po_y = 0;
double rotacija_po_x = 0;


//Funkcija za crtanje krugova
// x,y - koordinate kruga, p - polupreènik
void NacrtajKrug(GLfloat x, GLfloat y, GLfloat p) {

	int i;
	int linije = 100;
	GLfloat dvostrukoPI = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); //centar kruga
	for (i = 0; i <= linije; i++) {
		glVertex2f(
			x + (p * cos(i *  dvostrukoPI / linije)),
			y + (p * sin(i *  dvostrukoPI / linije))
		);
	}   glEnd();
}

//Funkcija za crtanje trouglova
void NacrtajTrougao(float a, float b, float c, float d, float e, float f) {
	glBegin(GL_TRIANGLES);
	glVertex2f(a, b);
	glVertex2f(c, d);
	glVertex2f(e, f);
	glEnd();
}

//Funkcija za crtanje linija
void NacrtajLiniju(float a, float b, float c, float d) {
	glBegin(GL_LINES);
	glVertex2f(a, b);
	glVertex2f(c, d);
	glEnd();
}

//Funkcija za prikaz neba
void nebo() {

	glBegin(GL_QUADS);
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
	glEnd();
}
//Funckija za crtanje planina
void planine() {

	//sa desne strane prva planina
	glColor3ub(61, 119, 135);
	NacrtajTrougao(0.55, 0, 1.1, 0, 0.8, 0.22);
	glColor3ub(29, 78, 92);
	NacrtajTrougao(0.55, 0, 0.65, 0, 0.8, 0.22);

	//svijetlo plavi dio najveæe planine
	glBegin(GL_QUADS);
	glColor3ub(75, 152, 173);
	glVertex2f(-.35, 0);
	glVertex2f(.75, 0);
	glVertex2f(.25, .45);
	glVertex2f(.1, .43);
	glEnd();

	//bijeli dio glavne planine
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(.25, .45);
	glVertex2f(.1, .43);
	glVertex2f(-.039, .3);
	glVertex2f(.08, .35);
	glVertex2f(.06, .25);
	glVertex2f(.17, .355);
	glVertex2f(.25, .27);
	glVertex2f(.25, .38);
	glVertex2f(.42, .3);
	glEnd();

	//sa lijevog kraja prva planina
	glBegin(GL_TRIANGLES);
	glColor3ub(61, 119, 135);
	glVertex2f(-1.1, 0);
	glVertex2f(-.75, 0);
	glVertex2f(-.9, .12);
	glColor3ub(29, 78, 92);
	glVertex2f(-1.1, 0);
	glVertex2f(-.98, 0);
	glVertex2f(-.9, .12);

	//sa lijevog kraja druga po redu planina
	glColor3ub(61, 119, 135);
	glVertex2f(-.8, 0);
	glVertex2f(-.3, 0);
	glVertex2f(-.55, .15);
	glColor3ub(29, 78, 92);
	glVertex2f(-.8, 0);
	glVertex2f(-.7, 0);
	glVertex2f(-.55, .15);

	//sa lijeve strane treæa planina
	glColor3ub(61, 119, 135);
	glVertex2f(-.45, 0);
	glVertex2f(.1, 0);
	glVertex2f(-.2, .23);
	glColor3ub(29, 78, 92);
	glVertex2f(-.45, 0);
	glVertex2f(-.35, 0);
	glVertex2f(-.2, .23);

	//središnja planina sa cvijeæem
	glColor3ub(61, 119, 135);
	glVertex2f(-.1, 0);
	glVertex2f(.3, 0);
	glVertex2f(.1, .12);
	glColor3ub(29, 78, 92);
	glVertex2f(-.1, 0);
	glVertex2f(0, 0);
	glVertex2f(.1, .12);
	glEnd();
}

//Funkcija za crtanje 3D kuæe
void kuæa3D()
{
	//smeði dio kuæe koji se na poèetku vidi
	glBegin(GL_QUADS);
	glColor3f(0.627, 0.322, 0.176);
	glVertex3f(0.20f, 0.05f, 0.0f);
	glVertex3f(0.20f, 0.0f, 0.0f);
	glVertex3f(0.30f, 0.0f, 0.0f);
	glVertex3f(0.30f, 0.05f, 0.0f);
	glEnd();

	//smeði dio kuæe sa druge strane
	glBegin(GL_QUADS);
	glColor3f(0.627, 0.322, 0.176);
	glVertex3f(0.20f, 0.05f, 0.05f);
	glVertex3f(0.20f, 0.0f, 0.05f);
	glVertex3f(0.30f, 0.0f, 0.05f);
	glVertex3f(0.30f, 0.05f, 0.05f);
	glEnd();

	//dva smeða kvadrata (boène strane kuæe)
	glBegin(GL_QUADS);
	glColor3f(0.627, 0.322, 0.176);
	glVertex3f(0.20f, 0.05f, 0.0f);
	glVertex3f(0.20f, 0.0f, 0.0f);
	glVertex3f(0.20f, 0.0f, 0.05f);
	glVertex3f(0.20f, 0.05f, 0.05f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.627, 0.322, 0.176);
	glVertex3f(0.30f, 0.05f, 0.05f);
	glVertex3f(0.30f, 0.0f, 0.05f);
	glVertex3f(0.30f, 0.0f, 0.0f);
	glVertex3f(0.30f, 0.05f, 0.0f);
	glEnd();

	//krov strana koja se vidi, prije rotiranja
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.193f, 0.045f, -0.005f);
	glVertex3f(0.193f, 0.075f, 0.025f);
	glVertex3f(0.307f, 0.075f, 0.025f);
	glVertex3f(0.307f, 0.045f, -0.005f);
	glEnd();

	//dio krova (ona strana koja se vidi tek nakon rotiranja)
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.193f, 0.075f, 0.025f);
	glVertex3f(0.193f, 0.045f, 0.055f);
	glVertex3f(0.307f, 0.045f, 0.055f);
	glVertex3f(0.307f, 0.075f, 0.025f);
	glEnd();

	//dva trougla sa strane krova kuæe
	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.20f, 0.05f, 0.0f);
	glVertex3f(0.20f, 0.075f, 0.025f);
	glVertex3f(0.20f, 0.05f, 0.05f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.30f, 0.05f, 0.0f);
	glVertex3f(0.30f, 0.075f, 0.025f);
	glVertex3f(0.30f, 0.05f, 0.05f);
	glEnd();

	//bijela vrata
	glBegin(GL_QUADS);
	glColor3f(1.f, 1.0f, 1.f);
	glVertex3f(0.199f, 0.035f, 0.015f);
	glVertex3f(0.199f, 0.0f, 0.015f);
	glVertex3f(0.199f, 0.0f, 0.03f);
	glVertex3f(0.199f, 0.035f, 0.03f);
	glEnd();

	//dva prozora sa prednje strane 
	//prvi sa lijeva
	glBegin(GL_QUADS);
	glColor3f(1.f, 1.0f, 1.5f);
	glVertex3f(0.215f, 0.035f, -0.0001f);
	glVertex3f(0.215f, 0.0113f, -0.0001f);
	glVertex3f(0.233f, 0.0113f, -0.0001f);
	glVertex3f(0.233f, 0.035f, 0.0001f);
	glEnd();

	//drugi sa lijeva
	glBegin(GL_QUADS);
	glColor3f(1.f, 1.0f, 1.5f);
	glVertex3f(0.265f, 0.035f, -0.0001f);
	glVertex3f(0.265f, 0.013f, -0.0001f);
	glVertex3f(0.283f, 0.013f, -0.0001f);
	glVertex3f(0.283f, 0.035f, 0.0001f);
	glEnd();

	//dva prozora sa zadnje strane
	glBegin(GL_QUADS);
	glColor3f(1.f, 1.0f, 1.5f);
	glVertex3f(0.215f, 0.035f, 0.0501f);
	glVertex3f(0.215f, 0.013f, 0.0501f);
	glVertex3f(0.233f, 0.0113f, 0.0501f);
	glVertex3f(0.233f, 0.035f, 0.0501f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.f, 1.0f, 1.5f);
	glVertex3f(0.265f, 0.035f, 0.0501f);
	glVertex3f(0.265f, 0.013f, 0.0501f);
	glVertex3f(0.283f, 0.013f, 0.0501f);
	glVertex3f(0.283f, 0.035f, 0.0501f);
	glEnd();
}

//Funkcija za crtanje cvijeæa na travi
void CvijeæeNaTravi() {

	//crveni cvijet (prvi sa lijeve strane)
	glColor3ub(235, 29, 2);
	NacrtajKrug(-.78, -.9f, .02);
	NacrtajKrug(-.72, -.9f, .02);
	NacrtajKrug(-.75, -.87f, .02);
	NacrtajKrug(-.75f, -.93, .02);
	//žuti centar
	glColor3ub(255, 242, 10);
	NacrtajKrug(-.75f, -.9, .015);

	//žuti cvijet
	glScalef(0.9, .9, 0);
	glTranslated(0, 0, 0);
	glColor3ub(250, 197, 40);
	NacrtajKrug(-.75, -.9, .015);
	NacrtajKrug(-.72, -.9, .02);
	NacrtajKrug(-.75, -.87, .02);
	NacrtajKrug(-.75, -.93, .02);
	NacrtajKrug(-.75, -.9, .015);
	glColor3ub(250, 197, 40);
	NacrtajKrug(-.78, -.9, .02);
	glColor3ub(252, 23, 23);
	NacrtajKrug(-.75, -.9, .015);
	glLoadIdentity();

	//crveni cvijet
	glTranslated(.25, -.03, 0);
	glColor3ub(235, 29, 2);
	NacrtajKrug(-.78, -.9, .02);
	NacrtajKrug(-.72, -.9, .02);
	NacrtajKrug(-.75, -.87, .02);
	NacrtajKrug(-.75, -.93, .02);
	glColor3ub(255, 242, 10);
	NacrtajKrug(-.75, -.9, .015);
	glLoadIdentity();

	//žuti cvijet
	glTranslated(.42, -.0, 0);
	glColor3ub(250, 197, 40);
	NacrtajKrug(-.78, -.9, .02);
	NacrtajKrug(-.72, -.9, .02);
	NacrtajKrug(-.75, -.93, .02);
	NacrtajKrug(-.75, -.87, .02);
	glColor3ub(252, 23, 23);
	NacrtajKrug(-.75, -.9, .015);
	glLoadIdentity();

	//rozi cvijet unutra crveno
	glTranslated(.56, -.04, 0);
	glColor3ub(255, 186, 245);
	NacrtajKrug(-.78, -.9, .02);
	NacrtajKrug(-.72, -.9, .02);
	NacrtajKrug(-.75, -.87, .02);
	NacrtajKrug(-.75, -.93, .02);
	glColor3ub(245, 24, 65);
	NacrtajKrug(-.75, -.9, .015);
	glLoadIdentity();

	//crveni cvijet
	glTranslated(.7, -.01, 0);
	glColor3ub(235, 29, 2);
	NacrtajKrug(-.78, -.9, .02);
	NacrtajKrug(-.72, -.9, .02);
	NacrtajKrug(-.75, -.87, .02);
	NacrtajKrug(-.75, -.93, .02);
	glColor3ub(255, 242, 10);
	NacrtajKrug(-.75, -.9, .015);
	glLoadIdentity();

	//rozi cvijet
	glTranslated(.87, .07, 0);
	glColor3ub(255, 186, 245);
	NacrtajKrug(-.78, -.9, .02);
	NacrtajKrug(-.72, -.9, .02);
	NacrtajKrug(-.75, -.87, .02);
	NacrtajKrug(-.75, -.93, .02);
	glColor3ub(245, 24, 65);
	NacrtajKrug(-.75, -.9, .015);
	glLoadIdentity();

	glTranslated(.97, -.02, 0);
	glColor3ub(255, 186, 245);
	NacrtajKrug(-.78, -.9, .02);
	NacrtajKrug(-.72, -.9, .02);
	NacrtajKrug(-.75, -.87, .02);
	NacrtajKrug(-.75, -.93, .02);
	glColor3ub(245, 24, 65);
	NacrtajKrug(-.75, -.9, .015);
	glLoadIdentity();

	glTranslated(1.12, -.03, 0);
	glColor3ub(235, 29, 2);
	NacrtajKrug(-.78, -.9, .02);
	NacrtajKrug(-.72, -.9, .02);
	NacrtajKrug(-.75, -.87, .02);
	NacrtajKrug(-.75, -.93, .02);
	glColor3ub(255, 242, 10);
	NacrtajKrug(-.75, -.9, .015);
	glLoadIdentity();

	glTranslated(1.26, -.04, 0);
	glColor3ub(235, 29, 2);
	NacrtajKrug(-.78, -.9, .02);
	NacrtajKrug(-.72, -.9, .02);
	NacrtajKrug(-.75, -.87, .02);
	NacrtajKrug(-.75, -.93, .02);
	glColor3ub(255, 242, 10);
	NacrtajKrug(-.75, -.9, .015);
	glLoadIdentity();

	glTranslated(1.5, .04, 0);
	glColor3ub(255, 186, 245);
	NacrtajKrug(-.78, -.9, .02);
	NacrtajKrug(-.72, -.9, .02);
	NacrtajKrug(-.75, -.87, .02);
	NacrtajKrug(-.75, -.93, .02);
	glColor3ub(245, 24, 65);
	NacrtajKrug(-.75, -.9, .015);
	glLoadIdentity();

	glTranslated(1.36, -.0, 0);
	glColor3ub(250, 197, 40);
	NacrtajKrug(-.78, -.9, .02);
	NacrtajKrug(-.72, -.9, .02);
	NacrtajKrug(-.75, -.87, .02);
	NacrtajKrug(-.75, -.93, .02);
	glColor3ub(252, 23, 23);
	NacrtajKrug(-.75, -.9, .015);
	glLoadIdentity();
}

//Funkcija za crtanje rijeke
void rijeka() {

	//trava iza rijeke
	glBegin(GL_QUADS);
	glColor3ub(150, 211, 38);
	glVertex2f(-1, -.00);
	glVertex2f(1, -.00);
	glVertex2f(1, -.01);
	glVertex2f(-1, -.01);

	//rijeka
	glColor3ub(43, 155, 207);
	glVertex2f(-1, -.01);
	glVertex2f(1, -.01);
	glVertex2f(1, -.1);
	glVertex2f(-1, -.1);
	glEnd();

	glColor3ub(109, 170, 199);
	glLineWidth(0.05);
	NacrtajLiniju(-0.85, -.06, -0.95, -.06);
	NacrtajLiniju(-0.5, -.035, -.56, -.035);
	NacrtajLiniju(0.0, -.06, -0.1, -.06);
	NacrtajLiniju(0.8, -.03, 0.9, -.03);
}

//Funkcija za crtanje trave oko rijeke
void dugaTrava() {

	glScalef(0.24, .2, 0);
	glTranslated(0.8, .49, 0);
	glColor3ub(68, 173, 47);
	NacrtajTrougao(-.5, -1.0, -.45, -1.0, -.35, -.65);
	NacrtajTrougao(-.5, -1.0, -.45, -1.0, -.6, -.65);
	NacrtajTrougao(-.2, -1.0, -.15, -1.0, -.35, -.65);
	NacrtajTrougao(-.2, -1.0, -.15, -1.0, -.0, -.65);
	NacrtajTrougao(-.45, -1.0, -.4, -1.0, -.2, -.65);
	NacrtajTrougao(.15, -1.0, .2, -1.0, .35, -.65);
	NacrtajTrougao(.15, -1.0, .2, -1.0, .05, -.65);
	NacrtajTrougao(.45, -1.0, .5, -1.0, .35, -.65);
	NacrtajTrougao(.55, -1.0, .6, -1.0, .55, -.65);
	NacrtajTrougao(.6, -1.0, .65, -1.0, .8, -.65);
	NacrtajTrougao(.85, -1.0, .9, -1.0, 1.0, -.65);
	glLoadIdentity();

	glScalef(0.25, .2, 0);
	glTranslated(0.0, .49, 0);
	glColor3ub(68, 173, 47);
	NacrtajTrougao(-.5, -1.0, -.45, -1.0, -.35, -.65);
	NacrtajTrougao(-.5, -1.0, -.45, -1.0, -.6, -.65);
	NacrtajTrougao(-.2, -1.0, -.15, -1.0, -.35, -.65);
	NacrtajTrougao(-.2, -1.0, -.15, -1.0, -.0, -.65);
	NacrtajTrougao(-.45, -1.0, -.4, -1.0, -.2, -.65);
	NacrtajTrougao(.15, -1.0, .2, -1.0, .35, -.65);
	NacrtajTrougao(.15, -1.0, .2, -1.0, .05, -.65);
	NacrtajTrougao(.45, -1.0, .5, -1.0, .35, -.65);
	NacrtajTrougao(.55, -1.0, .6, -1.0, .55, -.65);
	NacrtajTrougao(.6, -1.0, .65, -1.0, .8, -.65);
	NacrtajTrougao(.85, -1.0, .9, -1.0, 1.0, -.65);
	glLoadIdentity();

	glScalef(0.25, .2, 0);
	glTranslated(-2.5, .49, 0);
	glColor3ub(68, 173, 47);
	NacrtajTrougao(-.5, -1.0, -.45, -1.0, -.35, -.65);
	NacrtajTrougao(-.5, -1.0, -.45, -1.0, -.6, -.65);
	NacrtajTrougao(-.2, -1.0, -.15, -1.0, -.35, -.65);
	NacrtajTrougao(-.2, -1.0, -.15, -1.0, -.0, -.65);
	NacrtajTrougao(-.45, -1.0, -.4, -1.0, -.2, -.65);
	NacrtajTrougao(.15, -1.0, .2, -1.0, .35, -.65);
	NacrtajTrougao(.15, -1.0, .2, -1.0, .05, -.65);
	NacrtajTrougao(.45, -1.0, .5, -1.0, .35, -.65);
	NacrtajTrougao(.55, -1.0, .6, -1.0, .55, -.65);
	NacrtajTrougao(.6, -1.0, .65, -1.0, .8, -.65);
	NacrtajTrougao(.85, -1.0, .9, -1.0, 1.0, -.65);
	glLoadIdentity();
}

//Funkcija za prikaz broda
void brod() {

	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3ub(145, 89, 58);
	glVertex2f(-.01, -.04);
	glVertex2f(-.01, .3);
	glVertex2f(-.1, -.04);
	glVertex2f(-.01, .28);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(252, 25, 0);
	glVertex2f(-.01, .28);
	glVertex2f(-.01, -.0);
	glVertex2f(.14, -.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(252, 185, 0);
	glVertex2f(-.12, -.03);
	glVertex2f(-.1, -.06);
	glVertex2f(.1, -.06);
	glVertex2f(.12, -.03);
	glEnd();
}

//Funkcija za prikaz trave
void zemlja() {
	glBegin(GL_QUADS);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 0);
	glVertex2f(-1, 0);
	glEnd();
}

//Funkcija za prikaz svjetlije trave
void svijetlijePolje() {
	NacrtajTrougao(-.5, -.2, 1, -.4, 1, -.1);
	NacrtajTrougao(-1, -.4, -1, -.7, 0, -.5);
}

//Funkcija za crtanje žbunja iza rijeke
void žbunje() {
	//sa desne strane prvo
	NacrtajKrug(0.1, .005, .07);
	NacrtajKrug(0.2, .002, .04);

	//sa lijeve strane prvo
	NacrtajKrug(0.8, .005, .035);
	NacrtajKrug(0.88, .005, .065);
}

//Funkcija za crtanje cvijeæa iza rijeke (oko žbunja)
void cvijeæeIzaRijeke() {

	//sa lijeva na desno
	glColor3ub(247, 183, 225);
	NacrtajKrug(0.025, .006, .013);
	NacrtajKrug(0.014, .025, .013);
	NacrtajKrug(0.0015, .005, .013);
	glColor3ub(255, 3, 3);
	NacrtajKrug(0.012, .012, .01);

	glTranslated(.12, .03, 0);
	glColor3ub(247, 183, 225);
	NacrtajKrug(0.025, .006, .013);
	NacrtajKrug(0.0015, .005, .013);
	glColor3ub(255, 3, 3);
	NacrtajKrug(0.012, .012, .01);
	glLoadIdentity();

	glTranslated(.87, .02, 0);
	glColor3ub(247, 183, 225);
	NacrtajKrug(0.025, .006, .013);
	NacrtajKrug(0.014, .025, .013);
	NacrtajKrug(0.0015, .005, .013);
	glColor3ub(255, 3, 3);
	NacrtajKrug(0.012, .012, .01);
	glLoadIdentity();
}

//Funkcija za prikaz kišnih oblaka
void kišniOblaci() {

	NacrtajKrug(-2.03, .95, .1);
	NacrtajKrug(-1.84, .93, .15);
	NacrtajKrug(-1.54, .93, .18);
	NacrtajKrug(-1.28, .93, .15);
	NacrtajKrug(-1.0, .93, .17);
	NacrtajKrug(-.93, .95, .1);
	NacrtajKrug(-.72, .93, .15);
	NacrtajKrug(-.5, .93, .18);
	NacrtajKrug(-.28, .93, .15);
	NacrtajKrug(0.0, .95, .17);
	NacrtajKrug(.2, .93, .15);
	NacrtajKrug(.43, .93, .2);
	NacrtajKrug(.65, .93, .13);
	NacrtajKrug(.8, .95, .15);
	NacrtajKrug(.95, .95, .08);
}

//Funkcija za prikaz kiše
void kiša() {
	glBegin(GL_LINES);

	glVertex2f(-.85, 1.9); glVertex2f(-.8, 1.8);
	glVertex2f(-.55, 1.9); glVertex2f(-.5, 1.8);
	glVertex2f(-.25, 1.9); glVertex2f(-.2, 1.8);
	glVertex2f(.05, 1.9); glVertex2f(.1, 1.8);
	glVertex2f(.35, 1.9); glVertex2f(.4, 1.8);
	glVertex2f(.65, 1.9); glVertex2f(.7, 1.8);
	glVertex2f(.95, 1.9); glVertex2f(1.0, 1.8);

	glVertex2f(-1.0, 1.6); glVertex2f(-.95, 1.5);
	glVertex2f(-.7, 1.6); glVertex2f(-.65, 1.5);
	glVertex2f(-.4, 1.6); glVertex2f(-.35, 1.5);
	glVertex2f(-.1, 1.6); glVertex2f(-.05, 1.5);
	glVertex2f(.2, 1.6); glVertex2f(.25, 1.5);
	glVertex2f(.5, 1.6); glVertex2f(.55, 1.5);
	glVertex2f(.8, 1.6); glVertex2f(.85, 1.5);

	glVertex2f(-.85, 1.3); glVertex2f(-.8, 1.2);
	glVertex2f(-.55, 1.3); glVertex2f(-.5, 1.2);
	glVertex2f(-.25, 1.3); glVertex2f(-.2, 1.2);
	glVertex2f(.05, 1.3); glVertex2f(.1, 1.2);
	glVertex2f(.35, 1.3); glVertex2f(.4, 1.2);
	glVertex2f(.65, 1.3); glVertex2f(.7, 1.2);
	glVertex2f(.95, 1.3); glVertex2f(1.0, 1.2);

	glVertex2f(-1.0, 1.0); glVertex2f(-.95, .9);
	glVertex2f(-.7, 1.0); glVertex2f(-.65, 0.9);
	glVertex2f(-.4, 1.0); glVertex2f(-.35, 0.9);
	glVertex2f(-.1, 1.0); glVertex2f(-.05, 0.9);
	glVertex2f(.2, 1.0); glVertex2f(.25, .9);
	glVertex2f(.5, 1.0); glVertex2f(.55, 0.9);
	glVertex2f(.8, 1.0); glVertex2f(.85, 0.9);

	glVertex2f(-.85, .7); glVertex2f(-.8, .6);
	glVertex2f(-.55, .7); glVertex2f(-.5, 0.6);
	glVertex2f(-.25, .7); glVertex2f(-.2, 0.6);
	glVertex2f(.05, .7); glVertex2f(.1, .6);
	glVertex2f(.35, .7); glVertex2f(.4, .6);
	glVertex2f(.65, .7); glVertex2f(.7, .6);
	glVertex2f(.95, .7); glVertex2f(1.0, .6);

	glVertex2f(-1.0, .4); glVertex2f(-.95, .3);
	glVertex2f(-.7, .4); glVertex2f(-.65, 0.3);
	glVertex2f(-.4, .4); glVertex2f(-.35, 0.3);
	glVertex2f(-.1, .4); glVertex2f(-.05, 0.3);
	glVertex2f(.2, .4); glVertex2f(.25, .3);
	glVertex2f(.5, .4); glVertex2f(.55, 0.3);
	glVertex2f(.8, .40); glVertex2f(.85, 0.3);

	glVertex2f(-.85, .1); glVertex2f(-.8, 0.0);
	glVertex2f(-.55, .1); glVertex2f(-.5, 0.0);
	glVertex2f(-.25, .1); glVertex2f(-.2, 0.0);
	glVertex2f(.05, .1); glVertex2f(.1, .0);
	glVertex2f(.35, .1); glVertex2f(.4, .0);
	glVertex2f(.65, .1); glVertex2f(.7, .0);
	glVertex2f(.95, .1); glVertex2f(1.0, .0);

	glVertex2f(-1.0, -.2); glVertex2f(-.95, -.3);
	glVertex2f(-.7, -.2); glVertex2f(-.65, -0.3);
	glVertex2f(-.4, -.2); glVertex2f(-.35, -0.3);
	glVertex2f(-.1, -.2); glVertex2f(-.05, -0.3);
	glVertex2f(.2, -.2); glVertex2f(.25, -.3);
	glVertex2f(.5, -.2); glVertex2f(.55, -.3);
	glVertex2f(.8, -.2); glVertex2f(.85, -.3);

	glVertex2f(-.85, -.5); glVertex2f(-.8, -.6);
	glVertex2f(-.55, -.5); glVertex2f(-.5, -.6);
	glVertex2f(-.25, -.5); glVertex2f(-.2, -.6);
	glVertex2f(.05, -.5); glVertex2f(.1, -.6);
	glVertex2f(.35, -.5); glVertex2f(.4, -.6);
	glVertex2f(.65, -.5); glVertex2f(.7, -.6);
	glVertex2f(.95, -.5); glVertex2f(1.0, -.6);

	glVertex2f(-1.0, -.8); glVertex2f(-.95, -.9);
	glVertex2f(-.7, -.8); glVertex2f(-.65, -0.9);
	glVertex2f(-.4, -.8); glVertex2f(-.35, -0.9);
	glVertex2f(-.1, -.8); glVertex2f(-.05, -0.9);
	glVertex2f(.2, -.8); glVertex2f(.25, -.9);
	glVertex2f(.5, -.8); glVertex2f(.55, -.9);
	glVertex2f(.8, -.8); glVertex2f(.85, -.9);

	glVertex2f(-.85, -1.1); glVertex2f(-.8, -1.2);
	glVertex2f(-.55, -1.1); glVertex2f(-.5, -1.2);
	glVertex2f(-.25, -1.1); glVertex2f(-.2, -1.2);
	glVertex2f(.05, -1.1); glVertex2f(.1, -1.2);
	glVertex2f(.35, -1.1); glVertex2f(.4, -1.2);
	glVertex2f(.65, -1.1); glVertex2f(.7, -1.2);
	glVertex2f(.95, -1.1); glVertex2f(1.0, -1.2);

	glVertex2f(-1.0, -1.4); glVertex2f(-.95, -1.5);
	glVertex2f(-.7, -1.4); glVertex2f(-.65, -1.5);
	glVertex2f(-.4, -1.4); glVertex2f(-.35, -1.5);
	glVertex2f(-.1, -1.4); glVertex2f(-.05, -1.5);
	glVertex2f(.2, -1.4); glVertex2f(.25, -1.5);
	glVertex2f(.5, -1.4); glVertex2f(.55, -1.5);
	glVertex2f(.8, -1.4); glVertex2f(.85, -1.5);

	glEnd();
}

void klupa2()
{
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(0.2, -0.5);
	glVertex2f(0.2, -0.4);
	glVertex2f(0.3, -0.5);
	glVertex2f(0.3, -0.4);
	glEnd();

	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(0.6, -0.4);
	glVertex2f(0.6, -0.35);
	glVertex2f(0.1, -0.35);
	glVertex2f(0.1, -0.4);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(0.4, -0.5);
	glVertex2f(0.4, -0.4);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, -0.4);
	glEnd();
}

void klupa1()
{
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2, -0.5);
	glVertex2f(-0.2, -0.4);
	glVertex2f(-0.3, -0.5);
	glVertex2f(-0.3, -0.4);
	glEnd();

	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6, -0.4);
	glVertex2f(-0.6, -0.35);
	glVertex2f(-0.1, -0.35);
	glVertex2f(-0.1, -0.4);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex2f(-0.4, -0.5);
	glVertex2f(-0.4, -0.4);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, -0.4);
	glEnd();
}

GLfloat kišaP = 2.50f;
GLfloat brzinaKiše = 0.0f;

void kišaPada(int vrijednost) {

	if (kišaP < -1.0)
		kišaP = .50f;
	kišaP = kišaP - brzinaKiše;
	glutPostRedisplay();
	glutTimerFunc(100, kišaPada, 0);
}

GLfloat oblakP = 3.5f;
GLfloat brzinaOblaka = 0.02f;

void dolaziOblak(int vrijednost) {
	if (oblakP < 0.0)
		oblakP = 1.0f;
	oblakP -= brzinaOblaka;
	glutPostRedisplay();
	glutTimerFunc(100, dolaziOblak, 0);
}

GLfloat brodP = 1.2f;
GLfloat brzinaBroda = 0.01f;

void prolazakBroda(int vrijednost) {
	if (brodP < -1.5)
		brodP = 1.2f;
	brodP -= brzinaBroda;
	glutPostRedisplay();
	glutTimerFunc(100, prolazakBroda, 0);
}


void prikaz() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(140, 180, 200);

	nebo();

	planine();

	//Kišni oblaci
	glColor3ub(158, 161, 163);
	glPushMatrix();
	glTranslatef(oblakP, 0.0f, 0.0f);
	kišniOblaci();
	glPopMatrix();
	glLoadIdentity();

	//zemlja (trava, podloga)
	glColor3ub(130, 179, 82);
	zemlja();

	//dio gdje je trava svijetlija
	glColor3ub(162, 201, 83);
	svijetlijePolje();

	//žbunje iza rijeke
	glColor3ub(47, 158, 68);
	žbunje();

	cvijeæeIzaRijeke();

	rijeka();

	//kuæa 3D
	glRotatef(rotacija_po_x, 1.0, 0.0, 0.0);
	glRotatef(rotacija_po_y, 0.0, 1.0, 0.0);
	glPushMatrix();
	glScaled(3.2f, 3.2f, 3.2f);
	kuæa3D();
	glPopMatrix();
	glLoadIdentity();

	//brod
	glPushMatrix();
	glTranslatef(brodP, 0.0f, 0.0f);
	brod();
	glPopMatrix();
	glLoadIdentity();

	dugaTrava();

	CvijeæeNaTravi();

	//kiša
	glPushMatrix();
	glTranslatef(0.0f, kišaP, 0.0f);
	glColor3ub(210, 226, 247);
	glLineWidth(2);
	kiša();
	glPopMatrix();

	klupa2();

	klupa1();

	glutSwapBuffers();
}

//funkcija koja omoguæava da se na odreðena slova sa tastature, izvršavaju odreðeni dogaðaji
void pritisniTaster(unsigned char key, int x, int y) {

	switch (key) {
	case 'P':
		brzinaKiše = 0.2f;
		break;
	case 'S':
		kišaP = 2.50f;
		brzinaKiše = 0.0f;
	case 'M':
		glutDisplayFunc(prikaz);
		glutPostRedisplay();
		break;
	}
}

//funkcija za rotaciju kuæe, pomoæu strelica na tastaturi
void pritisniStrelicu(int key, int a, int b)
{
	if (key == GLUT_KEY_RIGHT)
		rotacija_po_y += 5;
	else if (key == GLUT_KEY_LEFT)
		rotacija_po_y -= 5;
	else if (key == GLUT_KEY_UP)
		rotacija_po_x += 5;
	else if (key == GLUT_KEY_DOWN)
		rotacija_po_x -= 5;
	glutPostRedisplay();

}

//funkcija koja omoguæava zaustavljanje i pokretanje oblaka na lijevi i desni taster miša
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		brzinaOblaka = 0.0f;
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		brzinaOblaka = 0.03f;
	}

	glutPostRedisplay();
}

void init()
{
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
	//glMatrixMode(GL_MODELVIEW);
}

void poèetniEkran()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 0, 0);

	glRasterPos3f(-0.4, 0.9, 0);
	char msg1[] = "Dobro dosli u magicni svijet";
	for (int i = 0; i < strlen(msg1); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg1[i]);

	glColor3f(0, 0, 1);
	glRasterPos3f(-0.8, 0.7, 0);
	char msg2[] = "Ako zelite zakoraciti u magicni svijet pritisnite M.";
	for (int i = 0; i < strlen(msg2); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg2[i]);

	glRasterPos3f(-0.8, 0.6, 0);
	char msg3[] = "Da promiijenite polozaj kuce, koristite strelice na tastaturi.";
	for (int i = 0; i < strlen(msg3); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg3[i]);

	glRasterPos3f(-0.8, 0.5, 0);
	char msg4[] = "Da zaustavite oblake koristite lijevi taster misa.";
	for (int i = 0; i < strlen(msg4); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg4[i]);

	glRasterPos3f(-0.8, 0.4, 0);
	char msg5[] = "Ipak ako zelite da se oblaci krecu, koristite desni taster misa.";
	for (int i = 0; i < strlen(msg5); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg5[i]);

	glRasterPos3f(-0.8, 0.3, 0);
	char msg6[] = "Da bi padala kisa potrebno vam je slovo P.";
	for (int i = 0; i < strlen(msg6); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg6[i]);

	glRasterPos3f(-0.8, 0.2, 0);
	char msg7[] = "Da kisa stane koristite slovo S.";
	for (int i = 0; i < strlen(msg7); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg7[i]);

	glutSwapBuffers();
}

void myTimer(int val)
{
	glutDisplayFunc(prikaz);
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MAGIJA_U_PRIRODI");
	glutReshapeWindow(700, 550);
	glutDisplayFunc(poèetniEkran);
	init();
	glutTimerFunc(10, dolaziOblak, 0);
	glutTimerFunc(1000, kišaPada, 0);
	glutTimerFunc(2000, prolazakBroda, 0);
	glutTimerFunc(10000, myTimer, 0);
	glutKeyboardFunc(pritisniTaster);
	glutSpecialFunc(pritisniStrelicu);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}





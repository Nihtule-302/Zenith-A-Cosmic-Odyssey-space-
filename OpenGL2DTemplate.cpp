/*------------------------------------------------------------------------------------------------------------------
										Ali Mohamed Wafa  202100302
										Zenith: A Cosmic Odyssey
	Controls:
		- Use arrow keys for navigation.
		- 'A' key increases speed until fuel runs out (activates Warp Speed).
		- 'Z' key decreases speed.

	Testing Controls:
		- 'H' key: Toggles planet and asteroid visibility.
		- '1' key: Increases speed with unlimited fuel for testing purposes.

	Bugs:
		- Bug: Warp Speed functionality may not work correctly if fuel runs out. Ensure the fuel meter is refilled for proper Warp Speed operation.
*/

#include <stdlib.h>
#include <glut.h>

// moving factors
float starsM1 = 0.0;
float starsM2 = 0.0;

float shipMx = 0.0;
float shipMy = 0.0;

float astroidX = rand() % 401;
float astroidM = 0.0;

float galaxyM = 0.0;

float planetM = 0.0;


// speed fators
float starsL1 = -.09;
float starsL2 = -1;
float starsSpeed = starsL1;

float shipSlow = 15;
float shipFast = 2;
float shipSpeed = shipSlow;

float astroidSlow = -2;
float astroidFast = -30;
float astroidSpeed = astroidSlow;

float galaxySlow = -0.001;
float galaxyFast = -.009;
float galaxySpeed = galaxySlow;

float planetSlow = -.2;
float planetFast = -15;
float planetSpeed = planetSlow;


//visability
bool ship1 = true;
bool ship2 = false;

//stamina(astroMana)
bool warp_speed_start = false;
bool manaEmpty = false;
bool manaFull = true;
float manaConsumption = .004;
float scalingFactor = 1.0;

//Testing
bool hide = false;
bool toggleSpeed = false;

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);

	//------------------------------- background ------------------------------------
	GLUquadric* quadric = gluNewQuadric();

	//stars Far

	//83, 4, 97
	glColor3d(83.0f / 255.0f, 4.0f / 255.0f, 97.0f / 255.0f);
	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex3f(50.0, 254.0, 0);
	glVertex3f(20.0, 104.0, 0);
	glVertex3f(50.0, 254.0, 0);
	glVertex3f(385.0, 106.0, 0);
	glVertex3f(358.0, 254.0, 0);
	glVertex3f(344.0, 565.0, 0);
	glVertex3f(381.0, 453.0, 0);
	glVertex3f(204.0, 254.0, 0);
	glVertex3f(220.0, 100.0, 0);
	glVertex3f(60.0, 539.0, 0);
	glVertex3f(10.0, 254.0, 0);
	glVertex3f(29.0, 568.0, 0);
	glVertex3f(191.0, 597.0, 0);
	glVertex3f(171.0, 366.0, 0);
	glVertex3f(110.0, 406.0, 0);
	glVertex3f(314.0, 435.0, 0);
	glVertex3f(215.0, 374.0, 0);
	glVertex3f(150.0, 295.0, 0);
	glVertex3f(195.0, 254.0, 0);
	glVertex3f(312.0, 568.0, 0);
	glVertex3f(126.0, 373.0, 0);
	glVertex3f(60.0, 99.0, 0);
	glVertex3f(10.0, 75.0, 0);
	glVertex3f(1.0, 10.0, 0);
	glVertex3f(300.0, 565.0, 0);
	glVertex3f(90.0, 62.0, 0);
	glVertex3f(301.0, 594.0, 0);
	glVertex3f(390.0, 10.0, 0);
	glVertex3f(395.0, 100.0, 0);
	glVertex3f(370.0, 88.0, 0);
	glVertex3f(323.0, 75.0, 0);
	glEnd();


	//Galaxy
	glPushMatrix();
	glTranslatef(0, galaxyM, 0);
	glTranslated(200, 400, 0);
	glRotated(-48, 0, 0, 1);


	glPushMatrix();
	glScaled(.6, 4, 1);
	//9,13,37
	glColor4f(9.0 / 255.0, 13.0 / 255.0, 37.0 / 255.0, .7);
	gluDisk(quadric, 0, 100, 100, 1);
	glPopMatrix();

	glPushMatrix();
	glScaled(.5, 3, 1);
	// 12,37,87
	glColor4f(12.0 / 255.0, 37.0 / 255.0, 87.0 / 255.0, .8);
	gluDisk(quadric, 0, 100, 100, 1);

	glPopMatrix();

	glPushMatrix();
	glScaled(.4, 2, 1);
	// 48,101,152
	glColor4f(40.0 / 255.0, 93.0 / 255.0, 144.0 / 255.0, .9);
	gluDisk(quadric, 0, 100, 100, 1);

	glPopMatrix();

	glPushMatrix();
	glScaled(.2, .9, 1);
	// 102,140,175
	glColor4f(102.0 / 255.0, 140.0 / 255.0, 175.0 / 255.0, 1);
	gluDisk(quadric, 0, 100, 100, 1);

	glPopMatrix();

	glPushMatrix();
	glScaled(.1, .4, 1);
	// 156,175,201
	glColor4f(156.0 / 255.0, 175.0 / 255.0, 201.0 / 255.0, 1);
	gluDisk(quadric, 0, 100, 100, 1);

	glPopMatrix();

	glPushMatrix();
	glScaled(.05, .2, 1);
	// 213, 226, 245
	glColor4f(213.0 / 255.0, 226.0 / 255.0, 245.0 / 255.0, 1);
	gluDisk(quadric, 0, 100, 100, 1);

	glPopMatrix();

	glPopMatrix();


	//Stars Near
	glPushMatrix();
	glTranslatef(0, starsM1, 0);

	glColor3f(0.78f, 0.69f, 0.83f);
	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex3f(227.0, 554.0, 0);
	glVertex3f(91.0, 91.0, 0);
	glVertex3f(95.0, 5.0, 0);
	glVertex3f(74.0, 10.0, 0);
	glVertex3f(126.0, 373.0, 0);
	glVertex3f(60.0, 99.0, 0);
	glVertex3f(10.0, 75.0, 0);
	glVertex3f(1.0, 10.0, 0);
	glVertex3f(300.0, 565.0, 0);
	glVertex3f(90.0, 62.0, 0);

	glEnd();

	glPopMatrix();

	//stars2
	glPushMatrix();
	glTranslatef(0, starsM2, 0);
	glTranslatef(0, 600, 0);

	glColor3f(0.78f, 0.69f, 0.83f);
	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex3f(358.0, 254.0, 0);
	glVertex3f(344.0, 565.0, 0);
	glVertex3f(381.0, 453.0, 0);
	glVertex3f(204.0, 254.0, 0);
	glVertex3f(220.0, 100.0, 0);
	glVertex3f(60.0, 539.0, 0);
	glVertex3f(10.0, 254.0, 0);
	glVertex3f(29.0, 568.0, 0);
	glVertex3f(227.0, 554.0, 0);
	glVertex3f(91.0, 91.0, 0);
	glVertex3f(95.0, 5.0, 0);
	glVertex3f(74.0, 10.0, 0);

	glEnd();

	glPopMatrix();

	//planets
	if (hide == false) {
		glPushMatrix();
		glTranslated(0, planetM, 0);

		glPushMatrix();
		glTranslated(50, 500, 0);
		glColor3f(79.0 / 255.0, 76.0 / 255.0, 176.0 / 255.0);
		gluDisk(quadric, 0, 36.05, 100, 1);
		glPopMatrix();

		glBegin(GL_POLYGON);
		//159,193,100
		glColor3f(159.0 / 255.0, 193.0 / 255.0, 100.0 / 255.0);
		glVertex3f(46.1, 528.1, 0);//Q2
		glVertex3f(56.1, 529.0, 0); //R2
		glVertex3f(63.6, 533.37, 0); //S2
		glVertex3f(54.6, 535.75, 0); //T2
		glVertex3f(42.7, 535.3, 0); //U2
		glVertex3f(33.99, 532.3, 0); //P2

		glEnd();

		glBegin(GL_POLYGON);

		glVertex3f(27.1, 508.37, 0);//J2
		glVertex3f(33.66, 502.9, 0); //O2
		glVertex3f(40.0, 480.0, 0); //N2
		glVertex3f(31.15, 473.14, 0); //M2
		glVertex3f(23.0, 479.2, 0); //L2
		glVertex3f(20.9, 491.0, 0); //K2

		glEnd();

		glBegin(GL_POLYGON);

		glVertex3f(60.0, 520.0, 0);//E2
		glVertex3f(64.34, 499.56, 0);//F2
		glVertex3f(74.66, 473.7, 0);//G2
		glVertex3f(80.0, 480.0, 0);//B2 
		glVertex3f(86.0, 498.35, 0);//H2 
		glVertex3f(83.9, 512.25, 0);//I2
		glVertex3f(80.0, 520.0, 0);//C2 
		glVertex3f(70.1, 517.17, 0);//D2

		glEnd();

		glPopMatrix();
	}

	//--------------------<\Background>------------------------------

	//--------------------<Astroids>----------------------------------

	if (hide == false) {
		glPushMatrix();
		glTranslated(astroidX, astroidM, 0);
		glTranslated(-190, 209.6, 0);

		glBegin(GL_POLYGON);
		glColor3f(54.0 / 255.0, 54.0 / 255.0, 54.0 / 255.0);
		glVertex3f(162.9, 380.1, 0); //A1
		glVertex3f(179.5, 391.2, 0); //B1
		glVertex3f(191.4, 420.4, 0); //C1
		glVertex3f(220.0, 420.0, 0); //D1

		glVertex3f(220.0, 380.0, 0); //E1
		glVertex3f(200.0, 360.0, 0); //F1
		glVertex3f(160.0, 360.0, 0); //Z
		glEnd();

		//36, 35, 35
		glBegin(GL_QUADS);
		glColor3f(36.0 / 255.0, 35.0 / 255.0, 35.0 / 255.0);
		glVertex3f(207.55, 411.7, 0); //O1
		glVertex3f(214.8, 413.9, 0); //P1
		glVertex3f(211.8, 403.5, 0); //Q1
		glVertex3f(205.4, 403.5, 0); //N1
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(209.95, 385.9, 0); //I1
		glVertex3f(207.8, 379.5, 0); //J1
		glVertex3f(195.5, 370.4, 0); //G1
		glVertex3f(200.0, 380.0, 0); //H1
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(175.5, 368.7, 0); //Z1
		glVertex3f(184.7, 367.2, 0); //W1
		glVertex3f(188.8, 365.0, 0); //V1
		glVertex3f(175.3, 365.2, 0); //U1
		glEnd();

		glBegin(GL_TRIANGLES);
		glVertex3f(190.4, 398.4, 0); //R1
		glVertex3f(196.6, 398.1, 0); //T1
		glVertex3f(188.8, 393.0, 0); //S1
		glEnd();

		glBegin(GL_TRIANGLES);
		glVertex3f(184.6, 380.6, 0); //M1
		glVertex3f(180.0, 380.0, 0); //K1
		glVertex3f(177.1, 375.7, 0); //L1
		glEnd();

		glPopMatrix();
	}

	//--------------------<\Astroids>---------------------------------

	//--------------------<Spaceship>--------------------------------

	//ship1
	if (ship1) {
		// Body
		glPushMatrix();
		glTranslated(shipMx, shipMy, 0);

		//Left
		glBegin(GL_TRIANGLES);
		glColor3d(83.0f / 255.0f, 4.0f / 255.0f, 97.0f / 255.0f);
		glVertex2d(200, 300);     //E
		glVertex2d(181.4, 219.99);//F
		glVertex2d(199.5, 219.99);//G
		glEnd();

		//120, 19, 69
		glBegin(GL_QUADS);
		glVertex2d(181.4, 219.99);//F
		glVertex2d(199.5, 219.99);//G
		glColor3d(120.0 / 255.0, 19.0 / 255.0, 69.0 / 255.0);
		glVertex2d(200, 200);//I
		glVertex2d(189.9, 200.3);//H
		glEnd();

		glBegin(GL_POLYGON);

		glColor3d(120.0 / 255.0, 19.0 / 255.0, 69.0 / 255.0);
		glVertex2d(169.2, 200.7);//j
		glVertex2d(181.4, 219.99);//F
		glVertex2d(189.9, 200.3);//H
		glVertex2d(180.6, 193);//L
		glVertex2d(179.8, 172.3);//K

		glEnd();

		//Right
		glPushMatrix();
		glTranslated(200, 0, 0);
		glRotatef(180, 0, 1, 0);
		glTranslated(-200, 0, 0);

		glBegin(GL_TRIANGLES);
		glColor3d(83.0f / 255.0f, 4.0f / 255.0f, 97.0f / 255.0f);
		glVertex2d(200, 300);     //E
		glVertex2d(181.4, 219.99);//F
		glVertex2d(199.5, 219.99);//G
		glEnd();

		glBegin(GL_QUADS);
		glVertex2d(181.4, 219.99);//F
		glVertex2d(199.5, 219.99);//G
		glColor3d(120.0 / 255.0, 19.0 / 255.0, 69.0 / 255.0);
		glVertex2d(200, 200);//I
		glVertex2d(189.9, 200.3);//H
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2d(181.4, 219.99);//F
		glVertex2d(189.9, 200.3);//H
		glVertex2d(180.6, 193);//L
		glVertex2d(179.8, 172.3);//K
		glVertex2d(169.2, 200.7);//j
		glEnd();

		glPopMatrix();

		//Window frame 20, 0, 23
		glPushMatrix();
		glTranslated(199.7, 248.4, 0);
		glScaled(0.9, 1.3, 1);

		glColor3d(20.0 / 255.0f, 0.0 / 255.0, 23.0 / 255.0);
		GLUquadric* quadric = gluNewQuadric();
		gluDisk(quadric, 0, 8.9, 100, 1);
		glPopMatrix();

		//Window 184, 169, 186
		glPushMatrix();
		glTranslated(199.7, 248.4, 0);
		glScaled(0.6, 1.0, 1);

		glColor3d(184.0 / 255.0f, 169.0 / 255.0, 186.0 / 255.0);
		gluDisk(quadric, 0, 8.9, 100, 1);
		glPopMatrix();

		//JetFire
		glPushMatrix();
		glTranslated(200.18, 184.69, 0);
		glColor3d(128.0 / 255.0f, 17.0 / 255.0, 0.0 / 255.0);
		gluDisk(quadric, 0, 17.10, 100, 1);
		glPopMatrix();

		glBegin(GL_TRIANGLES);
		glVertex2d(216.3, 184.89);//N
		glVertex2d(183.1, 184.89);//Q
		glColor4d(128.0 / 255.0f, 17.0 / 255.0, 0.0 / 255.0, 0.1);
		glVertex2d(200.0, 100);//P
		glEnd();

		glPushMatrix();
		glTranslated(200.18, 184.69, 0);
		glScaled(0.8, 0.8, 1);

		glColor3f(182.0 / 255.0f, 34.0 / 255.0, 3.0 / 255.0);
		gluDisk(quadric, 0, 17.10, 100, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(199.7, 184.89, 0);
		glScaled(0.8, 0.8, 1);
		glTranslated(-199.7, -184.89, 0);

		glBegin(GL_TRIANGLES);
		glVertex2d(216.3, 184.89);//N
		glVertex2d(183.1, 184.89);//Q
		glColor4f(182.0 / 255.0f, 34.0 / 255.0, 3.0 / 255.0, 0.3);
		glVertex2d(200.0, 100);//P
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslated(200.18, 184.69, 0);
		glScaled(0.5, 0.5, 1);

		glColor3f(252.0 / 255.0f, 100.0 / 255.0, 0.0 / 255.0);
		gluDisk(quadric, 0, 17.10, 100, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(199.7, 184.89, 0);
		glScaled(0.5, 0.5, 1);
		glTranslated(-199.7, -184.89, 0);

		glBegin(GL_TRIANGLES);
		glVertex2d(216.3, 184.89);//N
		glVertex2d(183.1, 184.89);//Q
		glColor4f(252.0 / 255.0f, 100.0 / 255.0, 0.0 / 255.0, 0.7);
		glVertex2d(200.0, 100);//P
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslated(200.18, 184.69, 0);
		glScaled(0.2, 0.2, 1);

		glColor3f(250.0 / 255.0f, 192.0 / 255.0, 0.0 / 255.0);
		gluDisk(quadric, 0, 17.10, 100, 1);
		glPopMatrix();

		glPushMatrix();
		glTranslated(199.7, 184.89, 0);
		glScaled(0.2, 0.3, 1);
		glTranslated(-199.7, -184.89, 0);

		glBegin(GL_TRIANGLES);
		glVertex2d(216.3, 184.89);//N
		glVertex2d(183.1, 184.89);//Q
		glVertex2d(200.0, 100);//P
		glEnd();
		glPopMatrix();

		glPopMatrix();
	}

	//ship2
	if (ship2) {
		//Body
		glPushMatrix();
		glTranslated(shipMx, shipMy, 0);
		glTranslated(200, 200, 0);
		glScaled(.9, 1.1, 1);
		glTranslated(-200, -200, 0);

		glBegin(GL_TRIANGLES);
		glColor3d(83.0f / 255.0f, 4.0f / 255.0f, 97.0f / 255.0f);
		glVertex2d(200, 300);     //E
		glVertex2d(181.4, 219.99);//F
		glVertex2d(199.5, 219.99);//G
		glEnd();

		//120, 19, 69
		glBegin(GL_QUADS);
		glVertex2d(181.4, 219.99);//F
		glVertex2d(199.5, 219.99);//G
		glColor3d(24.0 / 255.0, 74.0 / 255.0, 133.0 / 255.0);
		glVertex2d(200, 200);//I
		glVertex2d(189.9, 200.3);//H
		glEnd();

		glBegin(GL_POLYGON);

		glColor3d(24.0 / 255.0, 74.0 / 255.0, 133.0 / 255.0);
		glVertex2d(169.2, 200.7);//j
		glVertex2d(181.4, 219.99);//F
		glVertex2d(189.9, 200.3);//H
		glVertex2d(180.6, 193);//L
		glVertex2d(179.8, 172.3);//K

		glEnd();

		//Right
		glPushMatrix();
		glTranslated(200, 0, 0);
		glRotatef(180, 0, 1, 0);
		glTranslated(-200, 0, 0);

		glBegin(GL_TRIANGLES);
		glColor3d(83.0f / 255.0f, 4.0f / 255.0f, 97.0f / 255.0f);
		glVertex2d(200, 300);     //E
		glVertex2d(181.4, 219.99);//F
		glVertex2d(199.5, 219.99);//G
		glEnd();

		glBegin(GL_QUADS);
		//24, 74, 133
		glVertex2d(181.4, 219.99);//F
		glVertex2d(199.5, 219.99);//G
		glColor3d(24.0 / 255.0, 74.0 / 255.0, 133.0 / 255.0);
		glVertex2d(200, 200);//I
		glVertex2d(189.9, 200.3);//H
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2d(181.4, 219.99);//F
		glVertex2d(189.9, 200.3);//H
		glVertex2d(180.6, 193);//L
		glVertex2d(179.8, 172.3);//K
		glVertex2d(169.2, 200.7);//j
		glEnd();

		glPopMatrix();

		//Window frame 20, 0, 23
		glPushMatrix();
		glTranslated(199.7, 248.4, 0);
		glScaled(0.9, 1.3, 1);

		glColor3d(20.0 / 255.0f, 0.0 / 255.0, 23.0 / 255.0);
		GLUquadric* quadric = gluNewQuadric();
		gluDisk(quadric, 0, 8.9, 100, 1);
		glPopMatrix();

		//Window 184, 169, 186
		glPushMatrix();
		glTranslated(199.7, 248.4, 0);
		glScaled(0.6, 1.0, 1);

		glColor3d(184.0 / 255.0f, 169.0 / 255.0, 186.0 / 255.0);
		gluDisk(quadric, 0, 8.9, 100, 1);
		glPopMatrix();

		//JetFire (warp speed)
		glPushMatrix();

		glTranslated(200, 170.69, 0);
		glScaled(.7, 1.5, 1);
		glTranslated(-200, -184.69, 0);

		glPushMatrix();
		glTranslated(200.18, 184.69, 0);
		glColor3f(61.0 / 255.0, 136.0 / 255.0, 255.0 / 255.0);
		gluDisk(quadric, 0, 17.10, 100, 1);
		glPopMatrix();

		glBegin(GL_TRIANGLES);
		glVertex2d(216.3, 184.89);//N
		glVertex2d(183.1, 184.89);//Q
		glColor4f(61.0 / 255.0, 136.0 / 255.0, 255.0 / 255.0, 0.1);
		glVertex2d(200.0, 100);//P
		glEnd();

		glPopMatrix();

		glPushMatrix();

		glTranslated(200, 170.69, 0);
		glScaled(.5, 1.3, 1);
		glTranslated(-200, -184.69, 0);

		glPushMatrix();
		glTranslated(200.18, 184.69, 0);
		glColor3f(86.0 / 255.0, 182.0 / 255.0, 255.0 / 255.0);
		gluDisk(quadric, 0, 17.10, 100, 1);
		glPopMatrix();

		glBegin(GL_TRIANGLES);
		glVertex2d(216.3, 184.89);//N
		glVertex2d(183.1, 184.89);//Q
		glColor4f(86.0 / 255.0, 182.0 / 255.0, 255.0 / 255.0, 0.2);
		glVertex2d(200.0, 100);//P
		glEnd();

		glPopMatrix();

		glPushMatrix();

		glTranslated(200, 170.69, 0);
		glScaled(.2, .9, 1);
		glTranslated(-200, -184.69, 0);

		glPushMatrix();
		glTranslated(200.18, 184.69, 0);
		glColor3f(240.0 / 255.0, 250.0 / 255.0, 255.0 / 255.0);
		gluDisk(quadric, 0, 17.10, 100, 1);
		glPopMatrix();

		glBegin(GL_TRIANGLES);
		glVertex2d(216.3, 184.89);//N
		glVertex2d(183.1, 184.89);//Q
		glColor4f(240.0 / 255.0, 250.0 / 255.0, 255.0 / 255.0, .3);
		glVertex2d(200.0, 100);//P
		glEnd();

		glPopMatrix();

		glPopMatrix();
	}

	//--------------------<\Spaceship>--------------------------------


	//--------------------<Stamina(astroMana)>------------------------
	if (warp_speed_start || manaFull == false) {

		glPushMatrix();
		glTranslated(30, 100, 0);
		glScaled(.5, scalingFactor, 1);
		glTranslated(-30, -100, 0);

		glBegin(GL_POLYGON);
		glColor4f(240.0 / 255.0, 250.0 / 255.0, 255.0 / 255.0, .3);
		glVertex3d(20, 260, 0);//W
		glVertex3d(40, 260, 0);//V
		glVertex3d(40, 100, 0);//U
		glVertex3d(20, 100, 0);//T
		glEnd();
		glPopMatrix();


	}


	//--------------------<\Stamina>------------------------


	glFlush();
}


void timer_astroMana(int value) {
	// If warp speed is started and astroMana is not empty, consume astroMana
	if (warp_speed_start == true && manaEmpty == false) {
		manaFull = false;
		scalingFactor -= manaConsumption;
		ship2 = true;
		ship1 = false;
		if (scalingFactor <= 0) {
			warp_speed_start = false;
			manaEmpty = true;
			ship2 = false;
			ship1 = true;

			starsSpeed = starsL1;
			shipSpeed = shipSlow;
			galaxySpeed = galaxySlow;
			astroidSpeed = astroidSlow;
			planetSpeed = planetSlow;
		}
	}


	// If warp speed is stopped or astroMana is empty, stop warp speed
	if (warp_speed_start == false && manaFull == false) {
		scalingFactor += manaConsumption;
		ship1 = true;
		ship2 = false;

		if (scalingFactor >= 1) {
			manaFull = true;
			manaEmpty = false;
		}
	}

	glutPostRedisplay();
	glutTimerFunc(5, timer_astroMana, 0);
}


void timer_movingSpeed(int value) {
	starsM1 += starsSpeed;
	starsM2 += starsSpeed;
	astroidM += astroidSpeed;
	galaxyM += galaxySpeed;
	planetM += planetSpeed;

	if (starsM1 < -600.0) {
		starsM1 = 600.0;

	}

	if (starsM2 < -1200) {
		starsM2 = 0.0;
	}

	if (astroidM < -650) {
		astroidM = 0.0;
		astroidX = rand() % 401;
	}

	if (planetM < -536.05) {
		planetM = 127.9;
	}

	glutPostRedisplay();
	glutTimerFunc(1, timer_movingSpeed, 0);
}

void my_keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 'a':
		if (starsSpeed == starsL1) {
			starsSpeed = starsL2;
			shipSpeed = shipFast;

			astroidSpeed = astroidFast;
			planetSpeed = planetFast;
			galaxySpeed = galaxyFast;
			warp_speed_start = true;
		}
		break;

	case 'z':
		if (starsSpeed == starsL2) {
			starsSpeed = starsL1;
			shipSpeed = shipSlow;

			astroidSpeed = astroidSlow;
			planetSpeed = planetSlow;
			galaxySpeed = galaxySlow;
			warp_speed_start = false;
		}
		break;

	case 'h':
		if (hide == false)
			hide = true;
		else
			hide = false;
		break;

	case '1':
		if (toggleSpeed == false) {
			toggleSpeed = true;

			ship2 = true;
			ship1 = false;

			starsSpeed = starsL2;
			shipSpeed = shipFast;
			astroidSpeed = astroidFast;
			planetSpeed = planetFast;
			galaxySpeed = galaxyFast;
		}

		else {
			toggleSpeed = false;

			ship2 = false;
			ship1 = true;

			starsSpeed = starsL1;
			shipSpeed = shipSlow;
			astroidSpeed = astroidSlow;
			planetSpeed = planetSlow;
			galaxySpeed = galaxySlow;
		}
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void specFunc(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP: shipMy += shipSpeed; break;
	case GLUT_KEY_DOWN: shipMy -= shipSpeed; break;

	case GLUT_KEY_RIGHT:shipMx += shipSpeed; break;
	case GLUT_KEY_LEFT:shipMx -= shipSpeed; break;


	default: break;
	}
	glutPostRedisplay();
}

void main(int argc, char** argr) {

	glutInit(&argc, argr);

	glutInitWindowSize(400, 600);
	glutInitWindowPosition(150, 150);

	glutCreateWindow("OpenGL - 2D Template");
	glutDisplayFunc(Display);

	glutKeyboardFunc(my_keyboard);
	glutSpecialFunc(specFunc);

	glutTimerFunc(0, timer_astroMana, 0);
	glutTimerFunc(0, timer_movingSpeed, 0);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(10.0f / 255.0f, 1.0f / 255.0f, 28.0f / 255.0f, 0.0f);
	gluOrtho2D(0.0, 400, 0.0, 600);
	glEnable(GL_BLEND); //Enable blending.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glutMainLoop();
}

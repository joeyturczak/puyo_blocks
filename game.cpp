#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <string.h>

// Font
GLubyte space[] =
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

GLubyte rasters[][13] = {
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x36, 0x36, 0x36},
{0x00, 0x00, 0x00, 0x66, 0x66, 0xff, 0x66, 0x66, 0xff, 0x66, 0x66, 0x00, 0x00},
{0x00, 0x00, 0x18, 0x7e, 0xff, 0x1b, 0x1f, 0x7e, 0xf8, 0xd8, 0xff, 0x7e, 0x18},
{0x00, 0x00, 0x0e, 0x1b, 0xdb, 0x6e, 0x30, 0x18, 0x0c, 0x76, 0xdb, 0xd8, 0x70},
{0x00, 0x00, 0x7f, 0xc6, 0xcf, 0xd8, 0x70, 0x70, 0xd8, 0xcc, 0xcc, 0x6c, 0x38},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1c, 0x0c, 0x0e},
{0x00, 0x00, 0x0c, 0x18, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x18, 0x0c},
{0x00, 0x00, 0x30, 0x18, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x18, 0x30},
{0x00, 0x00, 0x00, 0x00, 0x99, 0x5a, 0x3c, 0xff, 0x3c, 0x5a, 0x99, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18, 0x00, 0x00},
{0x00, 0x00, 0x30, 0x18, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x60, 0x60, 0x30, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x06, 0x06, 0x03, 0x03},
{0x00, 0x00, 0x3c, 0x66, 0xc3, 0xe3, 0xf3, 0xdb, 0xcf, 0xc7, 0xc3, 0x66, 0x3c},
{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x38, 0x18},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x03, 0xe7, 0x7e},
{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0x07, 0x03, 0x03, 0xe7, 0x7e},
{0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0xff, 0xcc, 0x6c, 0x3c, 0x1c, 0x0c},
{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x03, 0x03, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e},
{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x03, 0x7f, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e},
{0x00, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x30, 0x18, 0x1c, 0x1c, 0x00, 0x00, 0x1c, 0x1c, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06},
{0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x06, 0x0c, 0x18, 0x30, 0x60},
{0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x18, 0x0c, 0x06, 0x03, 0xc3, 0xc3, 0x7e},
{0x00, 0x00, 0x3f, 0x60, 0xcf, 0xdb, 0xd3, 0xdd, 0xc3, 0x7e, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18},
{0x00, 0x00, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0xfc, 0xce, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xce, 0xfc},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xff},
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xcf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e},
{0x00, 0x00, 0x7c, 0xee, 0xc6, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06},
{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xff, 0xff, 0xe7, 0xc3},
{0x00, 0x00, 0xc7, 0xc7, 0xcf, 0xcf, 0xdf, 0xdb, 0xfb, 0xf3, 0xf3, 0xe3, 0xe3},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e},
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x3f, 0x6e, 0xdf, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c},
{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0xe0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff},
{0x00, 0x00, 0x3c, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3c},
{0x00, 0x03, 0x03, 0x06, 0x06, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x30, 0x60, 0x60},
{0x00, 0x00, 0x3c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x3c},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0x66, 0x3c, 0x18},
{0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x38, 0x30, 0x70},
{0x00, 0x00, 0x7f, 0xc3, 0xc3, 0x7f, 0x03, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0},
{0x00, 0x00, 0x7e, 0xc3, 0xc0, 0xc0, 0xc0, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x7f, 0xc3, 0xc3, 0xc3, 0xc3, 0x7f, 0x03, 0x03, 0x03, 0x03, 0x03},
{0x00, 0x00, 0x7f, 0xc0, 0xc0, 0xfe, 0xc3, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0xfc, 0x30, 0x30, 0x30, 0x33, 0x1e},
{0x7e, 0xc3, 0x03, 0x03, 0x7f, 0xc3, 0xc3, 0xc3, 0x7e, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0xc0, 0xc0, 0xc0, 0xc0},
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x18, 0x00},
{0x38, 0x6c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x0c, 0x00},
{0x00, 0x00, 0xc6, 0xcc, 0xf8, 0xf0, 0xd8, 0xcc, 0xc6, 0xc0, 0xc0, 0xc0, 0xc0},
{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78},
{0x00, 0x00, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xfe, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xfc, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, 0x00, 0x00},
{0xc0, 0xc0, 0xc0, 0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xfe, 0x00, 0x00, 0x00, 0x00},
{0x03, 0x03, 0x03, 0x7f, 0xc3, 0xc3, 0xc3, 0xc3, 0x7f, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xfe, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xfe, 0x03, 0x03, 0x7e, 0xc0, 0xc0, 0x7f, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x1c, 0x36, 0x30, 0x30, 0x30, 0x30, 0xfc, 0x30, 0x30, 0x30, 0x00},
{0x00, 0x00, 0x7e, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xc3, 0xe7, 0xff, 0xdb, 0xc3, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xc3, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0xc3, 0x00, 0x00, 0x00, 0x00},
{0xc0, 0x60, 0x60, 0x30, 0x18, 0x3c, 0x66, 0x66, 0xc3, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0xff, 0x60, 0x30, 0x18, 0x0c, 0x06, 0xff, 0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x0f, 0x18, 0x18, 0x18, 0x38, 0xf0, 0x38, 0x18, 0x18, 0x18, 0x0f},
{0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18},
{0x00, 0x00, 0xf0, 0x18, 0x18, 0x18, 0x1c, 0x0f, 0x1c, 0x18, 0x18, 0x18, 0xf0},
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x8f, 0xf1, 0x60, 0x00, 0x00, 0x00}
};

GLuint fontOffset;

void makeRasterFont(void)
{
    GLuint i, j;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    fontOffset = glGenLists(128);
    for (i = 32; i < 127; i++) {
        glNewList(i + fontOffset, GL_COMPILE);
        glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, rasters[i - 32]);
        glEndList();
    }
    glNewList(fontOffset + ' ', GL_COMPILE);
    glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, space);
    glEndList();
}

void printString(const char* s)
{
    glPushAttrib(GL_LIST_BIT);
    glListBase(fontOffset);
    glCallLists(strlen(s), GL_UNSIGNED_BYTE, (GLubyte*)s);
    glPopAttrib();
}

// Utility
int quick_pow10(int n)
{
    static int pow10[10] = {
        1, 10, 100, 1000, 10000,
        100000, 1000000, 10000000, 100000000, 1000000000
    };

    return pow10[n];
}

int getSpeed(int n)
{
    static int speed[7] = {
        900, 800, 700, 600, 500, 400, 300
    };
    return speed[n];
}

// Game variables
enum Block { red, blue, green, yellow, purple, white, empty };
enum Orientation { down, left, up, right };
enum Speed { slowest, slower, slow, normal, fast, faster, fastest };

float gridCols[6] = { -3.5, -2.5, -1.5, -0.5, 0.5, 1.5 };
float gridRows[13] = { -4.5, -3.5, -2.5, -1.5, -0.5, 0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5 };

int startPosition[2] = { 2, 11 };

int currentBlock[2];
int nextBlock[2];
int score;
const int BLOCK_SCORE = 100;

const int playAreaWidth = 6;
const int playAreaHeight = 13;

int playArea[playAreaWidth][playAreaHeight];
int connections[playAreaWidth][playAreaHeight];
int scoringBlocks[playAreaWidth][playAreaHeight];

int position[2];
int orientation;

bool rotateRight;
bool rotateLeft;
bool move;
bool gameOver;
bool paused;
bool scoring;
bool dropping;
bool newBlock;
bool chains;
bool counting;
bool playerDrop;

int chainBonus;
int speed;

int timer = 0;
int timeSinceLastTurn = 0;
int timeSinceLastDrop = 0;
int timeSinceLastScore = 0;

const int fastTurnTime = 50;
int turnTime;
const int dropTime = 250;
const int scoreTime = 500;

GLfloat textColorWhite[3] = { 1.0, 1.0, 1.0 };
GLfloat textColorRed[3] = { 1.0, 0.0, 0.0 };

int randomBlock()
{
    int num = rand() % 5;
    return num;
}

void initializeGame()
{
    srand(time(0));
    // Score 0
    score = 0;
    // Start position
    position[0] = startPosition[0];
    position[1] = startPosition[1];
    // Timer
    timer = glutGet(GLUT_ELAPSED_TIME);
    // Play Area and scoring blocks
    for (int i = 0; i < playAreaWidth; i++)
    {
        for (int j = 0; j < playAreaHeight; j++)
        {
            playArea[i][j] = empty;
            scoringBlocks[i][j] = 0;
            connections[i][j] = 0;
        }
    }
    // Current block
    currentBlock[0] = randomBlock();
    currentBlock[1] = randomBlock();
    // Next Block
    nextBlock[0] = randomBlock();
    nextBlock[1] = randomBlock();
    // Orientation
    orientation = down;
    // Rotate
    rotateLeft = true;
    rotateRight = true;
    // Move
    move = true;
    dropping = false;
    scoring = false;
    gameOver = false;
    paused = false;
    newBlock = false;
    chains = false;
    playerDrop = false;
    chainBonus = 1;
    speed = normal;
    turnTime = getSpeed(speed);
}

void drawBackground()
{
    // Gray background covering entire screen
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    glScalef(10.0, 16.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Main play area
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-1.0, 1.0, 0.0);
    glScalef(6.0, 12.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Next block area
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(3.5, 4.5, 0.0);
    glScalef(2.0, 3.0, 1.0);
    glutSolidCube(1.0);
    glColor3f(0.8, 0.8, 0.8);
    glutWireCube(1.0);
    glPopMatrix();

    // Score area
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.0, -6.5, 0.0);
    glScalef(8.0, 1.0, 1.0);
    glutSolidCube(1.0);
    glColor3f(0.8, 0.8, 0.8);
    glutWireCube(1.0);
    glPopMatrix();

    // Game over area
    glPushMatrix();
    glColor3f(0.1, 0.0, 0.0);
    glTranslatef(-1.5, 6.5, 0.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Main play area frame
    glPushMatrix();
    glTranslatef(-1.0, 1.0, 0.0);
    glScalef(6.0, 12.0, 1.0);
    glColor3f(0.8, 0.8, 0.8);
    glutWireCube(1.0);
    glPopMatrix();
}


void colorBlock(int color)
{
    switch (color)
    {
    case red:
        glColor3f(1.0, 0.0, 0.0);
        break;
    case blue:
        glColor3f(0.0, 0.0, 1.0);
        break;
    case green:
        glColor3f(0.0, 1.0, 0.0);
        break;
    case yellow:
        glColor3f(1.0, 1.0, 0.0);
        break;
    case purple:
        glColor3f(1.0, 0.0, 1.0);
        break;
    case white:
        glColor3f(1.0, 1.0, 1.0);
        break;
    default:
        glColor3f(0.0, 0.0, 0.0);
        break;
    }
}

int getPlayerLeft()
{
    if (orientation == left)
        return position[0] - 1;
    else
        return position[0];
}

int getPlayerRight()
{
    if (orientation == right)
        return position[0] + 1;
    else
        return position[0];
}

int getPlayerTop()
{
    if (orientation == down)
        return position[1] + 1;
    else
        return position[1];
}

int getPlayerBottom()
{
    if (orientation == up)
        return position[1] - 1;
    else
        return position[1];
}

void movePlayerHoriz(int direction)
{
    // Check if movement is possible
    // Check for edges
    if (direction < 0)
    {
        // Move left
        if (getPlayerLeft() == 0)
            // Player at left edge
            return;
        if (playArea[getPlayerLeft() - 1][getPlayerTop()] == empty && playArea[getPlayerLeft() - 1][getPlayerBottom()] == empty)
            position[0] += direction;

    }
    if (direction > 0)
    {
        // Move right
        if (getPlayerRight() == 5)
            // Player at right edge
            return;
        if (playArea[getPlayerRight() + 1][getPlayerTop()] == empty && playArea[getPlayerRight() + 1][getPlayerBottom()] == empty)
            position[0] += direction;
    }
}

void movePlayerVert()
{
    if (getPlayerBottom() > 0)
        position[1] -= 1;
}

void translatePlayer(int blockNum)
{
    float x = gridCols[position[0]];
    float y = gridRows[position[1]];
    if (orientation == down)
    {
        x = gridCols[position[0]];
        y = gridRows[position[1]] + blockNum;
    }
       
    if (orientation == left)
    {
        x = gridCols[position[0]] - blockNum;
        y = gridRows[position[1]];
    }

    if (orientation == up)
    {
        x = gridCols[position[0]];
        y = gridRows[position[1]] - blockNum;
    }
    if (orientation == right)
    {
        x = gridCols[position[0]] + blockNum;
        y = gridRows[position[1]];
    }
    glTranslatef(x, y, 0.0);
}


void drawPlayer()
{
    // Only draw in the frame
    if (position[1] < startPosition[1])
    {
        glPushMatrix();
        colorBlock(currentBlock[1]);
        translatePlayer(1);
        glutSolidCube(1.0);
        if (currentBlock[1] == empty)
            glColor3f(0.0, 0.0, 0.0);
        else
            glColor3f(0.2, 0.2, 0.2);
        glutWireCube(1.0);
        glPopMatrix();
    }
    glPushMatrix();
    colorBlock(currentBlock[0]);
    translatePlayer(0);
    glutSolidCube(1.0);
    if (currentBlock[0] == empty)
        glColor3f(0.0, 0.0, 0.0);
    else
        glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
}

void drawNext()
{
    glPushMatrix();
    colorBlock(nextBlock[0]);
    glTranslatef(3.5, 4.0, 0.0);
    glutSolidCube(1.0);
    glColor3f(0.2, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();
    colorBlock(nextBlock[1]);
    glTranslatef(3.5, 5.0, 0.0);
    glutSolidCube(1.0);
    glColor3f(0.2, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
}

void drawBlocks()
{
    for (int i = 0; i < playAreaWidth; i++)
    {
        for (int j = 0; j < playAreaHeight; j++)
        {
            if (playArea[i][j] != empty)
            {
                glPushMatrix();
                colorBlock(playArea[i][j]);
                glTranslatef(gridCols[i], gridRows[j], 0);
                glutSolidCube(1.0);
                glColor3f(0.2, 0.2, 0.2);
                glutWireCube(1.0);
                glPopMatrix();
            }
        }
    }
}

bool checkPlayerLanding()
{
    if (getPlayerBottom() == 0)
        return true;
    if (playArea[getPlayerLeft()][getPlayerBottom() - 1] != empty || playArea[getPlayerRight()][getPlayerBottom() - 1] != empty)
        return true;

    return false;
}

void addBlocksToPlayArea()
{
    playArea[position[0]][position[1]] = currentBlock[0];
    switch (orientation)
    {
    case down:
        playArea[position[0]][position[1] + 1] = currentBlock[1];
        break;
    case left:
        playArea[position[0] - 1][position[1]] = currentBlock[1];
        break;
    case up:
        playArea[position[0]][position[1] - 1] = currentBlock[1];
        break;
    case right:
        playArea[position[0] + 1][position[1]] = currentBlock[1];
        break;
    }
    currentBlock[0] = empty;
    currentBlock[1] = empty;
}

void dropBlocks()
{
    dropping = false;

    for (int i = 0; i < playAreaWidth; i++)
    {
        for (int j = 1; j < playAreaHeight - 1; j++)
        {
            if (playArea[i][j - 1] == empty && playArea[i][j] != empty)
            {
                dropping = true;
                playArea[i][j - 1] = playArea[i][j];
                playArea[i][j] = empty;
            }
        }
    }
    glutPostRedisplay();
}

void countConnections()
{
    for (int i = 0; i < playAreaWidth; i++)
    {
        for (int j = 0; j < playAreaHeight - 2; j++)
        {
            int conn = 0;
            if (playArea[i][j] != empty)
            {
                // Check down
                if (j > 0)
                {
                    if (playArea[i][j] == playArea[i][j - 1])
                        conn++;
                }
                // Check left
                if (i > 0)
                {
                    if (playArea[i][j] == playArea[i - 1][j])
                        conn++;
                }
                // Check up
                if (j < playAreaHeight - 2)
                {
                    if (playArea[i][j] == playArea[i][j + 1])
                        conn++;
                }
                // Check right
                if (i < playAreaWidth - 1)
                {
                    if (playArea[i][j] == playArea[i + 1][j])
                        conn++;
                }
            }
            connections[i][j] = conn;
        }
    }
}

void resetArrays()
{
    for (int i = 0; i < playAreaWidth; i++)
    {
        for (int j = 0; j < playAreaHeight; j++)
        {
            scoringBlocks[i][j] = 0;
            connections[i][j] = 0;
        }
    }
}

bool checkForChains(int col, int row)
{
    int conn = connections[col][row];
    int nextConn;

    if (conn >= 3)
        return true;
    else if (conn == 2)
    {
        // Check each surrounding block for a 2 or greater
        // A 4 chain will always have 2 blocks with 2 or more connections adjacent to each other
        // Down
        if (row > 0)
        {
            nextConn = connections[col][row - 1];
            if (playArea[col][row] == playArea[col][row - 1] && nextConn >= 2)
                return true;
        }
        // Left
        if (col > 0)
        {
            nextConn = connections[col - 1][row];
            if (playArea[col][row] == playArea[col - 1][row] && nextConn >= 2)
                return true;
        }
        // Up
        if (row < playAreaHeight - 2)
        {
            nextConn = connections[col][row + 1];
            if (playArea[col][row] == playArea[col][row + 1] && nextConn >= 2)
                return true;
        }
        // Right
        if (col < playAreaWidth - 1)
        {
            nextConn = connections[col + 1][row];
            if (playArea[col][row] == playArea[col + 1][row] && nextConn >= 2)
                return true;
        }
    }
    else if (conn == 1)
    {
        // Check each surrounding block for a 2 or greater. If it's 1, then there is no 4 chain.
        // Check down
        if (row > 0)
        {
            nextConn = connections[col][row - 1];
            if (playArea[col][row] == playArea[col][row - 1] && nextConn >= 2)
                return checkForChains(col, row - 1);
        }
        // Check left
        if (col > 0)
        {
            nextConn = connections[col - 1][row];
            if (playArea[col][row] == playArea[col - 1][row] && nextConn >= 2)
                return checkForChains(col - 1, row);
        }
        // Check up
        if (row < playAreaHeight - 2)
        {
            nextConn = connections[col][row + 1];
            if (playArea[col][row] == playArea[col][row + 1] && nextConn >= 2)
                return checkForChains(col, row + 1);
        }
        // Check right
        if (col < playAreaWidth - 1)
        {
            nextConn = connections[col + 1][row];
            if (playArea[col][row] == playArea[col + 1][row] && nextConn >= 2)
                return checkForChains(col + 1, row);
        }
    }
    return false;
}

void checkForGameOver()
{
    if (playArea[startPosition[0]][startPosition[1]] != empty)
        gameOver = true;
}

void loadNewBlock()
{
    currentBlock[0] = nextBlock[0];
    currentBlock[1] = nextBlock[1];

    nextBlock[0] = randomBlock();
    nextBlock[1] = randomBlock();

    position[0] = startPosition[0];
    position[1] = startPosition[1];

    orientation = down;
}

void removeBlocks()
{
    for (int i = 0; i < playAreaWidth; i++)
    {
        for (int j = 0; j < playAreaHeight - 2; j++)
        {
            if (playArea[i][j] == white)
            {
                playArea[i][j] = empty;
                score += (BLOCK_SCORE * chainBonus);
            }   
        }
    }
}

void resetTimers()
{
    timeSinceLastTurn = 0;
    timeSinceLastDrop = 0;
    timeSinceLastScore = 0;
    timer = glutGet(GLUT_ELAPSED_TIME);
}

void updateTimers()
{
    int t = glutGet(GLUT_ELAPSED_TIME);
    int dt = (t - timer);
    timeSinceLastTurn += dt;
    timeSinceLastDrop += dt;
    timeSinceLastScore += dt;
    timer = t;
}

void updateRotation()
{
    rotateLeft = false;
    rotateRight = false;
    // Check down orientation
    if (orientation == down)
    {
        if (getPlayerLeft() > 0)
        {
            if (playArea[getPlayerLeft() - 1][getPlayerBottom()] == empty)
                rotateLeft = true;
        }

        if (getPlayerRight() < playAreaWidth - 1)
        {
            if (playArea[getPlayerRight() + 1][getPlayerBottom()] == empty)
                rotateRight = true;
        }
    }
    // Check left orientation
    if (orientation == left)
    {
        if (getPlayerBottom() > 0)
        {
            if (playArea[getPlayerRight()][getPlayerBottom() - 1] == empty)
                rotateRight = true;
        }

        // Rotating left will always be available because there will be nothing above.
        rotateLeft = true;
    }
    // Check up orientation
    if (orientation == up)
    {
        if (getPlayerLeft() > 0)
        {
            if (playArea[getPlayerLeft() - 1][getPlayerTop()] == empty)
                rotateRight = true;
        }

        if (getPlayerRight() < playAreaWidth - 1)
        {
            if (playArea[getPlayerRight() + 1][getPlayerTop()] == empty)
                rotateLeft = true;
        }
    }
    // Check right orientation
    if (orientation == right)
    {
        if (getPlayerBottom() > 0)
        {
            if (playArea[getPlayerLeft()][getPlayerBottom() - 1] == empty)
                rotateLeft = true;
        }

        // Rotating right will always be available because there will be nothing above.
        rotateRight = true;
    }
}

void rotatePlayer(int direction)
{
    if (direction < 0)
    {
        if (orientation == down)
            orientation = left;
        else if (orientation == left)
            orientation = up;
        else if (orientation == up)
            orientation = right;
        else if (orientation == right)
            orientation = down;
    }

    if (direction > 0)
    {
        if (orientation == down)
            orientation = right;
        else if (orientation == left)
            orientation = down;
        else if (orientation == up)
            orientation = left;
        else if (orientation == right)
            orientation = up;
    }
}

void drawText()
{
    std::string s;
    glColor3fv(textColorWhite);
    // Title
    glRasterPos2f(-1.4, 7.4);
    printString("PUYO BLOCKS");
    
    // Next Block
    glRasterPos2f(3.05, 6.3);
    printString("NEXT");

    // Controls
    glRasterPos2f(2.7, 2.3);
    printString("CONTROLS");

    glRasterPos2f(2.3, 1.8);
    printString("A: MOVE LEFT");
    glRasterPos2f(2.3, 1.4);
    printString("D: MOVE RIGHT");
    glRasterPos2f(2.3, 1.0);
    printString("Q: ROTATE CCW");
    glRasterPos2f(2.3, 0.6);
    printString("E: ROTATE CW");
    glRasterPos2f(2.3, 0.2);
    printString("S: DROP BLOCK");
    glRasterPos2f(2.3, -0.2);
    printString("R: SPEED UP");
    glRasterPos2f(2.3, -0.6);
    printString("F: SPEED DOWN");
    glRasterPos2f(2.3, -1.0);
    printString("SPACE: PAUSE");


    // Instructions
    glRasterPos2f(2.7, -2.0);
    printString("CONNECT 4");
    glRasterPos2f(2.15, -2.4);
    printString("OR MORE BLOCKS");
    glRasterPos2f(2.6, -2.8);
    printString("OF THE SAME");
    glRasterPos2f(2.15, -3.2);
    printString("COLOR TO SCORE");

    // Speed
    switch (speed)
    {
    case 0:
        s = "SPEED: SLOWEST";
        break;
    case 1:
        s = "SPEED: SLOWER";
        break;
    case 2:
        s = "SPEED: SLOW";
        break;
    case 3:
        s = "SPEED: NORMAL";
        break;
    case 4:
        s = "SPEED: FAST";
        break;
    case 5:
        s = "SPEED: FASTER";
        break;
    case 6:
        s = "SPEED: FASTEST";
        break;
    default:
        break;
    }
    glRasterPos2f(2.2, -4.9);
    printString(s.c_str());

    if (gameOver)
        glColor3fv(textColorRed);
    // Score Text
    glRasterPos2f(-3.9, -6.6);

    s = "SCORE: ";
    int digit = 0;
    int scoreLeft = score;
    for (int i = 9; i > 0; i--)
    {
        digit = scoreLeft / quick_pow10(i - 1);
        if (digit > 9)
            digit = scoreLeft % quick_pow10(i - 1);
        scoreLeft -= (digit * quick_pow10(i - 1));
        s.push_back((char)('0' + digit));
    }
    printString(s.c_str());

    // Chain Multiplier Text
    glRasterPos2f(0.8, -6.6);

    s = "CHAIN BONUS: X";
    s.push_back((char)('0' + chainBonus));
    printString(s.c_str());

    if (gameOver)
    {
        glColor3fv(textColorWhite);
        glRasterPos2f(-2.0, 1.0);
        printString("GAME OVER");
        glRasterPos2f(-2.5, -5.6);
        printString("PRESS SPACE TO START AGAIN");
    }
    if (paused)
    {
        glColor3fv(textColorWhite);
        glRasterPos2f(-2.0, 1.0);
        printString(" PAUSED ");
        glRasterPos2f(-2.5, -5.6);
        printString("PRESS SPACE TO UNPAUSE");
    }
}

void game()
{
    updateTimers();
    updateRotation();
    if (!playerDrop)
        turnTime = getSpeed(speed);
    if (!gameOver && !paused)
    {
        if (move && timeSinceLastTurn > turnTime)
        {
            movePlayerVert();
            if (checkPlayerLanding())
            {
                // Put blocks into playArea
                addBlocksToPlayArea();
                // Update state
                move = false;
                dropping = true;
                
            }
            resetTimers();
        }
        if (dropping && timeSinceLastDrop > dropTime)
        {
            dropBlocks();
            if (!dropping)
            {
                counting = true;
            }
            resetTimers();
                
        }
        if (counting)
        {
            countConnections();

            chains = false;
            for (int i = 0; i < playAreaWidth; i++)
            {
                for (int j = 0; j < playAreaHeight - 2; j++)
                {
                    if (playArea[i][j] != empty)
                    {
                        if (checkForChains(i, j))
                        {
                            chains = true;
                            scoringBlocks[i][j] = 1;
                        }
                    }
                }
            }

            for (int i = 0; i < playAreaWidth; i++)
            {
                for (int j = 0; j < playAreaHeight - 2; j++)
                {
                    if (scoringBlocks[i][j] > 0)
                    {
                        playArea[i][j] = white;
                    }
                }
            }

            resetArrays();
            scoring = true;
            counting = false;
            resetTimers();
        }
        if (scoring && timeSinceLastScore > scoreTime)
        {
            if (chains)
            {
                removeBlocks();
                dropping = true;
                chainBonus += 1;
            }
            else
            {
                newBlock = true;
            }
            scoring = false;
            chains = false;
            resetTimers();
        }
        if (!scoring && !dropping)
        {
            move = true;
            chainBonus = 1;
            
            if (newBlock)
            {
                newBlock = false;
                playerDrop = false;
                // Load new block
                loadNewBlock();
            }
        }
    }

    checkForGameOver();

    glutPostRedisplay();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_FLAT);

    makeRasterFont();

    initializeGame();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();
    glPushMatrix();

    drawBackground();

    drawPlayer();

    drawNext();

    drawBlocks();

    glPopMatrix();
    drawText();
    glutSwapBuffers();

    // Normal play
    game();
    
    
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5, 5, -8, 8);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'a':
    case 'A':
        // Move left
        if (move && !paused && !playerDrop)
            movePlayerHoriz(-1);
        break;
    case 'd':
    case 'D':
        // Move right
        if (move && !paused && !playerDrop)
            movePlayerHoriz(1);
        break;
    case 'q':
    case 'Q':
        // Rotate left
        if (move && rotateLeft && !paused && !playerDrop)
            rotatePlayer(-1);
        break;
    case 'e':
    case 'E':
        // Rotate right
        if (move && rotateRight && !paused && !playerDrop)
            rotatePlayer(1);
        break;
    case 's':
    case 'S':
        // Move down faster
        if (move && !paused)
        {
            turnTime = fastTurnTime;
            playerDrop = true;
        }
            
        break;
    case 32: // Space
        if (gameOver)
            initializeGame();
        else
        {
            if (paused)
            {
                resetTimers();
                paused = false;
            }
            else
                paused = true;
        }
        break;
    case 'r':
    case 'R':
        if (!paused && !gameOver && speed < fastest)
            speed++;
        break;
    case 'f':
    case 'F':
        if (!paused && !gameOver && speed > 0)
            speed--;
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }

    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
#include<time.h>
#include "GL/glut.h"
#include<stdlib.h>
#include <cstdio>

using namespace std;

//Разукрашка
class Painter{
public:
	enum Color{ RED, WHITE, MAGENTA, DARK_BLUE, GREEN, BROWN, CYAN, BLACK };
	void rect(int x1, int y1, int x2, int y2){
		glBegin(GL_QUADS);
		glVertex2f(x1, y1);
		glVertex2f(x2, y1);
		glVertex2f(x2, y2);
		glVertex2f(x1, y2);
		glEnd();
	};
	void SetColor(Color color)
	{
		static const struct
		{
			float r, g, b;
		}
		colors[] = {
			{ 1, 0, 0 },//red
			{ 1, 1, 1 },//white
			{ 1, 0, 1 },//magenta
			{ 0, 0, 0.5 },//dark blue
			{ 0, 1, 0 },//green
			{ 0.5, 0.5, 0 },//brown
			{ 0, 1, 1 },//cyan
			{ 0, 0, 1 },//black
		};
		glColor3f(colors[color].r, colors[color].g, colors[color].b);
	};
};

//Класс фигура
class Tetromino{
public:
	enum Direction { LEFT = -1, Right = 1 };
	enum Name{ I, J, L, O, S, Z, T };
	Tetromino(Name name) : name_(name), angel_(0), x_(3), y_(0){};
	void draw(Painter &)const;
	void move(int dx, int dy){ x_ += dx; y_ += dy; };
	void rotate(Direction d){
		angel_ = (angel_ + d + 4) % 4;
	};
	bool map(int x, int y)const;
	int x()const{ return x_; }
	int y()const{ return y_; }
private:
	Name name_;
	int angel_;
	int x_;
	int y_;
};

void Tetromino::draw(Painter &p)const{
	p.SetColor(static_cast<Painter::Color>(name_));
	for (int x = 0; x < 4; ++x)
	{
		for (int y = 0; y < 4; ++y)
		{
			if (map(x, y))
			{
				p.rect((x + x_) * 8 + 1, (y + y_) * 8 + 1, (x + x_ + 1) * 8 - 1, (y + y_ + 1) * 8 - 1);
			}
		}
	}
};
//Фигуры и их поворот
bool Tetromino::map(int x, int y)const{
	static const char* SHAPES[] = {
		"  8 "
		"  8 "
		"  8 "
		"  8 ",
		//I
		"  8 "
		"  8 "
		" 88 "
		"    ",
		//J
		" 8  "
		" 8  "
		" 88 "
		"    ",
		//L
		" 88 "
		" 88 "
		"    "
		"    ",
		//O
		"  8 "
		" 88 "
		" 8  "
		"    ",
		//S
		" 8  "
		" 88 "
		"  8 "
		"    ",
		//Z
		"    "
		" 888"
		"  8 "
		"    ",
		//T
	};
	static const struct{ int x, y; }ROTATE[][16] = {
		{
			{ 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 },
			{ 1, 0 }, { 1, 1 }, { 1, 2 }, { 1, 3 },
			{ 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 },
			{ 3, 0 }, { 3, 1 }, { 3, 2 }, { 3, 3 }
		},
		{
			{ 3, 0 }, { 2, 0 }, { 1, 0 }, { 0, 0 },
			{ 3, 1 }, { 2, 1 }, { 1, 1 }, { 0, 1 },
			{ 3, 2 }, { 2, 2 }, { 1, 2 }, { 0, 2 },
			{ 3, 3 }, { 2, 3 }, { 1, 3 }, { 0, 3 }
		},
		{
			{ 3, 3 }, { 3, 2 }, { 3, 1 }, { 3, 0 },
			{ 2, 3 }, { 2, 2 }, { 2, 1 }, { 2, 0 },
			{ 1, 3 }, { 1, 2 }, { 1, 1 }, { 1, 0 },
			{ 0, 3 }, { 0, 2 }, { 0, 1 }, { 0, 0 }
		},
		{
			{ 0, 3 }, { 1, 3 }, { 2, 3 }, { 3, 3 },
			{ 0, 2 }, { 1, 2 }, { 2, 2 }, { 3, 2 },
			{ 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 1 },
			{ 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }
		},
	};
	return SHAPES[name_][ROTATE[angel_][y * 4 + x].y * 4 + ROTATE[angel_][y * 4 + x].x] != ' ';
}


// Поведение 
class Well{
public:
	Well(){
		for (int y = 0; y < 20; ++y)
		{
			for (int x = 0; x < 20; ++x)
			{
				map_[y][x] = false;
			}
		}

	};
	void draw(Painter &p)const{
		p.SetColor(Painter::WHITE);
		for (int y = 0; y < 20; ++y)
		{
			for (int x = 0; x < 20; ++x)
			{
				if (map_[y][x])
				{
					p.rect(x * 8 + 1, y * 8 + 1, (x + 1) * 8 - 1, (y + 1) * 8 - 1);
				}
				else
				{
					p.rect(x * 8 + 3, y * 8 + 3, (x + 1) * 8 - 4, (y + 1) * 8 - 4);
				}
			}
		}
	};
	bool isCollison(const Tetromino &t) const{
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
			{
				if (t.map(x, y))
				{
					int wx = x + t.x();
					int wy = y + t.y();
					if (wx<0 || wx>=10 || wy<0 || wy>=20)
					{
						return true;
					}
					if (map_[wy][wx])
					{
						return true;
					}
				}
			}
		}
		return false;
	};
	void unite(const Tetromino &t){
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
			{
				int wx = x + t.x();
				int wy = y + t.y();
				if (wx >= 0 && wx<10 && wy >= 0 && wy<20)
				{
					map_[wy][wx] = map_[wy][wx] || t.map(x, y);
				}
			}
		}
	};
	int removeSolidLines()
	{
		int res = 0;
		for (int y = 0; y < 20; ++y)
		{
			bool solid = true;
			for (int x = 0; x < 10; ++x)
			{
				if (!map_[y][x])
				{
					solid = false;
					break;
				}
			}
			if (solid)
			{
				++res;
				for (int yy = y - 1; yy > 0; --yy)
				{
					for (int x = 0; x < 10; ++x)
					{
						map_[yy + 1][x] = map_[yy][x];
					}
				}

			}
			for (int x = 0; x < 10; ++x)
			{
				map_[0][x] = false;
			}
		}
		return res;
	};
private:
	bool map_[20][10];
};
// Сама Игра
class Game{
public:
	enum Direction{ UP, DOWN, LEFT, RIGHT };
	Game() :tetromino_(static_cast<Tetromino::Name>(rand() % 7)){};
	void draw(Painter &p){
		well_.draw(p);
		tetromino_.draw(p);

	};
	void tick(){
		Tetromino t = tetromino_;
		t.move(0, 1);
		if (!well_.isCollison(t))
		{
			tetromino_ = t;
		}
		else
		{
			well_.unite(tetromino_);
			well_.removeSolidLines();
			tetromino_ = Tetromino(static_cast<Tetromino::Name>(rand() % 7));
			if (well_.isCollison(tetromino_))
			{
				restart();
			}
		}
	};
	void  restart(){ well_ = Well(); }
	void KeyEvent(Direction d){
		Tetromino t = tetromino_;
		switch (d)
		{
		case Game::UP:t.rotate(Tetromino::LEFT);
			break;
		case Game::DOWN:t.move(0, 1);
			break;
		case Game::LEFT:t.move(-1, 0);
			break;
		case Game::RIGHT:t.move(1, 0);
			break;
		}
		if (!well_.isCollison(t))
		{
			tetromino_ = t;
		}
	};
private:
	Well well_;
	Tetromino tetromino_;
};

Game game;

//отображение
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	Painter p;
	game.draw(p);
	glutSwapBuffers();
}

//Таймер Задержки
void timer(int){
	game.tick();
	display();
	glutTimerFunc(1000, timer, 0);
}

// Обработчик сообщений
void KeyEvent(int key, int x, int y){
	switch (key)
	{
	case GLUT_KEY_LEFT:
		game.KeyEvent(Game::LEFT);
		break;
	case GLUT_KEY_RIGHT:
		game.KeyEvent(Game::RIGHT);
		break;
	case GLUT_KEY_UP:
		game.KeyEvent(Game::UP);
		break;
	case GLUT_KEY_DOWN:
		game.KeyEvent(Game::DOWN);
		break;
	default:
		break;
	}
	display();
}

int main(int argc, char **argv){
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(10 * 20, 20 * 20);
	glutInitWindowPosition(400, 200);
	glutCreateWindow("Tetris");
	glClearColor(0.5, 0.5, 0.5, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 10 * 8, 20 * 8, 0, -1.0, 1.0);
	glutDisplayFunc(display);
	timer(0);
	glutSpecialFunc(KeyEvent);
	glutMainLoop();
	return 0;
}
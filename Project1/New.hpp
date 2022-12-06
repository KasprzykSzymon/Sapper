#pragma once
#define RMIN 10
#define RMAX 40
#define CMIN 10
#define CMAX 60
#define MMIN 10

#define SSIZE 100
#define SGROW 50

#define FSIZE 20 

struct Pool
{
	bool open;
	bool flag;
	bool mine;
	bool exploded;
	int  count;
};

class Minefield
{
protected:
    Pool** T;
    int r, c;
    int mc;
public:
    Minefield(int m, int n, int mn);
    ~Minefield();
    int RowCount();
    int ColCount();
    int MinCount();
    Pool& At(int rr, int cc);
};


class Stack
{
protected:
    int* S;
    int sp;
    int n;
public:
    Stack();
    ~Stack();
    bool notEmpty();
    void push(int a, int b);
    void pop(int& a, int& b);
};
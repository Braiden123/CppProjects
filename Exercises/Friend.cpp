//:Friend.cpp

struct X;

struct Y {
	void f(X*);
};

struct X {
private:
	int i;
public:
	X();
	friend void g(X*, int);
	friend void Y::f(X*);
	friend struct Z;
	friend void h();
};

X::X() {
	i = 0;
}

inline void g(X* x, int i) {
	x->i = i;
}

inline void Y::f(X* x) {
	x->i = 47;
}

struct Z {
private:
	int j;
public:
	Z();
	void g(X* x);
};

Z::Z() {
	j == 99;
}

inline void Z::g(X* x) {
	x->i += j;
}

inline void h() {
	X x;
	x.i = 100;
}

int main() {
	X x;
	Z z;
	z.g(&x);
} ///:~
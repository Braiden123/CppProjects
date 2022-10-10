//:ConstPointer.cpp

void t(int*) {}

void u(const int* cip) {
	*cip = 2;  //Illegal -- modifies value
	int i = *cip;
	int* ip2 = cip; //Illegal: non-const
}

const char* v() {
	return "result of function v()";
}

const int* const w() {
	static int i;
	return &i;
}

int main(int argc, char const *argv[])
{
	int x = 0;
	int* ip = &x;
	const int* cip = &x;
	t(ip);
	t(cip); //Not ok
	u(ip);
	u(cip);
	char* cp = v(); //Not OK
	const char* ccp = v();
	int* ip2 = w(); //Not ok
	const int* const ccip = w();
	const int* cip2 = w();
	*w() = 1; //Not ok
}///:~
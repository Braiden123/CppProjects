#ifndef HENNESTEGG_H
#define HENNESTEGG_H

using namespace std;

class Hen {
public:	
	class Nest {
	public:
		class Egg {
		public:
			void display();
			Egg();
			~Egg();
		};	
		void display();
		Nest();
		~Nest();
	};
	void display();
	Hen();
	~Hen();
};
#endif // HENNESTEGG_H ///:~
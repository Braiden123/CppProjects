/* 
 Title: TMA2Question3.h
 Description: Header file for TMA2Question3.cpp
 Date: Jan. 14 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
*/

/*
 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA2Question3 TMA2Question3.h
*/


#ifndef TMA2Question3_H
#define TMA2Question3_H

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
#endif // TMA2Question3_H ///:~
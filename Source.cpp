#include <iostream>
#include <exception>

int F00(int a) {
	if (a == 0) {
	//	throw std::invalid_argument("devided by zero. coz a==0");
		throw std::range_error("a==0");
	}
	int result{ 123 / a };
	return result;
}

int F01(int a, int b) {
	if (a < b) {
		const char* str = "lower argument";
		throw str;
	}
	int result{ a-b };
	return result;
}

void Bar()noexcept{ // не бросаем исключения
	throw 5;
}

using namespace std;

int main() {
	int a{ 0 };
	mark1: ;
	try {
		F00(a);
		F01(1, 6);
		;
	}
	catch (std::exception &ex) {
		
		std::cerr << ex.what() << " exception";
	}
	catch (std::range_error & ex) {
		std::cerr << ex.what() << " exception";
		a = 1;
		goto mark1; // Плохая практика. Можно создавать код легче читаемым. Есть метод, который можно сделать проще или по-другому. Решение, которое замалчивает проблему
	}
	catch (const char *ex) {
		std::cerr << ex << " exception";
	}
	catch (...) { // Не ставить этот catch в начале. В нужном порядке выстраивать exceptions
		std::cerr << "undefined exception";
	}

	return 0;
}
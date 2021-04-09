#include <iostream>
#ifdef _WIN32
	#include <windows.h>
#else
	#include <ctime>
#endif


int main()
{
	setlocale(LC_ALL, "Russian");

#ifdef _WIN32
	SYSTEMTIME st;
	GetLocalTime(&st);
	std::cout << "Текущая дата:"  << st.wDay << ":" << st.wMonth << "." << st.wYear << std::endl;
	std::cout << "OS: Windows" << std::endl;
#elif LINUX
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	cout << "Текущее время и дата:" << asctime(timeinfo) << endl;
	std::cout << "OS: Linux" << std::endl;
#endif 	

	std::cout << __DATE__ << std::endl;
	std::cout << __TIME__ << std::endl;
	std::cout << __FILE__ << std::endl;
#ifdef __cplusplus
	std::cout << "Version: " << __cplusplus << std::endl;
#else
	std::cout << "compiler linux" << std::endl;
#endif
	return 0;
}


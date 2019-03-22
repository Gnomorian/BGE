#include "BGEsystem/build.h"

#ifdef BGE_WINDOWS
#include <Windows.h>
#include "GameRunner.h"
int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR cmdline, int cmdShow)
{
	BGE::Engine::GameRunner runner;
	try
	{
		runner.Run();
	}
	catch (std::exception& e)
	{
		MessageBox(nullptr, e.what(), "ERROR", MB_OK | MB_ICONSTOP);
		return 1;
	}

	return 0;
}
#else
#include "GameRunner.h"
int main()
{
	BGE::Engine::GameRunner runner;
	runner.Run();

	return 0;
}
#endif // BGE_WINDOWS
#include <Windows.h>

#ifdef _WIN64
#define MAKEPYTHONHOME(version) "PYTHONHOME" version "_64"
#else
#define MAKEPYTHONHOME(version) "PYTHONHOME" version "_86"
#endif //_WIN64

extern "C" __declspec(dllexport) void init()
{
	if (GetModuleHandleA("python37.dll"))
	{
		auto pythonHomeName = MAKEPYTHONHOME("37");
		char newpythonhome[MAX_PATH + 11] = "PYTHONHOME=";
		if (!GetEnvironmentVariableA(pythonHomeName, newpythonhome + 11, MAX_PATH))
			return;
		SetEnvironmentVariableA("PYTHONHOME", newpythonhome + 11);
		_putenv(newpythonhome);
	}
}

#undef MAKEPYTHONHOME

BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
	)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
		init();
	return TRUE;
}
#include <Windows.h>

#ifdef _WIN64
#define MAKEPYTHONHOME(version) "PYTHONHOME" version "_64"
#else
#define MAKEPYTHONHOME(version) "PYTHONHOME" version "_86"
#endif //_WIN64

extern "C" __declspec(dllexport) void init()
{
	if (GetModuleHandleA("python27.dll"))
	{
		auto pythonHomeName = MAKEPYTHONHOME("27");
		char newpythonhome[MAX_PATH + 11] = "PYTHONHOME=";
		if (!GetEnvironmentVariableA(pythonHomeName, newpythonhome + 11, MAX_PATH))
			return;
		auto _putenv90 = (decltype(_putenv)*)GetProcAddress(GetModuleHandleA("msvcr90.dll"), "_putenv");
		if (!_putenv90)
			return;
		SetEnvironmentVariableA("PYTHONHOME", newpythonhome + 11);
		_putenv90(newpythonhome);
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
// dllmain.cpp : Define el punto de entrada de la aplicación DLL.
#include "pch.h"
#include "mydll.h"

//6_dll.

//Delcara una funcion expuesta.
extern "C"
{
    //Ejemplo de funcion sin parametros que retorna una cadena de texto
    __declspec(dllexport)  const char* GetCodename()
    {
        const char* msg = "Codename Aldo";
        return msg;
    }

    //Funcion que recibe dos parametros y retorna un valor
    __declspec(dllexport) double sumar(double a, double b)
    {
        return a + b;
    }
    std::string concatenacion(std::string* string1, std::string* string2)
    {
        return std::string(string1, string2);
    }
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


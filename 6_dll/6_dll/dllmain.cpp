// dllmain.cpp : Define el punto de entrada de la aplicación DLL.
#include "pch.h"
#include <string>

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
    __declspec(dllexport) std::string Concatenar(const std::string A, const std::string B)
    {
        return A + B;
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


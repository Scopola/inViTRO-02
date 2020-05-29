/*
	MSVC
	TLSCallback Function Example.
	by YANiS

	This code snippet is provided 'as is' without warranty of any kind.
	No malicious uses are allowed.
*/

#include <windows.h>

#pragma comment(linker, "/INCLUDE:__tls_used")
#pragma comment(linker, "/INCLUDE:_tls_entry")
#pragma data_seg(".CRT$XLB" )

VOID NTAPI TLSCallback(PVOID DllHandle, DWORD Reason, PVOID Reserved);

extern "C" {
    PIMAGE_TLS_CALLBACK tls_entry = TLSCallback;
}

VOID NTAPI TLSCallback(PVOID DllHandle, DWORD Reason, PVOID Reserved) {
    
	    switch(Reason)  { 
        case DLL_PROCESS_ATTACH:
				 // Initialize once for each new process.
				  MessageBoxA(NULL,
					  "Malicious code EXECUTED! (DLL_PROCESS_ATTACH)",
					  "PoC",
					  MB_ICONERROR);
					break;

        case DLL_THREAD_ATTACH:
				 // Do thread-specific initialization.
				  MessageBoxA(NULL,
					  "Malicious code EXECUTED! (DLL_THREAD_ATTACH)",
					  "PoC",
					  MB_ICONERROR);
					break;
					
		case DLL_THREAD_DETACH:
				 // Do thread-specific cleanup.
				  MessageBoxA(NULL,
					  "Malicious code EXECUTED! (DLL_THREAD_DETACH)",
					  "PoC",
					  MB_ICONERROR);
					break;

		case DLL_PROCESS_DETACH:
				 // Perform any necessary cleanup.
				  MessageBoxA(NULL,
					  "Malicious code EXECUTED! (DLL_PROCESS_DETACH)",
					  "PoC",
					  MB_ICONERROR);
					break;
			}
		}

int main() {
   
    return 0;
}
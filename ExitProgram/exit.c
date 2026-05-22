#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <string.h>

DWORD FindProcessId(const char *processName) {
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return 0;
    }

    if (Process32First(hSnapshot, &pe32)) {
        do {
            if (_stricmp(pe32.szExeFile, processName) == 0) {
                CloseHandle(hSnapshot);
                return pe32.th32ProcessID;
            }
        } while (Process32Next(hSnapshot, &pe32));
    }

    CloseHandle(hSnapshot);
    return 0;
}

void KillProcessByName(const char *processName) {
    DWORD pid = FindProcessId(processName);

    if (pid == 0) {
        printf("Process not found\n");
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pid);

    if (hProcess == NULL) {
        printf("Failed to open process\n");
        return;
    }

    if (TerminateProcess(hProcess, 0)) {
        printf("%s terminated\n", processName);
    } else {
        printf("Failed to terminate process\n");
    }

    CloseHandle(hProcess);
}

int main() {
    int f7Count = 0;
    SHORT prevState = 0;

    while (1) {
        SHORT state = GetAsyncKeyState(VK_F7);

        if ((state & 0x8000) && !(prevState & 0x8000)) {
            f7Count++;

            printf("F7 pressed (%d/2)\n", f7Count);

            if (f7Count >= 2) {
                KillProcessByName("firefox.exe");
                f7Count = 0;
            }
        }

        prevState = state;

        Sleep(50);
    }

    return 0;
}

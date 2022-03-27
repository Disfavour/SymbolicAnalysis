#include "StartMenu.h"
#include <Windows.h>

using namespace SymbolicAnalysisGUI;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew StartMenu);
    return 0;
}
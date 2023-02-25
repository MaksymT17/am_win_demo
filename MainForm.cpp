#include "MainForm.h"
#include <vector>
#undef _M_CEE
//#include <mutex>
#define _M_CEE

#include "AmApi.h"
#include<thread>

using namespace System;
using namespace System::Windows::Forms;

void function(System::Object^ obj)
{
    System::Threading::Thread::Sleep(3000);
    System::Media::SystemSounds::Exclamation->Play();

}

[STAThread]//leave this as is
void main(array<String^>^ args) {

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project5::MainForm form;
    form.textBox2->Text == "test";
    //std::thread thr(function, 5);
   // System::Threading::Thread^ t = gcnew System::Threading::Thread(gcnew System::Threading::ParameterizedThreadStart(function));
    //t->Start(form);
    Application::Run(% form);
}   
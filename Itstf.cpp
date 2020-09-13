//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USERES("Itstf.res");
USEFORM("UFDataI.cpp", FDataFile);
USEFORM("ChildWin.cpp", MDIChild);
USEUNIT("Math\UData.cpp");
USEUNIT("Math\UMatrix.cpp");
USEFORM("Main.cpp", MainForm);
USEFORM("UFgrts.cpp", Fgdtr);
USEFORM("UFgrtf.cpp", FGTmf);
USEUNIT("Math\UModel.cpp");
USEUNIT("Math\UCorrel.cpp");
USEUNIT("Math\UModelTmF.cpp");
USEFORM("UFTmfCalc.cpp", FTmfCalc);
USEFORM("about.cpp", AboutBox);
USEUNIT("Math\UCasual.cpp");
USEUNIT("Math\UModelArima.cpp");
USEUNIT("Math\UModelDif.cpp");
USEUNIT("Math\UModelExp.cpp");
USEUNIT("Math\UModelFFT.cpp");
USEUNIT("Math\UModelPol.cpp");
USEUNIT("Math\UMultiModel.cpp");
USEUNIT("Math\UReport.cpp");
USEFORM("UFdiagr.cpp", FDiagram);
USEUNIT("Math\UModelScsr.cpp");
USEFORM("UFTmSCalc.cpp", FMainCalc);
USEFORM("UFParam.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TMainForm), &MainForm);
       Application->CreateForm(__classid(TAboutBox), &AboutBox);
       Application->CreateForm(__classid(TFDataFile), &FDataFile);
       Application->CreateForm(__classid(TFDiagram), &FDiagram);
       Application->CreateForm(__classid(TForm1), &Form1);
       Application->Run();

	return 0;
}
//---------------------------------------------------------------------

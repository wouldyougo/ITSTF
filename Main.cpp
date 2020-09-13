//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#include <vector>

#include "AdvGrid.hpp"
#include <Chart.hpp>

#include "About.h"

#pragma hdrstop
//---------------------------------------------------------------------------
#include "ChildWin.h"
#include "UFTmSCalc.h"
#include "UFDataI.h"
#include "UFTmfCalc.h"
#include "UModelScsr.h"

//#include "UTableSs.h"
//---------------------------------------------------------------------------

#include "Main.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma link "RzLaunch"
#pragma resource "*.dfm"

TMainForm *MainForm;
//---------------------------------------------------------------------------

__fastcall TMainForm::TMainForm(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
TMDIChild * __fastcall TMainForm::CreateMDIChild(String Name){
	TMDIChild *Child;
	Child = new TMDIChild(Application);
	Child->Caption = Name;
   Child->Show();
   return Child;
}
//---------------------------------------------------------------------------

TFMainCalc * __fastcall TMainForm::CreateFMainCalc(String Name){
	TFMainCalc *Child;
	Child = new TFMainCalc(Application);
	Child->Caption = Name;
   Child->Show();
   return Child;
}

//---------------------------------------------------------------------------
TFTmfCalc * __fastcall TMainForm::CreateFTmfCalc(String Name){
	TFTmfCalc *Child;
	Child = new TFTmfCalc(Application);
	Child->Caption = Name;
   Child->Show();
   return Child;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HelpAbout1Execute(TObject *Sender){
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Help3Click(TObject *Sender){
    char CurrentDir[256];
    char RunFile[256];
    char APchar[256];

    sprintf(CurrentDir, "%s\\help", GetCurrentDir().c_str());
    FindExecutable("help.htm", CurrentDir, APchar);
    sprintf(RunFile, "%s %s\\help.htm", APchar, CurrentDir);
    WinExec(RunFile, SW_RESTORE);
}
//---------------------------------------------------------------------------
//	CreateMDIChild("NONAME" + IntToStr(MDIChildCount + 1));
void __fastcall TMainForm::FormShow(TObject *Sender){
   if( !TblSs.getE() ){
      MainForm->Close();
   }
}
//---------------------------------------------------------------------------
void TMainForm::saveData(TAdvStringGrid *aASG){
//   AnsiString Ext;
   AnsiString Name;

	if (SaveDialog1->Execute()){
       Name = SaveDialog1->FileName;
      if( SaveDialog1->FilterIndex == 1 ){
         Name = Name + ".tbl";
         aASG->SaveToFile( Name );
      }
      if( SaveDialog1->FilterIndex == 2 ){
         Name = Name + ".txt";
         aASG->SaveToASCII( Name );
      }
      if( SaveDialog1->FilterIndex == 3 ){
         Name = Name + ".dbf";
         FDataFile->SaveTableToDB( aASG, Name );
      }
      if( SaveDialog1->FilterIndex == 4 ){
         Name = Name + ".csv";
         aASG->SaveToCSV( Name );
      }
      if( SaveDialog1->FilterIndex == 5 ){
         Name = Name + ".htm";
         aASG->SaveToHTML( Name );
      }
      if( SaveDialog1->FilterIndex == 6 ){
         Name = Name + ".xls";
         aASG->SaveToXLS( Name );
      }
      if( SaveDialog1->FilterIndex == 7 ){
         Name = Name + ".doc";
         aASG->SaveToDOC( Name );
      }
   }
}
//---------------------------------------------------------------------------
void TMainForm::appDataToHtml(TAdvStringGrid *aASG, AnsiString Name){
      aASG->AppendToHTML( Name );
}
//---------------------------------------------------------------------------
void TMainForm::appDataToHtml(TAdvStringGrid *aASG){
   AnsiString Name;
	if (SaveDialog3->Execute()){
       Name = SaveDialog1->FileName;

      if( SaveDialog3->FilterIndex == 2 ){
      Name = Name + ".html";
      aASG->AppendToHTML( Name );
      }
   }
}
//---------------------------------------------------------------------------
void TMainForm::savePict(TChart *aChart){
   AnsiString Name;
	if (SaveDialog2->Execute()){
       Name = SaveDialog2->FileName;

      if( SaveDialog2->FilterIndex == 1 ){
      Name = Name + ".bmp";
//      aChart->SaveToBitmapFile("files\\" +Name);
      aChart->SaveToBitmapFile( Name );
      }
   }
}
//---------------------------------------------------------------------------
void TMainForm::savePict(TChart *aChart, AnsiString Name){
   Name = Name + ".bmp";//   aChart->SaveToBitmapFile("files\\" +Name);
   aChart->SaveToBitmapFile( Name );
}
//---------------------------------------------------------------------------
void TMainForm::saveTxt(TMemo *Memo){
   AnsiString Name;
	if (SaveDialog3->Execute()){
      Name = SaveDialog3->FileName;
      SaveDialog3->FilterIndex = 1;
      Name = Name + ".txt";
      Memo->Lines->SaveToFile(Name);
      //if( SaveDialog3->FilterIndex == 1 ){
   }
}
//---------------------------------------------------------------------------
void TMainForm::saveTxt(TMemo *Memo, AnsiString Name){
      Name = Name + ".txt";
      Memo->Lines->SaveToFile(Name);
}
//---------------------------------------------------------------------------
/*
      aASG->SaveToXML();
      aASG->SaveToFixed();
      aASG->LoadFromFile();

      aASG->AddColumn();
      aASG->AddRow();

      aASG->RemoveRows();
      aASG->RemoveCols();
      aASG->InsertRows();
      aASG->InsertCols();

      aASG->RemoveSelectedRows();

      aASG->ClearRows();
      aASG->ClearCols();
      aASG->ClearSelection();

      aASG->ExcelClipboardFormat();
      aASG->CopyToClipBoard();
      aASG->CopySelectionToClipBoard();
      aASG->PasteFromClipboard();
      aASG->PasteSelectionFromClipboard();
      aASG->CutToClipboard();
      aASG->CutSelectionToClipboard();
*/

void __fastcall TMainForm::FileOpenItem1Click(TObject *Sender){
   FDataFile->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FileExitItem1Click(TObject *Sender){
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AllClose1Click(TObject *Sender){
    for(int i = 0; i < MDIChildCount; i++){
    MainForm->MDIChildren[i]->Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButton6Click(TObject *Sender){
   if(MDIChildCount){
      MainForm->ActiveMDIChild->Close();
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButton10Click(TObject *Sender){
   if(MDIChildCount){
      MainForm->Previous();
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButton8Click(TObject *Sender){
   WindowCascade1->ExecuteTarget( this );
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButton12Click(TObject *Sender){
   if(MDIChildCount){
   if( ActiveMDIChild->WindowState != wsMinimized ){
       ActiveMDIChild->WindowState = wsMinimized;
   }else{
       ActiveMDIChild->WindowState = wsNormal;
   }
   }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToolButton14Click(TObject *Sender){
//	CreateMDIChild("NONAME" + IntToStr(MDIChildCount + 1));
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormActivate(TObject *Sender){
   try{
      FDataFile->ShowModal();
   }catch(...){
   }
}
//---------------------------------------------------------------------------




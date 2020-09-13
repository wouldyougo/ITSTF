//---------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------
#include "Main.h"
#include "UData.h"
#include "UReport.h"
//---------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------
#include "ChildWin.h"

//---------------------------------------------------------------------
#pragma package(smart_init)

#pragma link "AdvPanel"
#pragma link "AdvGrid"
#pragma link "BaseGrid"
#pragma link "RzSpnEdt"
#pragma link "RzButton"
#pragma link "RzEdit"
#pragma link "RzPanel"
#pragma link "RzRadGrp"
#pragma link "RzSplit"

#pragma resource "*.dfm"
//---------------------------------------------------------------------
__fastcall TMDIChild::TMDIChild(TComponent *Owner)
	: TForm(Owner)
{
   WinPtr = NULL;
   WinType = -1;
//   Chart1->SeriesList->CountActive();
//   Chart1->SeriesCount();
//   Chart1->SeriesList->Series->Active;
/*
   int SerCount = 0;
   SerCount = Chart1->SeriesCount();
   for(int i = 0; i < SerCount; i++){
      if( Chart1->SeriesList->Series[i]->Active ){
         VctrSeries.push_back( Chart1->SeriesList->Series[i] );
      }
   }
*/
}
//---------------------------------------------------------------------
void __fastcall TMDIChild::FormClose(TObject *Sender, TCloseAction &Action)
{
   try{
   TMDIChild * TmpWinPtr;
   if( WinType == 0 ){
      for(int i = 0; i < MainForm->MDIChildCount; i++){
         TmpWinPtr = dynamic_cast<TMDIChild *>( MainForm->MDIChildren[i] );
         TmpWinPtr = TmpWinPtr->WinPtr;
         if( this == TmpWinPtr ){
            MainForm->MDIChildren[i]->Close();
         }
      }
   }
//   if( WinPtr != NULL ){
//      WinPtr->updateWork();
//   }
	Action = caFree;
   }catch(...){
//      ShowMessage("TMDIChild::FormClose");
   }
}
//---------------------------------------------------------------------
void __fastcall TMDIChild::UpdateAsg(void){
   unsigned int tRowCount = this->StringGrid1->RowCount;
   for(unsigned int i = 1; i < tRowCount; i++){
      this->StringGrid1->Cells[0][i] = i-1;
   }  this->StringGrid1->Cells[0][0] = "№";
//      this->StringGrid1->Cells[1][0] = "Значение";
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::UpdateTcrt(void){
   if(RadioGroup1->ItemIndex == 0){
      UpdateTcrtAll();
   }else if(RadioGroup1->ItemIndex == 1){
      UpdateTcrtSelect();
   }
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::UpdateTcrtSelect(void){
   if(SpinEdit1->Value < SpinEdit2->Value){
      if( this->Chart1->BottomAxis->Maximum < SpinEdit1->Value ){
         this->Chart1->BottomAxis->Maximum = SpinEdit1->Value;
      }
      this->Chart1->BottomAxis->Minimum = SpinEdit1->Value;
      this->Chart1->BottomAxis->Maximum = SpinEdit2->Value;
   }else{
      if( this->Chart1->BottomAxis->Maximum < SpinEdit2->Value ){
         this->Chart1->BottomAxis->Maximum = SpinEdit2->Value;
      }
      this->Chart1->BottomAxis->Minimum = SpinEdit2->Value;
      this->Chart1->BottomAxis->Maximum = SpinEdit1->Value;
   }
   this->Chart1->BottomAxis->Automatic = false;
   this->Chart1->BottomAxis->AutomaticMinimum = false;
   this->Chart1->BottomAxis->AutomaticMaximum = false;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::UpdateTcrtAll(void){
   this->Chart1->BottomAxis->Automatic = true;
   this->Chart1->BottomAxis->AutomaticMinimum = true;
   this->Chart1->BottomAxis->AutomaticMaximum = true;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::UpdateSpinEdit(void){
//    SpinEdit2->Min = SpinEdit1->Value;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::SetSpinEdit(void){
    SpinEdit1->Max = this->StringGrid1->RowCount-2;
    SpinEdit2->Max = this->StringGrid1->RowCount-1 + 100;
    SpinEdit2->Min = SpinEdit1->Value;
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::BitBtn1Click(TObject *Sender){
   UpdateTcrt();
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::SpinEdit1Change(TObject *Sender){
   UpdateSpinEdit();
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::SpinEdit2Change(TObject *Sender){
   UpdateSpinEdit();
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::FormShow(TObject *Sender){
   this->Height = this->Constraints->MinHeight;
   this->Width =  this->Constraints->MinWidth;
//   this->Constraints->MaxHeight;
//   this->Constraints->MaxWidth;
}
//---------------------------------------------------------------------------
void TMDIChild::saveHTML(void){
	if (SaveDialog1->Execute()){
      AnsiString Name;
      Name = SaveDialog1->FileName;
      Rpt.openReport(Name);
         Name = this->Caption;
         Rpt.saveTxt(Name, 2);
      if( TabSheet1->TabVisible ){
         Rpt.saveTxt("График", 3);
         Rpt.savePict(Chart1);
      }
      if( TabSheet2->TabVisible ){
         Rpt.saveTxt("Данные", 3);
         Rpt.outTable(StringGrid1);
      }
      if( TabSheet3->TabVisible ){
         Name = LabelTbl->Caption;
         Rpt.saveTxt(Name, 3);
         Rpt.outTable(StringGrid2);
      }
      if( TabSheet4->TabVisible ){
         Rpt.saveTxt("Отчет", 3);
         Rpt.saveMemo(Memo1);
      }
      Rpt.closeReport();
      if(bmCheck->Checked){
         MainForm->RzLauncher1->FileName = SaveDialog1->FileName;
         MainForm->RzLauncher1->Launch();
      }
   }
}
//---------------------------------------------------------------------------
void TMDIChild::saveHTML(AnsiString FileName){
      AnsiString Name = FileName;
      Rpt.openReport(Name);
         Name = this->Caption;
         Rpt.saveTxt(Name, 2);
      if( TabSheet1->TabVisible ){
         Rpt.saveTxt("График", 3);
         Rpt.savePict(Chart1);
      }
      if( TabSheet2->TabVisible ){
         Rpt.saveTxt("Данные", 3);
         Rpt.outTable(StringGrid1);
      }
      if( TabSheet3->TabVisible ){
         Name = LabelTbl->Caption;
         Rpt.saveTxt(Name, 3);
         Rpt.outTable(StringGrid2);
      }
      if( TabSheet4->TabVisible ){
         Rpt.saveTxt("Отчет", 3);
         Rpt.saveMemo(Memo1);
      }
      Rpt.closeReport();
      if(bmCheck->Checked){
         MainForm->RzLauncher1->FileName = FileName;
         MainForm->RzLauncher1->Launch();
      }
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::bmSaveClick(TObject *Sender){
   saveHTML("Tmp.html");
}
//---------------------------------------------------------------------------

void __fastcall TMDIChild::bmSaveAsClick(TObject *Sender){
   saveHTML();
}
//---------------------------------------------------------------------------
void __fastcall TMDIChild::UpdateMainMenu(void){
      if( TabSheet1->TabVisible ){
         bmGrafSave->Visible = true;
      }else{
         bmGrafSave->Visible = false;
      }
      if( TabSheet2->TabVisible ){
         bmDataSave->Visible = true;
      }else{
         bmDataSave->Visible = false;
      }
      if( TabSheet3->TabVisible ){
         bmTablSave->Visible = true;
      }else{
         bmTablSave->Visible = false;
      }
      if( TabSheet4->TabVisible ){
         bmRepSave->Visible = true;
      }else{
         bmRepSave->Visible = false;
      }
}
//---------------------------------------------------------------------------


void __fastcall TMDIChild::bmCheckClick(TObject *Sender){
   bmCheck->Checked = !(bmCheck->Checked);
}
//---------------------------------------------------------------------------


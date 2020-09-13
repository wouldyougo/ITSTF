//----------------------------------------------------------------------------
#ifndef ChildWinH
#define ChildWinH

#include "UData.h"
#include "UReport.h"
//----------------------------------------------------------------------------
#include "AdvGrid.hpp"
#include "BaseGrid.hpp"
#include "RzButton.hpp"
#include "RzEdit.hpp"
#include "RzPanel.hpp"
#include "RzRadGrp.hpp"
#include "RzSplit.hpp"
#include "RzSpnEdt.hpp"
#include <Chart.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <Series.hpp>
#include <StdCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
class TMDIChild : public TForm
{
__published:
   TMainMenu *MainMenu1;
   TPageControl *PageControl1;
   TTabSheet *TabSheet1;
   TTabSheet *TabSheet2;
   TTabSheet *TabSheet3;
   TTabSheet *TabSheet4;
   TRzSizePanel *RzSizePanel2;
   TRzSplitter *RzSplitter1;
   TChart *Chart1;
   TAdvStringGrid *StringGrid1;
   TAdvStringGrid *StringGrid2;
   TRzSpinEdit *SpinEdit1;
   TRzSpinEdit *SpinEdit2;
   TRadioGroup *RadioGroup1;
   TGroupBox   *GroupBox1;
   TMemo *Memo1;
   TBitBtn *BitBtn1;
   TLineSeries *Series1;
   TLineSeries *Series2;
   TLineSeries *Series3;
   TTabSheet *TabSheet5;
   TRzSizePanel *RzSizePanel1;
   TPanel *Panel1;
   TLabel *LabelTbl;
   TSaveDialog *SaveDialog1;
   TMenuItem *bmRes;
   TMenuItem *bmDataSave;
   TMenuItem *bmTablSave;
   TMenuItem *bmGrafSave;
   TMenuItem *bmRepSave;
   TMenuItem *bmSaveAs;
   TMenuItem *bmSave;
   TMenuItem *Razdel;
   TMenuItem *bmCheck;

//   TMenuItem *N1;
//   TMenuItem *bmDataSave;
//   TMenuItem *bmTablSave;
//   TMenuItem *bmRepSave;
//   TMenuItem *bmGrafSave;

	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall BitBtn1Click(TObject *Sender);
   void __fastcall SpinEdit1Change(TObject *Sender);
   void __fastcall SpinEdit2Change(TObject *Sender);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall bmSaveClick(TObject *Sender);
   void __fastcall bmSaveAsClick(TObject *Sender);
   void __fastcall bmCheckClick(TObject *Sender);
private:
public:
   void __fastcall UpdateTcrt(void);
   void __fastcall UpdateTcrtSelect(void);
   void __fastcall UpdateTcrtAll(void);
   void __fastcall UpdateAsg(void);
   void __fastcall UpdateSpinEdit(void);
   void __fastcall SetSpinEdit(void);
   void __fastcall UpdateMainMenu(void);
	virtual __fastcall TMDIChild(TComponent *Owner);
//   virtual void setData(void){;}
   virtual void setData(qData aData){;}
   virtual void updateShow(void){;}
//   virtual void updateWork(void){;}
   qReport Rpt;   // класс репорт
   void saveHTML(void);
   void saveHTML(AnsiString Name);   
   TMDIChild * WinPtr;
   int         WinType;

   //std::vector< TChartSeries * > VctrSeries;
};
//----------------------------------------------------------------------------
#endif	

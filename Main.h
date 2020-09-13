//----------------------------------------------------------------------------
#ifndef MainH
#define MainH

//#include "ChildWin.h"
#include "UFTmSCalc.h"
#include "UFTmfCalc.h"
#include "UModelScsr.h"
//----------------------------------------------------------------------------
#include "LMDCustomComponent.hpp"
#include "LMDOneInstance.hpp"
#include "RzButton.hpp"
#include "RzPanel.hpp"
#include "RzSplit.hpp"
#include <ActnList.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include "RzLaunch.hpp"
//----------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:
	TMainMenu *MainMenu1;
    TMenuItem *Window1;
	TMenuItem *WindowCascadeItem;
	TMenuItem *WindowTileItem;
	TMenuItem *WindowArrangeItem;
	TOpenDialog *OpenDialog;
	TMenuItem *WindowMinimizeItem;
        TStatusBar *StatusBar;
        TActionList *ActionList1;
        TAction *FileExit1;
        TWindowCascade *WindowCascade1;
        TWindowTileHorizontal *WindowTileHorizontal1;
        TWindowArrange *WindowArrangeAll1;
        TWindowMinimizeAll *WindowMinimizeAll1;
        TAction *HelpAbout1;
        TWindowClose *FileClose1;
        TWindowTileVertical *WindowTileVertical1;
        TMenuItem *WindowTileItem2;
        TImageList *ImageList1;
    TMenuItem *File2;
    TMenuItem *FileOpenItem1;
    TMenuItem *FileCloseItem1;
    TMenuItem *AllClose1;
    TMenuItem *N2;
    TMenuItem *FileExitItem1;
    TMenuItem *Help2;
    TMenuItem *Help3;
    TMenuItem *HelpAboutItem1;
   TSaveDialog *SaveDialog1;
   TSaveDialog *SaveDialog2;
   TSaveDialog *SaveDialog3;
   TPageScroller *PageScroller1;
   TToolBar *ToolBar1;
   TToolButton *ToolButton1;
   TToolButton *ToolButton2;
   TToolButton *ToolButton3;
   TToolButton *ToolButton4;
   TToolButton *ToolButton5;
   TToolButton *ToolButton6;
   TToolButton *ToolButton7;
   TToolButton *ToolButton8;
   TToolButton *ToolButton9;
   TToolButton *ToolButton10;
   TToolButton *ToolButton11;
   TToolButton *ToolButton12;
   TToolButton *ToolButton13;
   TToolButton *ToolButton14;
   TToolButton *ToolButton15;
   TRzLauncher *RzLauncher1;
        void __fastcall HelpAbout1Execute(TObject *Sender);
    void __fastcall AllClose1Click(TObject *Sender);
    void __fastcall Help3Click(TObject *Sender);
   void __fastcall FileExitItem1Click(TObject *Sender);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall FileOpenItem1Click(TObject *Sender);
   void __fastcall ToolButton6Click(TObject *Sender);
   void __fastcall ToolButton10Click(TObject *Sender);
   void __fastcall ToolButton8Click(TObject *Sender);
   void __fastcall ToolButton12Click(TObject *Sender);
   void __fastcall ToolButton14Click(TObject *Sender);
   void __fastcall FormActivate(TObject *Sender);
private:
	TMDIChild * __fastcall CreateMDIChild(const String Name);

public:
   TFMainCalc * __fastcall CreateFMainCalc(String Name);
   TFTmfCalc  * __fastcall CreateFTmfCalc(String Name);   
	virtual __fastcall TMainForm(TComponent *Owner);
   void saveTxt(TMemo *Memo);
   void saveTxt(TMemo *Memo, AnsiString Name);   
   void saveData(TAdvStringGrid *aASG);
   void savePict(TChart *aChart);
   void savePict(TChart *aChart, AnsiString Name);
   void appDataToHtml(TAdvStringGrid *aASG, AnsiString Name);
   void appDataToHtml(TAdvStringGrid *aASG);

   
//----------------------------------------------------------------------------
   qTableSs TblSs;
//----------------------------------------------------------------------------
};
//----------------------------------------------------------------------------
extern TMainForm *MainForm;
//extern TMDIChild *__fastcall MDIChildCreate(void);
//----------------------------------------------------------------------------
#endif    

//-----------------------------------------------------------------------------
// Copyright (c) 2012 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#pragma once

#ifndef GUI_POPUP_MENU_CTRL_H
#define GUI_POPUP_MENU_CTRL_H

#ifndef _GUITEXTLISTCTRL_H_
#include "gui/controls/guiTextListCtrl.h"
#endif

#ifndef _GUIMENUBAR_H_
#include "gui/editor/guiMenuBar.h"
#endif

#ifndef _POPUPMENU_H_
#include "platform/menus/popupMenu.h"
#endif

class GuiPopupMenuBackgroundCtrl;

class GuiPopupMenuTextListCtrl : public GuiTextListCtrl
{
   friend class GuiPopupMenuBackgroundCtrl;
   friend class PopupMenu;

private:
   typedef GuiTextListCtrl Parent;

   GuiPopupMenuBackgroundCtrl* mBackground;

public:
   bool isSubMenu; //  Indicates that this text list is in a submenu
   Point2I maxBitmapSize;

   GuiMenuBar* mMenuBar;
   PopupMenu* mPopup;

   S32 mLastHighlightedMenuIdx;

   GuiPopupMenuTextListCtrl();

   // GuiControl overloads:
   bool onKeyDown(const GuiEvent &event) override;
   void onMouseDown(const GuiEvent &event) override;
   void onMouseUp(const GuiEvent &event) override;
   void onRenderCell(Point2I offset, Point2I cell, bool selected, bool mouseOver) override;

   void onCellHighlighted(Point2I cell) override; //  Added
};

class GuiPopupMenuBackgroundCtrl : public GuiControl
{
   typedef GuiControl Parent;

public:
   GuiPopupMenuBackgroundCtrl();
   void onMouseDown(const GuiEvent &event) override;
   void onMouseUp(const GuiEvent &event) override;
   void onMouseMove(const GuiEvent &event) override;
   void onMouseDragged(const GuiEvent &event) override;

   void close();

   void clearPopups();

   S32 findPopupMenu(PopupMenu* menu);

   Vector<PopupMenu*> mPopups;
   GuiMenuBar* mMenuBarCtrl;
};

#endif
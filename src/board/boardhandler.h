/*
 * boardhandler.h
 */

#ifndef BOARDHANDLER_H
#define BOARDHANDLER_H

#include "../defines.h"
#include "tree.h"
#include "sgfparser.h"
#include "board.h"
#include "boardwindow.h"

class BoardWindow;

class BoardHandler : public QObject
{
	Q_OBJECT
public:
	BoardHandler(BoardWindow *bw, Tree *tree =NULL, int size=19);
	~BoardHandler();

	void clearData();
	bool markedDead;
	
/*	// Navigation
	bool nextMove(bool autoplay=false);
	void previousMove();
	void gotoFirstMove();
	void gotoLastMove();
	void nextComment();
	void previousComment();
	void nextVariation();
	void previousVariation();
	void gotoVarStart();
	void gotoMainBranch();
	void gotoNextBranch();
	void navIntersection();
	void gotoNthMoveInVar(int n);
*/
	void updateMove(Move *m=0, bool ignore_update = false);
	bool updateAll(Matrix *m, bool toDraw=true);
	CursorType updateCursor(StoneColor c);
//	bool loadSGF(const QString fileName, const QString SGFLoaded=0, bool fastLoad=false);

	void findMoveByPos(int x,int  y);

public slots:
	void slotNavBackward();
	void slotNavForward();
	void slotNavFirst();
	void slotNavLast();
	void slotNavPrevComment();
	void slotNavNextComment();
	void slotNavPrevVar();
	void slotNavNextVar();	
	void slotNavStartVar();
	void slotNavMainBranch();
	void slotNavNextBranch();
	void slotNavIntersection();
	void slotNthMove(int n);

private:
	Board *board;
	Tree *tree;
	BoardWindow * boardwindow;

	int capturesBlack, capturesWhite, caps_black, caps_white;
	Move *lastValidMove;
//	GameMode gameMode;
	int boardSize;
	
	void gotoMove(Move *m);
	void updateVariationGhosts(Move *m);
	bool navIntersectionStatus;
};

#endif
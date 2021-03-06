#pragma once

enum END_SCENE
{
	ES_ENDING,
	ES_INITIAL,
	ES_END
};


enum ITEM_TYPE
{
	IT_TRIPLE_UP,
	IT_HOMING_MISSILE,
	IT_BOMB,
	IT_SPEED_UP,
	IT_DOUBLE_JUMP,
	IT_BULLET_DIST
};


enum ANIMATION_OPTION
{
	AO_LOOP,
	AO_ONCE_DESTROY
};

enum PLAYER_LV
{
	LV_1,
	LV_2,
	LV_3
};

enum MOVE_DIR
{
	MD_LEFT = -1,
	MD_NONE,
	MD_RIGHT
};



enum BUTTON_TYPE
{
	BT_START,
	BT_METHOD,
	BT_RANK,
	BT_QUIT,
	BT_HOME,
	BT_ARROW_RIGHT,
	BT_ARROW_LEFT,
	BT_RETRY
};

enum SCENE
{
	S_START,
	S_INGAME1,
	S_INGAME2,
	S_END
};

enum SCENE_TYPE
{
	ST_CURRENT,
	ST_NEXT
};



enum PANEL_TYPE
{
	PT_INFORM,
	PT_BULLET_DIST,
	PT_DOUBLE_JUMP,
	PT_TRIPLE_UP,
	PT_IMAGE,
	PT_NUMBER,
	PT_PLAYER_IMAGE,
	PT_SCORE // �� ����.
};

enum OBJECT_TYPE
{
	OT_PLAYER,
	OT_MONSTER,
	OT_PLAYER_BULLET,
	OT_MONSTER_BULLET,
	OT_UI,
	OT_DOOR,
	OT_CHECK,
	OT_OBSTACLE,
	OT_MOUSE,
	OT_BUTTON,
	OT_ITEM,
	OT_STAGE
};

enum COLLIDER_TYPE
{
	CT_RECT,
	CT_LEFT,
	CT_RIGHT,
	CT_GRAVITY
};
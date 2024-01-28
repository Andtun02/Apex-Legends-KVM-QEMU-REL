// player.h
#pragma once

typedef struct player
{
	float dist = 0;
	int entity_team = 0;
	float boxMiddle = 0;
	float h_y = 0;
	float width = 0;
	float height = 0;
	float b_x = 0;
	float b_y = 0;
	bool knocked = false;
	bool visible = false;
	int health = 0;
	int shield = 0;
	//seer
	int maxshield = 0;
	int armortype = 0;
	D3DXVECTOR3 EntityPosition;
	D3DXVECTOR3 LocalPlayerPosition;
	D3DXVECTOR3 localviewangle;
	float targetyaw = 0;
	bool isAlive = 0;
	char name[33] = { 0 };
	char modelname[1024] = { 0 };
}player;

//extern player players[100];

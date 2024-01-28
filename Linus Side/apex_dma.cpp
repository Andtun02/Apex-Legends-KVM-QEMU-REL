#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <random>
#include <chrono>
#include <iostream>
#include <cfloat>
#include "Game.h"
#include <thread>

//this is a test, with seconds
Memory apex_mem;
Memory client_mem;

//Just setting things up, dont edit.
bool firing_range = false;
bool active = true;
//extern bool bone_auto;  //apex_dma.cpp
uintptr_t aimentity = 0;
uintptr_t tmp_aimentity = 0;
uintptr_t lastaimentity = 0;
float max = 999.0f;
float max_dist = 200.0f*40.0f;
int team_player = 0;
float max_fov = 50;
const int toRead = 100;
int aim = true;
bool esp = true;
bool PrintHeldID;
bool item_glow = true;
bool player_glow = true;
bool PrintModelAndId = false;
char level_name[40];
extern bool aim_no_recoil;
bool aiming = false;
extern float smooth;
extern int bone;
float bulletspeed = 0.00;
float bulletgrav = 0.00;
int playerentcount = 101;
bool tapstrafeenable = false;
float CurrentWeaponADSZoom;
float ScopeZoom;
//box bool
bool BoxEnable = false;
//triggerbot?
bool SuperKeyToggle = true;
bool SuperKey = true;
//TDM Toggle
bool TDMToggle = false;
//Trigger Bot
bool triggerbot = false;
float isattacing = 0.0f;
int lstarvalueid;
//Firing Range 1v1 toggle
bool onevone = false;
int curFrameNumber;
//map
bool PrintMapCords = false;
int map = 0;
float veltest = 0.0f;
bool TogglePrediction = true;
//superglide stuff
float m_traversalProgress;
bool shooting = false;
int NoNadeAim = 0;
bool autoshoot = true;
bool TriggerBot = false;
int frameSleepTimer;
bool AutoFire = false;
//Player Glow Color and Brightness.
bool insidevaluegoggle = false;
//inside fill
unsigned char insidevalue = 14;  //0 = no fill, 14 = full fill
//Outline size
unsigned char outlinesize = 32; // 0-255
float glowr = 1.0f; //Red 0-255, higher is brighter color.
float glowg = 0.0f; //Green 0-255, higher is brighter color.
float glowb = 0.0f; //Blue 0-255, higher is brighter color.
//visable
float glowrviz = 0.0f; //Red 0-255, higher is brighter color.
float glowgviz = 1.0f; //Green 0-255, higher is brighter color.
float glowbviz = 0.0f; //Blue 0-255, higher is brighter color.
//knocked
float glowrknocked = 1.0f; //Red 0-255, higher is brighter color.
float glowgknocked = 1.0f; //Green 0-255, higher is brighter color.
float glowbknocked = 1.0f; //Blue 0-255, higher is brighter color.
//Screen Res
int ScreenResINT = 0; //0 is 1080p, 1 is 1440p
//Item Configs
//loot Fill
unsigned char lootfilled = 14;  //0 no fill, 14 100% fill
//loot outline siez
unsigned char lootoutline = 0;
bool skull = true;
//Backpacks
bool lightbackpack = false;
bool medbackpack = false;
bool heavybackpack = false;
bool goldbackpack = false;
//Shield Upgrades
bool shieldupgrade1 = false;  //white
bool shieldupgrade2 = false;  //blue
bool shieldupgrade3 = false;  //purple
bool shieldupgrade4 = false;  //gold
bool shieldupgrade5 = false;  //red
//Helmet Upgrades
bool shieldupgradehead1 = false;
bool shieldupgradehead2 = false;
bool shieldupgradehead3 = false;
bool shieldupgradehead4 = false;
//Knockdown Upgrades
bool shielddown1 = false;
bool shielddown2 = false;
bool shielddown3 = false;
bool shielddown4 = false;
//heaing and Misc
bool accelerant = false;
bool phoenix = false;
bool healthlarge = false;
bool healthsmall = false;
bool shieldbattsmall = false;
bool shieldbattlarge = false;
//Ammo
bool sniperammo = false;
bool heavyammo = false;
bool lightammo = false;
bool energyammo = false;
bool shotgunammo = false;
//Optics
bool optic1xhcog = false;
bool optic2xhcog = false;
bool opticholo1x = false;
bool opticholo1x2x = false;
bool opticthreat = false;
bool optic3xhcog = false;
bool optic2x4x = false;
bool opticsniper6x = false;
bool opticsniper4x8x = false;
bool opticsniperthreat = false;
//Magazines
bool sniperammomag1 = false;
bool energyammomag1 = false;
bool lightammomag1 = false;
bool heavyammomag1 = false;
bool sniperammomag2 = false;
bool energyammomag2 = false;
bool lightammomag2 = false;
bool heavyammomag2 = false;
bool sniperammomag3 = false;
bool energyammomag3 = false;
bool lightammomag3 = false;
bool heavyammomag3 = false;
bool sniperammomag4 = false;
bool energyammomag4 = false;
bool lightammomag4 = false;
bool heavyammomag4 = false;
//Attachments 
bool lasersight1 = false;
bool lasersight2 = false;
bool lasersight3 = false;
bool lasersight4 = false;
bool stocksniper1 = false;
bool stocksniper2 = false;
bool stocksniper3 = false;
bool stocksniper4 = false;
bool stockregular1 = false;
bool stockregular2 = false;
bool stockregular3 = false;
bool suppressor1 = false;
bool suppressor2 = false;
bool suppressor3 = false;
bool turbo_charger = false;
bool skull_piecer = false;
bool hammer_point = false;
bool disruptor_rounds = false;
bool boosted_loader = false;
bool shotgunbolt1 = false;
bool shotgunbolt2 = false;
bool shotgunbolt3 = false;
bool shotgunbolt4 = false;
//Nades
bool grenade_frag = false;
bool grenade_arc_star = false;
bool grenade_thermite = false;
//Kraber
bool weapon_kraber = false;
//Shotguns
bool weapon_mastiff = false;
bool weapon_eva8  = false;
bool weapon_peacekeeper  = false;
bool weapon_mozambique  = false;
//Energy weapons
bool weapon_lstar = false;
bool weapon_nemesis = false;
bool weapon_havoc = false;
bool weapon_devotion = false;
bool weapon_triple_take = false;
bool weapon_prowler  = false;
bool weapon_volt  = false;
//Heavy Weapons
bool weapon_flatline = false;
bool weapon_hemlock  = false;
bool weapon_3030_repeater = false; 
bool weapon_rampage  = false;
bool weapon_car_smg  = false;
//Light weapons
bool weapon_p2020  = false;
bool weapon_re45  = false;
bool weapon_g7_scout  = false;
bool weapon_alternator  = false;
bool weapon_r99  = false;
bool weapon_spitfire  = false;
bool weapon_r301 = false;
//Snipers.. wingman is the odd one...and the bow..
bool weapon_wingman  = false;
bool weapon_longbow  = false;
bool weapon_charge_rifle  = false;
bool weapon_sentinel  = false;
bool weapon_bow  = false;

//aim dist check. Just setting things up, dont edit.
float aimdist = 200.0f * 40.0f;
//Spectator name list for overlay
float LocalYAW;
float TargetYAW;
int TARGET_TEAMID;
int TEAM_TEAMID;
//item glow brightness. Just setting things up, dont edit.
int itemglowbrightness = 1;

uint32_t button_state[4];
int AimbotHotKey1 = 108;
int AimbotHotKey2 = 109;


//Just setting things up, dont edit.
bool actions_t = false;
bool esp_t = false;
bool aim_t = false;
bool vars_t = false;
bool item_t = false;
bool cactions_t = false;
bool TriggerBotRun_t = false;
uint64_t g_Base;
uint64_t c_Base;
bool next2 = false;
bool valid = false;
bool lock = false;
//trigger bot
bool is_trigger;
int attackState;

void TriggerBotRun()
{
	//testing
	//apex_mem.Write<int>(g_Base + OFFSET_IN_ATTACK + 0x8, 4);
	//std::this_thread::sleep_for(std::chrono::milliseconds(10));
	apex_mem.Write<int>(g_Base + OFFSET_IN_ATTACK + 0x8, 5);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	apex_mem.Write<int>(g_Base + OFFSET_IN_ATTACK + 0x8, 4);
	//printf("TriggerBotRun\n");
	//printf("attackState: %i\n", attackState);
}
bool IsInCrossHair(Entity &target)
{
	static uintptr_t last_t = 0;
	static float last_crosshair_target_time = -1.f;
	float now_crosshair_target_time = target.lastCrossHairTime();
	bool is_trigger = false;
	if (last_t == target.ptr)
	{
		if(last_crosshair_target_time != -1.f)
		{
			if(now_crosshair_target_time > last_crosshair_target_time)
			{
				is_trigger = true;
				//printf("Trigger\n");
				last_crosshair_target_time = -1.f;
			}
			else
			{
				is_trigger = false;
				last_crosshair_target_time = now_crosshair_target_time;
			}
		}
		else
		{
			is_trigger = false;
			last_crosshair_target_time = now_crosshair_target_time;
		}
	}
	else
	{
		last_t = target.ptr;
		last_crosshair_target_time = -1.f;
	}
	return is_trigger;
}


//Player Definitions, dont edit unless you know what you are doing.
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
	int maxshield = 0;
	int armortype = 0;
	Vector EntityPosition;
	Vector LocalPlayerPosition;
	QAngle localviewangle;
	float targetyaw = 0;
	bool isAlive = 0;
	char name[33] = { 0 };
	char modelname[1024] = { 0 };
}player;

//item defs?



//Your in the matrix neo.
struct Matrix
{
	float matrix[16];
};


//Visual check and aim check.?
float lastvis_esp[toRead];
float lastvis_aim[toRead];


//Specator stuff. Just setting things up, dont edit.
int tmp_spec = 0, spectators = 0;
int tmp_all_spec = 0, allied_spectators = 0;


//////////////////////////////////////////////////////////////////////////////////////////////////

int settingIndex;
int contextId;
std::array<float, 3> highlightParameter;
//works
void SetPlayerGlow(Entity& LPlayer, Entity& Target, int index)
{
	if (player_glow >= 1)
	{
			if (!Target.isGlowing() || (int)Target.buffer[OFFSET_GLOW_THROUGH_WALLS_GLOW_VISIBLE_TYPE] != 1) {
				float currentEntityTime = 5000.f;
				if (!isnan(currentEntityTime) && currentEntityTime > 0.f) {
					if (!(firing_range) && (Target.isKnocked() || !Target.isAlive()))
					{
						contextId = 14;
						settingIndex = 80;
						highlightParameter = { glowrknocked, glowgknocked, glowbknocked };
					}
					else if (Target.lastVisTime() > lastvis_aim[index] || (Target.lastVisTime() < 0.f && lastvis_aim[index] > 0.f))
					{
						contextId = 15;
						settingIndex = 81;
						highlightParameter = { glowrviz, glowgviz, glowbviz };
					}
					else 
					{
						contextId = 16;
						settingIndex = 82;
						highlightParameter = { glowr, glowg, glowb };
					}
					Target.enableGlow();
				}
			}
	}
	
}


uint64_t PlayerLocal;
int PlayerLocalTeamID;
int EntTeam;
int LocTeam;

void ProcessPlayer(Entity& LPlayer, Entity& target, uint64_t entitylist, int index)
{
	int entity_team = target.getTeamId();
	TARGET_TEAMID = target.getTeamId();

	TEAM_TEAMID = LPlayer.getTeamId();
	//printf("TEAM_TEAMID: %i\n", TEAM_TEAMID);
	//printf("TARGET_TEAMID: %i\n", TARGET_TEAMID);		
	//
	float localyaw = LPlayer.GetYaw();
	float targetyaw = target.GetYaw();
	LocalYAW = localyaw;
	TargetYAW = targetyaw;
	//printf("localyaw: %f\n", localyaw);
	//printf("LocalYAW: %f\n", LocalYAW);
	if (!target.isAlive())
	{
		
		
		if(localyaw==targetyaw)
		{
			if(LPlayer.getTeamId() == entity_team)
				tmp_all_spec++;
			else
				tmp_spec++;
		}
		return;
	}
	
	if (TDMToggle)
	{// Check if the target entity is on the same team as the local player
		//int entity_team = Target.getTeamId();
		//printf("Target Team: %i\n", entity_team);


		uint64_t PlayerLocal;
		apex_mem.Read<uint64_t>(g_Base + OFFSET_LOCAL_ENT, PlayerLocal);
		int PlayerLocalTeamID;
		apex_mem.Read<int>(PlayerLocal + OFFSET_TEAM, PlayerLocalTeamID);



		if (entity_team % 2) EntTeam = 1;
		else EntTeam = 2;
		if (PlayerLocalTeamID % 2) LocTeam = 1;
		else LocTeam = 2;

		//printf("Target Team: %i\nLocal Team: %i\n", EntTeam, LocTeam);
		if (EntTeam == LocTeam)
			return;

	}
	
	
						

	Vector EntityPosition = target.getPosition();
	Vector LocalPlayerPosition = LPlayer.getPosition();
	float dist = LocalPlayerPosition.DistTo(EntityPosition);
	//Prints POS of localplayer for map cords for full map radar. only enable when adding a new map or fixing a old one, will output to console.
	//std::printf("  X: %.6f   ||    Y:%.6f",LocalPlayerPosition.x, LocalPlayerPosition.y); //Prints x and y cords of localplayer to get mainmap radar stuff.
	if (PrintMapCords)
	{
		std::printf("X: %.6f || Y: %.6f || %s\n", LocalPlayerPosition.x, LocalPlayerPosition.y, level_name);
	}

	if (dist > aimdist) return;
	
	
	//Firing range stuff
	if(!firing_range && !onevone)
		if (entity_team < 0 || entity_team>50 || entity_team == team_player) return;
	
	//Vis check aiming? dunno
	if(aim==2)
	{
		if((target.lastVisTime() > lastvis_aim[index]))
		{
			float fov = CalculateFov(LPlayer, target);
			if (fov < max)
			{
				max = fov;
				tmp_aimentity = target.ptr;
			}
		}
		else
		{
			if(aimentity==target.ptr)
			{
				aimentity=tmp_aimentity=lastaimentity=0;
			}
		}
		if (aimentity != 0)
		{
			uint64_t LocalPlayer = 0;
			apex_mem.Read<uint64_t>(g_Base + OFFSET_LOCAL_ENT, LocalPlayer);
			
			Entity Target = getEntity(aimentity);
			Entity LPlayer = getEntity(LocalPlayer);
			
			if(TriggerBot && IsInCrossHair(Target))
			{
				TriggerBotRun();
			}
		}
	}
	else
	{
		float fov = CalculateFov(LPlayer, target);
		if (fov < max)
		{
			max = fov;
			tmp_aimentity = target.ptr;
		}
	}
	
	SetPlayerGlow(LPlayer, target, index);
	lastvis_aim[index] = target.lastVisTime();
}


void ClientActions()
{
	cactions_t = true;
	while (cactions_t)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		while (g_Base!=0)
		{
			
			uint64_t LocalPlayer = 0;
			apex_mem.Read<uint64_t>(g_Base + OFFSET_LOCAL_ENT, LocalPlayer);
			Entity LPlayer = getEntity(LocalPlayer);
			uint64_t entitylist = g_Base + OFFSET_ENTITYLIST;
			attackState = 0;
			apex_mem.Read<int>(g_Base + OFFSET_IN_ATTACK, attackState); //108
			int tduckState = 0;
			apex_mem.Read<int>(g_Base + OFFSET_IN_TOGGLE_DUCK, tduckState); //61
			
			apex_mem.Read<typeof(button_state)>(g_Base + OFFSET_INPUT_SYSTEM + 0xb0, button_state);
			int HeldID;
			apex_mem.Read<int>(LocalPlayer + OFFSET_OFF_WEAPON, HeldID); // 0x1a1c
			//printf("NoNadeAim: %s\n", PrintHeldID ? "true" : "false");
			if(PrintHeldID)
			{
				printf("%d\n", HeldID);
			}
			
			if (HeldID == -251)
			{
				NoNadeAim = 1;
			}
			else
			{
				NoNadeAim = 0;
			}
			//printf("NoNadeAim: %s\n", NoNadeAim ? "true" : "false");
			int zoomState = 0;
			apex_mem.Read<int>(g_Base + OFFSET_IN_ZOOM, zoomState); //109
			int frameSleepTimer;
			int lastFrameNumber;
			bool superGlideStart;
			int superGlideTimer;
			curFrameNumber;
			float m_traversalProgressTmp = 0.0f;
			apex_mem.Read<int>(g_Base + OFFSET_GLOBAL_VARS + 0x0008, curFrameNumber); // GlobalVars + 0x0008
			//printf("TriggerBot: %d\n", TriggerBot ? 1 : 0);
			//printf("attackState: %i\n", attackState);
			//printf("TogglePrediction: %d\n", TogglePrediction ? 1 : 0);
			//float zoomfovtest;
			//apex_mem.Read<float>(LocalPlayer + OFFSET_ZOOM_FOV, zoomfovtest); //109
			//printf("zoomfovtest: %f\n", zoomfovtest);
			/*
			uint64_t wephandle = 0;
			apex_mem.Read<uint64_t>(LocalPlayer + OFFSET_WEAPON, wephandle);
			
			wephandle &= 0xffff;

			uint64_t wep_entity = 0;
			apex_mem.Read<uint64_t>(entitylist + (wephandle << 5), wep_entity);
			
			apex_mem.Read<float>(wep_entity + (0x1600 + 0x00bc), ScopeZoom); // m_playerData + m_targetZoomFOV
			
			//apex_mem.Read<float>(wep_entity + OFFSET_ZOOM_FOV, CurrentWeaponADSZoom);
			//printf("Zoom with scopes: %f\n", ScopeZoom);
			
			ulong ehWeaponHandle2;
			apex_mem.Read<uint64_t>(LocalPlayer + OFFSET_WEAPON, ehWeaponHandle2); // 0x1a1c
			ehWeaponHandle2 &= 0xFFFF; // eHandle
			ulong pWeapon2;
			apex_mem.Read<uint64_t>(entitylist + (ehWeaponHandle2 * 0x20), pWeapon2);
			uint32_t weaponID2;
			apex_mem.Read<uint32_t>(pWeapon2 + OFFSET_WEAPON_NAME, weaponID2); //0x1844
			
			printf("%d\n", weaponID2);
			*/
			//float minimapscale = 0.0f;
			//apex_mem.Read<float>(g_Base + OFFSET_MINIMAP_SCALE, minimapscale); //109
			//printf("minimapscale: %f\n", minimapscale);
			//printf("minimapscale: %f\n", minimapscale);
			//printf("Playerentcount: %i\n", playerentcount);
			//printf("Playerentcount: %i\n", itementcount);
			apex_mem.Read<float>(LocalPlayer + OFFSET_TRAVERSAL_PROGRESS, m_traversalProgress);
			//printf("Travel Time: %f\n", m_traversalProgress);
			//printf("Frame Sleep Timer: %i\n", frameSleepTimer);
			//printf("Last Frame: %i\n", lastFrameNumber);
			//printf("Super Glide Timer: %i\n", superGlideTimer);
			//printf("Last Frame: %i\n", lastFrameNumber);
			//printf("Cur Frame: %i\n", curFrameNumber);
			//printf("superGlideStart: %d\n", superGlideStart ? 1 : 0);
			int jump;
			int ducktoggle;
			int forceduck;
			//printf("Jump Value: %i\n", jump);
			//printf("Toggle Jump: %i\n", ducktoggle);
			//printf("Force Duck: %i\n", forceduck);
			apex_mem.Read<int>(g_Base + OFFSET_FORCE_JUMP + 0x8, jump);
			apex_mem.Read<int>(g_Base + OFFSET_IN_TOGGLE_DUCK + 0x8, ducktoggle);
			apex_mem.Read<int>(g_Base + OFFSET_FORCE_DUCK + 0x8, forceduck);
			//apex_mem.Write<int>(g_Base + OFFSET_FORCE_JUMP + 0x8, 4);
			//autofire
			
			while (AutoFire)
			{
				apex_mem.Write<int>(g_Base + OFFSET_IN_ATTACK + 0x8, 4);
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
				apex_mem.Write<int>(g_Base + OFFSET_IN_ATTACK + 0x8, 5);
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
				apex_mem.Write<int>(g_Base + OFFSET_IN_ATTACK + 0x8, 4);
			}
			//printf("AutoFire: %d\n", AutoFire ? 1 : 0);
			if (curFrameNumber > lastFrameNumber)
			{
				frameSleepTimer = 10; // <- middle of the frame // needs 5 for 144fps and 10 for 75 fps
			}
			lastFrameNumber = curFrameNumber;
			 
			if (frameSleepTimer == 0)
			{
				if(SuperKey)
				{
					if (m_traversalProgress > 0.87 && m_traversalProgress < 0.90) // needs to end at 0.90 for 144 fps and 0.92 for 75 fps
					{
						superGlideStart = true;
					}
				 
					if (superGlideStart)
					{
						superGlideTimer++;
						//printf("Timer Started \n");
						if (superGlideTimer == 5)
						{
							apex_mem.Write<int>(g_Base + OFFSET_FORCE_JUMP + 0x8, 5);
						}
						else if (superGlideTimer == 6)
						{
							apex_mem.Write<int>(g_Base + OFFSET_IN_TOGGLE_DUCK + 0x8, 6);
						}
						else if (superGlideTimer == 10) //needs to be 10 for 75 and 144fps?
						{
							apex_mem.Write<int>(g_Base + OFFSET_FORCE_JUMP + 0x8, 4);
							apex_mem.Write<int>(g_Base + OFFSET_FORCE_DUCK + 0x8, 5);
							apex_mem.Write<int>(g_Base + OFFSET_FORCE_DUCK + 0x8, 4);
							m_traversalProgressTmp = m_traversalProgress;
						}
						else if (superGlideTimer > 10 && m_traversalProgress != m_traversalProgressTmp)
						{
							superGlideStart = false;
							superGlideTimer = 0;
						}
					}
				}
			}
			frameSleepTimer -= 1;
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
	cactions_t = false;
}
//Main stuff, dont edit.
void DoActions()
{
	actions_t = true;
	while (actions_t)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		uint32_t counter = 0;

		while (g_Base!=0 && c_Base!=0)
		{
			
			
			if(firing_range)
			{
				playerentcount = 16000;
			}
			else
			{
				playerentcount = 101;
			}
			
			uint64_t LocalPlayer = 0;
			apex_mem.Read<uint64_t>(g_Base + OFFSET_LOCAL_ENT, LocalPlayer);
			Entity LPlayer = getEntity(LocalPlayer);
			uint64_t entitylist = g_Base + OFFSET_ENTITYLIST;
			
			
			
			
			if(insidevaluegoggle)
			{
				insidevalue = 14;
			}
			else
			{
				insidevalue = 0;
			}
			
			char MapName[200] = { 0 };
			//uint64_t MapName_ptr;
			//apex_mem.Read<uint64_t>(g_Base + OFFSET_HOST_MAP, MapName_ptr);
			//apex_mem.ReadArray<char>(MapName_ptr, MapName, 200);
			
			apex_mem.ReadArray<char>(g_Base + OFFSET_LEVELNAME, level_name, sizeof(level_name));	
			//printf("%s\n", level_name);
			
			
			if (strcmp(level_name, "mp_rr_tropic_island_mu2") == 0) 
			{
				map = 1;
			} 
			else if (strcmp(level_name, "mp_rr_canyonlands_hu") == 0) 
			{
				map = 2;
			}
			else if (strcmp(level_name, "mp_rr_desertlands_hu") == 0) 
			{
				map = 3;
			}
			else if (strcmp(level_name, "mp_rr_olympus_mu2") == 0) 
			{
				map = 4;
			} 
			else  if (strcmp(level_name, "mp_rr_divided_moon") == 0)
			{
				map = 5;
			}
			else
			{
				map = 0;
			}
			//printf("%i\n", map);
			std::this_thread::sleep_for(std::chrono::milliseconds(30));
			
			if (LocalPlayer == 0) continue;

			//Entity LPlayer = getEntity(LocalPlayer);

			team_player = LPlayer.getTeamId();
			if (team_player < 0 || team_player>50 && !onevone)
			{
				continue;
			}
			//uint64_t entitylist = g_Base + OFFSET_ENTITYLIST;

			uint64_t baseent = 0;
			apex_mem.Read<uint64_t>(entitylist, baseent);
			if (baseent == 0)
			{
				continue;
			}
			//Nade test
			//int HeldID;
			//apex_mem.Read<int>(LocalPlayer + OFFSET_OFF_WEAPON, HeldID); // 0x1a1c
			//printf("%i\n", HeldID);
			
			
			//Dont edit.
			max = 999.0f;
			tmp_aimentity = 0;
			tmp_spec = 0;
			tmp_all_spec = 0;
			if(firing_range)
			{
				int c=0;
				//Ammount of ents to loop, dont edit.
				for (int i = 0; i < playerentcount; i++)
				{
					uint64_t centity = 0;
					apex_mem.Read<uint64_t>(entitylist + ((uint64_t)i << 5), centity);
					if (centity == 0) continue;
					if (LocalPlayer == centity) continue;

					Entity Target = getEntity(centity);
					if (!Target.isDummy())
					{
						continue;
					}



									   
					ProcessPlayer(LPlayer, Target, entitylist, c);
					c++;
				}
			}
			else
			{
				for (int i = 0; i < toRead; i++)
				{
					uint64_t centity = 0;
					apex_mem.Read<uint64_t>(entitylist + ((uint64_t)i << 5), centity);
					if (centity == 0) continue;
					if (LocalPlayer == centity) continue;

					Entity Target = getEntity(centity);
					if (!Target.isPlayer())
					{
						continue;
					}
					
					ProcessPlayer(LPlayer, Target, entitylist, i);

					int entity_team = Target.getTeamId();
					if (entity_team == team_player && !onevone)
					{
						continue;
					}

										   
				}
			}

			if(!spectators && !allied_spectators)
			{
				spectators = tmp_spec;
				allied_spectators = tmp_all_spec;
			}
			else
			{
				//refresh spectators count every ~2 seconds
				counter++;
				if(counter==70)
				{
					spectators = tmp_spec;
					allied_spectators = tmp_all_spec;
					counter = 0;
				}
			}

			if(!lock)
				aimentity = tmp_aimentity;
			else
				aimentity = lastaimentity;			
		}
	}
	actions_t = false;
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////

player players[toRead];

//ESP loop.. this helps right?
static void EspLoop()
{
	esp_t = true;
	while(esp_t)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		while(g_Base!=0 && c_Base!=0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			if (esp)
			{
				valid = false;

				uint64_t LocalPlayer = 0;
				apex_mem.Read<uint64_t>(g_Base + OFFSET_LOCAL_ENT, LocalPlayer);
				if (LocalPlayer == 0)
				{
					next2 = true;
					while(next2 && g_Base!=0 && c_Base!=0 && esp)
					{
						std::this_thread::sleep_for(std::chrono::milliseconds(1));
					}
					continue;
				}
				Entity LPlayer = getEntity(LocalPlayer);
				int team_player = LPlayer.getTeamId();
				if (team_player < 0 || team_player>50)
				{
					next2 = true;
					while(next2 && g_Base!=0 && c_Base!=0 && esp)
					{
						std::this_thread::sleep_for(std::chrono::milliseconds(1));
					}
					continue;
				}
				Vector LocalPlayerPosition = LPlayer.getPosition();

				uint64_t viewRenderer = 0;
				apex_mem.Read<uint64_t>(g_Base + OFFSET_RENDER, viewRenderer);
				uint64_t viewMatrix = 0;
				apex_mem.Read<uint64_t>(viewRenderer + OFFSET_MATRIX, viewMatrix);
				Matrix m = {};
				apex_mem.Read<Matrix>(viewMatrix, m);

				uint64_t entitylist = g_Base + OFFSET_ENTITYLIST;
				
				memset(players,0,sizeof(players));
				int ScreenX;
				int ScreenY;
				if (ScreenResINT == 0)
				{
					ScreenX = 1920;
					ScreenY = 1080;
				}
				if (ScreenResINT == 1)
				{
					ScreenX = 2560;
					ScreenY = 1440;
				}
				if(firing_range)
				{
					int c=0;
					//Ammount of ents to loop, dont edit.
					for (int i = 0; i < playerentcount; i++)
					{
						uint64_t centity = 0;
						apex_mem.Read<uint64_t>( entitylist + ((uint64_t)i << 5), centity);
						if (centity == 0)
						{
							continue;
						}		
						
						if (LocalPlayer == centity)
						{
							continue;
						}

						Entity Target = getEntity(centity);

						if (!Target.isDummy())
						{
							continue;
						}
						/*
						if (!Target.isAlive())
						{
							continue;
						}
						*/
						int entity_team = Target.getTeamId();
						if (!onevone)
						{
							if (entity_team < 0 || entity_team>50 || entity_team == team_player)
							{
								continue;
							}
						}
						else
						{
							if (entity_team < 0 || entity_team>50)
							{
                              continue;
                            }
						}
						Vector EntityPosition = Target.getPosition();
						float dist = LocalPlayerPosition.DistTo(EntityPosition);

						if (dist > max_dist || dist < 50.0f)
						{	
							continue;
						}
						
						Vector bs = Vector();
						//Change res to your res here, default is 1080p but can copy paste 1440p here
						
						WorldToScreen(EntityPosition, m.matrix, ScreenX, ScreenY, bs); //2560, 1440
						if (esp)
						{
							Vector hs = Vector();
							Vector HeadPosition = Target.getBonePositionByHitbox(0);
							//Change res to your res here, default is 1080p but can copy paste 1440p here
							WorldToScreen(HeadPosition, m.matrix, ScreenX, ScreenY, hs); //2560, 1440
							float height = abs(abs(hs.y) - abs(bs.y));
							float width = height / 2.0f;
							float boxMiddle = bs.x - (width / 2.0f);
							int health = Target.getHealth();
							int shield = Target.getShield();
							int maxshield = Target.getMaxshield();
							int armortype = Target.getArmortype();
							players[c] = 
							{
								dist,
								entity_team,
								boxMiddle,
								hs.y,
								width,
								height,
								bs.x,
								bs.y,
								0,
								(Target.lastVisTime() > lastvis_esp[c]),
								health,
								shield,
								maxshield,
								armortype
								//Target.isAlive()
								
							};
							Target.get_name(g_Base, i-1, &players[c].name[0]);
							Target.get_modelname(g_Base, &players[c].modelname[0]);
							lastvis_esp[c] = Target.lastVisTime();
							valid = true;
							c++;
						}
					}
				}	
				else if (!firing_range)
				{
					for (int i = 0; i < toRead; i++)
					{
						uint64_t centity = 0;
						apex_mem.Read<uint64_t>( entitylist + ((uint64_t)i << 5), centity);
						if (centity == 0)
						{
							continue;
						}
						
						if (LocalPlayer == centity)
						{
							continue;
						}

						Entity Target = getEntity(centity);
						
						if (!Target.isPlayer())
						{
							continue;
						}

						if (!Target.isAlive())
						{
							continue;
						}

						int entity_team = Target.getTeamId();
						if (!onevone)
						{
							if (entity_team < 0 || entity_team>50 || entity_team == team_player)
							{
								continue;
							}
						}
						else
						{
							if (entity_team < 0 || entity_team>50)
							{
                              continue;
                            }
						}

						Vector EntityPosition = Target.getPosition();
						float dist = LocalPlayerPosition.DistTo(EntityPosition);
						if (dist > max_dist || dist < 50.0f)
						{	
							continue;
						}

						Vector bs = Vector();
						//Change res to your res here, default is 1080p but can copy paste 1440p here
						WorldToScreen(EntityPosition, m.matrix, ScreenX, ScreenY, bs); //2560, 1440
						if (esp)
						{
							Vector hs = Vector();
							Vector HeadPosition = Target.getBonePositionByHitbox(0);
							//Change res to your res here, default is 1080p but can copy paste 1440p here
							WorldToScreen(HeadPosition, m.matrix, ScreenX, ScreenY, hs); //2560, 1440
							float height = abs(abs(hs.y) - abs(bs.y));
							float width = height / 2.0f;
							float boxMiddle = bs.x - (width / 2.0f);
							int health = Target.getHealth();
							int shield = Target.getShield();
							int maxshield = Target.getMaxshield();
							int armortype = Target.getArmortype();
							Vector EntityPosition = Target.getPosition();
							Vector LocalPlayerPosition = LPlayer.getPosition();
							QAngle localviewangle = LPlayer.GetViewAngles();
							float targetyaw = Target.GetYaw();
							bool IsAlive = Target.isAlive();
							
							
							players[i] = 
							{
								dist,
								entity_team,
								boxMiddle,
								hs.y,
								width,
								height,
								bs.x,
								bs.y,
								Target.isKnocked(),
								(Target.lastVisTime() > lastvis_esp[i]),
								health,
								shield,
								maxshield,
								armortype,
								EntityPosition,
								LocalPlayerPosition,
								localviewangle,
								targetyaw,
								IsAlive
							};
							Target.get_name(g_Base, i-1, &players[i].name[0]);
							Target.get_modelname(centity, &players[i].modelname[0]);
							//uint64_t modelname_ptr = 0;
							//apex_mem.Read<uint64_t>(g_Base + OFFSET_MODELNAME, modelname_ptr);
							//apex_mem.ReadArray<char>(modelname_ptr, &players[i].modelname[0], 1024);
							//printf("Model Name: %s\n", &players[i].modelname[0]);
							
							lastvis_esp[i] = Target.lastVisTime();
							valid = true;
						}
					}
				}

				next2 = true;
				while(next2 && g_Base!=0 && c_Base!=0 && esp)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(1));
				}
			}
		}
	}
	esp_t = false;
}
//Aimbot Loop stuff
static void AimbotLoop()
{
	aim_t = true;
	while (aim_t)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		while (g_Base!=0 && c_Base!=0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			if (aim>0)
			{
				if (aimentity == 0 || !aiming)
				{
					lock=false;
					lastaimentity=0;
					continue;
				}
				lock=true;
				lastaimentity = aimentity;
				uint64_t LocalPlayer = 0;
				apex_mem.Read<uint64_t>(g_Base + OFFSET_LOCAL_ENT, LocalPlayer);
				if (LocalPlayer == 0) continue;
				Entity LPlayer = getEntity(LocalPlayer);
				QAngle Angles = CalculateBestBoneAim(LPlayer, aimentity, max_fov);
				if (Angles.x == 0 && Angles.y == 0)
				{
					lock=false;
					lastaimentity=0;
					continue;
				}
				LPlayer.SetViewAngles(Angles);
			}
		}
	}
	aim_t = false;
}
//Client memory vars/reads. HAVE to match windows client numbers.
static void set_vars(uint64_t add_addr)
{
	printf("Reading EliteNinja2 vars...\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	//Get addresses of client vars
	uint64_t check_addr = 0;
	client_mem.Read<uint64_t>(add_addr, check_addr);
	uint64_t aim_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t), aim_addr);
	uint64_t esp_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*2, esp_addr);
	uint64_t aiming_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*3, aiming_addr);
	uint64_t g_Base_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*4, g_Base_addr);
	uint64_t next2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*5, next2_addr);
	uint64_t player_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*6, player_addr);
	uint64_t valid_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*7, valid_addr);
	uint64_t max_dist_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*8, max_dist_addr);
	uint64_t item_glow_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*9, item_glow_addr);
	uint64_t player_glow_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*10, player_glow_addr);
	uint64_t aim_no_recoil_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*11, aim_no_recoil_addr);
	uint64_t smooth_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*12, smooth_addr);
	uint64_t max_fov_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*13, max_fov_addr);
	uint64_t bone_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*14, bone_addr);
	uint64_t spectators_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*16, spectators_addr);
	uint64_t allied_spectators_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*17, allied_spectators_addr);
	uint64_t glowr_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*18, glowr_addr);
	uint64_t glowg_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*19, glowg_addr);
	uint64_t glowb_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*20, glowb_addr);
	uint64_t firing_range_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*21, firing_range_addr);
	uint64_t lightbackpack_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*22, lightbackpack_addr);
	uint64_t medbackpack_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*23, medbackpack_addr);
	uint64_t heavybackpack_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*24, heavybackpack_addr);
	uint64_t shieldupgrade1_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*25, shieldupgrade1_addr);
	uint64_t shieldupgradehead1_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*26, shieldupgradehead1_addr);
	uint64_t accelerant_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*27, accelerant_addr);
	uint64_t phoenix_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*28, phoenix_addr);
	uint64_t healthlarge_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*29, healthlarge_addr);
	uint64_t healthsmall_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*30, healthsmall_addr);
	uint64_t shieldbattsmall_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*31, shieldbattsmall_addr);
	uint64_t shieldbattlarge_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*32, shieldbattlarge_addr);
	uint64_t sniperammo_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*33, sniperammo_addr);
	uint64_t heavyammo_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*34, heavyammo_addr);
	uint64_t optic1xhcog_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*35, optic1xhcog_addr);
	uint64_t lightammo_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*36, lightammo_addr);
	uint64_t energyammo_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*37, energyammo_addr);
	uint64_t shotgunammo_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*38, shotgunammo_addr);
	uint64_t lasersight1_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*39, lasersight1_addr);
	uint64_t sniperammomag1_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*40, sniperammomag1_addr);
	uint64_t energyammomag1_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*41, energyammomag1_addr);
	uint64_t stocksniper1_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*42, stocksniper1_addr);
	uint64_t stockregular1_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*43, stockregular1_addr);
	uint64_t shielddown1_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*44, shielddown1_addr);
	uint64_t lightammomag1_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*45, lightammomag1_addr);
	uint64_t heavyammomag1_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*46, heavyammomag1_addr);
	uint64_t optic2xhcog_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*47, optic2xhcog_addr);
	uint64_t opticholo1x_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*48, opticholo1x_addr);
	uint64_t opticholo1x2x_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*49, opticholo1x2x_addr);
	uint64_t opticthreat_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*50, opticthreat_addr);
	uint64_t optic3xhcog_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*51, optic3xhcog_addr);
	uint64_t optic2x4x_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*52, optic2x4x_addr);
	uint64_t opticsniper6x_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*53, opticsniper6x_addr);
	uint64_t opticsniper4x8x_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*54, opticsniper4x8x_addr);
	uint64_t opticsniperthreat_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*55, opticsniperthreat_addr);
	uint64_t suppressor1_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*56, suppressor1_addr);
	uint64_t turbo_charger_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*57, turbo_charger_addr);
	uint64_t grenade_frag_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*58, grenade_frag_addr);
	uint64_t grenade_arc_star_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*59, grenade_arc_star_addr);
	uint64_t grenade_thermite_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*60, grenade_thermite_addr);
	uint64_t shotgunbolt1_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*61, shotgunbolt1_addr);
	uint64_t weapon_kraber_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*62, weapon_kraber_addr);
	uint64_t weapon_mastiff_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*63, weapon_mastiff_addr);
	uint64_t weapon_lstar_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*64, weapon_lstar_addr);
	uint64_t weapon_havoc_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*65, weapon_havoc_addr);
	uint64_t weapon_devotion_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*66, weapon_devotion_addr);
	uint64_t weapon_triple_take_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*67, weapon_triple_take_addr);
	uint64_t weapon_flatline_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*68, weapon_flatline_addr);
	uint64_t weapon_hemlock_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*69, weapon_hemlock_addr);
	uint64_t weapon_g7_scout_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*70, weapon_g7_scout_addr);
	uint64_t weapon_alternator_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*71, weapon_alternator_addr);
	uint64_t weapon_r99_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*72, weapon_r99_addr);
	uint64_t weapon_prowler_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*73, weapon_prowler_addr);
	uint64_t weapon_volt_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*74, weapon_volt_addr);
	uint64_t weapon_longbow_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*75, weapon_longbow_addr);
	uint64_t weapon_charge_rifle_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*76, weapon_charge_rifle_addr);
	uint64_t weapon_spitfire_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*77, weapon_spitfire_addr);
	uint64_t weapon_r301_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*78, weapon_r301_addr);
	uint64_t weapon_eva8_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*79, weapon_eva8_addr);
	uint64_t weapon_peacekeeper_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*80, weapon_peacekeeper_addr);
	uint64_t weapon_mozambique_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*81, weapon_mozambique_addr);
	uint64_t weapon_wingman_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*82, weapon_wingman_addr);
	uint64_t weapon_p2020_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*83, weapon_p2020_addr);
	uint64_t weapon_re45_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*84, weapon_re45_addr);
	uint64_t weapon_sentinel_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*85, weapon_sentinel_addr);
	uint64_t weapon_bow_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*86, weapon_bow_addr);
	uint64_t weapon_3030_repeater_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*87, weapon_3030_repeater_addr);
	uint64_t weapon_rampage_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*88, weapon_rampage_addr);
	uint64_t weapon_car_smg_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*89, weapon_car_smg_addr);
	uint64_t aimdist_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*90, aimdist_addr);
	uint64_t itemglowbrightness_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*91, itemglowbrightness_addr);
	uint64_t glowrviz_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*92, glowrviz_addr);
	uint64_t glowgviz_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*93, glowgviz_addr);
	uint64_t glowbviz_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*94, glowbviz_addr);
	uint64_t glowrknocked_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*95, glowrknocked_addr);
	uint64_t glowgknocked_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*96, glowgknocked_addr);
	uint64_t glowbknocked_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*97, glowbknocked_addr);
	uint64_t bulletspeed_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*98, bulletspeed_addr);
	uint64_t bulletgrav_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*99, bulletgrav_addr);
	uint64_t weapon_nemesis_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*100, weapon_nemesis_addr);
	uint64_t EntTeam_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*102, EntTeam_addr);
	uint64_t LocTeam_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*103, LocTeam_addr);
	uint64_t TDMToggle_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*104, TDMToggle_addr);
	uint64_t onevone_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*105, onevone_addr);
	uint64_t shieldupgrade2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*106, shieldupgrade2_addr);
	uint64_t shieldupgradehead2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*107, shieldupgradehead2_addr);
	uint64_t shieldupgrade3_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*108, shieldupgrade3_addr);
	uint64_t shieldupgradehead3_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*109, shieldupgradehead3_addr);
	uint64_t shieldupgrade4_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*110, shieldupgrade4_addr);
	uint64_t shieldupgradehead4_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*111, shieldupgradehead4_addr);
	uint64_t shielddown2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*112, shielddown2_addr);
	uint64_t shielddown3_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*113, shielddown3_addr);
	uint64_t shielddown4_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*114, shielddown4_addr);
	uint64_t sniperammomag2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*115, sniperammomag2_addr);
	uint64_t sniperammomag3_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*116, sniperammomag3_addr);
	uint64_t sniperammomag4_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*117, sniperammomag4_addr);
	uint64_t energyammomag2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*118, energyammomag2_addr);
	uint64_t energyammomag3_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*119, energyammomag3_addr);
	uint64_t energyammomag4_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*120, energyammomag4_addr);
	uint64_t lightammomag2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*121, lightammomag2_addr);
	uint64_t lightammomag3_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*122, lightammomag3_addr);
	uint64_t lightammomag4_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*123, lightammomag4_addr);
	uint64_t heavyammomag2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*124, heavyammomag2_addr);
	uint64_t heavyammomag3_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*125, heavyammomag3_addr);
	uint64_t heavyammomag4_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*126, heavyammomag4_addr);
	uint64_t lasersight2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*127, lasersight2_addr);
	uint64_t lasersight3_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*128, lasersight3_addr);
	uint64_t lasersight4_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*129, lasersight4_addr);
	uint64_t stocksniper2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*130, stocksniper2_addr);
	uint64_t stockregular2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*131, stockregular2_addr);
	uint64_t stocksniper3_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*132, stocksniper3_addr);
	uint64_t stockregular3_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*133, stockregular3_addr);
	uint64_t suppressor2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*134, suppressor2_addr);
	uint64_t suppressor3_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*135, suppressor3_addr);
	uint64_t skull_piecer_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*136, skull_piecer_addr);
	uint64_t hammer_point_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*137, hammer_point_addr);
	uint64_t disruptor_rounds_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*138, disruptor_rounds_addr);
	uint64_t boosted_loader_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*139, boosted_loader_addr);
	uint64_t shotgunbolt2_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*140, shotgunbolt2_addr);
	uint64_t shotgunbolt3_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*141, shotgunbolt3_addr);
	uint64_t shotgunbolt4_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*142, shotgunbolt4_addr);
	uint64_t insidevaluegoggle_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*143, insidevaluegoggle_addr);
	uint64_t outlinesize_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*144, outlinesize_addr);
	uint64_t goldbackpack_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*145, goldbackpack_addr);
	uint64_t shieldupgrade5_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*146, shieldupgrade5_addr);
	uint64_t SuperKey_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*147, SuperKey_addr);
	uint64_t m_traversalProgress_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*150, m_traversalProgress_addr);
	uint64_t LocalYAW_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*151, LocalYAW_addr);
	uint64_t TargetYAW_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*152, TargetYAW_addr);
	uint64_t TARGET_TEAMID_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*153, TARGET_TEAMID_addr);
	uint64_t TEAM_TEAMID_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*154, TEAM_TEAMID_addr);
	uint64_t TriggerBot_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*155, TriggerBot_addr);
	uint64_t tapstrafeenable_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*156, tapstrafeenable_addr);
	uint64_t lstarvalueid_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*157, lstarvalueid_addr);
	uint64_t PrintMapCords_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*158, PrintMapCords_addr);
	uint64_t veltest_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*159, veltest_addr);
	uint64_t CurrentWeaponADSZoom_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*160, CurrentWeaponADSZoom_addr);
	uint64_t map_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*161, map_addr);
	uint64_t TogglePrediction_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*162, TogglePrediction_addr);
	uint64_t AutoFire_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*163, AutoFire_addr);
	uint64_t PrintModelAndId_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*164, PrintModelAndId_addr);
	uint64_t ScreenResINT_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*165, ScreenResINT_addr);
	uint64_t BoxEnable_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*166, BoxEnable_addr);
	uint64_t NoNadeAim_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*167, NoNadeAim_addr);
	uint64_t PrintHeldID_addr = 0;
	client_mem.Read<uint64_t>(add_addr + sizeof(uint64_t)*168, PrintHeldID_addr);
	uint32_t check = 0;
	client_mem.Read<uint32_t>(check_addr, check);
	if(check != 0xABCD)
	{
		active = false;
		return;
	}
	vars_t = true;
	while(vars_t)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		if(c_Base!=0 && g_Base!=0)
		{
			client_mem.Write<uint32_t>(check_addr, 0);
			printf("\nLet the fun begin!\n");
		}

		while(c_Base!=0 && g_Base!=0)
		{
			//same as above, has to match with eveything else
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			client_mem.Write<uint64_t>(g_Base_addr, g_Base);
			client_mem.Write<int>(spectators_addr, spectators);
			client_mem.Write<int>(allied_spectators_addr, allied_spectators);
			client_mem.Read<int>(aim_addr, aim);
			client_mem.Read<bool>(esp_addr, esp);
			client_mem.Read<bool>(aiming_addr, aiming);
			client_mem.Read<float>(max_dist_addr, max_dist);
			client_mem.Read<bool>(item_glow_addr, item_glow);
			client_mem.Read<bool>(player_glow_addr, player_glow);
			client_mem.Read<bool>(aim_no_recoil_addr, aim_no_recoil);
			client_mem.Read<float>(smooth_addr, smooth);
			client_mem.Read<float>(max_fov_addr, max_fov);
			client_mem.Read<int>(bone_addr, bone);
			client_mem.Read<float>(glowr_addr, glowr);
			client_mem.Read<float>(glowg_addr, glowg);
			client_mem.Read<float>(glowb_addr, glowb);
			client_mem.Read<bool>(firing_range_addr, firing_range);
			client_mem.Read<bool>(lightbackpack_addr, lightbackpack);
			client_mem.Read<bool>(medbackpack_addr, medbackpack);
			client_mem.Read<bool>(heavybackpack_addr, heavybackpack);
			client_mem.Read<bool>(shieldupgrade1_addr, shieldupgrade1);
			client_mem.Read<bool>(shieldupgradehead1_addr, shieldupgradehead1);
			client_mem.Read<bool>(accelerant_addr, accelerant);
			client_mem.Read<bool>(phoenix_addr, phoenix);
			client_mem.Read<bool>(healthlarge_addr, healthlarge);
			client_mem.Read<bool>(healthsmall_addr, healthsmall);
			client_mem.Read<bool>(shieldbattsmall_addr, shieldbattsmall);
			client_mem.Read<bool>(shieldbattlarge_addr, shieldbattlarge);
			client_mem.Read<bool>(sniperammo_addr, sniperammo);
			client_mem.Read<bool>(heavyammo_addr, heavyammo);
			client_mem.Read<bool>(optic1xhcog_addr, optic1xhcog);
			client_mem.Read<bool>(lightammo_addr, lightammo);
			client_mem.Read<bool>(energyammo_addr, energyammo);
			client_mem.Read<bool>(shotgunammo_addr, shotgunammo);
			client_mem.Read<bool>(lasersight1_addr, lasersight1);
			client_mem.Read<bool>(sniperammomag1_addr, sniperammomag1);
			client_mem.Read<bool>(energyammomag1_addr , energyammomag1);
			client_mem.Read<bool>(stocksniper1_addr, stocksniper1);
			client_mem.Read<bool>(stockregular1_addr, stockregular1);
			client_mem.Read<bool>(stocksniper2_addr, stocksniper2);
			client_mem.Read<bool>(stockregular2_addr, stockregular2);
			client_mem.Read<bool>(stocksniper3_addr, stocksniper3);
			client_mem.Read<bool>(stockregular3_addr, stockregular3);
			client_mem.Read<bool>(shielddown1_addr, shielddown1);
			client_mem.Read<bool>(lightammomag1_addr, lightammomag1);
			client_mem.Read<bool>(heavyammomag1_addr, heavyammomag1);
			client_mem.Read<bool>(optic2xhcog_addr, optic2xhcog);
			client_mem.Read<bool>(opticholo1x_addr, opticholo1x);
			client_mem.Read<bool>(opticholo1x2x_addr, opticholo1x2x);
			client_mem.Read<bool>(opticthreat_addr, opticthreat);
			client_mem.Read<bool>(optic3xhcog_addr, optic3xhcog);
			client_mem.Read<bool>(optic2x4x_addr, optic2x4x);
			client_mem.Read<bool>(opticsniper6x_addr, opticsniper6x);
			client_mem.Read<bool>(opticsniper4x8x_addr, opticsniper4x8x);
			client_mem.Read<bool>(opticsniperthreat_addr, opticsniperthreat);
			client_mem.Read<bool>(suppressor1_addr, suppressor1);
			client_mem.Read<bool>(turbo_charger_addr, turbo_charger);
			client_mem.Read<bool>(grenade_frag_addr, grenade_frag);
			client_mem.Read<bool>(grenade_arc_star_addr, grenade_arc_star);
			client_mem.Read<bool>(grenade_thermite_addr, grenade_thermite);
			client_mem.Read<bool>(shotgunbolt1_addr, shotgunbolt1);
			client_mem.Read<bool>(shotgunbolt2_addr, shotgunbolt2);
			client_mem.Read<bool>(shotgunbolt3_addr, shotgunbolt3);
			client_mem.Read<bool>(shotgunbolt4_addr, shotgunbolt4);
			client_mem.Read<bool>(weapon_kraber_addr, weapon_kraber);
			client_mem.Read<bool>(weapon_mastiff_addr, weapon_mastiff);
			client_mem.Read<bool>(weapon_lstar_addr, weapon_lstar);
			client_mem.Read<bool>(weapon_havoc_addr, weapon_havoc);
			client_mem.Read<bool>(weapon_devotion_addr, weapon_devotion);
			client_mem.Read<bool>(weapon_triple_take_addr, weapon_triple_take);
			client_mem.Read<bool>(weapon_flatline_addr, weapon_flatline);
			client_mem.Read<bool>(weapon_hemlock_addr, weapon_hemlock);
			client_mem.Read<bool>(weapon_g7_scout_addr, weapon_g7_scout);
			client_mem.Read<bool>(weapon_alternator_addr, weapon_alternator);
			client_mem.Read<bool>(weapon_r99_addr, weapon_r99);
			client_mem.Read<bool>(weapon_prowler_addr, weapon_prowler);
			client_mem.Read<bool>(weapon_volt_addr, weapon_volt);
			client_mem.Read<bool>(weapon_longbow_addr, weapon_longbow);
			client_mem.Read<bool>(weapon_charge_rifle_addr, weapon_charge_rifle);
			client_mem.Read<bool>(weapon_spitfire_addr, weapon_spitfire);
			client_mem.Read<bool>(weapon_r301_addr, weapon_r301);
			client_mem.Read<bool>(weapon_eva8_addr, weapon_eva8);
			client_mem.Read<bool>(weapon_peacekeeper_addr, weapon_peacekeeper);
			client_mem.Read<bool>(weapon_mozambique_addr, weapon_mozambique);
			client_mem.Read<bool>(weapon_wingman_addr, weapon_wingman);
			client_mem.Read<bool>(weapon_p2020_addr, weapon_p2020);
			client_mem.Read<bool>(weapon_re45_addr, weapon_re45);
			client_mem.Read<bool>(weapon_sentinel_addr, weapon_sentinel);
			client_mem.Read<bool>(weapon_bow_addr, weapon_bow);
			client_mem.Read<bool>(weapon_3030_repeater_addr, weapon_3030_repeater);
			client_mem.Read<bool>(weapon_rampage_addr, weapon_rampage);
			client_mem.Read<bool>(weapon_car_smg_addr, weapon_car_smg);
			client_mem.Read<float>(aimdist_addr, aimdist);
			client_mem.Read<int>(itemglowbrightness_addr, itemglowbrightness);
			//glow visable
			client_mem.Read<float>(glowrviz_addr, glowrviz);
			client_mem.Read<float>(glowgviz_addr, glowgviz);
			client_mem.Read<float>(glowbviz_addr, glowbviz);
			//knocked
			client_mem.Read<float>(glowrknocked_addr, glowrknocked);
			client_mem.Read<float>(glowgknocked_addr, glowgknocked);
			client_mem.Read<float>(glowbknocked_addr, glowbknocked);
			client_mem.Read<float>(bulletspeed_addr, bulletspeed);
			client_mem.Read<float>(bulletgrav_addr, bulletgrav);
			//new weapon, nemesis
			
			client_mem.Read<bool>(weapon_nemesis_addr, weapon_nemesis);
			//More TDM toggle stuff
			client_mem.Write<int>(EntTeam_addr, EntTeam);
			client_mem.Write<int>(LocTeam_addr, LocTeam);
			client_mem.Read<bool>(TDMToggle_addr, TDMToggle);
			//1v1
			client_mem.Read<bool>(onevone_addr, onevone);
			//map
			client_mem.Read<bool>(shieldupgrade2_addr, shieldupgrade2);
			client_mem.Read<bool>(shieldupgradehead2_addr, shieldupgradehead2);
			
			client_mem.Read<bool>(shieldupgrade3_addr, shieldupgrade3);
			client_mem.Read<bool>(shieldupgradehead3_addr, shieldupgradehead3);
			
			client_mem.Read<bool>(shieldupgrade4_addr, shieldupgrade4);
			client_mem.Read<bool>(shieldupgrade5_addr, shieldupgrade5);
			client_mem.Read<bool>(shieldupgradehead4_addr, shieldupgradehead4);
			client_mem.Read<bool>(shielddown2_addr, shielddown2);
			client_mem.Read<bool>(shielddown3_addr, shielddown3);
			client_mem.Read<bool>(shielddown4_addr, shielddown4);
			
			client_mem.Read<bool>(sniperammomag2_addr, sniperammomag2);
			client_mem.Read<bool>(sniperammomag3_addr, sniperammomag3);
			client_mem.Read<bool>(sniperammomag4_addr, sniperammomag4);
			
			client_mem.Read<bool>(energyammomag2_addr, energyammomag2);
			client_mem.Read<bool>(energyammomag3_addr, energyammomag3);
			client_mem.Read<bool>(energyammomag4_addr, energyammomag4);
			
			client_mem.Read<bool>(lightammomag2_addr, lightammomag2);
			client_mem.Read<bool>(lightammomag3_addr, lightammomag3);
			client_mem.Read<bool>(lightammomag4_addr, lightammomag4);
			
			client_mem.Read<bool>(heavyammomag2_addr, heavyammomag2);
			client_mem.Read<bool>(heavyammomag3_addr, heavyammomag3);
			client_mem.Read<bool>(heavyammomag4_addr, heavyammomag4);
			
			client_mem.Read<bool>(lasersight2_addr, lasersight2);
			client_mem.Read<bool>(lasersight3_addr, lasersight3);
			client_mem.Read<bool>(lasersight4_addr, lasersight4);
			
			client_mem.Read<bool>(stocksniper2_addr, stocksniper2);
			client_mem.Read<bool>(stockregular2_addr, stockregular2);
			
			client_mem.Read<bool>(stocksniper3_addr, stocksniper3);
			client_mem.Read<bool>(stockregular3_addr, stockregular3);
		
			client_mem.Read<bool>(suppressor2_addr, suppressor2);
			client_mem.Read<bool>(suppressor3_addr, suppressor3);
			
			client_mem.Read<bool>(skull_piecer_addr, skull_piecer);
			client_mem.Read<bool>(hammer_point_addr, hammer_point);
			client_mem.Read<bool>(disruptor_rounds_addr, disruptor_rounds);
			client_mem.Read<bool>(boosted_loader_addr, boosted_loader);
			client_mem.Read<bool>(insidevaluegoggle_addr, insidevaluegoggle);
			client_mem.Read<unsigned char>(outlinesize_addr, outlinesize);
			client_mem.Read<bool>(goldbackpack_addr, goldbackpack);
			client_mem.Write<float>(m_traversalProgress_addr, m_traversalProgress);
			client_mem.Read<bool>(SuperKey_addr, SuperKey);
			
			client_mem.Write<float>(LocalYAW_addr, LocalYAW);
			client_mem.Write<float>(TargetYAW_addr, TargetYAW);
			
			client_mem.Write<int>(TARGET_TEAMID_addr, TARGET_TEAMID);
			client_mem.Write<int>(TEAM_TEAMID_addr, TEAM_TEAMID);
			
			client_mem.Read<bool>(TriggerBot_addr, TriggerBot);
			
			client_mem.Read<bool>(tapstrafeenable_addr, tapstrafeenable);
			
			client_mem.Read<int>(lstarvalueid_addr, lstarvalueid);
			
			client_mem.Read<bool>(PrintMapCords_addr, PrintMapCords);
			client_mem.Read<float>(veltest_addr, veltest);
			client_mem.Write<float>(CurrentWeaponADSZoom_addr, CurrentWeaponADSZoom);
			client_mem.Write<int>(map_addr, map);
			
			client_mem.Read<bool>(TogglePrediction_addr, TogglePrediction);
			
			client_mem.Read<bool>(AutoFire_addr, AutoFire);
			
			client_mem.Read<bool>(PrintModelAndId_addr, PrintModelAndId);
			client_mem.Read<int>(ScreenResINT_addr, ScreenResINT);
			client_mem.Read<bool>(BoxEnable_addr, BoxEnable);
			client_mem.Write<int>(NoNadeAim_addr, NoNadeAim);
			client_mem.Read<bool>(PrintHeldID_addr, PrintHeldID);
			//client_mem.Read<bool>(bone_auto_addr, bone_auto);



			if(esp && next2)
			{
				if(valid)
				client_mem.WriteArray<player>(player_addr, players, toRead);
				
				client_mem.Write<bool>(valid_addr, valid);
				client_mem.Write<bool>(next2_addr, true); //next2

				bool next2_val = false;
				do
				{
					client_mem.Read<bool>(next2_addr, next2_val);
					std::this_thread::sleep_for(std::chrono::milliseconds(1));
				} while (next2_val && g_Base!=0 && c_Base!=0);
				
				next2 = false;
			}
		}
	}
	vars_t = false;
}

// Item Glow Stuff
//RED
bool IsGlowActive(long centity) {
    // Assuming OFFSET_GLOW_ENABLE represents the state of the glow (1 for active, 0 for inactive)
    int glowState;
    apex_mem.Read<int>(centity + OFFSET_GLOW_ENABLE, glowState);
    
    // Check if the glow state is active
    return (glowState == 1);
}
void RedHighlight(long centity) {
    if (!IsGlowActive(centity)) {
        std::array<unsigned char, 4> highlightFunctionBits = {
            lootfilled,   // InsideFunction  HIGHLIGHT_FILL_LOOT_SCANNED
            125,   // OutlineFunction OutlineFunction HIGHLIGHT_OUTLINE_LOOT_SCANNED 
            64,
            64
        };
        std::array<float, 3> highlightParameter = { 1, 0, 0 };
        apex_mem.Write<int>(centity + OFFSET_GLOW_THROUGH_WALLS, 2);
        apex_mem.Write<int>(centity + OFFSET_GLOW_ENABLE, 1);
        static const int contextId = 1;
        long highlightSettingsPtr;
        apex_mem.Read<long>(g_Base + HIGHLIGHT_SETTINGS, highlightSettingsPtr);
        apex_mem.Write<typeof(highlightFunctionBits)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x0, highlightFunctionBits); 
        apex_mem.Write<typeof(highlightParameter)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x4, highlightParameter);
    }
}
//GREEN
void GreenHighlight(long centity)
{
	if (!IsGlowActive(centity)) {
		std::array<unsigned char, 4> highlightFunctionBits = {
			lootfilled,   // InsideFunction  HIGHLIGHT_FILL_LOOT_SCANNED
			125,   // OutlineFunction OutlineFunction HIGHLIGHT_OUTLINE_LOOT_SCANNED 
			64,
			64
		};
		std::array<float, 3> highlightParameter = { 0, 1, 0 };
		apex_mem.Write<int>(centity + OFFSET_GLOW_THROUGH_WALLS, 2);
		apex_mem.Write<int>(centity + OFFSET_GLOW_ENABLE, 2);
        static const int contextId = 2;
        long highlightSettingsPtr;
        apex_mem.Read<long>(g_Base + HIGHLIGHT_SETTINGS, highlightSettingsPtr);
        apex_mem.Write<typeof(highlightFunctionBits)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x0, highlightFunctionBits); 
        apex_mem.Write<typeof(highlightParameter)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x4, highlightParameter);
    }
}
//BLUE
void BlueHighlight(long centity)
{
	if (!IsGlowActive(centity)) {
		std::array<unsigned char, 4> highlightFunctionBits = {
			lootfilled,   // InsideFunction  HIGHLIGHT_FILL_LOOT_SCANNED
			125,   // OutlineFunction OutlineFunction HIGHLIGHT_OUTLINE_LOOT_SCANNED 
			64,
			64
		};
		std::array<float, 3> highlightParameter = { 0, 0, 1 };
		apex_mem.Write<int>(centity + OFFSET_GLOW_THROUGH_WALLS, 2);
		apex_mem.Write<int>(centity + OFFSET_GLOW_ENABLE, 3);
        static const int contextId = 3;
        long highlightSettingsPtr;
        apex_mem.Read<long>(g_Base + HIGHLIGHT_SETTINGS, highlightSettingsPtr);
        apex_mem.Write<typeof(highlightFunctionBits)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x0, highlightFunctionBits); 
        apex_mem.Write<typeof(highlightParameter)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x4, highlightParameter);
    }
}
//WHITE
void WhiteHighlight(long centity)
{
	if (!IsGlowActive(centity)) {
		std::array<unsigned char, 4> highlightFunctionBits = {
			lootfilled,   // InsideFunction  HIGHLIGHT_FILL_LOOT_SCANNED
			125,   // OutlineFunction OutlineFunction HIGHLIGHT_OUTLINE_LOOT_SCANNED 
			64,
			64
		};
		std::array<float, 3> highlightParameter = { 1, 1, 1 };
		apex_mem.Write<int>(centity + OFFSET_GLOW_THROUGH_WALLS, 2);
		apex_mem.Write<int>(centity + OFFSET_GLOW_ENABLE, 4);
        static const int contextId = 4;
        long highlightSettingsPtr;
        apex_mem.Read<long>(g_Base + HIGHLIGHT_SETTINGS, highlightSettingsPtr);
        apex_mem.Write<typeof(highlightFunctionBits)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x0, highlightFunctionBits); 
        apex_mem.Write<typeof(highlightParameter)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x4, highlightParameter);
    }
}
//PURPLE
void PurpleHighlight(long centity)
{
	if (!IsGlowActive(centity)) {
		std::array<unsigned char, 4> highlightFunctionBits = {
			lootfilled,   // InsideFunction  HIGHLIGHT_FILL_LOOT_SCANNED
			125,   // OutlineFunction OutlineFunction HIGHLIGHT_OUTLINE_LOOT_SCANNED 
			64,
			64
		};
		std::array<float, 3> highlightParameter = { 0.2941, 0, 0.5098 };
		apex_mem.Write<uint32_t>(centity + OFFSET_GLOW_THROUGH_WALLS, 2);
		apex_mem.Write<int>(centity + OFFSET_GLOW_ENABLE, 5);
        static const int contextId = 5;
        long highlightSettingsPtr;
        apex_mem.Read<long>(g_Base + HIGHLIGHT_SETTINGS, highlightSettingsPtr);
        apex_mem.Write<typeof(highlightFunctionBits)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x0, highlightFunctionBits); 
        apex_mem.Write<typeof(highlightParameter)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x4, highlightParameter);
    }
}
//GOLD
void GoldHighlight(long centity)
{
	if (!IsGlowActive(centity)) {
		std::array<unsigned char, 4> highlightFunctionBits = {
			lootfilled,   // InsideFunction  HIGHLIGHT_FILL_LOOT_SCANNED
			125,   // OutlineFunction OutlineFunction HIGHLIGHT_OUTLINE_LOOT_SCANNED 
			64,
			64
		};
		std::array<float, 3> highlightParameter = { 1, 0.8431, 0 };
		apex_mem.Write<uint32_t>(centity + OFFSET_GLOW_THROUGH_WALLS, 2);
		apex_mem.Write<int>(centity + OFFSET_GLOW_ENABLE, 6);
        static const int contextId = 6;
        long highlightSettingsPtr;
        apex_mem.Read<long>(g_Base + HIGHLIGHT_SETTINGS, highlightSettingsPtr);
        apex_mem.Write<typeof(highlightFunctionBits)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x0, highlightFunctionBits); 
        apex_mem.Write<typeof(highlightParameter)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x4, highlightParameter);
    }
}
//TEAL
void TealHighlight(long centity)
{
	if (!IsGlowActive(centity)) {
		std::array<unsigned char, 4> highlightFunctionBits = {
			lootfilled,   // InsideFunction  HIGHLIGHT_FILL_LOOT_SCANNED
			125,   // OutlineFunction OutlineFunction HIGHLIGHT_OUTLINE_LOOT_SCANNED 
			64,
			64
		};
		std::array<float, 3> highlightParameter = { 0, 1, 1 };
		apex_mem.Write<uint32_t>(centity + OFFSET_GLOW_THROUGH_WALLS, 2);
		apex_mem.Write<int>(centity + OFFSET_GLOW_ENABLE, 7);
        static const int contextId = 7;
        long highlightSettingsPtr;
        apex_mem.Read<long>(g_Base + HIGHLIGHT_SETTINGS, highlightSettingsPtr);
        apex_mem.Write<typeof(highlightFunctionBits)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x0, highlightFunctionBits); 
        apex_mem.Write<typeof(highlightParameter)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x4, highlightParameter);
    }
}
//ORANGE
void OrangeHighlight(long centity)
{
	if (!IsGlowActive(centity)) {
		std::array<unsigned char, 4> highlightFunctionBits = {
			lootfilled,   // InsideFunction  HIGHLIGHT_FILL_LOOT_SCANNED
			125,   // OutlineFunction OutlineFunction HIGHLIGHT_OUTLINE_LOOT_SCANNED 
			64,
			64
		};
		std::array<float, 3> highlightParameter = { 1, 0.5490, 0 };
		apex_mem.Write<uint32_t>(centity + OFFSET_GLOW_THROUGH_WALLS, 2);
		apex_mem.Write<int>(centity + OFFSET_GLOW_ENABLE, 8);
        static const int contextId = 8;
        long highlightSettingsPtr;
        apex_mem.Read<long>(g_Base + HIGHLIGHT_SETTINGS, highlightSettingsPtr);
        apex_mem.Write<typeof(highlightFunctionBits)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x0, highlightFunctionBits); 
        apex_mem.Write<typeof(highlightParameter)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x4, highlightParameter);
    }
}
//YELLOW
void YellowHighlight(long centity)
{
	if (!IsGlowActive(centity)) {
		std::array<unsigned char, 4> highlightFunctionBits = {
			lootfilled,   // InsideFunction  HIGHLIGHT_FILL_LOOT_SCANNED
			125,   // OutlineFunction OutlineFunction HIGHLIGHT_OUTLINE_LOOT_SCANNED 
			64,
			64
		};
		std::array<float, 3> highlightParameter = { 0.2, 1, 0 };
		apex_mem.Write<uint32_t>(centity + OFFSET_GLOW_THROUGH_WALLS, 2);
		apex_mem.Write<int>(centity + OFFSET_GLOW_ENABLE, 9);
        static const int contextId = 9;
        long highlightSettingsPtr;
        apex_mem.Read<long>(g_Base + HIGHLIGHT_SETTINGS, highlightSettingsPtr);
        apex_mem.Write<typeof(highlightFunctionBits)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x0, highlightFunctionBits); 
        apex_mem.Write<typeof(highlightParameter)>(highlightSettingsPtr + HIGHLIGHT_TYPE_SIZE * contextId + 0x4, highlightParameter);
    }
}
/*
//LOBA GLOW
void LOBAHighlight(long centity)
{
	if (!IsGlowActive(centity)) {
		std::array<unsigned char, 4> highlightFunctionBits = {
			137,   // InsideFunction  HIGHLIGHT_FILL_LOOT_SCANNED
			138,   // OutlineFunction OutlineFunction HIGHLIGHT_OUTLINE_LOOT_SCANNED 
			64,
			64
		};
		apex_mem.Write<uint32_t>(centity + OFFSET_GLOW_THROUGH_WALLS, 2);
		uint32_t contextId;
		apex_mem.Read<uint32_t>(centity + OFFSET_GLOW_ENABLE, contextId);
		uint8_t hightState;
		apex_mem.Read<uint8_t>(centity + contextId + OFFSET_HIGHLIGHTSERVERACTIVESTATES, hightState);
		uint64_t HighlightSettings;
		apex_mem.Read<uint64_t>(g_Base + HIGHLIGHT_SETTINGS, HighlightSettings);
		apex_mem.Write<typeof(highlightFunctionBits)>(HighlightSettings + 40 * hightState + 4, highlightFunctionBits);
	}
}


		apex_mem.Write<uint32_t>(centity + OFFSET_GLOW_THROUGH_WALLS, 2);
		apex_mem.Write<int>(centity + OFFSET_GLOW_ENABLE, 8);
		static const int contextId = 8;
		int settingIndex = 97;
		apex_mem.Write<unsigned char>(centity + OFFSET_HIGHLIGHTSERVERACTIVESTATES + contextId, settingIndex);
		uint64_t HighlightSettings;
		apex_mem.Read<uint64_t>(g_Base + HIGHLIGHT_SETTINGS, HighlightSettings);
		apex_mem.Write<typeof(highlightFunctionBits)>(HighlightSettings + 40 * settingIndex + 4, highlightFunctionBits);


		apex_mem.Write<uint32_t>(centity + OFFSET_GLOW_THROUGH_WALLS, 2);
		uint32_t contextId;
		apex_mem.Read<uint32_t>(centity + OFFSET_GLOW_ENABLE, contextId);
		uint8_t hightState;
		apex_mem.Read<uint8_t>(centity + contextId + OFFSET_HIGHLIGHTSERVERACTIVESTATES, hightState);
		uint64_t HighlightSettings;
		apex_mem.Read<uint64_t>(g_Base + HIGHLIGHT_SETTINGS, HighlightSettings);
		apex_mem.Write<typeof(highlightFunctionBits)>(HighlightSettings + 40 * hightState + 4, highlightFunctionBits);		

*/

static void item_glow_t()
{
	item_t = true;
	while(item_t)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		int k = 0;
		while(g_Base!=0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			uint64_t entitylist = g_Base + OFFSET_ENTITYLIST;
			if (item_glow)
			{
				//item ENTs to loop, 10k-15k is normal. 10k might be better but will not show all the death boxes i think.
				for (int i = 0; i < 15000; i++)
				{
					uint64_t viewRenderer = 0;
					apex_mem.Read<uint64_t>(g_Base + OFFSET_RENDER, viewRenderer);
					uint64_t viewMatrix = 0;
					apex_mem.Read<uint64_t>(viewRenderer + OFFSET_MATRIX, viewMatrix);
					Matrix m = {};
					apex_mem.Read<Matrix>(viewMatrix, m);
					uint64_t entitylist = g_Base + OFFSET_ENTITYLIST;
					uint64_t centity = 0;
					apex_mem.Read<uint64_t>(entitylist + ((uint64_t)i << 5), centity);
					if (centity == 0) continue;
					Item item = getItem(centity);
					
					//testing
					uint64_t LocalPlayer = 0;
					apex_mem.Read<uint64_t>(g_Base + OFFSET_LOCAL_ENT, LocalPlayer);
					
					//Item filter glow name setup and search.
					char glowName[200] = { 0 };
					uint64_t name_ptr;
					apex_mem.Read<uint64_t>(centity + OFFSET_MODELNAME, name_ptr);
					apex_mem.ReadArray<char>(name_ptr, glowName, 200);
					
					//item ids?
					uint64_t ItemID;
					apex_mem.Read<uint64_t>(centity + OFFSET_ITEM_ID, ItemID);
					//uint64_t ItemID2;
					//ItemID2 = ItemID % 301;
					//printf("%ld\n", ItemID); 
					if (PrintModelAndId)
					{
						printf("Model Name: %s, Item ID: %lu\n", glowName, ItemID);
					}
					//Level name printf
					//char LevelNAME[200] = { 0 };
					//uint64_t levelname_ptr;
					//apex_mem.Read<uint64_t>(g_Base + OFFSET_LEVELNAME, levelname_ptr);
					//apex_mem.ReadArray<char>(levelname_ptr, LevelNAME, 200);
					//printf("%s\n", LevelNAME);
				
					
					//Prints stuff you want to console
					//if (strstr(glowName, "mdl/")) 
					//{
					//printf("%ld\n", ItemID);
					//}
					//Search model name and if true sets glow, must be a better way to do this.. if only i got the item id to work..
					
					if (centity == 0)
					{
						continue;
					}
					//BOX
					if (BoxEnable)
					{
						if (item.isBox())
						{
							RedHighlight(centity);
						}
					}
					//RED GLOW  is 1 0 0  89
					if (strstr(glowName, "mdl/props/wattson_trophy_system/wattson_trophy_system.rmdl") ||
					strstr(glowName, "mdl/props/crypto_drone/crypto_drone.rmdl") ||
					strstr(glowName, "mdl/props/caustic_gas_tank/caustic_gas_tank.rmdl") ||
					strstr(glowName, "mdl/props/wattson_electric_fence/wattson_electric_fence.rmdl") ||
					strstr(glowName, "mdl/props/rampart_cover_wall/rampart_cover_wall.rmdl") ||
					strstr(glowName, "mdl/props/rampart_turret/rampart_turret.rmdl") ||
					(shieldupgrade5 && ItemID == 536870912201) || 
					(skull && strstr(glowName, "mdl/Weapons/skull_grenade/skull_grenade_base_v.rmdl")) ||
					(shotgunammo && ItemID == 142) ||
					(grenade_frag && ItemID == 213) ||
					(grenade_thermite && ItemID == 212) ||
					(weapon_kraber && ItemID == 1) ||
					(weapon_mastiff && ItemID == 2) ||
					(weapon_eva8 && ItemID == 85) |
					(weapon_peacekeeper && ItemID == 90) ||
					(weapon_mozambique && ItemID == 95) ||
					(weapon_bow && ItemID == 127) ||
					(item.isBox())) 
					{
						RedHighlight(centity);
					}
					//GREEN GLOW  is 0 1 0   91  
					if (strstr(glowName, "mdl/props/nessie/nessie") ||
					strstr(glowName, "mdl/props/octane_jump_pad/octane_jump_pad.rmdl")) 
					{
						 GreenHighlight(centity);
					}
					//BLUE GLOW  is 0 0 1  90
					if (strstr(glowName, "mdl/props/loba_loot_stick/loba_loot_stick.rmdl") ||
					(medbackpack && ItemID == 208) ||
					(shieldupgrade2 && (ItemID == 322122547394 || ItemID == 21110945375846599)) ||
					(shieldupgradehead2 && ItemID == 189) || 
					(accelerant && ItemID == 182) || 
					(shieldbattsmall && ItemID == 187) || 
					(shieldbattlarge && ItemID == 186) || 
					(sniperammo && ItemID == 144) ||
					(lasersight2 && ItemID == 230) ||
					(sniperammomag2 && ItemID == 245) ||
					(energyammomag2 && ItemID == 241) ||
					(stocksniper2 && ItemID == 256) ||
					(stockregular2 && ItemID == 253) ||
					(shielddown2 && ItemID == 204) ||
					(lightammomag2 && ItemID == 233) ||
					(heavyammomag2 && ItemID == 237) ||
					(optic2xhcog && ItemID == 216) ||
					(opticholo1x2x && ItemID == 218) ||
					(opticsniper6x && ItemID == 222) ||
					(suppressor2 && ItemID == 226) ||
					(shotgunbolt2 && ItemID == 249) ||
					(grenade_arc_star && ItemID == 214) ||
					(weapon_longbow && ItemID == 65) ||
					(weapon_charge_rifle && ItemID == 70) ||
					(weapon_wingman && ItemID == 106) ||
					(weapon_sentinel && ItemID == 122))
					{
						BlueHighlight(centity);
					}
					//WHITE GLOW  is 1 1 1  72
					if (lightbackpack && ItemID == 207 ||
					shieldupgrade1 && (ItemID == 214748364993 || ItemID == 14073963583897798) ||
					(shieldupgradehead1 && ItemID == 188) || 
					(healthlarge && ItemID == 184) || 
					(healthsmall && ItemID == 185) ||
					(optic1xhcog && ItemID == 215) ||
					(lasersight1 && ItemID == 229) ||
					(sniperammomag1 && ItemID == 244) ||
					(energyammomag1 && ItemID == 240) ||
					(stocksniper1 && ItemID == 255) ||
					(stockregular1 && ItemID == 252) ||
					(shielddown1 && ItemID == 203) ||
					(lightammomag1 && ItemID == 232) ||
					(heavyammomag1 && ItemID == 236) ||
					(opticholo1x && ItemID == 217) ||
					(suppressor1 && ItemID == 225) ||
					(shotgunbolt1 && ItemID == 248)) 
					{
						WhiteHighlight(centity);
					}
					//PURPLE GLOW   is 0.2941, 0, 0.5098   74
					if (heavybackpack && ItemID == 209 ||
					(shieldupgrade3 && (ItemID == 429496729795 || ItemID == 52776987629977800)) || 
					(shieldupgradehead3 && ItemID == 190) || 
					(phoenix && ItemID == 183) ||
					(lasersight3 && ItemID == 231) ||
					(energyammomag3 && ItemID == 242) ||
					(stocksniper3 && ItemID == 257) ||
					(stockregular3 && ItemID == 254) ||
					(shielddown3 && ItemID == 205) ||
					(lightammomag3 && ItemID == 234) ||
					(heavyammomag3 && ItemID == 238) ||
					(optic3xhcog && ItemID == 220) ||
					(optic2x4x && ItemID == 221) ||
					(opticsniper4x8x && ItemID == 223) ||
					(suppressor3 && ItemID == 227) ||
					(shotgunbolt3 && ItemID == 250)) 
					{
						PurpleHighlight(centity);
					}
					//GOLD GLOW  is 1, 0.8431, 0  75
					if (goldbackpack && ItemID == 210 || 
					(shieldupgradehead4 && ItemID == 191) ||
					(sniperammomag3 && ItemID == 246) ||
					(sniperammomag4 && ItemID == 247) ||
					(energyammomag4 && ItemID == 243) ||
					(shielddown4 && ItemID == 206) ||
					(shieldupgrade4 && (ItemID == 429496729796)) ||
					(lightammomag4 && ItemID == 235) ||
					(heavyammomag4 && ItemID == 239) ||
					(opticthreat && ItemID == 219) ||
					(opticsniperthreat && ItemID == 224) ||
					(turbo_charger && ItemID == 258) ||
					(skull_piecer && ItemID == 260) ||
					(hammer_point && ItemID == 263) ||
					(disruptor_rounds && ItemID == 262) ||
					(boosted_loader && ItemID == 272) ||
					(shotgunbolt4 && ItemID == 251)) 
					{
						GoldHighlight(centity);
					}
					//TEAL GLOW  is 0 1 1   65
					if (heavyammo && ItemID == 143 ||
					(weapon_flatline  && ItemID == 28) ||
					(weapon_hemlock && ItemID == 33) ||
					(weapon_prowler && ItemID == 56) ||
					(weapon_3030_repeater && ItemID == 129) ||
					(weapon_rampage && ItemID == 146) ||
					(weapon_car_smg && ItemID == 151))
					{
						TealHighlight(centity);
					}
					//ORANGE GLOW   is  1, 0.5490, 0   66
					if (lightammo && ItemID == 140 ||
					(weapon_g7_scout && ItemID == 39) ||
					(weapon_alternator && ItemID == 44) ||
					(weapon_r99 && ItemID == 49) ||
					(weapon_spitfire && ItemID == 75) ||
					(weapon_r301 && ItemID == 80) ||
					(weapon_p2020 && ItemID == 111) ||
					(weapon_re45 && ItemID == 116)) 
					{
						OrangeHighlight(centity);
					}
					//YELLOW GLOW  is 0.2, 1, 0   73
					
					if (energyammo && ItemID == 141 || 
					(weapon_lstar && ItemID == 7) ||
					(weapon_nemesis && ItemID == 135) ||
					(weapon_havoc && ItemID == 13) ||
					(weapon_devotion && ItemID == 18) ||
					(weapon_triple_take && ItemID == 23) ||
					(weapon_volt && ItemID == 60)) 
					{
						YellowHighlight(centity);
					}
					
					// CREDITS to Rikkie https://www.unknowncheats.me/forum/members/169606.html
					// for all the weapon ids and item ids code, you are a life saver!
					//ulong ehWeaponHandle;
					//apex_mem.Read<uint64_t>(LocalPlayer + OFFSET_WEAPON, ehWeaponHandle); // 0x1a1c
					//ehWeaponHandle &= 0xFFFF; // eHandle
					//ulong pWeapon;
					//apex_mem.Read<uint64_t>(entitylist + (ehWeaponHandle * 0x20), pWeapon);
					
					
					
					
					
					//uint32_t weaponID;
					//apex_mem.Read<uint32_t>(pWeapon + OFFSET_WEAPON_NAME, weaponID); //0x1844
					//printf("%d\n", weaponID);
					//printf("%f\n", bulletspeed);
					//printf("%f\n", bulletgrav);
					
					//uint64_t wephandle = 0;
					//apex_mem.Read<uint64_t>(LocalPlayer + OFFSET_WEAPON, wephandle);
					
					//wephandle &= 0xffff;

					//uint64_t wep_entity = 0;
					//apex_mem.Read<uint64_t>(entitylist + (wephandle << 5), wep_entity);
					//float projectile_speed;
					//apex_mem.Read<float>(wep_entity + OFFSET_BULLET_SPEED, projectile_speed);
					//float projectile_scale;
					//apex_mem.Read<float>(wep_entity + OFFSET_BULLET_SCALE, projectile_scale);
					//int ammo;
					//apex_mem.Read<int>(wep_entity + OFFSET_AMMO, ammo);
					//float zoom_fov;
					//apex_mem.Read<float>(wep_entity + OFFSET_ZOOM_FOV, zoom_fov);
					//printf("Weapon ID: %ld - Bullet Speed: %f - Bullet Gravity: %f - Zoom FOV: %f - Ammo: %d - Speed: %f - Scale: %f\n", wep_entity, bulletspeed, bulletgrav, zoom_fov, ammo, projectile_speed, projectile_scale);				
				}
				k=1;
				//Change the 60 ms to lower to make the death boxes filker less.
				std::this_thread::sleep_for(std::chrono::milliseconds(600));
				
			}
			
					}
					k=0;
				}

	item_t = false;
}



int main(int argc, char *argv[])
{
	if(geteuid() != 0)
	{
		//run as root..
		printf("Error: %s is not running as root\n", argv[0]);
		return 0;
	}

	const char* cl_proc = "EliteNinja2.exe";
	const char* ap_proc = "r5apex.exe";
	//const char* ap_proc = "EasyAntiCheat_launcher.exe";

	//Client "add" offset
	uint64_t add_off = 0x5de60; //todo make this auto update..

	std::thread aimbot_thr;
	std::thread esp_thr;
	std::thread actions_thr;
	std::thread cactions_thr;
	std::thread TriggerBotRun_thr; //triggerbot
	std::thread itemglow_thr;
	std::thread vars_thr;
	while(active)
	{
		if(apex_mem.get_proc_status() != process_status::FOUND_READY)
		{
			if(aim_t)
			{
				aim_t = false;
				esp_t = false;
				actions_t = false;
				cactions_t = false;
				TriggerBotRun_t	= false; //triggerbot
				item_t = false;
				g_Base = 0;
				cactions_thr.~thread();
				TriggerBotRun_thr.~thread(); //triggerbot
				aimbot_thr.~thread();
				esp_thr.~thread();
				actions_thr.~thread();
				itemglow_thr.~thread();
			}

			std::this_thread::sleep_for(std::chrono::seconds(1));
			printf("Searching for Apex process...\n");

			apex_mem.open_proc(ap_proc);

			if(apex_mem.get_proc_status() == process_status::FOUND_READY)
			{
				g_Base = apex_mem.get_proc_baseaddr();
				printf("\nApex process found\n");
				printf("Base: %lx\n", g_Base);

				aimbot_thr = std::thread(AimbotLoop);
				esp_thr = std::thread(EspLoop);
				actions_thr = std::thread(DoActions);
				cactions_thr = std::thread(ClientActions);
				TriggerBotRun_thr = std::thread(TriggerBotRun); //triggerbot
				itemglow_thr = std::thread(item_glow_t);
				aimbot_thr.detach();
				esp_thr.detach();
				cactions_thr.detach();
				TriggerBotRun_thr.detach(); //triggerbot
				actions_thr.detach();
				itemglow_thr.detach();
			}
		}
		else
		{
			apex_mem.check_proc();
		}

		if(client_mem.get_proc_status() != process_status::FOUND_READY)
		{
			if(vars_t)
			{
				vars_t = false;
				c_Base = 0;

				vars_thr.~thread();
			}
			
			std::this_thread::sleep_for(std::chrono::seconds(1));
			printf("Searching for EliteNinja2 process...\n");

			client_mem.open_proc(cl_proc);

			if(client_mem.get_proc_status() == process_status::FOUND_READY)
			{
				c_Base = client_mem.get_proc_baseaddr();
				printf("EliteNinja2 process found\n");
				printf("Base: %lx\n", c_Base);

				vars_thr = std::thread(set_vars, c_Base + add_off);
				vars_thr.detach();
			}
		}
		else
		{
			client_mem.check_proc();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return 0;
}
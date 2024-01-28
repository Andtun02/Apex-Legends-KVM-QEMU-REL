//Date 01/25/2024
//GameVersion=v3.0.55.37
//KrackerCo's Fork



#define OFFSET_ENTITYLIST 0x1db2e38 //cl_entitylist  updated 01/10/2024
#define OFFSET_LOCAL_ENT 0x2161538 //LocalPlayer might be moved to AVC_GameMovement updated 01/10/2024
#define OFFSET_NAME_LIST 0xc5e9fd0 //NameList updated 01/10/2024
#define OFFSET_GLOBAL_VARS 0x16d65c0 // GlobalVars updated 01/10/2024
 
#define OFFSET_LEVELNAME 0x16d6ac0 //LevelName //updated 01/10/2024
#define OFFSET_CLIENTSTATE OFFSET_LEVELNAME - 0x1c0 //ClientState  ClientState = LevelName - 0x1C0  //updated 01/10/2024
#define OFFSET_SIGNONSTATE OFFSET_CLIENTSTATE + 0xAC //SignonState   ( ClientState + 0xAC)  //updated 01/10/2024
#define OFFSET_HOST_MAP 0x015eee90 + 0x58 //host_map + 0x58 //updated 01/10/2024
 
#define OFFSET_TEAM 0x30C //m_iTeamNum //uupdated 01/10/2024
#define OFFSET_HEALTH 0x02fc //m_iHealth //uupdated 01/10/2024
#define OFFSET_SHIELD 0x01a0 //m_shieldHealth //uupdated 01/10/2024
#define OFFSET_MAXSHIELD 0x01a4 //m_shieldHealthMax //uupdated 01/10/2024
#define OFFSET_ARMORTYPE 0x45CC //m_armorType //uupdated 01/10/2024
#define OFFSET_NAME 0x0449 //m_iName //uupdated 01/10/2024
#define OFFSET_SIGN_NAME 0x440 //m_iSignifierName //uupdated 01/10/2024
#define OFFSET_ABS_VELOCITY 0x0170 //m_vecAbsVelocity //uupdated 01/10/2024
#define OFFSET_VISIBLE_TIME 0x1950 //CPlayer!lastVisibleTime  //uupdated 01/10/2024  // 0x3?
#define OFFSET_ZOOMING 0x1b91 //m_bZooming //uupdated 01/10/2024
#define OFFSET_FORCE_DUCK 0x073cd8a0 //in_duck //uupdated 01/10/2024
#define OFFSET_TRAVERSAL_PROGRESS 0x2abc //m_traversalProgress //uupdated 01/10/2024
#define OFFSET_FORCE_JUMP 0x073cd7a0 //in_jump //uupdated 01/10/2024
 
#define OFFSET_WEAPON_NAME 0x1524 //m_weaponNameIndex 2nd one //uupdated 01/10/2024
#define OFFSET_OFF_WEAPON 0x1904 //m_latestNonOffhandWeapons //uupdated 01/10/2024
#define OFFSET_IN_ATTACK 0x073cd6a0 // in_attack //uupdated 01/10/2024
#define OFFSET_IN_TOGGLE_DUCK 0x073cd6e0 //in_toggle_duck //uupdated 01/10/2024
#define OFFSET_IN_ZOOM 0x073cd840 //in_zoom updated 01/10/2024
#define OFFSET_WALL_RUN_START_TIME 0x3524 //m_wallRunStartTime updated 01/10/2024
#define OFFSET_WALL_RUN_CLEAR_TIME 0x3528 //m_wallRunClearTime updated 01/10/2024
#define OFFSET_FLAGS 0x00c8 //m_fFlags //uupdated 01/10/2024 updated 01/10/2024
#define OFFSET_IN_FORWARD 0x073cd5f0 //in_forward //updated 01/10/2024
 
#define OFFSET_LIFE_STATE 0x658 //m_lifeState, >0 = dead //updated 01/10/2024
#define OFFSET_BLEED_OUT_STATE 0x26A0 //m_bleedoutState, >0 = knocked //updated 01/10/2024
 
#define OFFSET_ORIGIN 0x17C //m_vecAbsOrigin - 3rd offset after the first int and vector //updated 01/10/2024
#define OFFSET_BONES 0x0d60 + 0x48 //m_nForceBone + 0x48 //updated 01/10/2024
#define OFFSET_STUDIOHDR 0xfb0 //CBaseAnimating!m_pStudioHdr //updated 01/10/2024
#define OFFSET_AIMPUNCH 0x23f8 //m_currentFrameLocalPlayer.m_vecPunchWeapon_Angle, first one//updated 01/10/2024
#define OFFSET_CAMERAPOS 0x1e90 //CPlayer!camera_origin //updated 01/10/2024
#define OFFSET_VIEWANGLES 0x24f4 - 0x14 //m_ammoPoolCapacity - 0x14//updated 01/10/2024
#define OFFSET_BREATH_ANGLES OFFSET_VIEWANGLES - 0x10 //updated 01/10/2024
#define OFFSET_OBSERVER_MODE 0x3454 //m_iObserverMode//updated 01/10/2024
#define OFFSET_OBSERVING_TARGET 0x3460 //m_hObserverTarget//updated 01/10/2024
#define OFFSET_IN_USE 0x073cd820 //in_use updated 01/10/2024
 
 
#define OFFSET_MATRIX 0x11a350 //ViewMatrix//updated 01/10/2024
#define OFFSET_RENDER 0x73cc3e0 //ViewRender displays ESp, heath dist names etc //updated 01/10/2024
 
#define OFFSET_WEAPON 0x18F4 //m_latestPrimaryWeapons //updated 01/10/2024
#define OFFSET_BULLET_SPEED 0x1e5c //CWeaponX!m_flProjectileSpeed maybe its WeaponSettings.projectile_launch_speed now //updated 01/10/2024
#define OFFSET_BULLET_SCALE 0x1e64 //CWeaponX!m_flProjectileScale maybe its WeaponSettings.projectile_gravity_scale now //updated 01/10/2024
#define OFFSET_ZOOM_FOV 0x1590 + 0x00b8 //m_playerData + m_curZoomFOV //updated 01/10/2024
#define OFFSET_AMMO 0x1514 //m_ammoInClip first offset //updated 01/10/2024
 
//#define OFFSET_ITEM_GLOW 0x02f0 //m_highlightFunctionBits
#define OFFSET_ITEM_ID 0x1518 // item id? m_customScriptInt ? //updated 01/10/2024
#define OFFSET_MODELNAME 0x0030 // m_ModelName //updated 01/10/2024
#define OFFSET_M_CUSTOMSCRIPTINT OFFSET_ITEM_ID //m_customScriptInt //updated 01/10/2024
#define OFFSET_YAW 0x21fc - 0x8 //m_currentFramePlayer.m_ammoPoolCount - 0x8 //updated 01/10/2024
 
//#define OFFSET_GLOW_T1 0x262+ 0x30 //16256 = enabled, 0 = disabled
//#define OFFSET_GLOW_T2 0x2dc+ 0x30 //1193322764 = enabled, 0 = disabled
#define OFFSET_GLOW_ENABLE 0x28C //7 = enabled, 2 = disabled  Script_Highlight_SetCurrentContext //updated 01/10/2024
#define OFFSET_GLOW_THROUGH_WALLS 0x26C //2 = enabled, 5 = disabled  Script_Highlight_SetVisibilityType // Glow_VisibleType //updated 01/10/2024
 

#define GLOW_START_TIME 0x02c8 + 0x30 //m_playerFloatLookStartTime=0x02c4 //updated 01/10/2024
#define OFFSET_HIGHLIGHTSERVERACTIVESTATES 0x28C //updated 11/1/2023
 
#define OFFSET_GLOW_ENABLE_GLOW_CONTEXT OFFSET_GLOW_ENABLE // Script_Highlight_SetCurrentContext updated 01/10/2024
#define OFFSET_GLOW_THROUGH_WALLS_GLOW_VISIBLE_TYPE OFFSET_GLOW_THROUGH_WALLS // Script_Highlight_SetVisibilityType 5th mov updated 01/10/2024
#define GLOW_LIFE_TIME 0x3A4+ 0x30 // Script_Highlight_SetLifeTime + 4 updated 01/10/2024
#define GLOW_DISTANCE 0x26c // Script_Highlight_SetFarFadeDist updated 01/10/2024
#define GLOW_TYPE 0x29c // Script_Highlight_GetState + 4 updated 01/10/2024
#define GLOW_COLOR 0x1D0+ 0x30 // Script_CopyHighlightState 15th mov updated 01/10/2024
#define GLOW_FADE 0x388+ 0x30 // ats 3rd result of 3 offsets consecutive or first + 8 updated 01/10/2024
#define HIGHLIGHT_SETTINGS 0xB93DFD0 //?  //updated 01/9/2024
#define HIGHLIGHT_TYPE_SIZE 0x34 //? updated 01/10/2024
#define OFFSET_CROSSHAIR_LAST OFFSET_VISIBLE_TIME + 0x8 //CPlayer!lastCrosshairTargetTime // CPlayer!lastVisibleTime + 0x8 updated 01/10/2024
#define OFFSET_CROSSHAIR_START 0x19C8 //CPlayer!crosshairTargetStartTime updated 01/9/2024
#define OFFSET_INPUT_SYSTEM 0x1755c80 //InputSystem   updated 01/10/2024
#pragma warning (disable : 4715)
#pragma warning (disable : 4005)
#pragma warning (disable : 4305)
#pragma warning (disable : 4244)
#include "overlay.h"
#include <fstream>
#include <iomanip>
#include "player.h"
#include <iostream>
#include "world.h"

extern player players[100];
extern world KingsCanyon;
extern world WorldsEdge;
extern world Olympus;
extern world BrokenMoon;
extern world StormPoint;
extern std::vector<std::string> targetList; // A vector to store the names of targeted players
extern bool isInTargetList;
extern bool SpecLiveView;
extern int mapid;
extern bool PrintHeldID;
extern int ScreenResINT;
extern bool TogglePrediction;
bool SpectatorWatchingLivetoggle = true;
extern float veltest;
extern bool MapRadarName;
bool Keyboard;
bool Gamepad;
extern bool MapRadarTeamID;
//death box
extern bool BoxEnable;
float RadarDistMod = 0.0f;
extern float directionlinesize;
extern float MINIMAPZOOM;
extern int lstarvalueid;
extern float CurrentWeaponADSZoom;
extern bool MainMapRadarToggle;
extern bool bone_auto;
float spectolerance = 0.01f;
extern bool isInTargetListRED;
extern bool RenderInfoBar;
extern bool PrintMapCords;
extern bool MiniMapFaceing;
extern bool SpectatorToggle;
extern int EntTeam;
extern int LocTeam;
extern float LocalYAW;
extern float TargetYAW;
extern int SpectartorPOSX;
extern int SpectartorPOSY;
extern bool spectatornameshow;
extern int NameHeightAjust;
extern bool SeerBars;
extern bool NormalBars;
int background_height = 0;
int health_bar_height1 = 0;
int health_bar_height2 = 0;
int health_bar_height3 = 0;
int health_bar_height4 = 0;
int health_bar_height3m = 0;
int health_bar_height4m = 0;
int BackgroundYPOS = 0;
int BackgroundXPOS = 0;
int HeathXPOS = 0;
int HeathYPOS = 0;
extern int ShieldHeightDisplay;;
extern int ShieldWidthDisplay;
int shield_25Value;
int bg_offsetValue;
int bar_widthValue;
extern float NonADS;
extern float ADS;
using namespace std;
extern bool firing_range;
extern int aim;
extern bool esp;
extern bool item_glow;
extern bool player_glow;
extern bool aim_no_recoil;
extern bool ready;
extern bool use_nvidia;
extern float max_dist;
extern float smooth;
extern bool MiniMapGuides;
extern float bulletspeed;
extern float bulletgrav;
//superglide
extern bool SuperKey;
extern int frameSleepTimerValue; //not used
extern int superGlideTimerValue; //not used
extern float m_traversalProgress_min;
extern float m_traversalProgress_max;
extern float m_traversalProgress;
//Dynamic Fov
extern float dynamicfov;
extern float dynamicfovmax;
extern float max_fov;
extern int bone;
extern int spectators;
extern int allied_spectators;
//Left and Right Aim key toggle
extern bool toggleaim;
extern bool toggleaim2;
extern bool PrintModelAndId;
int e = 0;
int InputSelect = 1;
extern float MapTeamIDScale;
extern float MapTeamIDBackground;
int control = 0;
//glow color and type
extern float glowr; //Red Value
extern float glowg; //Green Value
extern float glowb; //Blue Value
extern float glowcolor[3];
//MiniMap Radar
int minimapradardotsize1 = 5;
int minimapradardotsize2 = 5;
extern bool minimapradar;
float ModdedZoom;
//more glow stuff
extern bool insidevaluegoggle;
extern int outlinesize;
//glow visable
extern float glowrviz;
extern float glowgviz;
extern float glowbviz;
extern float glowcolorviz[3];
//knocked
extern float glowrknocked;
extern float glowgknocked;
extern float glowbknocked;
extern float glowcolorknocked[3];
//TDM Toggle
extern bool TDMToggle;
//Ha think i was done ?
//Item Filter Brute Force!
extern bool lightbackpack;
extern bool medbackpack;
extern bool heavybackpack;
extern bool goldbackpack;
extern bool shieldupgrade1;
extern bool shieldupgradehead1;
extern bool shieldupgrade2;
extern bool shieldupgradehead2;
extern bool shieldupgrade3;
extern bool shieldupgradehead3;
extern bool shieldupgrade4;
extern bool shieldupgrade5;
extern bool shieldupgradehead4;
extern bool accelerant;
extern bool phoenix;
extern bool healthlarge;
extern bool healthsmall;
extern bool shieldbattsmall;
extern bool shieldbattlarge;
extern bool sniperammo;
extern bool heavyammo;
extern bool optic1xhcog;
extern bool lightammo;
extern bool energyammo;
extern bool shotgunammo;
extern bool lasersight1;
extern bool lasersight2;
extern bool lasersight3;
extern bool lasersight4;
extern bool sniperammomag1;
extern bool energyammomag1;
extern bool sniperammomag2;
extern bool energyammomag2;
extern bool sniperammomag3;
extern bool energyammomag3;
extern bool sniperammomag4;
extern bool energyammomag4;
extern bool stocksniper1;
extern bool stockregular1;
extern bool stocksniper2;
extern bool stockregular2;
extern bool stocksniper3;
extern bool stockregular3;
extern bool shielddown1;
extern bool shielddown2;
extern bool shielddown3;
extern bool shielddown4;
extern bool lightammomag1;
extern bool heavyammomag1;
extern bool lightammomag2;
extern bool heavyammomag2;
extern bool lightammomag3;
extern bool heavyammomag3;
extern bool lightammomag4;
extern bool heavyammomag4;
extern bool optic2xhcog;
extern bool opticholo1x;
extern bool opticsniper6x;
extern bool opticsniper4x8x;
extern bool opticsniperthreat;
extern bool optic2x4x;
extern bool opticthreat;
extern bool optic3xhcog;
extern bool opticholo1x2x;
extern bool suppressor1;
extern bool suppressor2;
extern bool suppressor3;
extern bool turbo_charger;
extern bool skull_piecer;
extern bool hammer_point;
extern bool disruptor_rounds;
extern bool boosted_loader;
extern bool grenade_frag;
extern bool grenade_arc_star;
extern bool grenade_thermite;
extern bool shotgunbolt1;
extern bool shotgunbolt2;
extern bool shotgunbolt3;
extern bool shotgunbolt4;
extern bool weapon_kraber;
extern bool weapon_mastiff;
extern bool weapon_lstar;
extern bool weapon_havoc;
extern bool weapon_devotion;
extern bool weapon_triple_take;
extern bool weapon_flatline;
extern bool weapon_hemlock;
extern bool weapon_g7_scout;
extern bool weapon_alternator;
extern bool weapon_r99;
extern bool weapon_prowler;
extern bool weapon_volt;
extern bool weapon_longbow;
extern bool weapon_charge_rifle;
extern bool weapon_spitfire;
extern bool weapon_r301;
extern bool weapon_eva8;
extern bool weapon_peacekeeper;
extern bool weapon_mozambique;
extern bool weapon_wingman;
extern bool weapon_p2020;
extern bool weapon_re45;
extern bool weapon_sentinel;
extern bool weapon_bow;
extern bool weapon_3030_repeater;
extern bool weapon_rampage;
extern bool weapon_car_smg;
extern bool weapon_nemesis;


//Aim Dist check
extern float aimdist;
//item glow brightness
extern int itemglowbrightness;
//Menu Stuff
int menu1 = 0;
int menu2 = 0;
int menu3 = 0;
int menu4 = 0;
int menu5 = 0;
int menu6 = 0;
//triggerbot
extern bool triggerbot;
//1v1
extern bool onevone;
//screen pos ajuster
//ajuster for screen pos
extern int worldsedgetoprightx = 0;
extern int worldsedgetoprighty = 0;
extern int worldsedgebtmleftx = 0;
extern int worldsedgebtmlefty = 0;



int width;
int height;
bool k_leftclick = false;
bool k_ins = false;
bool spectatornameshow_ins = false;
bool show_menu = false;
visuals v;

extern bool IsKeyDown(int vk);

LONG nv_default = WS_POPUP | WS_CLIPSIBLINGS;
LONG nv_default_in_game = nv_default | WS_DISABLED;
LONG nv_edit = nv_default_in_game | WS_VISIBLE;

LONG nv_ex_default = WS_EX_TOOLWINDOW;
LONG nv_ex_edit = nv_ex_default | WS_EX_LAYERED | WS_EX_TRANSPARENT;
LONG nv_ex_edit_menu = nv_ex_default | WS_EX_TRANSPARENT;

static DWORD WINAPI StaticMessageStart(void* Param)
{
	Overlay* ov = (Overlay*)Param;
	ov->CreateOverlay();
	return 0;
}

BOOL CALLBACK EnumWindowsCallback(HWND hwnd, LPARAM lParam)
{
	wchar_t className[255] = L"";
	GetClassName(hwnd, className, 255);
	if (use_nvidia)
	{
		if (wcscmp(XorStrW(L"CEF-OSC-WIDGET"), className) == 0) //Nvidia overlay
		{
			HWND* w = (HWND*)lParam;
			if (GetWindowLong(hwnd, GWL_STYLE) != nv_default && GetWindowLong(hwnd, GWL_STYLE) != nv_default_in_game)
				return TRUE;
			*w = hwnd;
			return TRUE;
		}
	}
	else
	{
		if (wcscmp(XorStrW(L"overlay"), className) == 0) //Custom overlay
		{
			HWND* w = (HWND*)lParam;
			*w = hwnd;
			return TRUE;
		}
	}
	return TRUE;
}

// Data
static ID3D11Device* g_pd3dDevice = NULL;
static ID3D11DeviceContext* g_pd3dDeviceContext = NULL;
static IDXGISwapChain* g_pSwapChain = NULL;
static ID3D11RenderTargetView* g_mainRenderTargetView = NULL;

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();

void Overlay::RenderMenu()
{
	static bool aim_enable = false;
	static bool vis_check = false;
	static bool spec_disable = false;
	static bool all_spec_disable = false;

	if (aim > 0)
	{
		aim_enable = true;
		if (aim > 1)
		{
			vis_check = true;
		}
		else
		{
			vis_check = false;
		}
	}
	else
	{
		aim_enable = false;
		vis_check = false;
	}

	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2(520, 1070), ImGuiCond_Once);
	ImGui::Begin(XorStr("##title"), (bool*)true, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);
	//if (ImGui::BeginTabBar(XorStr("Tab")))
	//{
		//if (ImGui::BeginTabItem(XorStr("##")))
		//{
				if (ImGui::CollapsingHeader("Main Toggle Settings"))
				{
					menu1 = 1;
					ImGui::Sliderbox(XorStr("ESP On/Off"), &esp);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("AIM On/Off"), &aim_enable);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Glow Items"), &item_glow);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("1v1"), &onevone);
					ImGui::Sliderbox(XorStr("Glow Players"), &player_glow);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Mini-Map Radar"), &minimapradar);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Mini-Map Guide"), &MiniMapGuides);
					if (aim_enable)
					{
						
						ImGui::Sliderbox(XorStr("No Recoil"), &aim_no_recoil);
						if (vis_check)
						{
							aim = 2;
						}
						else
						{
							aim = 1;
						}
					}
					else
					{
						aim = 0;
					}
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Firing Range"), &firing_range);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("TDM Toggle"), &TDMToggle);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Screen Size:"));;
					ImGui::RadioButton("1920x1080", &ScreenResINT, 0);
					ImGui::SameLine();
					ImGui::RadioButton("2560x1440", &ScreenResINT, 1);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Aiming Distance:"));
					ImGui::SameLine();
					ImGui::TextColored(GREEN, "%.f meters", aimdist / 39.62);
					ImGui::SliderFloat(XorStr("##Aim Distance"), &aimdist, 10.0f * 39.62, 1600.0f * 39.62, "##");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Keyboard Or Controller:"));
					ImGui::RadioButton("Keyboard", &InputSelect, 1); ImGui::SameLine();
					ImGui::RadioButton("Controller ", &InputSelect, 2); ImGui::SameLine();
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Keyboard Aim Keys:"));
					ImGui::RadioButton("Left Mouse", &e, 1); ImGui::SameLine();
					ImGui::RadioButton("Right Mouse ", &e, 2); ImGui::SameLine();
					ImGui::RadioButton("Left/Right Mouse", &e, 3);
					//Setting one and unsetting the other
					if (e == 1)
					{
						toggleaim = true;
						toggleaim2 = false;
					}
					else if (e == 2)
					{
						toggleaim = false;
						toggleaim2 = true;
					}
					else if (e == 3)
					{
						toggleaim = true;
						toggleaim2 = true;
					}
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("ADS Fov: "));
					ImGui::SameLine();
					ImGui::TextColored(GREEN, "%0.f", ADS);
					ImGui::SliderFloat(XorStr("##ADSFOV"), &ADS, 0.0f, 100.0f, "%0.f");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Non-ADS Fov: "));
					ImGui::SameLine();
					ImGui::TextColored(GREEN, "%0.f", NonADS);
					ImGui::SliderFloat(XorStr("##NONADSFOV"), &NonADS, 0.0f, 100.0f, "%0.f");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Max distance for everything:"));
					ImGui::SameLine();
					ImGui::TextColored(GREEN,"%d meters", (int)(max_dist / 40));
					ImGui::SliderFloat(XorStr("##1"), &max_dist, 100.0f * 40, 3800.0f * 40, "##");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));

					ImGui::Text(XorStr("Smooth Aim Value:"));
					ImGui::SameLine();
					ImGui::TextColored(GREEN, "%.f", smooth);
					ImGui::SliderFloat(XorStr("##2"), &smooth, 90.0f, 1500.0f, "##");
					ImGui::SameLine();
					ImGui::Text(XorStr("90+ Is Safe"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Aiming Bone:"));
					ImGui::Text(XorStr("0 = Head, 1 = Neck, 2 = Chest, 3 = Stomach"));
					ImGui::SliderInt(XorStr("##bone slider"), &bone, 0, 5);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("ESP Options:"));
					ImGui::Sliderbox(XorStr("Glow Fill Toggle"), &insidevaluegoggle);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Box ESP"), &v.box);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Outline Size"));
					ImGui::SliderInt("##Slider", reinterpret_cast<int*>(&outlinesize), 32, 255);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Distance"), &v.distance);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Health"), &v.healthbar);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Shields"), &v.shieldbar);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Names"), &v.name);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Model Names"), &v.modelname);
					ImGui::Sliderbox(XorStr("MapRadarName"), &MapRadarName);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("MapRadarTeamID"), &MapRadarTeamID);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text("Player Glow ");
					ImGui::TextColored(ImVec4(glowrviz, glowgviz, glowbviz, 1.0f), "Visable:");
					ImGui::ColorEdit3("##Glow Color Picker Visible", glowcolorviz, ImGuiColorEditFlags_Float);
					{
						glowrviz = glowcolorviz[0];
						glowgviz = glowcolorviz[1];
						glowbviz = glowcolorviz[2];
					}
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text("Player Glow Not ");
					ImGui::TextColored(ImVec4(glowr, glowg, glowb, 1.0f), "Visable:");
					ImGui::ColorEdit3("##Glow Color Not Visable", glowcolor, ImGuiColorEditFlags_Float);
					{
						glowr = glowcolor[0];
						glowg = glowcolor[1];
						glowb = glowcolor[2];
					}
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Player Glow "));
					ImGui::TextColored(ImVec4(glowrknocked, glowgknocked, glowbknocked, 1.0f), "Knocked:");
					ImGui::ColorEdit3("##Glow Color Knocked", glowcolorknocked, ImGuiColorEditFlags_Float);
					{
						glowrknocked = glowcolorknocked[0];
						glowgknocked = glowcolorknocked[1];
						glowbknocked = glowcolorknocked[2];
					}
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Saving and Loading. Need to Save Once to make the file."));
					//Saving
					if (ImGui::Button("Save Config"))
					{
						ofstream config("Settings.txt");
						if (config.is_open())
						{
							config << std::boolalpha << firing_range << "\n";
							config << aim << "\n";
							config << std::boolalpha << esp << "\n";
							config << std::boolalpha << item_glow << "\n";
							config << std::boolalpha << player_glow << "\n";
							config << std::boolalpha << aim_no_recoil << "\n";
							config << max_dist << "\n";
							config << smooth << "\n";
							config << max_fov << "\n";
							config << bone << "\n";
							config << glowr << "\n";
							config << glowg << "\n";
							config << glowb << "\n";
							config << glowcolor[0] << "\n";
							config << glowcolor[1] << "\n";
							config << glowcolor[2] << "\n";
							config << v.healthbar << "\n";
							config << v.shieldbar << "\n";
							config << v.distance << "\n";
							config << std::boolalpha << minimapradar << "\n";
							config << std::boolalpha << lightbackpack << "\n";
							config << std::boolalpha << medbackpack << "\n";
							config << std::boolalpha << heavybackpack << "\n";
							config << std::boolalpha << shieldupgrade1 << "\n";
							config << std::boolalpha << shieldupgradehead1 << "\n";
							config << std::boolalpha << shieldupgrade2 << "\n";
							config << std::boolalpha << shieldupgradehead2 << "\n";
							config << std::boolalpha << shieldupgrade3 << "\n";
							config << std::boolalpha << shieldupgradehead3 << "\n";
							config << std::boolalpha << shieldupgrade4 << "\n";
							config << std::boolalpha << shieldupgradehead4 << "\n";
							config << std::boolalpha << accelerant << "\n";
							config << std::boolalpha << phoenix << "\n";
							config << std::boolalpha << healthlarge << "\n";
							config << std::boolalpha << healthsmall << "\n";
							config << std::boolalpha << shieldbattsmall << "\n";
							config << std::boolalpha << shieldbattlarge << "\n";
							config << std::boolalpha << sniperammo << "\n";
							config << std::boolalpha << heavyammo << "\n";
							config << std::boolalpha << optic1xhcog << "\n";
							config << std::boolalpha << lightammo << "\n";
							config << std::boolalpha << energyammo << "\n";
							config << std::boolalpha << shotgunammo << "\n";
							config << std::boolalpha << lasersight1 << "\n";
							config << std::boolalpha << lasersight2 << "\n";
							config << std::boolalpha << lasersight3 << "\n";
							config << std::boolalpha << lasersight4 << "\n";
							config << std::boolalpha << sniperammomag1 << "\n";
							config << std::boolalpha << energyammomag1 << "\n";
							config << std::boolalpha << sniperammomag2 << "\n";
							config << std::boolalpha << energyammomag2 << "\n";
							config << std::boolalpha << sniperammomag3 << "\n";
							config << std::boolalpha << energyammomag3 << "\n";
							config << std::boolalpha << sniperammomag4 << "\n";
							config << std::boolalpha << energyammomag4 << "\n";
							config << std::boolalpha << stocksniper1 << "\n";
							config << std::boolalpha << stockregular1 << "\n";
							config << std::boolalpha << stocksniper2 << "\n";
							config << std::boolalpha << stockregular2 << "\n";
							config << std::boolalpha << stocksniper3 << "\n";
							config << std::boolalpha << stockregular3 << "\n";
							config << std::boolalpha << shielddown1 << "\n";
							config << std::boolalpha << shielddown2 << "\n";
							config << std::boolalpha << shielddown3 << "\n";
							config << std::boolalpha << shielddown4 << "\n";
							config << std::boolalpha << lightammomag1 << "\n";
							config << std::boolalpha << heavyammomag1 << "\n";
							config << std::boolalpha << lightammomag2 << "\n";
							config << std::boolalpha << heavyammomag2 << "\n";
							config << std::boolalpha << lightammomag3 << "\n";
							config << std::boolalpha << heavyammomag3 << "\n";
							config << std::boolalpha << lightammomag4 << "\n";
							config << std::boolalpha << heavyammomag4 << "\n";
							config << std::boolalpha << optic2xhcog << "\n";
							config << std::boolalpha << opticholo1x << "\n";
							config << std::boolalpha << opticsniper6x << "\n";
							config << std::boolalpha << opticsniper4x8x << "\n";
							config << std::boolalpha << opticsniperthreat << "\n";
							config << std::boolalpha << optic2x4x << "\n";
							config << std::boolalpha << opticthreat << "\n";
							config << std::boolalpha << optic3xhcog << "\n";
							config << std::boolalpha << opticholo1x2x << "\n";
							config << std::boolalpha << suppressor1 << "\n";
							config << std::boolalpha << suppressor2 << "\n";
							config << std::boolalpha << suppressor3 << "\n";
							config << std::boolalpha << turbo_charger << "\n";
							config << std::boolalpha << grenade_frag << "\n";
							config << std::boolalpha << grenade_arc_star << "\n";
							config << std::boolalpha << grenade_thermite << "\n";
							config << std::boolalpha << shotgunbolt1 << "\n";
							config << std::boolalpha << shotgunbolt2 << "\n";
							config << std::boolalpha << shotgunbolt3 << "\n";
							config << std::boolalpha << shotgunbolt4 << "\n";
							config << std::boolalpha << weapon_kraber << "\n";
							config << std::boolalpha << weapon_mastiff << "\n";
							config << std::boolalpha << weapon_lstar << "\n";
							config << std::boolalpha << weapon_havoc << "\n";
							config << std::boolalpha << weapon_devotion << "\n";
							config << std::boolalpha << weapon_triple_take << "\n";
							config << std::boolalpha << weapon_flatline << "\n";
							config << std::boolalpha << weapon_hemlock << "\n";
							config << std::boolalpha << weapon_g7_scout << "\n";
							config << std::boolalpha << weapon_alternator << "\n";
							config << std::boolalpha << weapon_r99 << "\n";
							config << std::boolalpha << weapon_prowler << "\n";
							config << std::boolalpha << weapon_volt << "\n";
							config << std::boolalpha << weapon_longbow << "\n";
							config << std::boolalpha << weapon_charge_rifle << "\n";
							config << std::boolalpha << weapon_spitfire << "\n";
							config << std::boolalpha << weapon_r301 << "\n";
							config << std::boolalpha << weapon_eva8 << "\n";
							config << std::boolalpha << weapon_peacekeeper << "\n";
							config << std::boolalpha << weapon_mozambique << "\n";
							config << std::boolalpha << weapon_wingman << "\n";
							config << std::boolalpha << weapon_p2020 << "\n";
							config << std::boolalpha << weapon_re45 << "\n";
							config << std::boolalpha << weapon_sentinel << "\n";
							config << std::boolalpha << weapon_bow << "\n";
							config << std::boolalpha << weapon_3030_repeater << "\n";
							config << std::boolalpha << weapon_rampage << "\n";
							config << std::boolalpha << weapon_car_smg << "\n";
							config << toggleaim << "\n";
							config << toggleaim2 << "\n";
							config << e << "\n";
							config << minimapradardotsize1 << "\n";
							config << minimapradardotsize2 << "\n";
							config << aimdist << "\n";
							config << itemglowbrightness << "\n";
							config << dynamicfov << "\n";
							config << dynamicfovmax << "\n";
							config << glowrviz << "\n";
							config << glowgviz << "\n";
							config << glowbviz << "\n";
							config << glowcolorviz[0] << "\n";
							config << glowcolorviz[1] << "\n";
							config << glowcolorviz[2] << "\n";
							config << glowrknocked << "\n";
							config << glowgknocked << "\n";
							config << glowbknocked << "\n";
							config << glowcolorknocked[0] << "\n";
							config << glowcolorknocked[1] << "\n";
							config << glowcolorknocked[2] << "\n";
							config << bulletspeed << "\n";
							config << bulletgrav << "\n";
							config << std::boolalpha << weapon_nemesis << "\n";
							config << std::boolalpha << triggerbot << "\n";
							config << std::boolalpha << insidevaluegoggle << "\n";
							config << std::boolalpha << goldbackpack << "\n";
							config << std::boolalpha << outlinesize << "\n";
							config << std::boolalpha << onevone << "\n";
							config << std::boolalpha << turbo_charger << "\n";
							config << std::boolalpha << skull_piecer << "\n";
							config << std::boolalpha << hammer_point << "\n";
							config << std::boolalpha << disruptor_rounds << "\n";
							config << std::boolalpha << shieldupgrade5 << "\n";
							config << frameSleepTimerValue << "\n";
							config << superGlideTimerValue << "\n";
							config << m_traversalProgress_min << "\n";
							config << m_traversalProgress_max << "\n";
							config << SuperKey << "\n";
							config << std::boolalpha << boosted_loader << "\n";
							config << ADS << "\n";
							config << NonADS << "\n";
							config << bg_offsetValue << "\n";
							config << bar_widthValue << "\n";
							config << shield_25Value << "\n";
							config << ShieldHeightDisplay << "\n";
							config << BackgroundXPOS << "\n";
							config << BackgroundYPOS << "\n";
							config << HeathXPOS << "\n";
							config << HeathYPOS << "\n";
							config << health_bar_height2 << "\n";
							config << background_height << "\n";
							config << NameHeightAjust << "\n";
							config << v.name << "\n";
							config << SpectartorPOSX << "\n";
							config << SpectartorPOSY << "\n";
							config << SpectatorToggle << "\n";
							config << MiniMapFaceing << "\n";
							config << directionlinesize << "\n";
							config << veltest << "\n";
							config << RenderInfoBar << "\n";
							config << SpectatorWatchingLivetoggle << "\n";
							config << MainMapRadarToggle << "\n";
							config << TogglePrediction << "\n";
							config << bone_auto << "\n";
							config << v.modelname << "\n";
							config << ScreenResINT << "\n";
							config << BoxEnable << "\n";
							config << v.box << "\n";
							config << std::boolalpha << control << "\n";
							config << InputSelect << "\n";
							config << MapRadarName << "\n";
							config << MapTeamIDScale << "\n";
							config << MapTeamIDBackground << "\n";
							config << MapRadarTeamID;
							config.close();
						}
					}
					ImGui::SameLine();
					//Loading
					if (ImGui::Button("Load Config"))
					{
						ifstream config("Settings.txt");
						if (config.is_open())
						{
							config >> std::boolalpha >> firing_range;
							config >> aim;
							config >> std::boolalpha >> esp;
							config >> std::boolalpha >> item_glow;
							config >> std::boolalpha >> player_glow;
							config >> std::boolalpha >> aim_no_recoil;
							config >> max_dist;
							config >> smooth;
							config >> max_fov;
							config >> bone;
							config >> glowr;
							config >> glowg;
							config >> glowb;
							config >> glowcolor[0];
							config >> glowcolor[1];
							config >> glowcolor[2];
							config >> v.healthbar;
							config >> v.shieldbar;
							config >> v.distance;
							config >> minimapradar;
							config >> lightbackpack;
							config >> medbackpack;
							config >> heavybackpack;
							config >> shieldupgrade1;
							config >> shieldupgradehead1;
							config >> shieldupgrade2;
							config >> shieldupgradehead2;
							config >> shieldupgrade3;
							config >> shieldupgradehead3;
							config >> shieldupgrade4;
							config >> shieldupgradehead4;
							config >> accelerant;
							config >> phoenix;
							config >> healthlarge;
							config >> healthsmall;
							config >> shieldbattsmall;
							config >> shieldbattlarge;
							config >> sniperammo;
							config >> heavyammo;
							config >> optic1xhcog;
							config >> lightammo;
							config >> energyammo;
							config >> shotgunammo;
							config >> lasersight1;
							config >> lasersight2;
							config >> lasersight3;
							config >> lasersight4;
							config >> sniperammomag1;
							config >> energyammomag1;
							config >> sniperammomag2;
							config >> energyammomag2;
							config >> sniperammomag3;
							config >> energyammomag3;
							config >> sniperammomag4;
							config >> energyammomag4;
							config >> stocksniper1;
							config >> stockregular1;
							config >> stocksniper2;
							config >> stockregular2;
							config >> stocksniper3;
							config >> stockregular3;
							config >> shielddown1;
							config >> shielddown2;
							config >> shielddown3;
							config >> shielddown4;
							config >> lightammomag1;
							config >> heavyammomag1;
							config >> lightammomag2;
							config >> heavyammomag2;
							config >> lightammomag3;
							config >> heavyammomag3;
							config >> lightammomag4;
							config >> heavyammomag4;
							config >> optic2xhcog;
							config >> opticholo1x;
							config >> opticsniper6x;
							config >> opticsniper4x8x;
							config >> opticsniperthreat;
							config >> optic2x4x;
							config >> opticthreat;
							config >> optic3xhcog;
							config >> opticholo1x2x;
							config >> suppressor1;
							config >> suppressor2;
							config >> suppressor3;
							config >> turbo_charger;
							config >> grenade_frag;
							config >> grenade_arc_star;
							config >> grenade_thermite;
							config >> shotgunbolt1;
							config >> shotgunbolt2;
							config >> shotgunbolt3;
							config >> shotgunbolt4;
							config >> weapon_kraber;
							config >> weapon_mastiff;
							config >> weapon_lstar;
							config >> weapon_havoc;
							config >> weapon_devotion;
							config >> weapon_triple_take;
							config >> weapon_flatline;
							config >> weapon_hemlock;
							config >> weapon_g7_scout;
							config >> weapon_alternator;
							config >> weapon_r99;
							config >> weapon_prowler;
							config >> weapon_volt;
							config >> weapon_longbow;
							config >> weapon_charge_rifle;
							config >> weapon_spitfire;
							config >> weapon_r301;
							config >> weapon_eva8;
							config >> weapon_peacekeeper;
							config >> weapon_mozambique;
							config >> weapon_wingman;
							config >> weapon_p2020;
							config >> weapon_re45;
							config >> weapon_sentinel;
							config >> weapon_bow;
							config >> weapon_3030_repeater;
							config >> weapon_rampage;
							config >> weapon_car_smg;
							config >> toggleaim;
							config >> toggleaim2;
							config >> e;
							config >> minimapradardotsize1;
							config >> minimapradardotsize2;
							config >> aimdist;
							config >> itemglowbrightness;
							config >> dynamicfov;
							config >> dynamicfovmax;
							config >> glowrviz;
							config >> glowgviz;
							config >> glowbviz;
							config >> glowcolorviz[0];
							config >> glowcolorviz[1];
							config >> glowcolorviz[2];
							config >> glowrknocked;
							config >> glowgknocked;
							config >> glowbknocked;
							config >> glowcolorknocked[0];
							config >> glowcolorknocked[1];
							config >> glowcolorknocked[2];
							config >> bulletspeed;
							config >> bulletgrav;
							config >> weapon_nemesis;
							config >> triggerbot;
							config >> insidevaluegoggle;
							config >> goldbackpack;
							config >> outlinesize;
							config >> onevone;
							config >> turbo_charger;
							config >> skull_piecer;
							config >> hammer_point;
							config >> disruptor_rounds;
							config >> shieldupgrade5;
							config >> frameSleepTimerValue;
							config >> superGlideTimerValue;
							config >> m_traversalProgress_min;
							config >> m_traversalProgress_max;
							config >> SuperKey;
							config >> boosted_loader;
							config >> ADS;
							config >> NonADS;
							config >> bg_offsetValue;
							config >> bar_widthValue;
							config >> shield_25Value;
							config >> ShieldHeightDisplay;
							config >> BackgroundXPOS;
							config >> BackgroundYPOS;
							config >> HeathXPOS;
							config >> HeathYPOS;
							config >> health_bar_height2;
							config >> background_height;
							config >> NameHeightAjust;
							config >> v.name;
							config >> SpectartorPOSX;
							config >> SpectartorPOSY;
							config >> SpectatorToggle;
							config >> MiniMapFaceing;
							config >> directionlinesize;
							config >> veltest;
							config >> RenderInfoBar;
							config >> SpectatorWatchingLivetoggle;
							config >> MainMapRadarToggle;
							config >> TogglePrediction;
							config >> bone_auto;
							config >> v.modelname;
							config >> ScreenResINT;
							config >> BoxEnable;
							config >> v.box;
							config >> control;
							config >> InputSelect;
							config >> MapRadarName;
							config >> MapTeamIDScale;
							config >> MapTeamIDBackground;
							config >> MapRadarTeamID;
							config.close();

						}
					}
					ImGui::SameLine();
					ImGui::Text(XorStr("Saved to Settings.txt"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					if (menu1 == 1)
					{
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Radar Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Item Filter Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Weapone Filter Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Weapon Attachment's"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Debug Options"), 0);
					}
					
				}
				if (ImGui::CollapsingHeader("Radar Settings"))
				{
					menu2 = 1;
					//Dot Size for both mini and main map
					ImGui::Text(XorStr("MiniMap Radar Dot Size"));
					ImGui::SliderInt(XorStr("##MiniMap Dot Size"), &minimapradardotsize1, 1, 15);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("MiniMap Radar Outline Size"));
					ImGui::SliderInt(XorStr("##MiniMap Outer Ring Thickness"), &minimapradardotsize2, 1, 15);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Direction Line Size: "));
					ImGui::SameLine();
					ImGui::TextColored(GREEN, "%.3f", directionlinesize);
					ImGui::SliderFloat(XorStr("##directionlinesize"), &directionlinesize, 0.0f, 5.0f, "%0.3f");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					if (ImGui::Button("Reload KingsCanyon Map Data")) {
						KingsCanyon.loadFromFile("KingsCanyon.txt");
					}
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					if (ImGui::Button("Reload WorldsEdge Map Data")) {
						WorldsEdge.loadFromFile("WorldsEdge.txt");
					}
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					if (ImGui::Button("Reload Olympus Map Data")) {
						Olympus.loadFromFile("Olympus.txt");
					}
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					if (ImGui::Button("Reload BrokenMoon Map Data")) {
						BrokenMoon.loadFromFile("BrokenMoon.txt");
					}
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					if (ImGui::Button("Reload StormPoint Map Data")) {
						StormPoint.loadFromFile("StormPoint.txt");
					}
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::SliderFloat(XorStr("MapTeamIDBackground"), &MapTeamIDBackground, 0.0f, 1.0f, "%0.3f");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::SliderFloat(XorStr("MapTeamIDScale"), &MapTeamIDScale, 0.0f, 1.0f, "%0.3f");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					if (menu2 == 1)
					{
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Main Toggle Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Item Filter Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Weapone Filter Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Weapon Attachment's"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Debug Options"), 0);
					}
				}
				if (ImGui::CollapsingHeader("Item Filter Settings"))
				{
					menu3 = 1;
					ImGui::Text(XorStr("Backpacks:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("##1011White"), &lightbackpack);
					ImGui::SameLine();
					ImGui::Text(XorStr("White"));
					
					
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##1012Blue"), &medbackpack);
					ImGui::SameLine();
					ImGui::TextColored(BLUE, "Blue");
					
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##1013Purple"), &heavybackpack);
					ImGui::SameLine();
					ImGui::TextColored(PURPLE, "Purple");
					
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##1014Gold"), &goldbackpack);
					ImGui::SameLine();
					ImGui::TextColored(GOLD, "Gold");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Body Shields:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					
					ImGui::Sliderbox(XorStr("##10121White"), &shieldupgrade1);
					ImGui::SameLine();
					ImGui::Text(XorStr("White"));
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##10122Blue"), &shieldupgrade2);
					ImGui::SameLine();
					ImGui::TextColored(BLUE, "Blue");
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##10123Purple"), &shieldupgrade3);
					ImGui::SameLine();
					ImGui::TextColored(PURPLE, "Purple");
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##10124Gold"), &shieldupgrade4);
					ImGui::SameLine();
					ImGui::TextColored(GOLD, "Gold");
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##10125Red"), &shieldupgrade5);
					ImGui::SameLine();
					ImGui::TextColored(RED, "RED");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Helmets"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					
					ImGui::Sliderbox(XorStr("##10130White"), &shieldupgradehead1);
					ImGui::SameLine();
					ImGui::Text(XorStr("White"));

					
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##10131Blue"), &shieldupgradehead2);
					ImGui::SameLine();
					ImGui::TextColored(BLUE, "Blue");
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##10132Purple"), &shieldupgradehead3);
					ImGui::SameLine();
					ImGui::TextColored(PURPLE, "Purple");
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##10133Gold"), &shieldupgradehead4);
					ImGui::SameLine();
					ImGui::TextColored(GOLD, "Gold");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Knockdown Shields:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					
					ImGui::Sliderbox(XorStr("##10141White"), &shielddown1);
					ImGui::SameLine();
					ImGui::Text(XorStr("White"));
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##10142Blue"), &shielddown2);
					ImGui::SameLine();
					ImGui::TextColored(BLUE, "Blue");
					ImGui::SameLine();

					
					ImGui::Sliderbox(XorStr("##10143urple"), &shielddown3);
					ImGui::SameLine();
					ImGui::TextColored(PURPLE, "Purple");
					ImGui::SameLine();

					
					ImGui::Sliderbox(XorStr("##10144Gold"), &shielddown4);
					ImGui::SameLine();
					ImGui::TextColored(GOLD, "Gold");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::TextColored(GREEN, "Health Packs");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));					
					ImGui::Sliderbox(XorStr("Small Health"), &healthsmall);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Large Health"), &healthlarge);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Phoenix Kit"), &phoenix);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::TextColored(BLUE, "Shield Packs");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Small Shield"), &shieldbattsmall);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Large Shield"), &shieldbattlarge);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Ult:"));
					ImGui::Sliderbox(XorStr("Ultimate Accelerant"), &accelerant);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Death Box ESP"), &BoxEnable);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					if (menu3 == 1)
					{
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Main Toggle Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Radar Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Weapone Filter Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Weapon Attachment's"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Debug Options"), 0);
					}
				}
				if (ImGui::CollapsingHeader("Weapone Filter Settings"))
				{
					menu4 = 1;
					//Light Weapons
					
					ImGui::TextColored(ORANGE, "Light Weapons:");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Light Ammo"), &lightammo);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("P2020"), &weapon_p2020);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("RE-45"), &weapon_re45);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("R-99"), &weapon_r99);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("G7 Scout"), &weapon_g7_scout);
					ImGui::Sliderbox(XorStr("Spitfire"), &weapon_spitfire);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("R-301"), &weapon_r301);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Alternator "), &weapon_alternator);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					//Heavy Weapons

					ImGui::TextColored(TEAL, "Heavy Weapons:");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Heavy Ammo"), &heavyammo);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("C.A.R."), &weapon_car_smg);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Flatline"), &weapon_flatline);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Hemlok"), &weapon_hemlock);
					ImGui::Sliderbox(XorStr("Prowler "), &weapon_prowler);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("30-30"), &weapon_3030_repeater);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Rampage"), &weapon_rampage);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					//Energy Weapons
					
					
					ImGui::TextColored(YELLOW, "Energy Weapons:");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Energy Ammo"), &energyammo);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Triple Take"), &weapon_triple_take);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("L-STAR"), &weapon_lstar);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Volt"), &weapon_volt);
					ImGui::Sliderbox(XorStr("Devotion "), &weapon_devotion);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("HAVOC"), &weapon_havoc);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Nemesis"), &weapon_nemesis);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					
					//Shotgun Weapons
					
					
					ImGui::TextColored(RED, "Shotgun Weapons:");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Shotgun Ammo"), &shotgunammo);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("EVA-8"), &weapon_eva8);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Mozambique"), &weapon_mozambique);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Peacekeeper"), &weapon_peacekeeper);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Mastiff"), &weapon_mastiff);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					//Sniper Weapons
					
					
					
					ImGui::TextColored(BLUE, "Sniper Weapons:");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Sniper Ammo"), &sniperammo);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Charge Rifle"), &weapon_charge_rifle);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Longbow"), &weapon_longbow);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Sentinel"), &weapon_sentinel);
					ImGui::Sliderbox(XorStr("Wingman "), &weapon_wingman);
					//KRABER
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Special Weapons:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Kraber .50-Cal Sniper"), &weapon_kraber);
					ImGui::Sliderbox(XorStr("Bocek Bow"), &weapon_bow);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Nades"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Frag grenade"), &grenade_frag);
					ImGui::Sliderbox(XorStr("Arc Star"), &grenade_arc_star);
					ImGui::Sliderbox(XorStr("Thermite"), &grenade_thermite);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					if (menu4 == 1)
					{
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Main Toggle Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Radar Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Item Filter Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Weapon Attachment's"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Debug Options"), 0);
					}
				}
				if (ImGui::CollapsingHeader("Weapon Attachment's"))
				{
					menu5 = 1;
					ImGui::TextColored(BLUE, "Sniper Mags:");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("##1011177White"), &sniperammomag1);
					ImGui::SameLine();
					ImGui::Text(XorStr("White"));
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##10118Blue"), &sniperammomag2);
					ImGui::SameLine();
					ImGui::TextColored(BLUE, "Blue");
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##10117Purple"), &sniperammomag3);
					ImGui::SameLine();
					ImGui::TextColored(PURPLE, "Purple");
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##10116Gold"), &sniperammomag4);
					ImGui::SameLine();
					ImGui::TextColored(GOLD, "Gold");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::TextColored(TEAL, "Heavy Mags:");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					
					ImGui::Sliderbox(XorStr("##10112White"), &heavyammomag1);
					ImGui::SameLine();
					ImGui::Text(XorStr("White"));
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##10113Blue"), &heavyammomag2);
					ImGui::SameLine();
					ImGui::TextColored(BLUE, "Blue");
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##10114Purple"), &heavyammomag3);
					ImGui::SameLine();
					ImGui::TextColored(PURPLE, "Purple");
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##10115Gold"), &heavyammomag4);
					ImGui::SameLine();
					ImGui::TextColored(GOLD, "Gold");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::TextColored(ORANGE, "Light Mags:");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("##1558White"), &lightammomag1);
					ImGui::SameLine();
					ImGui::Text(XorStr("White"));
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##1557Blue"), &lightammomag2);
					ImGui::SameLine();
					ImGui::TextColored(BLUE, "Blue");
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##1556Purple"), &lightammomag3);
					ImGui::SameLine();
					ImGui::TextColored(PURPLE, "Purple");
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##1555Gold"), &lightammomag4);
					ImGui::SameLine();
					ImGui::TextColored(GOLD, "Gold");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::TextColored(YELLOW, "Energy Mags:");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					
					ImGui::Sliderbox(XorStr("##1554White"), &energyammomag1);
					ImGui::SameLine();
					ImGui::Text(XorStr("White"));
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##1553Blue"), &energyammomag2);
					ImGui::SameLine();
					ImGui::TextColored(BLUE, "Blue");
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##15252Purple"), &energyammomag3);
					ImGui::SameLine();
					ImGui::TextColored(PURPLE, "Purple");
					ImGui::SameLine();
					
					ImGui::Sliderbox(XorStr("##1551Gold"), &energyammomag4);
					ImGui::SameLine();
					ImGui::TextColored(GOLD, "Gold");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("HCOG:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("1x HCOG"), &optic1xhcog);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("2x HCOG"), &optic2xhcog);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("3x HCOG"), &optic3xhcog);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("2-4x"), &optic2x4x);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Sniper:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Sniper 6x"), &opticsniper6x);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Sniper 4-8x"), &opticsniper4x8x);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Sniper Threat"), &opticsniperthreat);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Holo:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("1x Holo"), &opticholo1x);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("2x Holo"), &opticholo1x2x);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("1x Threat"), &opticthreat);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Attachements:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Laser Sights:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("##48323White"), &lasersight1);
					ImGui::SameLine();
					ImGui::Text(XorStr("White"));
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##4833Blue"), &lasersight2);
					ImGui::SameLine();
					ImGui::TextColored(BLUE, "Blue");
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##4583Purple"), &lasersight3);
					ImGui::SameLine();
					ImGui::TextColored(PURPLE, "Purple");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Sniper Stocks:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("##6483White"), &stocksniper1);
					ImGui::SameLine();
					ImGui::Text(XorStr("White"));
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##4783Blue"), &stocksniper2);
					ImGui::SameLine();
					ImGui::TextColored(BLUE, "Blue");
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##4883Purple"), &stocksniper3);
					ImGui::SameLine();
					ImGui::TextColored(PURPLE, "Purple");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Regular Stocks:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("##4893White"), &stockregular1);
					ImGui::SameLine();
					ImGui::Text(XorStr("White"));
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##41183Blue"), &stockregular2);
					ImGui::SameLine();
					ImGui::TextColored(BLUE, "Blue");
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##42283Purple"), &stockregular3);
					ImGui::SameLine();
					ImGui::TextColored(PURPLE, "Purple");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Suppressor's:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("##48333White"), &suppressor1);
					ImGui::SameLine();
					ImGui::Text(XorStr("White"));
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##44483Blue"), &suppressor2);
					ImGui::SameLine();
					ImGui::TextColored(BLUE, "Blue");
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("##48553Purple"), &suppressor3);
					ImGui::SameLine();
					ImGui::TextColored(PURPLE, "Purple");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Text(XorStr("Weapon Mods:"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Turbo Charger"), &turbo_charger);
					ImGui::SameLine();
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Skull Piecer"), &skull_piecer);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Hammer Point"), &hammer_point);
					ImGui::Sliderbox(XorStr("Disruptor Rounds"), &disruptor_rounds);
					ImGui::SameLine();
					ImGui::Sliderbox(XorStr("Boosted Loader"), &boosted_loader);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					if (menu5 == 1)
					{
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Main Toggle Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Radar Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Item Filter Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Weapone Filter Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Debug Options"), 0);
					}
				}

				if (ImGui::CollapsingHeader("Debug Options"))
				{
					menu6 = 1;
					ImGui::Text(XorStr("TEST MENU"));
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Map Cords On/Off"), &PrintMapCords);
					ImGui::Dummy(ImVec2(0.0f, 10.0f));
					ImGui::Sliderbox(XorStr("Print Held ID"), &PrintHeldID);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("Print Model/Id On/Off"), &PrintModelAndId);
					ImGui::Dummy(ImVec2(0.0f, 10.0f));
					ImGui::Text(XorStr("Map ID: "));
					ImGui::SameLine();
					ImGui::TextColored(GREEN, "%d", mapid);
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::Sliderbox(XorStr("SuperGlide Toggle"), &SuperKey);
					ImGui::Dummy(ImVec2(0.0f, 10.0f));
					ImGui::Text(XorStr("16 - background_height: %d"), background_height);
					ImGui::SliderInt(XorStr("##background_height"), &background_height, -100, 100, "%d");
					ImGui::Dummy(ImVec2(0.0f, 10.0f));
					ImGui::Text(XorStr("158 - HP Bar Size: %d"), bar_widthValue);
					ImGui::SliderInt(XorStr("##bar_widthValue"), &bar_widthValue, -100, 300, "%d");
					ImGui::Dummy(ImVec2(0.0f, 10.0f));
					ImGui::Text(XorStr("30 - Shield Bar Size: %d"), shield_25Value);
					ImGui::SliderInt(XorStr("##shield_25Value"), &shield_25Value, -100, 200, "%d");
					ImGui::Dummy(ImVec2(0.0f, 10.0f));
					ImGui::Text(XorStr("-10 - ShieldHeightDisplay: %d"), ShieldHeightDisplay);
					ImGui::SliderInt(XorStr("##ShieldHeightDisplay"), &ShieldHeightDisplay, -200, 200, "%d");
					ImGui::Dummy(ImVec2(0.0f, 10.0f));
					ImGui::Text(XorStr("5 - ShieldWidthDisplay: %d"), ShieldWidthDisplay);
					ImGui::SliderInt(XorStr("##ShieldWidthDisplay"), &ShieldWidthDisplay, -100, 200, "%d");
					ImGui::Dummy(ImVec2(0.0f, 10.0f));
					ImGui::Text(XorStr("0 - HeathXPOS: %d"), HeathXPOS);
					ImGui::SliderInt(XorStr("##HeathXPOS"), &HeathXPOS, -100, 200, "%d");
					ImGui::Dummy(ImVec2(0.0f, 10.0f));
					ImGui::Text(XorStr("0 - HeathYPOS: %d"), HeathYPOS);
					ImGui::SliderInt(XorStr("##HeathYPOS"), &HeathYPOS, -100, 200, "%d");
					ImGui::Dummy(ImVec2(0.0f, 10.0f));
					ImGui::Text(XorStr("0 - Heath Bar Height: %d"), health_bar_height2);
					ImGui::SliderInt(XorStr("##health_bar_height2"), &health_bar_height2, -50, 50, "%d");					
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::TextColored(GREEN, "%.4f Bullet Speed | 0.08 default", bulletspeed);
					ImGui::SliderFloat(XorStr("##bulletspeed"), &bulletspeed, -1.0f, 1.0f, "##");
					ImGui::Dummy(ImVec2(0.0f, 5.0f));
					ImGui::TextColored(GREEN, "%.4f Bullet Grav | 0.05 default", bulletgrav);
					ImGui::SliderFloat(XorStr("##bulletgrav"), &bulletgrav, -1.0f, 1.0f, "##");
					if (menu6 == 1)
					{
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Main Toggle Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Radar Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Item Filter Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Weapone Filter Settings"), 0);
						ImGui::GetStateStorage()->SetInt(ImGui::GetID("Weapon Attachment's"), 0);
						//ImGui::GetStateStorage()->SetInt(ImGui::GetID("Other Options"), 0);
					}
				}
				//ImGui::EndTabItem();
			

		//}

		//ImGui::EndTabBar();
	//}
	ImGui::Dummy(ImVec2(0.0f, 5.0f));
	ImGui::Text(XorStr("Overlay FPS: %.3f ms/frame (%.1f FPS)"), 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();
}

void Overlay::RenderInfo()
{	
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2(350, 30));
	ImGui::Begin(XorStr("##info"), (bool*)true, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
	DrawLine(ImVec2(1, 2), ImVec2(350, 2), RED, 2);
	ImGui::TextColored(RED, "%d", spectators);
	ImGui::SameLine();
	ImGui::Text("--");
	ImGui::SameLine();
	ImGui::TextColored(GREEN, "%d", allied_spectators);
	ImGui::SameLine();
	ImGui::Text("--");
	ImGui::SameLine();
	ImGui::TextColored(WHITE, "%.f", max_fov);
	ImGui::SameLine();
	ImGui::Text("--");
	ImGui::SameLine();
	/*if (spectators > 0)
	{
		if (SpectatorWatchingLivetoggle)
		{
			SpectatorWatchingLive();
		}
	}
	*/
	if (isInTargetListRED)
	{
		ImGui::TextColored(RED, "Target is in the List!", isInTargetListRED);
	}
	if (!isInTargetListRED)
	{
		ImGui::TextColored(GREEN, "No Targets", isInTargetListRED);
	}
	//Aim is on = 2, On but No Vis Check = 1, Off = 0
	if (aim == 2)
	{
		ImGui::TextColored(GREEN, "Aim On %d", aim);
	}
	else
	{
		ImGui::TextColored(RED, "Aim Off %d", aim);
	}
	ImGui::SameLine();
	if (triggerbot)
	{
		ImGui::TextColored(GREEN, "1v1 On");
	}
	else
	{
		ImGui::TextColored(RED, "1v1 Off");
	}
	DrawLine(ImVec2(1, 28), ImVec2(350, 28), RED, 2);
	ImGui::End();
}
uint32_t counters[100] = { 0 };
/*
void Overlay::SpectatorWatchingLive() {
	ImGui::SetNextWindowPos(ImVec2(350, 0));
	ImGui::SetNextWindowSize(ImVec2(400, 150));
	ImGui::Begin(XorStr("##SpectatorWatchingLive"), (bool*)true, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
	ImGui::Text(XorStr("Enemy Spectators"));
	//ImGui::TextColored(GREEN, "Local Yaw: %.7f", LocalYAW);
	
	//ImGui::Text("counter: %d", counter);

	for (int i = 0; i < 100; i++) 
	{
		if (!players[i].isAlive) 
		{
			if (players[i].targetyaw != 0.00000f)
			{
				if (LocalYAW == players[i].targetyaw)
				{
					//ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s - %.7f", players[i].name, players[i].targetyaw);
					counters[i] = 0;
				}
				else if (LocalYAW != players[i].targetyaw)
				{
					counters[i]++;
				}
				if (counters[i] < 500)
				{
					ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", players[i].name);
				}
			}
		}
	}

	ImGui::End();
}

*/

// Function to save the target list to a file
void SaveTargetListToFile() {
	std::ofstream targetFile("target_list.txt");
	if (targetFile.is_open()) {
		for (const std::string& playerName : targetList) {
			targetFile << playerName << "\n";
		}
		targetFile.close();
	}
}

// Function to load the target list from a file
void LoadTargetListFromFile() {
	std::ifstream targetFile("target_list.txt");
	if (targetFile.is_open()) {
		// Clear the existing target list before loading
		targetList.clear();

		std::string playerName;
		while (std::getline(targetFile, playerName)) {
			targetList.push_back(playerName);
		}
		targetFile.close();
	}
}

float GetOuterRadius(float screenWidth, float screenHeight, float fullFOV) {
	float smallerDimension = screenWidth < screenHeight ? screenWidth : screenHeight;
	float radians = fullFOV * 3.14159265f / 180.0f; // Convert degrees to radians
	float result = (smallerDimension / 2) / tan(radians / 2);
	return result;
}

float GetInnerRadius(float outerRadius, float desiredFOV, float fullFOV) {
	float radians = desiredFOV * 3.14159265f / 180.0f; // Convert degrees to radians
	float fovRatio = radians / (fullFOV * 3.14159265f / 180.0f); // Convert degrees to radians
	float result = outerRadius * fovRatio;
	return result;
}
#define M_PI		3.14159265358979323846	// matches value in gcc v2 math.h
int GetFovCircleRadius(float AimbotFovDegrees, float ViewFov, int ScreenWidth)
{
	// The reason for using ViewFov/2 should be rather obvious when looking at the illustration in my post
	const float Scale = tan(AimbotFovDegrees / 180 * M_PI) / tan((ViewFov / 2) / 180 * M_PI);
	return Scale * ScreenWidth / 2;
}
void Overlay::FovCircleDraw()
{
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2((float)getWidth(), (float)getHeight()));
	ImGui::Begin(XorStr("##fovcirc"), (bool*)true, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoBringToFrontOnFocus);

	int screenWidth = getWidth(); // Replace with your method for getting screen width
	/*int screenHeight = getHeight(); // Replace with your method for getting screen height
	float fullFOV = 100.0f; // Your full FOV in degrees

	ImVec2 screenCenter = ImVec2(screenWidth / 2, screenHeight / 2);

	// Calculate the adjusted inner radius based on the desired FOV and adjustment
	float innerRadius = GetInnerRadius(GetOuterRadius(screenWidth, screenHeight, fullFOV), desiredFOV + fovAdjustment, fullFOV);
	

	int roundedZoom = static_cast<int>(CurrentWeaponADSZoom);
	if (roundedZoom == 70)
	{
		ModdedZoom = 5.8;
	}
	else if (roundedZoom == 60)
	{
		ModdedZoom = 6;
	}
	else if (roundedZoom == 55)
	{
		ModdedZoom = 6.5;
	}
	else if (roundedZoom == 38)
	{
		ModdedZoom = 3.3;
	}
	else if (roundedZoom == 26)
	{
		ModdedZoom = 10;
	}
	else if (roundedZoom == 19)
	{
		ModdedZoom = 3;
	}
	else if (roundedZoom == 13)
	{
		ModdedZoom = 20;
	}
	else if (roundedZoom == 10)
	{
		ModdedZoom = 14;
	}
	else if (roundedZoom == 8)
	{
		ModdedZoom = 17;
	}
	else
	{
		ModdedZoom = max_fov;
	}
	*/
	
	
	const float circleRadius = GetFovCircleRadius(ModdedZoom, 100, screenWidth);
	const ImVec2 center(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2);
	ImGui::GetWindowDrawList()->AddCircle(center, circleRadius, IM_COL32(255, 0, 0, 255), 64, 2.0f); // Adjust the color and segment count as needed

	ImGui::End();
}
void Overlay::SpectatorInfo() {
	ImGui::SetNextWindowPos(ImVec2(800, 0));
	ImGui::SetNextWindowSize(ImVec2(300, 1000));
	ImGui::Begin(XorStr("##SpectatorInfo"), (bool*)true, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
	ImGui::Text(XorStr("Target List"));
	ImGui::Dummy(ImVec2(0.0f, 5.0f));
	ImGui::Text(XorStr("Red is in Target List"));
	ImGui::Text(XorStr("Green is Still Alive"));
	ImGui::Dummy(ImVec2(0.0f, 5.0f));
	
	for (int i = 0; i < 100; i++) {
		if (players[i].name[0] != 0)
		{
			isInTargetList = std::find(targetList.begin(), targetList.end(), players[i].name) != targetList.end();
			if (isInTargetList)
			{
				// Use red color for names in the TargetList
				ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", players[i].name);
				//isInTargetListRED = true;  // Set to true if at least one player in the list is both in the target list and still alive
				//String(ImVec2(players[i].boxMiddle, (players[i].b_y - players[i].height - NameHeightAjust)), WHITE, players[i].name);

			}
			else if(!isInTargetList)
			{
				ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "%s", players[i].name);				
			}
			

			ImGui::SameLine(); // Keep the button and the name on the same line

			// Add button to add to target list
			if (ImGui::Button(("Add###AddToTargetList" + std::to_string(i)).c_str())) {
				// Check if the name is not in the TargetList before adding
				if (std::find(targetList.begin(), targetList.end(), players[i].name) == targetList.end()) {
					targetList.push_back(players[i].name);
				}
			}
			ImGui::SameLine(); // Keep the button and the name on the same line

			// Add button to remove from target list
			if (ImGui::Button(("Remove###RemoveFromTargetList" + std::to_string(i)).c_str())) {
				// Remove the player's name from the target list (if it exists)
				targetList.erase(std::remove(targetList.begin(), targetList.end(), players[i].name), targetList.end());
			}

		}
	}
	// After the loop, you can check if no players meet the condition and set it to false
	
	ImGui::End();

	// Create a new window to display the target list
	ImGui::SetNextWindowPos(ImVec2(1100, 0));
	ImGui::SetNextWindowSize(ImVec2(300, 1000));
	ImGui::Begin(XorStr("##TargetList"), (bool*)true, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
	
	ImGui::Text(XorStr("Target Saved list"), SpectartorPOSY);
	ImGui::Dummy(ImVec2(0.0f, 5.0f));
	for (int i = 0; i < targetList.size(); i++) {
		ImGui::Text(targetList[i].c_str());
		ImGui::SameLine(); // Keep the button and the name on the same line
		// Add a "Remove" button next to each name
		if (ImGui::Button(("Remove###RemoveFromTargetList" + std::to_string(i)).c_str())) {
			// Remove the player's name from the target list
			targetList.erase(targetList.begin() + i);
		}
	}
	ImGui::Dummy(ImVec2(0.0f, 5.0f));
	if (ImGui::Button("Save")) {
		SaveTargetListToFile(); // Call your save function when the button is clicked
	}
	ImGui::SameLine(); // Keep the button and the name on the same line
	if (ImGui::Button("Load")) {
		LoadTargetListFromFile(); // Call your save function when the button is clicked
	}

	ImGui::End();
}

void Overlay::ClickThrough(bool v)
{
	if (v)
	{
		nv_edit = nv_default_in_game | WS_VISIBLE;
		if (GetWindowLong(overlayHWND, GWL_EXSTYLE) != nv_ex_edit)
			SetWindowLong(overlayHWND, GWL_EXSTYLE, nv_ex_edit);
	}
	else
	{
		nv_edit = nv_default | WS_VISIBLE;
		if (GetWindowLong(overlayHWND, GWL_EXSTYLE) != nv_ex_edit_menu)
			SetWindowLong(overlayHWND, GWL_EXSTYLE, nv_ex_edit_menu);
	}
}
float CalculateDivisionFactor(float fov) {
	// Define the minimum and maximum FOV values for your range
	float minFOV = 0.0f;
	float maxFOV = 50.0f;

	// Define the corresponding division factors for the min and max FOV
	float minFactor = 1.0f;  // Division factor for min FOV (e.g., 2 FOV / 2 FOV = 1)
	float maxFactor = 0.77f; // Division factor for max FOV (e.g., 50 FOV / 0.77 = 64.935)

	// Calculate the division factor using linear interpolation
	float divisionFactor = minFactor + (fov - minFOV) * (maxFactor - minFactor) / (maxFOV - minFOV);

	return divisionFactor;
}
DWORD Overlay::CreateOverlay()
{
	EnumWindows(EnumWindowsCallback, (LPARAM)&overlayHWND);
	Sleep(300);
	if (overlayHWND == 0)
	{
		printf(XorStr("Can't find the overlay, HIT ALT-Z\n"));
		Sleep(1000);
		exit(0);
	}

	HDC hDC = ::GetWindowDC(NULL);
	width = ::GetDeviceCaps(hDC, HORZRES);
	height = ::GetDeviceCaps(hDC, VERTRES);

	running = true;

	// Initialize Direct3D
	if (!CreateDeviceD3D(overlayHWND))
	{
		CleanupDeviceD3D();
		return 1;
	}

	// Show the window
	::ShowWindow(overlayHWND, SW_SHOWDEFAULT);
	::UpdateWindow(overlayHWND);

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	ImGui::GetStyle().WindowMinSize = ImVec2(1, 1);

	// Setup Platform/Renderer bindings
	ImGui_ImplWin32_Init(overlayHWND);
	ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

	ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 0.00f);

	// Main loop
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	ClickThrough(true);
	while (running)
	{
		HWND wnd = GetWindow(GetForegroundWindow(), GW_HWNDPREV);
		if (use_nvidia)
		{
			if (GetWindowLong(overlayHWND, GWL_STYLE) != nv_edit)
				SetWindowLong(overlayHWND, GWL_STYLE, nv_edit);
			if (show_menu || spectatornameshow)
			{
				ClickThrough(false);
			}
			else
			{
				if (GetWindowLong(overlayHWND, GWL_EXSTYLE) != nv_ex_edit)
					SetWindowLong(overlayHWND, GWL_EXSTYLE, nv_ex_edit);
				ClickThrough(true);
			}
		}
		if (wnd != overlayHWND)
		{
			SetWindowPos(overlayHWND, wnd, 0, 0, 0, 0, SWP_ASYNCWINDOWPOS | SWP_NOMOVE | SWP_NOSIZE);
			::UpdateWindow(overlayHWND);
		}

		if (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
			continue;
		}

		// Start the Dear ImGui frame
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		if (IsKeyDown(VK_LBUTTON) && !k_leftclick)
		{
			io.MouseDown[0] = true;
			k_leftclick = true;
		}
		else if (!IsKeyDown(VK_LBUTTON) && k_leftclick)
		{
			io.MouseDown[0] = false;
			k_leftclick = false;
		}

		if (IsKeyDown(VK_INSERT) && !k_ins && ready)
		{
			show_menu = !show_menu;
			ClickThrough(!show_menu);
			k_ins = true;
		}
		else if (!IsKeyDown(VK_INSERT) && k_ins)
		{
			k_ins = false;
		}

		if (IsKeyDown(VK_DELETE) && !spectatornameshow_ins && ready)
		{
			spectatornameshow = !spectatornameshow;
			
			spectatornameshow_ins = true;
		}
		else if (!IsKeyDown(VK_DELETE) && spectatornameshow_ins)
		{
			spectatornameshow_ins = false;
		}

		if (show_menu)
			RenderMenu();
		if (RenderInfoBar)
		{
			RenderInfo();
		}
		
		if (spectatornameshow)
		{
			SpectatorInfo();
			//SpectatorWatchingLive();  //disable me
		}
		
		//if(SpecLiveView)
		//SpectatorWatchingLive();
	
		for (static bool once = true; once; once = false)
		{
			LoadTargetListFromFile();
		}
		RenderEsp();
		float divisionFactor = CalculateDivisionFactor(max_fov); // Adjusts for FOV of 30
		//FovCircleDraw();

		// Rendering
		ImGui::EndFrame();
		ImGui::Render();
		const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
		g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
		g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

		g_pSwapChain->Present(1, 0); // Present with vsync

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	ClickThrough(true);

	CleanupDeviceD3D();
	::DestroyWindow(overlayHWND);
	return 0;
}

void Overlay::Start()
{
	DWORD ThreadID;
	CreateThread(NULL, 0, StaticMessageStart, (void*)this, 0, &ThreadID);
}

void Overlay::Clear()
{
	running = 0;
	Sleep(50);
	if (use_nvidia)
	{
		SetWindowLong(overlayHWND, GWL_STYLE, nv_default);
		SetWindowLong(overlayHWND, GWL_EXSTYLE, nv_ex_default);
	}
}

int Overlay::getWidth()
{
	return width;
}

int Overlay::getHeight()
{
	return height;
}

// Helper functions

void CreateRenderTarget()
{
	ID3D11Texture2D* pBackBuffer;
	g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
	if (pBackBuffer)
	{
		g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
		pBackBuffer->Release();
	}
}

bool CreateDeviceD3D(HWND hWnd)
{
	// Setup swap chain
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 2;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	UINT createDeviceFlags = 0;
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
		return false;

	CreateRenderTarget();
	return true;
}

void CleanupRenderTarget()
{
	if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}

void CleanupDeviceD3D()
{
	CleanupRenderTarget();
	if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
	if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}

void Overlay::DrawLine(ImVec2 a, ImVec2 b, ImColor color, float width)
{
	ImGui::GetWindowDrawList()->AddLine(a, b, color, width);
}

void Overlay::DrawBox(ImColor color, float x, float y, float w, float h)
{
	DrawLine(ImVec2(x, y), ImVec2(x + w, y), color, 1.0f);
	DrawLine(ImVec2(x, y), ImVec2(x, y + h), color, 1.0f);
	DrawLine(ImVec2(x + w, y), ImVec2(x + w, y + h), color, 1.0f);
	DrawLine(ImVec2(x, y + h), ImVec2(x + w, y + h), color, 1.0f);
}


void Overlay::Text(ImVec2 pos, ImColor color, const char* text_begin, const char* text_end, float wrap_width, const ImVec4* cpu_fine_clip_rect)
{
	ImGui::GetWindowDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), pos, color, text_begin, text_end, wrap_width, cpu_fine_clip_rect);
}

void Overlay::String(ImVec2 pos, ImColor color, const char* text)
{
	Text(pos, color, text, text + strlen(text), 200, 0);
}

void Overlay::RectFilled(float x0, float y0, float x1, float y1, ImColor color, float rounding, int rounding_corners_flags)
{
	ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(x0, y0), ImVec2(x1, y1), color, rounding, rounding_corners_flags);
}

void Overlay::ProgressBar(float x, float y, float w, float h, int value, int v_max)
{
	ImColor barColor = ImColor(
		min(510 * (v_max - value) / 100, 255),
		min(510 * value / 100, 255),
		25,
		255
	);
	
	RectFilled(x, y, x + w, y + ((h / float(v_max)) * (float)value), barColor, 0.0f, 0);
}


//Seer Hp and Shield bars (never re fixed the armor type so its set to max shield)

void DrawQuadFilled(ImVec2 p1, ImVec2 p2, ImVec2 p3, ImVec2 p4, ImColor color) {
	ImGui::GetWindowDrawList()->AddQuadFilled(p1, p2, p3, p4, color);
}
void DrawQuadFilled2(ImVec2 p1, ImVec2 p2, ImVec2 p3, ImVec2 p4, ImColor color) {
	ImGui::GetWindowDrawList()->AddQuadFilled(p1, p2, p3, p4, color);
}
void DrawHexagon(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& p5, const ImVec2& p6, ImU32 col, float thickness)
{
	ImGui::GetWindowDrawList()->AddHexagon(p1, p2, p3, p4, p5, p6, col, thickness);
}
void DrawHexagonFilled(const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& p5, const ImVec2& p6, ImU32 col)
{
	ImGui::GetWindowDrawList()->AddHexagonFilled(p1, p2, p3, p4, p5, p6, col);
}

void HeathBar(const ImVec2& healthBarPosition, const ImVec2& healthBarEnd, ImU32 col)
{
	ImGui::GetWindowDrawList()->AddRectFilled(healthBarPosition, healthBarEnd, col); // Green color
}
ImU32 GetHealthColor(float healthProportion) {
	ImVec4 white = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	ImVec4 red = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);

	ImVec4 color;

	// Linear interpolation from white to red based on health proportion
	color = ImVec4(white.x * healthProportion + red.x * (1.0f - healthProportion),
		white.y * healthProportion + red.y * (1.0f - healthProportion),
		white.z * healthProportion + red.z * (1.0f - healthProportion),
		1.0f);

	return IM_COL32((int)(color.x * 255), (int)(color.y * 255), (int)(color.z * 255), 255);
}
void Overlay::DrawSeerLikeHealth(float x, float y, int shield, int max_shield, int armorType, int health) {

	int bg_offset = bg_offsetValue;
	int bar_width = bar_widthValue;
	// 4steps...2*3=6
	// 38*4=152 152+6 = 158
	// 5steps...2*4=8
	// 30*5=150 150+8 = 158
	float max_health = 100.0f;
	float shield_step = 25.0f;

	int shield_25 = shield_25Value;
	int steps = 5;
	float healthProportion = static_cast<float>(health) / static_cast<float>(max_health);
	//ImU32 healthColor = IM_COL32(255, 255 * (1.0f - healthProportion), 0, 255);
	ImU32 healthColor = GetHealthColor(healthProportion);
	ImVec2 bg1(x - bar_width / 2 - bg_offset, y);
	ImVec2 bg2(bg1.x - 10, bg1.y - 16 - background_height);
	ImVec2 bg3(bg2.x + 5, bg2.y - 7);
	ImVec2 bg4(bg3.x + bar_width + bg_offset, bg3.y);
	ImVec2 bg5(bg4.x + 11, bg4.y + 18);
	ImVec2 bg6(x + bar_width / 2 + bg_offset, y);
	DrawHexagonFilled(bg1, bg2, bg3, bg4, bg5, bg6, ImColor(0, 0, 0, 120));


	ImVec2 h1(bg1.x + HeathXPOS + 3, bg1.y + HeathYPOS - 4);
	ImVec2 h2(h1.x - 5, h1.y - health_bar_height2); // hp bar main height
	ImVec2 h3(h2.x + (float)health / max_health * bar_width, h2.y);
	ImVec2 h4(h1.x + (float)health / max_health * bar_width, h1.y); // hp bar bottem right
	ImVec2 h3m(h2.x + bar_width, h2.y); //shadow bottem right
	ImVec2 h4m(h1.x + bar_width, h1.y); // shadow top right
	if (SeerBars)
	{
		DrawQuadFilled(h1, h2, h3, h4, WHITE);
	}
	if (NormalBars)
	{
		DrawQuadFilled2(h1, h2, h3, h4, healthColor);
	}


	ImColor shieldCracked(97, 97, 97);
	ImColor shieldCrackedDark(67, 67, 67);

	ImColor shieldCol;
	ImColor shieldColDark; //not used, but the real seer q has shadow inside
	if (max_shield == 50) { //white
		shieldCol = ImColor(247, 247, 247);
		shieldColDark = ImColor(164, 164, 164);
	}
	else if (max_shield == 75) { //blue
		shieldCol = ImColor(39, 178, 255);
		shieldColDark = ImColor(27, 120, 210);
	}
	else if (max_shield == 100) { //purple
		shieldCol = ImColor(206, 59, 255);
		shieldColDark = ImColor(136, 36, 220);
	}
	else if (max_shield == 100) { //gold
		shieldCol = ImColor(255, 255, 79);
		shieldColDark = ImColor(218, 175, 49);
	}
	else if (max_shield == 125) { //red
		shieldCol = ImColor(219, 2, 2);
		shieldColDark = ImColor(219, 2, 2);
	}
	else {
		shieldCol = ImColor(247, 247, 247);
		shieldColDark = ImColor(164, 164, 164);
	}
	int shield_tmp = shield;
	int shield1 = 0;
	int shield2 = 0;
	int shield3 = 0;
	int shield4 = 0;
	int shield5 = 0;
	if (shield_tmp > 25) {
		shield1 = 25;
		shield_tmp -= 25;
		if (shield_tmp > 25) {
			shield2 = 25;
			shield_tmp -= 25;
			if (shield_tmp > 25) {
				shield3 = 25;
				shield_tmp -= 25;
				if (shield_tmp > 25) {
					shield4 = 25;
					shield_tmp -= 25;
					shield5 = shield_tmp;
				}
				else {
					shield4 = shield_tmp;
				}
			}
			else {
				shield3 = shield_tmp;
			}
		}
		else {
			shield2 = shield_tmp;
		}
	}
	else {
		shield1 = shield_tmp;
	}
	ImVec2 s1(h2.x - 1, h2.y - 2);
	ImVec2 s2(s1.x - 3, s1.y - 5);
	ImVec2 s3(s2.x + shield1 / shield_step * shield_25, s2.y);
	ImVec2 s4(s1.x + shield1 / shield_step * shield_25, s1.y);
	ImVec2 s3m(s2.x + shield_25, s2.y);
	ImVec2 s4m(s1.x + shield_25, s1.y);

	ImVec2 ss1(s4m.x + 2, s1.y);
	ImVec2 ss2(s3m.x + 2, s2.y);
	ImVec2 ss3(ss2.x + shield2 / shield_step * shield_25, s2.y);
	ImVec2 ss4(ss1.x + shield2 / shield_step * shield_25, s1.y);
	ImVec2 ss3m(ss2.x + shield_25, s2.y);
	ImVec2 ss4m(ss1.x + shield_25, s1.y);

	ImVec2 sss1(ss4m.x + 2, s1.y);
	ImVec2 sss2(ss3m.x + 2, s2.y);
	ImVec2 sss3(sss2.x + shield3 / shield_step * shield_25, s2.y);
	ImVec2 sss4(sss1.x + shield3 / shield_step * shield_25, s1.y);
	ImVec2 sss3m(sss2.x + shield_25, s2.y);
	ImVec2 sss4m(sss1.x + shield_25, s1.y);

	ImVec2 ssss1(sss4m.x + 2, s1.y);
	ImVec2 ssss2(sss3m.x + 2, s2.y);
	ImVec2 ssss3(ssss2.x + shield4 / shield_step * shield_25, s2.y);
	ImVec2 ssss4(ssss1.x + shield4 / shield_step * shield_25, s1.y);
	ImVec2 ssss3m(ssss2.x + shield_25, s2.y);
	ImVec2 ssss4m(ssss1.x + shield_25, s1.y);

	ImVec2 sssss1(ssss4m.x + 2, s1.y);
	ImVec2 sssss2(ssss3m.x + 2, s2.y);
	ImVec2 sssss3(sssss2.x + shield5 / shield_step * shield_25, s2.y);
	ImVec2 sssss4(sssss1.x + shield5 / shield_step * shield_25, s1.y);
	ImVec2 sssss3m(sssss2.x + shield_25, s2.y);
	ImVec2 sssss4m(sssss1.x + shield_25, s1.y);
	if (max_shield == 50) {
		if (shield <= 25) {
			if (shield < 25) {
				DrawQuadFilled(s1, s2, s3m, s4m, shieldCracked);
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(s1, s2, s3, s4, shieldCol);

		}
		else if (shield <= 50) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			if (shield != 50) {
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
		}
	}
	else if (max_shield == 75) {
		if (shield <= 25) {
			if (shield < 25) {
				DrawQuadFilled(s1, s2, s3m, s4m, shieldCracked);
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(s1, s2, s3, s4, shieldCol);

		}
		else if (shield <= 50) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			if (shield < 50) {
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
		}
		else if (shield <= 75) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			if (shield < 75) {
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
		}
	}
	else if (max_shield == 100) {
		if (shield <= 25) {
			if (shield < 25) {
				DrawQuadFilled(s1, s2, s3m, s4m, shieldCracked);
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(s1, s2, s3, s4, shieldCol);

		}
		else if (shield <= 50) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			if (shield < 50) {
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
		}
		else if (shield <= 75) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			if (shield < 75) {
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
		}
		else if (shield <= 100) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
			if (shield < 100) {
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ssss1, ssss2, ssss3, ssss4, shieldCol);
		}
	}
	else if (max_shield == 125) {
		if (shield <= 25) {
			if (shield < 25) {
				DrawQuadFilled(s1, s2, s3m, s4m, shieldCracked);
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(s1, s2, s3, s4, shieldCol);

		}
		else if (shield <= 50) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			if (shield < 50) {
				DrawQuadFilled(ss1, ss2, ss3m, ss4m, shieldCracked);
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
		}
		else if (shield <= 75) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			if (shield < 75) {
				DrawQuadFilled(sss1, sss2, sss3m, sss4m, shieldCracked);
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
		}
		else if (shield <= 100) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
			if (shield < 100) {
				DrawQuadFilled(ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(ssss1, ssss2, ssss3, ssss4, shieldCol);
		}
		else if (shield <= 125) {
			DrawQuadFilled(s1, s2, s3, s4, shieldCol);
			DrawQuadFilled(ss1, ss2, ss3, ss4, shieldCol);
			DrawQuadFilled(sss1, sss2, sss3, sss4, shieldCol);
			DrawQuadFilled(ssss1, ssss2, ssss3, ssss4, shieldCol);
			if (shield < 125) {
				DrawQuadFilled(sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
			}
			if (shield != 0)
				DrawQuadFilled(sssss1, sssss2, sssss3, sssss4, shieldCol);
		}
	}
}


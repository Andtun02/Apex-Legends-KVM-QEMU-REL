#pragma warning (disable : 4715)
#pragma warning (disable : 4005)
#pragma warning (disable : 4305)
#pragma warning (disable : 4244)
#include "main.h"
#include "world.h"
#include <random>
#include <map>
#include "player.h"
#include <Xinput.h>
#include <atomic>
#include <Windows.h>
#include <sstream> // Include this header for stringstream
#pragma comment(lib, "Xinput.lib")
#include <ctime>



extern player players[100];

uint32_t check = 0xABCD;

//Aiming keys: left and right mouse button
int aim_key = VK_LBUTTON; //Left Click
int aim_key2 = VK_RBUTTON; //Right Click
//int aim_key = VK_XBUTTON2; //Left Click  //mouse 5
//int aim_key2 = VK_XBUTTON2; //Right Click  //mouse 5
int StopAimBot = VK_XBUTTON2;
int TapBotEnableControl = VK_CONTROL;
int aimathead = VK_CONTROL;
float MINIMAPZOOM = 0.3f;
extern float spectolerance;
bool MapRadarName = false;
int mapid = 0;
extern int InputSelect;
extern int control;
extern bool Keyboard;
extern bool Gamepad;
//box toggle
bool BoxEnable = false;
//screen res
int ScreenResINT = 0;
float MainRadarMulti;
bool bone_auto = true;
bool MapRadarTeamID;
bool PrintModelAndId = false;
bool TogglePrediction = false;
bool MainMapRadarToggle = true;
bool RenderInfoBar = true;
extern bool SpectatorWatchingLivetoggle;
float CurrentWeaponADSZoom;
bool mainradartoggle = false;
bool mainradarmap = false; //if the Main Map Radar is enabled
bool controlleraiming = false;
bool controlleraiming2 = false;
bool SpecLiveView_ins = false;
bool AutoFire = false;
float veltest = 0.0f;
std::vector<std::string> targetList;
float directionlinesize = 2.0f;
bool SpecLiveView = false;
bool PrintMapCords = false;
int NoNadeAim = 0;
int SpecLiveViewBttn = VK_F9;
bool isInTargetList = false;
int lstarvalueid;
float targetyawvalue;
//float minimapfaceajust = 270.0f;
bool MiniMapFaceing = true;
bool tapstrafeenable = false;
bool TriggerBot = false;
bool SpectatorToggle = false;
int TriggerBotKey = 0x58;
int SpectartorPOSX;
int SpectartorPOSY;
bool spectatornameshow = false;
float LocalYAW;
float TargetYAW;
int TARGET_TEAMID = 0;
int TEAM_TEAMID = 0;
bool SeerBars = false;
bool NormalBars = true;
extern int HeathXPOS;
extern int HeathYPOS;
extern int background_height;
int ShieldHeightDisplay = 10;
int ShieldWidthDisplay = 5;
int NameHeightAjust = 16;
extern int bg_offsetValue;
extern int bar_widthValue;
extern int shield_25Value;
extern int BackgroundXPOS;
extern int BackgroundYPOS;
extern int health_bar_height2;
//Left and Right Aim key toggle
bool toggleaim = false;
bool toggleaim2 = false;
extern int e;
bool firing_range = false;
bool use_nvidia = true; //Nvidia Shadowplay Overlay
bool active = true;
bool ready = false;
extern visuals v;
int aim = 2; //read
bool esp = true; //read
bool item_glow = true;
bool player_glow = true;
bool aim_no_recoil = true;
bool aiming = false; //read
uint64_t g_Base = 0; //write
float max_dist = 3800.0f * 40.0f; //read //Max Distance of ESP 3800 is full map
float smooth = 110.0f; //Min 100 for safe aimbotting
float max_fov = 15.0f; //15 is the sweetspot for 1080p
float NonADS = 50;
float ADS = 10;
// Dynamic Fov
float dynamicfov = 10;
float dynamicfovmax = 15.0f;
//tdm check
int EntTeam;
int LocTeam;
bool TDMToggle = false;
//triggerbot
bool triggerbot = false;

//superglide
bool SuperKey = false;
int frameSleepTimerValue = 10; //not used
int superGlideTimerValue = 10; //not used
float m_traversalProgress_min = 0.85f;
float m_traversalProgress_max = 0.92f;
float m_traversalProgress;
//1v1
bool onevone = false;
bool insidevaluegoggle = true;
int outlinesize = 32;
float bulletspeed = 0.08;
float bulletgrav = 0.05;
bool MiniMapGuides = false;
int bone = 2; //0 Head, 1 Neck, 2 Body, 3 Stomace, 4 Nuts
//Player Glow Color and Brightness
//Glow Knocked
float glowr = 1.0f; //Red Value
float glowg = 0.0f; //Green Value
float glowb = 0.0f; //Blue Value
float glowcolor[3] = { 000.0f, 000.0f, 000.0f };
//more glow stuff
//glow visable
float glowrviz = 0.0f;
float glowgviz = 1.0f;
float glowbviz = 0.0f;
float glowcolorviz[3] = { 000.0f, 000.0f, 000.0f };
//knocked
float glowrknocked = 1.0f;
float glowgknocked = 1.0f;
float glowbknocked = 1.0f;
float glowcolorknocked[3] = { 000.0f, 000.0f, 000.0f };
extern int minimapradardotsize1;
extern int minimapradardotsize2;
bool minimapradar = false;
//Ha think i was done ?
//Item Filter Brute Force!
bool lightbackpack = false;
bool medbackpack = false;
bool heavybackpack = false;
bool goldbackpack = false;
bool shieldupgrade1 = false;
bool shieldupgradehead1 = false;
bool shieldupgrade2 = false;
bool shieldupgradehead2 = false;
bool shieldupgrade3 = false;
bool shieldupgradehead3 = false;
bool shieldupgrade4 = false;
bool shieldupgrade5 = false;
bool shieldupgradehead4 = false;
bool accelerant = false;
bool phoenix = false;
bool healthlarge = false;
bool healthsmall = false;
bool shieldbattsmall = false;
bool shieldbattlarge = false;
bool sniperammo = false;
bool heavyammo = false;
bool optic1xhcog = false;
bool lightammo = false;
bool energyammo = false;
bool shotgunammo = false;
bool lasersight1 = false;
bool lasersight2 = false;
bool lasersight3 = false;
bool lasersight4 = false;
bool sniperammomag1 = false;
bool energyammomag1 = false;
bool sniperammomag2 = false;
bool energyammomag2 = false;
bool sniperammomag3 = false;
bool energyammomag3 = false;
bool sniperammomag4 = false;
bool energyammomag4 = false;
bool stocksniper1 = false;
bool stockregular1 = false;
bool stocksniper2 = false;
bool stockregular2 = false;
bool stocksniper3 = false;
bool stockregular3 = false;
bool shielddown1 = false;
bool shielddown2 = false;
bool shielddown3 = false;
bool shielddown4 = false;
bool lightammomag1 = false;
bool heavyammomag1 = false;
bool lightammomag2 = false;
bool heavyammomag2 = false;
bool lightammomag3 = false;
bool heavyammomag3 = false;
bool lightammomag4 = false;
bool heavyammomag4 = false;
bool optic2xhcog = false;
bool opticholo1x = false;
bool opticsniper6x = false;
bool opticsniper4x8x = false;
bool opticsniperthreat = false;
bool optic2x4x = false;
bool opticthreat = false;
bool optic3xhcog = false;
bool opticholo1x2x = false;
bool suppressor1 = false;
bool suppressor2 = false;
bool suppressor3 = false;
bool turbo_charger = false;
bool skull_piecer = false;
bool hammer_point = false;
bool disruptor_rounds = false;
bool boosted_loader = false;
bool grenade_frag = false;
bool grenade_arc_star = false;
bool grenade_thermite = false;
bool shotgunbolt1 = false;
bool shotgunbolt2 = false;
bool shotgunbolt3 = false;
bool shotgunbolt4 = false;
bool weapon_kraber = false;
bool weapon_mastiff = false;
bool weapon_lstar = false;
bool weapon_havoc = false;
bool weapon_devotion = false;
bool weapon_triple_take = false;
bool weapon_flatline = false;
bool weapon_hemlock = false;
bool weapon_g7_scout = false;
bool weapon_alternator = false;
bool weapon_r99 = false;
bool weapon_prowler = false;
bool weapon_volt = false;
bool weapon_longbow = false;
bool weapon_charge_rifle = false;
bool weapon_spitfire = false;
bool weapon_r301 = false;
bool weapon_eva8 = false;
bool weapon_peacekeeper = false;
bool weapon_mozambique = false;
bool weapon_wingman = false;
bool weapon_p2020 = false;
bool weapon_re45 = false;
bool weapon_sentinel = false;
bool weapon_bow = false;
bool weapon_3030_repeater = false;
bool weapon_rampage = false;
bool weapon_car_smg = false;
bool weapon_nemesis = false;
float MapTeamIDScale = 1.0;
float MapTeamIDBackground = 0.0;
// Aim distance check
float aimdist = 9905.0f;
//item glow brightness
int itemglowbrightness = 10;
bool PrintHeldID;
bool thirdperson = false;
int spectators = 0; //write
int allied_spectators = 0; //write
bool valid = true; //write
bool next2 = true; //read write

uint64_t add[170];

bool k_f5 = 0;
bool k_f6 = 0;
bool k_f7 = 0;
bool k_f8 = 0;
bool k_f9 = 0;
bool k_f10 = 0;


bool k_f20 = 0;

bool k_f100 = 0;

player players[100];



//Radar Code
#define M_PI		3.14159265358979323846	// matches value in gcc v2 math.h

static D3DXVECTOR3 RotatePoint(D3DXVECTOR3 EntityPos, D3DXVECTOR3 LocalPlayerPos, int posX, int posY, int sizeX, int sizeY, float angle, float zoom, bool* viewCheck)
{
	float r_1, r_2;
	float x_1, y_1;

	r_1 = -(EntityPos.y - LocalPlayerPos.y);
	r_2 = EntityPos.x - LocalPlayerPos.x;
	float Yaw = angle - 90.0f;

	float yawToRadian = Yaw * (float)(M_PI / 180.0F);
	x_1 = (float)(r_2 * (float)cos((double)(yawToRadian)) - r_1 * sin((double)(yawToRadian))) / 20;
	y_1 = (float)(r_2 * (float)sin((double)(yawToRadian)) + r_1 * cos((double)(yawToRadian))) / 20;

	*viewCheck = y_1 < 0;

	x_1 *= zoom;
	y_1 *= zoom;

	int sizX = sizeX / 2;
	int sizY = sizeY / 2;

	x_1 += sizX;
	y_1 += sizY;

	if (x_1 < 5)
		x_1 = 5;

	if (x_1 > sizeX - 5)
		x_1 = sizeX - 5;

	if (y_1 < 5)
		y_1 = 5;

	if (y_1 > sizeY - 5)
		y_1 = sizeY - 5;


	x_1 += posX;
	y_1 += posY;


	return D3DXVECTOR3(x_1, y_1, 0);
}

//Main Map Radar Color


//Minimap Stuff
/*struct RGBA2 {
	int R;
	int G;
	int B;
	int A;
};*/

struct RGBA {
	uint8_t R, G, B, A;
};
std::vector<RGBA> brightColors = {
	{255, 0, 0, 255},      // Red  1
	{0, 255, 0, 255},      // Green2
	{0, 0, 255, 255},      // Blue3
	{255, 255, 0, 255},    // Yellow4
	{255, 0, 255, 255},    // Magenta5
	{0, 255, 255, 255},    // Cyan6
	{255, 128, 0, 255},    // Orange7
	{128, 0, 255, 255},    // Purple8
	{255, 0, 128, 255},    // Pink9
	{0, 255, 128, 255},    // Teal10
	{128, 255, 0, 255},    // Lime11
	{0, 128, 255, 255},    // Sky Blue12
	{255, 192, 0, 255},    // Gold13
	{0, 255, 192, 255},    // Turquoise14
	{192, 0, 255, 255},    // Lavender15
	{255, 128, 128, 255},  // Light Red16
	{128, 255, 128, 255},  // Light Green17
	{128, 128, 255, 255},  // Light Blue18
	{255, 255, 128, 255},  // Light Yellow19
	{255, 128, 255, 255},  // Light Magenta20
	{128, 255, 255, 255},  // Light Cyan21
	{128, 0, 128, 255},     // Team 22 - Purple
	{255, 255, 255, 255},  // Team 23 - White
	{0, 128, 0, 255},      // Team 24 - Dark Green
	{255, 165, 0, 255},    // Team 25 - Orange
	{128, 0, 0, 255},      // Team 26 - Maroon
	{0, 0, 128, 255},      // Team 27 - Navy
	{128, 128, 0, 255},    // Team 28 - Olive
	{0, 128, 128, 255},    // Team 29 - Teal
	{64, 64, 64, 255}     // Team 30 - Gray
};

//std::map<int, RGBA2> teamColors;
RGBA getColorForTeam(int teamID) {
	if (teamID >= 1 && teamID <= brightColors.size()) {
		// Subtract 1 from teamID to use it as an index (0-based)
		return brightColors[static_cast<std::vector<RGBA, std::allocator<RGBA>>::size_type>(teamID) - 1];
	}
	else {
		// Handle out-of-range team IDs
		return { 0, 0, 0, 0 }; // Default color (black) or any other appropriate handling
	}
}
static void TeamMiniMap(int x, int y, int radius, int teamID, float targetyaw)
{
	/*RGBA2 color;
	auto it = teamColors.find(teamID);
	if (it == teamColors.end()) {
		// Define the minimum sum of RGB values for a color to be considered "light"
		const int MIN_SUM_RGB = 500;

		// Generate a new random color for this team, discarding colors with a low sum of RGB values
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 255);
		RGBA2 color;
		do {
			color = { dis(gen), dis(gen), dis(gen), 255 };
		} while (color.R + color.G + color.B < MIN_SUM_RGB);

		// Store the color in the teamColors map
		teamColors[teamID] = color;
	}
	else {
		// Use the previously generated color for this team
		color = it->second;
	}*/

	RGBA color = getColorForTeam(teamID);
	//std::cout << "Team " << teamID << " color: RGB(" << int(color.R) << ", " << int(color.G) << ", " << int(color.B) << ")\n";
	auto colOutline = ImGui::ColorConvertFloat4ToU32(ImVec4(0.0, 0.0, 0.0, 1.0));
	ImVec2 center(x, y);
	ImGui::GetWindowDrawList()->AddCircleFilled(center, radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color.R / 255.0f, color.G / 255.0f, color.B / 255.0f, color.A / 255.0f)));
	ImGui::GetWindowDrawList()->AddCircle(center, radius, colOutline, 12, minimapradardotsize2);
	float angleInDegrees = targetyaw - 270.0f - LocalYAW;  // Assuming targetyaw is in degrees
	ImVec2 endpoint(x + radius * std::cos(angleInDegrees * 3.14159265f / 180.0f), y - radius * std::sin(angleInDegrees * 3.14159265f / 180.0f));
	if (MiniMapFaceing)
	{
		
		// Draw the arrow shape
		ImGui::GetWindowDrawList()->AddLine(center, endpoint, colOutline, directionlinesize);
	}

}

bool menu = true;
bool firstS = true;
//Radar Settings.. ToDO: Put in ImGui menu to change in game
namespace RadarSettings
{
	bool Radar = true;
	bool teamRadar = true;
	bool enemyRadar = true;
	int xAxis_Radar = 0;
	int yAxis_Radar = 400;
	int radartype = 0;
	int width_Radar = 400;
	int height_Radar = 400;
	int distance_Radar = 250;
	int distance_Radar2 = 1000;
};

void DrawRadarPointMiniMap(D3DXVECTOR3 EneamyPos, D3DXVECTOR3 LocalPos, float LocalPlayerY, float eneamyDist, int TeamID, int xAxis, int yAxis, int width, int height, D3DXCOLOR color, float targetyaw)
{
	bool out = false;
	D3DXVECTOR3 siz;
	siz.x = width;
	siz.y = height;
	D3DXVECTOR3 pos;
	pos.x = xAxis;
	pos.y = yAxis;
	bool ck = false;
	D3DXVECTOR3 single = RotatePoint(EneamyPos, LocalPos, pos.x, pos.y, siz.x, siz.y, LocalPlayerY, MINIMAPZOOM, &ck);
	if (eneamyDist >= 0.f && eneamyDist < RadarSettings::distance_Radar)
	{
		for (int i = 1; i <= 30; i++)
		{
			TeamMiniMap(single.x, single.y, minimapradardotsize1, TeamID, targetyaw);
		}
	}
}
auto colOutline = ImGui::ColorConvertFloat4ToU32(ImVec4(0.0, 0.0, 0.0, 1.0));

static void DrawTeam(int x, int y, int w, int h, RGBA color, bool drawTeamID, int teamID) {
	// Draw a filled circle for the team
	ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(x, y), minimapradardotsize1, ImGui::ColorConvertFloat4ToU32(ImVec4(color.R / 255.0, color.G / 255.0, color.B / 255.0, color.A / 255.0)));

	// Draw an outlined circle for the team
	ImGui::GetWindowDrawList()->AddCircle(ImVec2(x, y), minimapradardotsize1, colOutline, 12, minimapradardotsize2);

	if (drawTeamID) {
		// Draw a thin black background for the team ID
		ImVec2 textSize = ImGui::CalcTextSize(std::to_string(teamID).c_str());
		float backgroundThickness = MapTeamIDBackground;  // Adjust this value for the desired thickness
		ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(x - textSize.x / 2 - backgroundThickness, y - textSize.y / 2 - backgroundThickness),
			ImVec2(x + textSize.x / 2 + backgroundThickness, y + textSize.y / 2 + backgroundThickness),
			IM_COL32(0, 0, 0, 200));

		// Convert WHITE to ImColor
		ImColor whiteColor = IM_COL32(255, 255, 255, 255);

		// Set the text size
		ImGui::SetWindowFontScale(MapTeamIDScale);  // Adjust this value for the desired text size

		// Draw the team ID number
		ImGui::GetWindowDrawList()->AddText(ImVec2(x - textSize.x / 2, y - textSize.y / 2), whiteColor, std::to_string(teamID).c_str());
	}
}

void DrawRadarPoint(D3DXVECTOR3 EneamyPos, D3DXVECTOR3 LocalPos, float LocalPlayerY, float eneamyDist, int TeamID, int xAxis, int yAxis, int width, int height, D3DXCOLOR color)
{
	bool out = false;
	D3DXVECTOR3 siz;
	siz.x = width;
	siz.y = height;
	D3DXVECTOR3 pos;
	pos.x = xAxis;
	pos.y = yAxis;
	bool ck = false;

	D3DXVECTOR3 single = RotatePoint(EneamyPos, LocalPos, pos.x, pos.y, siz.x, siz.y, LocalPlayerY, 0.3f, &ck);

	if (eneamyDist >= 0.f && eneamyDist < RadarSettings::distance_Radar)
	{
		if (TeamID >= 1 && TeamID <= 30) {
			DrawTeam(pos.x, pos.y, 9, 9, brightColors[TeamID - 1], true, TeamID);
		}
	}
}
//MiniMap Radar Stuff
void MiniMapRadar(D3DXVECTOR3 EneamyPos, D3DXVECTOR3 LocalPos, float LocalPlayerY, float eneamyDist, int TeamId, float targetyaw)
{
	ImGuiStyle* style = &ImGui::GetStyle();
	style->WindowRounding = 0.2f;
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.13529413f, 0.14705884f, 0.15490198f, 0.82f));
	ImGuiWindowFlags TargetFlags;
	TargetFlags = ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_::ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar;
	if (!firstS)
	{
		ImGui::SetNextWindowPos(ImVec2{ 1200, 60 }, ImGuiCond_Once);
		firstS = true;
	}
	if (RadarSettings::Radar == true)
	{
		if (ScreenResINT == 0)
		{
			ImGui::SetNextWindowSize({ 250, 250 });  //1080p
		}
		if (ScreenResINT == 1)
		{
			ImGui::SetNextWindowSize({ 334, 334 });  //1440p
		}
		//ImGui::SetNextWindowPos(ImVec2{ 45, 45 });
		
		//
		ImGui::Begin(("Radar"), 0, TargetFlags);
		{
			ImDrawList* Draw = ImGui::GetWindowDrawList();
			ImVec2 DrawPos = ImGui::GetCursorScreenPos();
			ImVec2 DrawSize = ImGui::GetContentRegionAvail();
			ImVec2 midRadar = ImVec2(DrawPos.x + (DrawSize.x / 2), DrawPos.y + (DrawSize.y / 2));
			if (MiniMapGuides)
			{
				ImGui::GetWindowDrawList()->AddLine(ImVec2(midRadar.x - DrawSize.x / 2.f, midRadar.y), ImVec2(midRadar.x + DrawSize.x / 2.f, midRadar.y), IM_COL32(255, 255, 255, 255));
				ImGui::GetWindowDrawList()->AddLine(ImVec2(midRadar.x, midRadar.y - DrawSize.y / 2.f), ImVec2(midRadar.x, midRadar.y + DrawSize.y / 2.f), IM_COL32(255, 255, 255, 255));
			}
			
			DrawRadarPointMiniMap(EneamyPos, LocalPos, LocalPlayerY, eneamyDist, TeamId, DrawPos.x, DrawPos.y, DrawSize.x, DrawSize.y, { 255, 255, 255, 255 }, targetyaw);
		}
		ImGui::End();
	}
	ImGui::PopStyleColor();
}
bool IsKeyDown(int vk)
{
	return (GetAsyncKeyState(vk) & 0x8000) != 0;
}
//Full map radar test, Needs Manual setting of cords
//ImVec2 can be replaced with Vector2D

//These values only work with 1920x1080 fullscreen, you have to redo the values for anything else..
// 
// Take screenshot, First is top right x pos, then bttm left y pos from screen shot
// 
// First set is the x cord, then the screenshot x cord. then the y cord, then the screenshot y cord.
// 1440p is x1.333333 for the second set of numbers for each. IE: ImVec2(1197, 185) would be ImVec2(1596, 246)
/*
world KingsCanyon(ImVec2(25223.177734, 28906.144531), ImVec2(1197, 185), ImVec2(10399.223633, 13334.792969), ImVec2(1014, 381));  //updated 1/24/2024

world WorldsEdge(ImVec2(28125.958984, 24938.097656), ImVec2(1277, 226), ImVec2(-26317.468750, -26350.337891), ImVec2(664, 805)); // mp_rr_desertlands_hu updated 1/22/2024

world Olympus(ImVec2(19524.753906, 20655.933594), ImVec2(1259, 309), ImVec2(-17893.945312, -25585.177734), ImVec2(836, 829 )); //updated ?

world BrokenMoon(ImVec2(27194.974609, 30955.087891), ImVec2(1304, 147), ImVec2(-30958.753906, -33503.359375), ImVec2(618, 909)); // mp_rr_divided_moon updated ?

world StormPoint(ImVec2(36265.171875, 32998.039062), ImVec2(1314, 189), ImVec2(-35452.109375, -24413.312500), ImVec2(603, 758));  // mp_rr_tropic_island_mu1_storm updated 1/21/2024
*/

world KingsCanyon("KingsCanyon.txt");
world WorldsEdge("WorldsEdge.txt");
world Olympus("Olympus.txt");
world BrokenMoon("BrokenMoon.txt");
world StormPoint("StormPoint.txt");

void Text2(ImVec2 pos, ImColor color, const char* text_begin, const char* text_end, float wrap_width, const ImVec4* cpu_fine_clip_rect)
{
	ImGui::GetWindowDrawList()->AddText(ImGui::GetFont(), ImGui::GetFontSize(), pos, color, text_begin, text_end, wrap_width, cpu_fine_clip_rect);
}
void String2(ImVec2 pos, ImColor color, const char* text)
{
	float textWidth = ImGui::CalcTextSize(text).x;
	Text2(pos, color, text, text + strlen(text), textWidth, 0);
}
std::vector<ImVec2> drawnNamePositions;
//DONE get map auto 
ImVec2 worldToScreenMap(D3DXVECTOR3 origin, int TeamID, float MainRadarMulti, const char* playername) {
	float ratioX;
	float ratioY;
	ImVec2 w1;
	ImVec2 s1;
	if (mapid == 1) { // Storm Point
		ratioX = StormPoint.ratioX;
		ratioY = StormPoint.ratioY;
		w1 = StormPoint.w1;
		s1 = ImVec2(StormPoint.s1.x * MainRadarMulti, StormPoint.s1.y * MainRadarMulti);
		ImVec2 s2 = ImVec2(StormPoint.s2.x * MainRadarMulti, StormPoint.s2.y * MainRadarMulti);
	}
	else if (mapid == 2) { // KingsCanyon
		ratioX = KingsCanyon.ratioX;
		ratioY = KingsCanyon.ratioY;
		w1 = KingsCanyon.w1;
		s1 = ImVec2(KingsCanyon.s1.x * MainRadarMulti, KingsCanyon.s1.y * MainRadarMulti);
		ImVec2 s2 = ImVec2(KingsCanyon.s2.x * MainRadarMulti, KingsCanyon.s2.y * MainRadarMulti);
	}
	else if (mapid == 3) { // WorldsEdge
		ratioX = WorldsEdge.ratioX;
		ratioY = WorldsEdge.ratioY;
		w1 = WorldsEdge.w1;
		s1 = ImVec2(WorldsEdge.s1.x * MainRadarMulti, WorldsEdge.s1.y * MainRadarMulti);
		ImVec2 s2 = ImVec2(WorldsEdge.s2.x * MainRadarMulti, WorldsEdge.s2.y * MainRadarMulti);
	}
	else if (mapid == 4) { // Olympus 
		ratioX = Olympus.ratioX;
		ratioY = Olympus.ratioY;
		w1 = Olympus.w1;
		s1 = ImVec2(Olympus.s1.x * MainRadarMulti, Olympus.s1.y * MainRadarMulti);
		ImVec2 s2 = ImVec2(Olympus.s2.x * MainRadarMulti, Olympus.s2.y * MainRadarMulti);
	}
	else if (mapid == 5) { // BrokenMoon 
		ratioX = BrokenMoon.ratioX;
		ratioY = BrokenMoon.ratioY;
		w1 = BrokenMoon.w1;
		s1 = ImVec2(BrokenMoon.s1.x * MainRadarMulti, BrokenMoon.s1.y * MainRadarMulti);
		ImVec2 s2 = ImVec2(BrokenMoon.s2.x * MainRadarMulti, BrokenMoon.s2.y * MainRadarMulti);
	}
	else {
		return ImVec2(0, 0);
	}


	//difference from location 1
	float world_diff_x = origin.x - w1.x;
	float world_diff_y = origin.y - w1.y;

	//get the screen offsets by applying the ratio
	float scr_diff_x = world_diff_x * ratioX * MainRadarMulti;
	float scr_diff_y = world_diff_y * ratioY * MainRadarMulti;

	//for x, add the offset to the screen x of location 1
	//for y, subtract the offset from the screen y of location 1 (cuz Y is from bottom to up in Apex but it's from up to bottom in screen)
	float pos_x = s1.x + scr_diff_x;
	float pos_y = s1.y - scr_diff_y;
	if (MapRadarTeamID) {
		if (TeamID >= 1 && TeamID <= 30) {
			DrawTeam(pos_x, pos_y, 9, 9, brightColors[TeamID - 1], true, TeamID);
		}
	}
	else {
		if (TeamID >= 1 && TeamID <= 30) {
			DrawTeam(pos_x, pos_y, 9, 9, brightColors[TeamID - 1], false, 0);
		}
	}

	if (MapRadarName) {
		ImVec2 playerNamePos = ImVec2(pos_x + 5, pos_y - 10);
		ImVec2 boxSize = ImVec2(100, 20);

		// Iteratively attempt different positions until a non-overlapping one is found
		int maxAttempts = 50;
		int attempts = 0;

		while (attempts < maxAttempts) {
			bool collision = false;

			// Check for collisions with existing name positions
			for (const ImVec2& drawnPos : drawnNamePositions) {
				if (!(playerNamePos.x > drawnPos.x + boxSize.x || playerNamePos.x + boxSize.x < drawnPos.x ||
					playerNamePos.y > drawnPos.y + boxSize.y || playerNamePos.y + boxSize.y < drawnPos.y)) {
					// Collision detected, set the flag
					collision = true;
					break;
				}
			}

			// If no collision, break from the loop
			if (!collision) {
				break;
			}

			// Collision detected, adjust the position and try again
			playerNamePos.y -= (attempts % 2 == 0) ? 10 : -10;  // Alternately adjust up and down
			attempts++;
		}

		// Draw box for player name
		ImGui::GetWindowDrawList()->AddRectFilled(playerNamePos, ImVec2(playerNamePos.x + boxSize.x, playerNamePos.y + boxSize.y), IM_COL32(20, 20, 20, 200));

		// Convert WHITE to ImColor
		ImColor whiteColor = IM_COL32(255, 255, 255, 255);

		// Draw player name
		String2(ImVec2(playerNamePos.x + 5, playerNamePos.y + 5), whiteColor, playername);

		// Add the new position to the list
		drawnNamePositions.push_back(playerNamePos);
	}
}

bool IsKeyHeldDown(int keyCode) {
	return (GetAsyncKeyState(keyCode) & 0x8000) != 0;
}
bool isInTargetListRED = false;
bool conditionWasTrue = false; // Flag to track previous condition state
float threshold = 0.00001f;
auto startTime = std::chrono::high_resolution_clock::now(); // Initialize startTime outside the loop
void Overlay::RenderEsp()
{
	next2 = false;
	if (g_Base != 0 && esp)
	{
		
		memset(players, 0, sizeof(players));
				
		while (!next2 && esp)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		
		if (next2 && valid)
		{

			
			ImGui::SetNextWindowPos(ImVec2(0, 0));
			ImGui::SetNextWindowSize(ImVec2((float)getWidth(), (float)getHeight()));
			ImGui::Begin(XorStr("##esp"), (bool*)true, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoBringToFrontOnFocus);
			isInTargetListRED = false;
			for (int i = 0; i < 100; i++)
			{

				if (v.box)
				{
					if (players[i].visible)
					{
						if (players[i].dist < 16000.0f)
							DrawBox(GREEN, players[i].boxMiddle, players[i].h_y, players[i].width, players[i].height); //BOX
						else
							DrawBox(ORANGE, players[i].boxMiddle, players[i].h_y, players[i].width, players[i].height); //BOX
					}
					else
					{
						DrawBox(RED, players[i].boxMiddle, players[i].h_y, players[i].width, players[i].height); //white if player not visible
					}
				}
				if (players[i].health > 0)
				{
					//targetyawvalue = players[i].targetyaw;
					std::string distance = std::to_string(players[i].dist / 39.62);
					distance = distance.substr(0, distance.find('.')) + "m (" + std::to_string(players[i].entity_team) + ")";

					float radardistance = (int)((players[i].LocalPlayerPosition, players[i].dist) / 39.62);
					
					//Radar Stuff
					if (minimapradar == true)
					{
							MiniMapRadar(players[i].EntityPosition, players[i].LocalPlayerPosition, players[i].localviewangle.y, radardistance, players[i].entity_team, players[i].targetyaw);
					}
					if (v.line)
						DrawLine(ImVec2((float)(getWidth() / 2), (float)getHeight()), ImVec2(players[i].b_x, players[i].b_y), BLUE, 1); //LINE FROM MIDDLE SCREEN
					
					
					if (v.healthbar)
					{
							if (players[i].dist < 16000.0f)
							{
								DrawSeerLikeHealth((players[i].b_x - (players[i].width / 2.0f) + ShieldWidthDisplay), (players[i].b_y - players[i].height - ShieldHeightDisplay), players[i].shield, players[i].maxshield, players[i].armortype, players[i].health); //health bar												
							}
					}
					if (mainradarmap == true)
					{
						worldToScreenMap(players[i].EntityPosition, players[i].entity_team, MainRadarMulti, players[i].name);
					}

					if (v.distance && v.name && !v.modelname)
					{
						isInTargetList = std::find(targetList.begin(), targetList.end(), players[i].name) != targetList.end();
						if (isInTargetList)
						{
							std::string combinedText = distance + " | " + players[i].name;

							// Calculate the total width of the text by combining distance and modelname
							float totalWidth = ImGui::CalcTextSize(players[i].modelname).x;

							// Calculate the starting position to center the text
							ImVec2 textPosition3Start = ImVec2(players[i].boxMiddle, (players[i].b_y + 1 - totalWidth / 2.0f, players[i].b_y + 5));

							// Draw the text on top of the background
							String(textPosition3Start, RED, combinedText.c_str());

							isInTargetListRED = true; // Set to true if at least one player in the list is both in the target list and still alive
						}
						else
						{
							std::string combinedText = distance.c_str() + std::string(" | ") + players[i].name;
							String(ImVec2(players[i].boxMiddle, (players[i].b_y + 1)), GREEN, combinedText.c_str());  // Combined text
						}
					}

					if (v.distance && !v.name && !v.modelname)
					{
						isInTargetList = std::find(targetList.begin(), targetList.end(), players[i].name) != targetList.end();
						if (isInTargetList)
						{
							std::string combinedText = distance + " | " + players[i].name;

							// Calculate the total width of the text by combining distance and modelname
							float totalWidth = ImGui::CalcTextSize(players[i].name).x;

							// Calculate the starting position to center the text
							ImVec2 textPosition3Start = ImVec2(players[i].boxMiddle, (players[i].b_y + 1 - totalWidth / 2.0f, players[i].b_y + 5));

							// Draw the text on top of the background
							String(textPosition3Start, RED, combinedText.c_str());

							isInTargetListRED = true; // Set to true if at least one player in the list is both in the target list and still alive
						}
						else
						{
							String(ImVec2(players[i].boxMiddle, (players[i].b_y + 1)), GREEN, distance.c_str());  //DISTANCE
						}
					}

					if (v.name && !v.distance && !v.modelname)
					{
						isInTargetList = std::find(targetList.begin(), targetList.end(), players[i].name) != targetList.end();
						if (isInTargetList)
						{
							std::string combinedText = players[i].name;

							// Calculate the total width of the text by combining distance and modelname
							float totalWidth = ImGui::CalcTextSize(players[i].modelname).x;

							// Calculate the starting position to center the text
							ImVec2 textPosition3Start = ImVec2(players[i].boxMiddle, (players[i].b_y + 1 - totalWidth / 2.0f, players[i].b_y + 5));

							// Draw the text on top of the background
							String(textPosition3Start, RED, combinedText.c_str());

							isInTargetListRED = true; // Set to true if at least one player in the list is both in the target list and still alive
						}
						else
						{
							String(ImVec2(players[i].boxMiddle, (players[i].b_y - players[i].height - NameHeightAjust)), GREEN, players[i].name);
						}
						
					}

					if (v.modelname && !v.distance && !v.name)
					{
						isInTargetList = std::find(targetList.begin(), targetList.end(), players[i].name) != targetList.end();
						if (isInTargetList)
						{
							std::stringstream nameStream;
							nameStream << players[i].name;
							std::string nameString = nameStream.str();

							std::stringstream modelnameStream;
							modelnameStream << players[i].modelname;
							std::string modelnameString = modelnameStream.str();

							// Combine the names and modelname
							std::string combinedText = nameString + "\n" + modelnameString;

							// Calculate the total width of the text by combining distance and modelname
							float totalWidth = ImGui::CalcTextSize(players[i].modelname).x;

							// Calculate the starting position to center the text
							ImVec2 textPosition3Start = ImVec2(players[i].boxMiddle, (players[i].b_y + 1 - totalWidth / 2.0f, players[i].b_y + 5));

							// Draw the text on top of the background
							String(textPosition3Start, RED, combinedText.c_str());

							isInTargetListRED = true; // Set to true if at least one player in the list is both in the target list and still alive
						}
						else
						{
							// Calculate the total width of the text by combining distance and modelname
							float totalWidth = ImGui::CalcTextSize(players[i].modelname).x;

							// Calculate the starting position to center the text
							ImVec2 textPosition3Start = ImVec2(players[i].boxMiddle, (players[i].b_y + 1 - totalWidth / 2.0f, players[i].b_y + 5));

							// Draw the background rectangle


							// Render the combined text
							String(textPosition3Start, GREEN, players[i].modelname);
						}
					}

					if (v.modelname && v.distance && v.name)
					{
						isInTargetList = std::find(targetList.begin(), targetList.end(), players[i].name) != targetList.end();
						isInTargetList = std::find(targetList.begin(), targetList.end(), players[i].name) != targetList.end();
						if (isInTargetList)
						{
							std::string combinedText = distance + " | " + players[i].name + "\n" + players[i].modelname;

							// Calculate the total width of the text by combining distance and modelname
							float totalWidth = ImGui::CalcTextSize(players[i].name).x;

							// Calculate the starting position to center the text
							ImVec2 textPosition3Start = ImVec2(players[i].boxMiddle, (players[i].b_y + 1 - totalWidth / 2.0f, players[i].b_y + 5));

							// Draw the text on top of the background
							String(textPosition3Start, RED, combinedText.c_str());

							isInTargetListRED = true; // Set to true if at least one player in the list is both in the target list and still alive
						}
						else
						{
							std::string combinedText = distance + " | " + players[i].name + "\n" + players[i].modelname;
							// Calculate the total width of the text by combining distance and modelname
							float totalWidth = ImGui::CalcTextSize(players[i].modelname).x;

							// Calculate the starting position to center the text
							ImVec2 textPosition3Start = ImVec2(players[i].boxMiddle, (players[i].b_y + 1 - totalWidth / 2.0f, players[i].b_y + 5));

							// Render the combined text
							String(textPosition3Start, GREEN, combinedText.c_str());
						}
					}

					if (v.modelname && v.distance && !v.name)
					{
						isInTargetList = std::find(targetList.begin(), targetList.end(), players[i].name) != targetList.end();
						if (isInTargetList)
						{
							std::string combinedText = distance + " " + players[i].name + "\n" + players[i].modelname;

							// Calculate the total width of the text by combining distance and modelname
							float totalWidth = ImGui::CalcTextSize(players[i].modelname).x;

							// Calculate the starting position to center the text
							ImVec2 textPosition3Start = ImVec2(players[i].boxMiddle, (players[i].b_y + 1 - totalWidth / 2.0f, players[i].b_y + 5));

							// Render the combined text
							String(textPosition3Start, RED, combinedText.c_str());

							isInTargetListRED = true; // Set to true if at least one player in the list is both in the target list and still alive
						}
						else
						{
							std::string combinedText = distance + "\n" + players[i].modelname;

							// Calculate the total width of the text by combining distance and modelname
							float totalWidth = ImGui::CalcTextSize(players[i].modelname).x;

							// Calculate the starting position to center the text
							ImVec2 textPosition3Start = ImVec2(players[i].boxMiddle, (players[i].b_y + 1 - totalWidth / 2.0f, players[i].b_y + 5));

							// Render the combined text
							String(textPosition3Start, GREEN, combinedText.c_str());
						}
					}

					if (v.modelname && !v.distance && v.name)
					{
						isInTargetList = std::find(targetList.begin(), targetList.end(), players[i].name) != targetList.end();
						if (isInTargetList)
						{
							std::stringstream nameStream;
							nameStream << players[i].name;
							std::string nameString = nameStream.str();

							std::stringstream modelnameStream;
							modelnameStream << players[i].modelname;
							std::string modelnameString = modelnameStream.str();

							// Combine the names and modelname
							std::string combinedText = nameString + "\n" + modelnameString;
							
							// Calculate the total width of the text by combining distance and modelname
							float totalWidth = ImGui::CalcTextSize(players[i].modelname).x;

							// Calculate the starting position to center the text
							ImVec2 textPosition3Start = ImVec2(players[i].boxMiddle, (players[i].b_y + 1 - totalWidth / 2.0f, players[i].b_y + 5));

							// Draw the text on top of the background
							String(textPosition3Start, RED, combinedText.c_str());

							isInTargetListRED = true; // Set to true if at least one player in the list is both in the target list and still alive
						}
						else
						{
							std::stringstream nameStream;
							nameStream << players[i].name;
							std::string nameString = nameStream.str();

							std::stringstream modelnameStream;
							modelnameStream << players[i].modelname;
							std::string modelnameString = modelnameStream.str();

							// Combine the names and modelname
							std::string combinedText = nameString + "\n" + modelnameString;
							
							// Calculate the total width of the text by combining distance and modelname
							float totalWidth = ImGui::CalcTextSize(players[i].modelname).x;

							// Calculate the starting position to center the text
							ImVec2 textPosition3Start = ImVec2(players[i].boxMiddle, (players[i].b_y + 1 - totalWidth / 2.0f, players[i].b_y + 5));

							// Render the combined text
							String(textPosition3Start, GREEN, combinedText.c_str());
						}
					}

					if (!v.modelname && !v.distance && !v.name)
					{
						isInTargetList = std::find(targetList.begin(), targetList.end(), players[i].name) != targetList.end();
						if (isInTargetList)
						{
							std::stringstream nameStream;
							nameStream << players[i].name;
							std::string nameString = nameStream.str();

							// Combine the names and modelname
							std::string combinedText = nameString;

							// Calculate the total width of the text by combining distance and modelname
							float totalWidth = ImGui::CalcTextSize(players[i].name).x;

							// Calculate the starting position to center the text
							ImVec2 textPosition3Start = ImVec2(players[i].boxMiddle, (players[i].b_y + 1 - totalWidth / 2.0f, players[i].b_y + 5));

							// Draw the text on top of the background
							String(textPosition3Start, RED, combinedText.c_str());

							isInTargetListRED = true; // Set to true if at least one player in the list is both in the target list and still alive
						}
					}
				}
			}

		ImGui::End();
		}
	}
}

int main(int argc, char** argv)
{
	add[0] = (uintptr_t)&check;
	add[1] = (uintptr_t)&aim;
	add[2] = (uintptr_t)&esp;
	add[3] = (uintptr_t)&aiming;
	add[4] = (uintptr_t)&g_Base;
	add[5] = (uintptr_t)&next2;
	add[6] = (uintptr_t)&players[0];
	add[7] = (uintptr_t)&valid;
	add[8] = (uintptr_t)&max_dist;
	add[9] = (uintptr_t)&item_glow;
	add[10] = (uintptr_t)&player_glow;
	add[11] = (uintptr_t)&aim_no_recoil;
	add[12] = (uintptr_t)&smooth;
	add[13] = (uintptr_t)&max_fov;
	add[14] = (uintptr_t)&bone;
	add[16] = (uintptr_t)&spectators;
	add[17] = (uintptr_t)&allied_spectators;
	add[18] = (uintptr_t)&glowr;
	add[19] = (uintptr_t)&glowg;
	add[20] = (uintptr_t)&glowb;
	add[21] = (uintptr_t)&firing_range;
	add[22] = (uintptr_t)&lightbackpack;
	add[23] = (uintptr_t)&medbackpack;
	add[24] = (uintptr_t)&heavybackpack;
	add[25] = (uintptr_t)&shieldupgrade1;
	add[26] = (uintptr_t)&shieldupgradehead1;
	add[27] = (uintptr_t)&accelerant;
	add[28] = (uintptr_t)&phoenix;
	add[29] = (uintptr_t)&healthlarge;
	add[30] = (uintptr_t)&healthsmall;
	add[31] = (uintptr_t)&shieldbattsmall;
	add[32] = (uintptr_t)&shieldbattlarge;
	add[33] = (uintptr_t)&sniperammo;
	add[34] = (uintptr_t)&heavyammo;
	add[35] = (uintptr_t)&optic1xhcog;
	add[36] = (uintptr_t)&lightammo;
	add[37] = (uintptr_t)&energyammo;
	add[38] = (uintptr_t)&shotgunammo;
	add[39] = (uintptr_t)&lasersight1;
	add[40] = (uintptr_t)&sniperammomag1;
	add[41] = (uintptr_t)&energyammomag1;
	add[42] = (uintptr_t)&stocksniper1;
	add[43] = (uintptr_t)&stockregular1;
	add[44] = (uintptr_t)&shielddown1;
	add[45] = (uintptr_t)&lightammomag1;
	add[46] = (uintptr_t)&heavyammomag1;
	add[47] = (uintptr_t)&optic2xhcog;
	add[48] = (uintptr_t)&opticholo1x;
	add[49] = (uintptr_t)&opticholo1x2x;
	add[50] = (uintptr_t)&opticthreat;
	add[51] = (uintptr_t)&optic3xhcog;
	add[52] = (uintptr_t)&optic2x4x;
	add[53] = (uintptr_t)&opticsniper6x;
	add[54] = (uintptr_t)&opticsniper4x8x;
	add[55] = (uintptr_t)&opticsniperthreat;
	add[56] = (uintptr_t)&suppressor1;
	add[57] = (uintptr_t)&turbo_charger;
	add[58] = (uintptr_t)&grenade_frag;
	add[59] = (uintptr_t)&grenade_arc_star;
	add[60] = (uintptr_t)&grenade_thermite;
	add[61] = (uintptr_t)&shotgunbolt1;
	add[62] = (uintptr_t)&weapon_kraber;
	add[63] = (uintptr_t)&weapon_mastiff;
	add[64] = (uintptr_t)&weapon_lstar;
	add[65] = (uintptr_t)&weapon_havoc;
	add[66] = (uintptr_t)&weapon_devotion;
	add[67] = (uintptr_t)&weapon_triple_take;
	add[68] = (uintptr_t)&weapon_flatline;
	add[69] = (uintptr_t)&weapon_hemlock;
	add[70] = (uintptr_t)&weapon_g7_scout;
	add[71] = (uintptr_t)&weapon_alternator;
	add[72] = (uintptr_t)&weapon_r99;
	add[73] = (uintptr_t)&weapon_prowler;
	add[74] = (uintptr_t)&weapon_volt;
	add[75] = (uintptr_t)&weapon_longbow;
	add[76] = (uintptr_t)&weapon_charge_rifle;
	add[77] = (uintptr_t)&weapon_spitfire;
	add[78] = (uintptr_t)&weapon_r301;
	add[79] = (uintptr_t)&weapon_eva8;
	add[80] = (uintptr_t)&weapon_peacekeeper;
	add[81] = (uintptr_t)&weapon_mozambique;
	add[82] = (uintptr_t)&weapon_wingman;
	add[83] = (uintptr_t)&weapon_p2020;
	add[84] = (uintptr_t)&weapon_re45;
	add[85] = (uintptr_t)&weapon_sentinel;
	add[86] = (uintptr_t)&weapon_bow;
	add[87] = (uintptr_t)&weapon_3030_repeater;
	add[88] = (uintptr_t)&weapon_rampage;
	add[89] = (uintptr_t)&weapon_car_smg;
	add[90] = (uintptr_t)&aimdist;
	add[91] = (uintptr_t)&itemglowbrightness;
	add[92] = (uintptr_t)&glowrviz;
	add[93] = (uintptr_t)&glowgviz;
	add[94] = (uintptr_t)&glowbviz;
	add[95] = (uintptr_t)&glowrknocked;
	add[96] = (uintptr_t)&glowgknocked;
	add[97] = (uintptr_t)&glowbknocked;
	add[98] = (uintptr_t)&bulletspeed;
	add[99] = (uintptr_t)&bulletgrav;
	add[100] = (uintptr_t)&weapon_nemesis;

	add[102] = (uintptr_t)&EntTeam;
	add[103] = (uintptr_t)&LocTeam;
	add[104] = (uintptr_t)&TDMToggle;
	add[105] = (uintptr_t)&onevone;
	add[106] = (uintptr_t)&shieldupgrade2;
	add[107] = (uintptr_t)&shieldupgradehead2;
	add[108] = (uintptr_t)&shieldupgrade3;
	add[109] = (uintptr_t)&shieldupgradehead3;
	add[110] = (uintptr_t)&shieldupgrade4;
	add[111] = (uintptr_t)&shieldupgradehead4;
	add[112] = (uintptr_t)&shielddown2;
	add[113] = (uintptr_t)&shielddown3;
	add[114] = (uintptr_t)&shielddown4;

	add[115] = (uintptr_t)&sniperammomag2;
	add[116] = (uintptr_t)&sniperammomag3;
	add[117] = (uintptr_t)&sniperammomag4;

	add[118] = (uintptr_t)&energyammomag2;
	add[119] = (uintptr_t)&energyammomag3;
	add[120] = (uintptr_t)&energyammomag4;

	add[121] = (uintptr_t)&lightammomag2;
	add[122] = (uintptr_t)&lightammomag3;
	add[123] = (uintptr_t)&lightammomag4;

	add[124] = (uintptr_t)&heavyammomag2;
	add[125] = (uintptr_t)&heavyammomag3;
	add[126] = (uintptr_t)&heavyammomag4;

	add[127] = (uintptr_t)&lasersight2;
	add[128] = (uintptr_t)&lasersight3;
	add[129] = (uintptr_t)&lasersight4;

	add[130] = (uintptr_t)&stocksniper2;
	add[131] = (uintptr_t)&stockregular2;

	add[132] = (uintptr_t)&stocksniper3;
	add[133] = (uintptr_t)&stockregular3;

	add[134] = (uintptr_t)&suppressor2;
	add[135] = (uintptr_t)&suppressor3;

	add[136] = (uintptr_t)&skull_piecer;
	add[137] = (uintptr_t)&hammer_point;
	add[138] = (uintptr_t)&disruptor_rounds;
	add[139] = (uintptr_t)&boosted_loader;
	add[140] = (uintptr_t)&shotgunbolt2;
	add[141] = (uintptr_t)&shotgunbolt3;
	add[142] = (uintptr_t)&shotgunbolt4;
	add[143] = (uintptr_t)&insidevaluegoggle;
	add[144] = (uintptr_t)&outlinesize;
	add[145] = (uintptr_t)&goldbackpack;
	add[146] = (uintptr_t)&shieldupgrade5;

	add[147] = (uintptr_t)&SuperKey;
	add[148] = (uintptr_t)&m_traversalProgress_min;
	add[149] = (uintptr_t)&m_traversalProgress_max;
	add[150] = (uintptr_t)&m_traversalProgress;

	add[151] = (uintptr_t)&LocalYAW; //float
	add[152] = (uintptr_t)&TargetYAW; //float
	add[153] = (uintptr_t)&TARGET_TEAMID; //int
	add[154] = (uintptr_t)&TEAM_TEAMID; //int

	add[155] = (uintptr_t)&TriggerBot; //triggerbot

	add[156] = (uintptr_t)&tapstrafeenable; //tap bot?
	add[157] = (uintptr_t)&lstarvalueid; //tap bot?
	add[158] = (uintptr_t)&PrintMapCords; //tap bot?
	add[159] = (uintptr_t)&veltest;
	add[160] = (uintptr_t)&CurrentWeaponADSZoom;

	add[161] = (uintptr_t)&mapid;

	add[162] = (uintptr_t)&TogglePrediction;
	add[163] = (uintptr_t)&AutoFire;
	add[164] = (uintptr_t)&PrintModelAndId;

	add[165] = (uintptr_t)&ScreenResINT;
	add[166] = (uintptr_t)&BoxEnable;
	add[167] = (uintptr_t)&NoNadeAim;
	add[168] = (uintptr_t)&PrintHeldID;


	printf(XorStr("GameVersion=v3.0.55.37 || EXE Ver 1.0.0 |-| Overlay Version by KrackerCo\n"));

	Overlay ov1 = Overlay();
	ov1.Start();
	printf(XorStr("Waiting for The Extra Ban .... Never Gonna Get it!\n"));
	while (check == 0xABCD)
	{
		if (IsKeyDown(VK_F4))
		{
			active = false;
			break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	if (active)
	{
		ready = true;
		printf(XorStr("Ready To Bring The Aim\n"));
	}

	while (active)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		if (IsKeyDown(VK_F4))
		{
			active = false;
		}

		//Load at start for saved settings to take effect. Need to save once to make the file. 
		for (static bool once = true; once; once = false) {
			std::ifstream config("Settings.txt");
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
		//Hotkey to Turn on and off Aimbot
		if (IsKeyDown(VK_F2) && k_f6 == 0)
		{
			k_f6 = 1;
			switch (aim)
			{
			case 0:
				aim = 1;
				break;
			case 1:
				aim = 2;
				break;
			case 2:
				aim = 0;
				break;
			default:
				break;
			}
		}
		else if (!IsKeyDown(VK_F2) && k_f6 == 1)
		{
			k_f6 = 0;
		}
		if (InputSelect == 1)
		{
			Keyboard = true;
			Gamepad = false;
		}
		else if (InputSelect == 2)
		{
			Keyboard = false;
			Gamepad = true;
		}
		if (Keyboard == 1 && NoNadeAim == 0)
		{
			if (IsKeyDown(aim_key) && toggleaim && !IsKeyDown(aim_key2) && !IsKeyDown(TriggerBotKey) && !IsKeyDown(StopAimBot) || controlleraiming2 && !controlleraiming)
			{
				aiming = true;
				max_fov = NonADS;
				TriggerBot = false;
			}

			else if (IsKeyDown(aim_key2) && toggleaim2 && !IsKeyDown(TriggerBotKey) && !IsKeyDown(StopAimBot) || controlleraiming)
			{
				aiming = true;
				max_fov = ADS;
				TriggerBot = false;
				//std::cout << "controlleraiming: " << controlleraiming << std::endl;
			}
			else if (IsKeyDown(TriggerBotKey) && !IsKeyDown(StopAimBot))
			{
				aiming = false;
				max_fov = ADS;
				TriggerBot = true;
			}
			else if (IsKeyDown(StopAimBot))
			{
				aiming = false;
				max_fov = ADS;
				TriggerBot = false;
			}
			else
			{
				aiming = false;
				max_fov = ADS;
				TriggerBot = false;

			}
			if (MainMapRadarToggle)
			{
				if (IsKeyDown(SpecLiveViewBttn) && !SpecLiveView_ins && ready)
				{
					SpecLiveView = !SpecLiveView;
					SpecLiveView_ins = true;
				}
				else if (!IsKeyDown(SpecLiveViewBttn) && SpecLiveView_ins)
				{
					SpecLiveView_ins = false;
				}

				if (IsKeyDown(0x4D) && mainradartoggle == 0)
				{
					mainradartoggle = 1;
					switch (mainradarmap)
					{
					case 0:
						mainradarmap = true;
						minimapradar = false;
						break;
					case 1:
						mainradarmap = false;
						minimapradar = true;
						break;
					}
				}

				else if (!IsKeyDown(0x4D) && mainradartoggle == 1)
				{
					mainradartoggle = 0;
				}
			}
		}
		else if (Gamepad == 1 && NoNadeAim == 0)
		{
			static bool isPressed = false;

			XINPUT_STATE state;
			ZeroMemory(&state, sizeof(XINPUT_STATE));

			DWORD result = XInputGetState(0, &state);

			if (result == ERROR_SUCCESS) {
				// Gamepad is connected

				// Check the state of the left and right triggers
				bool leftTriggerPressed = (state.Gamepad.bLeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD);
				bool rightTriggerPressed = (state.Gamepad.bRightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD);
				bool backButtonPressed = (state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK) != 0;

				if (backButtonPressed && !isPressed) {
					mainradarmap = !mainradarmap;
					minimapradar = !minimapradar;

					isPressed = true;  // Set the flag to true when button is pressed
				}
				else if (!backButtonPressed) {
					isPressed = false;  // Reset the flag when button is released
				}

				if (rightTriggerPressed && leftTriggerPressed) {
					aiming = true;
					max_fov = ADS;
				}
				else if (rightTriggerPressed && !leftTriggerPressed) {
					aiming = true;
					max_fov = NonADS;
				}
				else if (!rightTriggerPressed && leftTriggerPressed) {
					aiming = true;
					max_fov = ADS;
				}
				else
				{
					aiming = false;
					max_fov = ADS;
					TriggerBot = false;
				}
			}
		}

		if (IsKeyDown(TapBotEnableControl))
		{
			tapstrafeenable = true;
		}
		else
		{
			tapstrafeenable = false;
		}
		static bool hotkeyPressed = false;
		static int boneorg;
		if (IsKeyDown(aimathead))
		{
			if (!hotkeyPressed)
			{
				boneorg = bone;
				bone = 0;
				hotkeyPressed = true;
			}
		}
		else if (hotkeyPressed && !IsKeyDown(aimathead))
		{
			hotkeyPressed = false;
			bone = boneorg;
		}
		
		
		if (ScreenResINT == 0)
		{
			MainRadarMulti = 1;
		}
		if (ScreenResINT == 1)
		{
			MainRadarMulti = 1.333333;
		}

		//std::cout << "MainRadarMulti: " << MainRadarMulti << std::endl;

		//EXIT CODE/PANICBUTTON
		if (IsKeyDown(0x76))
		{
			glowrviz = 0;
			glowgviz = 0;
			glowbviz = 0;
			glowr = 0;
			glowg = 0;
			glowb = 0;
			glowrknocked = 0;
			glowgknocked = 0;
			glowbknocked = 0;
			esp = false;
			item_glow = false;
			player_glow = false;
			minimapradar = false;
			v.name = false;
			smooth = 300.0f;
			v.distance = false;
			v.healthbar = false;
			v.shieldbar = false;
			RenderInfoBar = false;
			SpectatorWatchingLivetoggle = false;
			MainMapRadarToggle = false;
		}
		if (IsKeyDown(0x7B))
		{
			std::ifstream config("Settings.txt");
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
	}
	ready = false;
	ov1.Clear();
	if (!use_nvidia)
		system(XorStr("taskkill /F /T /IM overlay_ap.exe")); //custom overlay process name
	return 0;
}




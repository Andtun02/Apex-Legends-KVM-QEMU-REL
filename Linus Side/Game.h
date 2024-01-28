#include "Math.h"
#include "offsets.h"
#include "memory.h"
#include "glowmode.h"

#define NUM_ENT_ENTRIES			(1 << 12)
#define ENT_ENTRY_MASK			(NUM_ENT_ENTRIES - 1)

typedef struct Bone
{
	uint8_t pad1[0xCC];
	float x;
	uint8_t pad2[0xC];
	float y;
	uint8_t pad3[0xC];
	float z;
}Bone;

struct GColor 
{
    float r, g, b;
};



struct Fade 
{
    int a, b;
    float c, d, e, f;
};

class Entity
{
public:
	uint64_t ptr;
	uint8_t buffer[0x3FF0];
	Vector getPosition();
	bool isDummy();
	bool isPlayer();
	bool isKnocked();
	bool isAlive();
	float lastVisTime();
	int getTeamId();
	int getHealth();
	int getShield();
	int getArmortype();
	int getMaxshield();
	bool isGlowing();
	bool isZooming();
	Vector getAbsVelocity();
	QAngle GetSwayAngles();
	QAngle GetViewAngles();
	Vector GetCamPos();
	QAngle GetRecoil();
	Vector GetViewAnglesV();
	float GetYaw();
	void enableGlow();
	void disableGlow();
	float lastCrossHairTime();
	void SetViewAngles(SVector angles);
	void SetViewAngles(QAngle& angles);
	Vector getBonePosition(int id);
	Vector getBonePositionByHitbox(int id);
	bool Observing(uint64_t entitylist);
	float GetCurrentFov();
	void get_name(uint64_t g_Base, uint64_t index, char* name);
	void get_modelname(uint64_t g_Base, char* modelname);
};

class Item
{
public:
	uint64_t ptr;
	uint8_t buffer[0x3FF0];
	Vector getPosition();
	bool isItem();
	bool isBox();
	bool isTrap();
	bool isGlowing();
	void enableGlow();
	void disableGlow();
	void BlueGlow();
};



class WeaponXEntity
{
public:
	void update(uint64_t LocalPlayer);
	float get_projectile_speed();
	float get_projectile_gravity();
	float get_zoom_fov();
	int get_ammo();

private:
	float projectile_scale;
	float projectile_speed;
	float zoom_fov;
	int ammo;
};

struct ClientClass {
	uint64_t pCreateFn;
	uint64_t pCreateEventFn;
	uint64_t pNetworkName;
	uint64_t pRecvTable;
	uint64_t pNext;
	uint32_t ClassID;
	uint32_t ClassSize;
};

Entity getEntity(uintptr_t ptr);
Item getItem(uintptr_t ptr);

bool WorldToScreen(Vector from, float* m_vMatrix, int targetWidth, int targetHeight, Vector& to);
float CalculateFov(Entity& from, Entity& target);
QAngle CalculateBestBoneAim(Entity& from, uintptr_t target, float max_fov);
void get_class_name(uint64_t entity_ptr, char* out_str);
void charge_rifle_hack(uint64_t entity_ptr);
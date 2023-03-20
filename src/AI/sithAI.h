#ifndef _SITHAI_H
#define _SITHAI_H

#include <stdint.h>
#include "types.h"
#include "globals.h"

#include "World/sithThing.h" // sithActor struct def

#define sithAI_Startup_ADDR (0x004E9AA0)
#define sithAI_Shutdown_ADDR (0x004E9B90)
#define sithAI_Open_ADDR (0x004E9BD0)
#define sithAI_Close_ADDR (0x004E9C00)
#define sithAI_NewEntry_ADDR (0x004E9CB0)
#define sithAI_FreeEntry_ADDR (0x004E9D80)
#define sithAI_TickAll_ADDR (0x004E9E20)
#define sithAI_TickActor_ADDR (0x004E9E90)
#define sithAI_SetActorFireTarget_ADDR (0x004E9F80)
#define sithAI_RegisterCommand_ADDR (0x004EA0A0)
#define sithAI_FindCommand_ADDR (0x004EA110)
#define sithAI_PrintThings_ADDR (0x004EA190)
#define sithAI_PrintThingStatus_ADDR (0x004EA230)
#define sithAI_LoadThingActorParams_ADDR (0x004EA3F0)
#define sithAI_idkframesalloc_ADDR (0x004EA520)
#define sithAI_Tick_ADDR (0x004EA5E0)
#define sithAI_sub_4EA630_ADDR (0x004EA630)
#define sithAI_idk_msgarrived_target_ADDR (0x004EA890)
#define sithAI_SetLookFrame_ADDR (0x004EAB80)
#define sithAI_SetMoveThing_ADDR (0x004EAC90)
#define sithAI_Jump_ADDR (0x004EACF0)
#define sithAI_sub_4EAD60_ADDR (0x004EAD60)
#define sithAI_sub_4EAF40_ADDR (0x004EAF40)
#define sithAI_CheckSightThing_ADDR (0x004EB090)
#define sithAI_sub_4EB300_ADDR (0x004EB300)
#define sithAI_physidk_ADDR (0x004EB4B0)
#define sithAI_sub_4EB640_ADDR (0x004EB640)
#define sithAI_FirstThingInView_ADDR (0x004EB790)
#define sithAI_sub_4EB860_ADDR (0x004EB860)
#define sithAI_SetRandomThingLook_ADDR (0x004EB880)
#define sithAI_RandomFireVector_ADDR (0x004EB920)
#define sithAI_RandomRotationVector_ADDR (0x004EB9A0)
#define sithAI_FireWeapon_ADDR (0x004EBA10)
#define sithAI_GetThingsInView_ADDR (0x004EBE80)
#define sithAI_CanDetectSightThing_ADDR (0x004EC140)

typedef struct sithThing sithThing;

typedef struct sithAICommand
{
    char name[32];
    sithAICommandFunc_t func;
    int param1;
    int param2;
    int param3;
} sithAICommand;

enum SITHAI_MODE_E
{
    SITHAI_MODE_MOVING = 0x01,
    SITHAI_MODE_ATTACKING = 0x02,
    SITHAI_MODE_SEARCHING = 0x04,
    SITHAI_MODE_TURNING = 0x08,
    SITHAI_MODE_HASDEST = 0x10,
    SITHAI_MODE_TOUGHSKIN= 0x20,
    SITHAI_MODE_NO_CHECK_FOR_CLIFF = 0x40,
    SITHAI_MODE_UNK80 = 0x80,
    SITHAI_MODE_UNK100 = 0x100,
    SITHAI_MODE_ACTIVE = 0x200,
    SITHAI_MODE_TARGET_VISIBLE = 0x400,
    SITHAI_MODE_FLEEING = 0x800,
    SITHAI_MODE_SLEEPING = 0x1000,
    SITHAI_MODE_DISABLED = 0x2000,
    SITHAI_MODE_WANTALLEVENTS = 0x10000, // Jones
    SITHAI_MODE_WALLCRAWLING = 0x200000, // Jones probably
    SITHAI_MODE_NOCHASING = 0x2000000, // Jones
    SITHAI_MODE_ARMOREDSKIN = 0x8000000, // Jones
};

enum SITHAI_EVENT_E
{
    SITHAI_EVENTHITSECTOR = 0x1,
    SITHAI_EVENT_2 = 0x2,
    SITHAI_EVENTTOUCHED = 0x4,
    SITHAI_EVENT_8 = 0x8,
    SITHAI_EVENT_10 = 0x10,
    SITHAI_EVENT_20 = 0x20,
    SITHAI_EVENTMOVETARGETCHANGED = 0x40,
    SITHAI_EVENT_80 = 0x80,
    SITHAI_EVENTMODECHANGED = 0x100,
    SITHAI_EVENTHITWALL = 0x200,
    SITHAI_EVENTHITCLIFF = 0x400,
    SITHAI_EVENTGOALREACHED = 0x800,
    SITHAI_EVENTTARGETED = 0x1000,
    SITHAI_EVENTGOALSET = 0x2000,
    SITHAI_EVENTFIRE = 0x4000,
    SITHAI_EVENT_8000 = 0x8000,
    SITHAI_EVENTPREFIRE = 0x10000,
    SITHAI_EVENTPOSTFIRE = 0x20000,
    SITHAI_EVENT_40000 = 0x40000,
    SITHAI_EVENTGOALUNREACHABLE = 0x80000
};

extern int sithAI_bOpened;
extern sithActor sithAI_actors[256];
extern int sithAI_inittedActors;

int sithAI_Startup();
void sithAI_Shutdown();
int sithAI_Open();
void sithAI_Close();
void sithAI_NewEntry(sithThing *thing);
void sithAI_FreeEntry(sithThing *thing);
void sithAI_TickAll();
void sithAI_TickActor(sithActor *actor);
void sithAI_SetActorFireTarget(sithActor *actor, int a2, intptr_t a3);
void sithAI_RegisterCommand(char *cmdName, void *func, int param1, int param2, int param3);
sithAICommand* sithAI_FindCommand(const char *cmdName);
int sithAI_PrintThings();
int sithAI_PrintThingStatus(int a1, char *idxStr);
int sithAI_LoadThingActorParams(stdConffileArg *arg, sithThing *thing, int param);
void sithAI_idkframesalloc(sithThing *a2, sithThing *a3, rdVector3 *a4);
void sithAI_Tick(sithThing *thing, float deltaSeconds);
void sithAI_sub_4EA630(sithActor *actor, float deltaSeconds);
void sithAI_idk_msgarrived_target(sithActor *actor, float deltaSeconds);
void sithAI_SetLookFrame(sithActor *actor, rdVector3 *lookPos);
void sithAI_SetMoveThing(sithActor *actor, rdVector3 *movePos, float moveSpeed);
void sithAI_Jump(sithActor *actor, rdVector3 *pos, float vel);
void sithAI_sub_4EAD60(sithActor *actor);
void sithAI_sub_4EAF40(sithActor *actor);
int sithAI_CheckSightThing(sithThing* thing, rdVector3* targetPosition, sithThing* targetThing, float fov, float maxDistance, float unused, rdVector3* targetErrorDir, float* targetDistance);
int sithAI_sub_4EB300(sithThing *a3, rdVector3 *a4, rdVector3 *arg8, float argC, float arg10, float a7, rdVector3 *a5, float *a8);
int sithAI_physidk(sithActor *a7, rdVector3 *a4, int *arg8);
int sithAI_sub_4EB640(sithActor *actor, rdVector3 *a4, sithSector *a2, int *out);
int sithAI_FirstThingInView(sithSector *sector, rdMatrix34 *out, float autoaimFov, float autoaimMaxDist, int a5, sithThing **thingList, int a7, float a8);
int sithAI_sub_4EB860(int a1, float a2);
void sithAI_SetRandomThingLook(rdMatrix34 *a1, sithThing *a2, rdVector3 *a3, float a4);
void sithAI_RandomFireVector(rdVector3 *out, float magnitude);
void sithAI_RandomRotationVector(rdVector3 *out);
int sithAI_FireWeapon(sithActor *actor, float a2, float a3, float a4, float a5, int bAltFire, int a7);
void sithAI_GetThingsInView(sithSector *a1, rdMatrix34 *a2, float a3);
int sithAI_CanDetectSightThing(sithActor* actor, sithThing* targetThing, float distance);

//static int (*sithAI_Startup)() = (void*)sithAI_Startup_ADDR;
//static int (*sithAI_LoadThingActorParams)(stdConffileArg *arg, sithThing *thing, int param) = (void*)sithAI_LoadThingActorParams_ADDR;
//static void (*sithAI_FreeEntry)(sithThing *thing) = (void*)sithAI_FreeEntry_ADDR;
//static void (*sithAI_Tick)(sithThing *thing, float deltaSeconds) = (void*)sithAI_Tick_ADDR;
//static void (*sithAI_TickActor)(sithActor *actor) = (void*)sithAI_TickActor_ADDR;
//static void (*sithAI_TickAll)() = (void*)sithAI_TickAll_ADDR;
//static void (*sithAI_SetActorFireTarget)(sithActor *a1, int a2, int a3) = (void*)sithAI_SetActorFireTarget_ADDR;
//static int (*sithAI_FirstThingInView)(sithSector *a1, rdMatrix34 *a2, float a3, float a4, int a5, sithThing **a6, int a7, float a8) = (void*)sithAI_FirstThingInView_ADDR;

//static int (*sithAI_FireWeapon)(sithActor *a1, float a2, float a3, float a4, float a5, int a6, int a7) = (void*)sithAI_FireWeapon_ADDR;
//static int (*sithAI_SetMoveThing)(sithActor *actor, rdVector3 *movePos, float moveSpeed) = (void*)sithAI_SetMoveThing_ADDR;
//static void (*sithAI_Jump)(sithActor *actor, rdVector3 *a2, float a3) = (void*)sithAI_Jump_ADDR;
//static void (*sithAI_SetLookFrame)(sithActor *actor, rdVector3 *lookPos) = (void*)sithAI_SetLookFrame_ADDR;

//static void (*sithAI_sub_4EA630)(sithActor *actor, float deltaSeconds) = (void*)sithAI_sub_4EA630_ADDR;
//static void (*sithAI_sub_4EAF40)(sithActor *a1) = (void*)sithAI_sub_4EAF40_ADDR;
//static int (*sithAI_sub_4EB300)(sithThing *a3, rdVector3 *a4, rdVector3 *arg8, float argC, float arg10, float a7, rdVector3 *a5, float *a8) = (void*)sithAI_sub_4EB300_ADDR;
//static void (*sithAI_idk_msgarrived_target)(sithActor *actor, float deltaSeconds) = (void*)sithAI_idk_msgarrived_target_ADDR;
//static void (*sithAI_sub_4EAD60)(sithActor *actor) = (void*)sithAI_sub_4EAD60_ADDR;
//static int (*sithAI_physidk)(sithActor *a7, rdVector3 *a4, int *arg8) = (void*)sithAI_physidk_ADDR;
//static int (*sithAI_sub_4EB640)(sithActor *arg0, rdVector3 *a4, sithSector *a2, int *argC) = (void*)sithAI_sub_4EB640_ADDR;
//static int (*sithAI_CheckSightThing)(sithThing *a3, rdVector3 *a4, sithThing *arg8, float argC, float arg10, float a6, rdVector3 *a5, float *a8) = (void*)sithAI_CheckSightThing_ADDR;

#endif // _SITHAI_H

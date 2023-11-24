
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	fb_doorSM.state = ST_INIT;
	fb_ledSM.timer = 0;
}

void _CYCLIC ProgramCyclic(void)
{
	
	
	FB_DoorSM(&fb_doorSM);
	fb_ledSM.state = fb_doorSM.state;
	fb_driveSM.speed = fb_doorSM.speed;
	FB_LedSM(&fb_ledSM);
	FB_DriveSM(&fb_driveSM);
	
}

void _EXIT ProgramExit(void)
{
	fb_driveSM.command = 0;
	FB_DriveSM(&fb_driveSM);
}


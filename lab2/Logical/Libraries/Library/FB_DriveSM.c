
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_DriveSM(struct FB_DriveSM* inst)
{
	UINT st = inst->state & 0x6F;
	
	if (!inst->enable)
	{
		inst->command = CMD_SHUTDOWN;
	}
	else
	{
		switch(st)
		{
			case ST_DISABLE:
				inst->command = CMD_SHUTDOWN;
				break;
			case ST_SWITCH_ON:
				inst->command = CMD_SWITCH_ON;
				break;
			case ST_READY:
				inst->command = CMD_ENABLE;
				break;
		}
	}
}

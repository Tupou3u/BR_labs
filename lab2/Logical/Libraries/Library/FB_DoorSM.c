
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
void FB_DoorSM(struct FB_DoorSM* inst)
{	
	switch(inst->state)
	{
		case ST_INIT:
			inst->state = ST_UNKNOWN;
			break;
		case ST_UNKNOWN:
			if (inst->sw0 == 1 & inst->direction == 0)
			{
				inst->state = ST_OPEN;
			}
			else if (inst->sw3 == 1 & inst->direction == 1)
			{
				inst->state = ST_CLOSE;
			}
			
			inst->speed = (inst->direction < 1) ? StartSpeed : -1*StartSpeed;
			break;
		case ST_OPEN:
			if (inst->direction == 1)
			{
				inst->state = ST_ACC_NEG;
			}
			
			inst->speed = 0;
			break;
		case ST_CLOSE:
			if (inst->direction == 0)
			{
				inst->state = ST_ACC_POS;
			}
			
			inst->speed = 0;
			break;
		case ST_ACC_POS:
			if (inst->sw2 == 0)
			{
				inst->state = ST_POS;
			}
			else if (inst->direction == 1)
			{
				inst->state = ST_DEC_NEG;
			}
			
			inst->speed = HighSpeed;
			break;
		case ST_ACC_NEG:
			if (inst->sw1 == 1)
			{
				inst->state = ST_NEG;
			}
			else if (inst->direction == 0)
			{
				inst->state = ST_DEC_POS;
			}
			
			inst->speed = -1*HighSpeed;
			break;
		case ST_POS:
			if (inst->sw1 == 0)
			{
				inst->state = ST_DEC_POS;
			}
			else if (inst->direction == 1)
			{
				inst->state = ST_NEG;
			}
			
			inst->speed = NormalSpeed;
			break;
		case ST_NEG:
			if (inst->sw2 == 1)
			{
				inst->state = ST_DEC_NEG;
			}
			else if(inst->direction == 0)
			{
				inst->state = ST_POS;
			}
			
			inst->speed = -1*NormalSpeed;
			break;
		case ST_DEC_POS:
			if (inst->sw0 == 0)
			{
				inst->state = ST_OPEN;
			}
			else if (inst->direction == 1)
			{
				inst->state = ST_ACC_NEG;
			}
			
			inst->speed = LowSpeed;
			break;
		case ST_DEC_NEG:
			if (inst->sw3 == 1)
			{
				inst->state = ST_CLOSE;
			}
			else if(inst->direction == 0)
			{
				inst->state = ST_ACC_POS;
			}
			
			inst->speed = -1*LowSpeed;
			break;
	}
}

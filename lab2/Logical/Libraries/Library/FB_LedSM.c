
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
void FB_LedSM(struct FB_LedSM* inst)
{
	switch(inst->state)
	{	
		case ST_INIT:
			inst->led0 = 0;
			inst->led1 = 0;
			inst->led2 = 0;
			inst->led3 = 0;
			break;
		case ST_UNKNOWN:
			if (inst->timer > 500)
			{
				inst->led0 = !(inst->led0);
				inst->led1 = !(inst->led1);
				inst->led2 = !(inst->led2);
				inst->led3 = !(inst->led3);
				inst->timer = 0;
			}
			break;
		case ST_OPEN:
			inst->led0 = 0;
			inst->led1 = 0;
			inst->led2 = 0;
			inst->led3 = 0;
			break;
		case ST_CLOSE:
			inst->led0 = 1;
			inst->led1 = 1;
			inst->led2 = 1;
			inst->led3 = 1;
			break;
		case ST_ACC_POS:
			inst->led0 = 1;
			inst->led1 = 1;
			if (inst->timer > 500)
			{
				inst->led2 = !(inst->led2);
				inst->timer = 0;
			}
			
			inst->led3 = 0;
			break;
		case ST_ACC_NEG:
			inst->led0 = 1;
			if (inst->timer > 500)
			{
				inst->led1 = !(inst->led1);
				inst->timer = 0;
			}
			
			inst->led2 = 0;
			inst->led3 = 0;
			break;
		case ST_POS:
			inst->led0 = 1;
			if (inst->timer > 500)
			{
				inst->led1 = !(inst->led1);
				inst->timer = 0;
			}
			inst->led2 = 0;
			inst->led3 = 0;
			break;
		case ST_NEG:
			inst->led0 = 1;
			inst->led1 = 1;
			if (inst->timer > 500)
			{
				inst->led2 = !(inst->led2);
				inst->timer = 0;
			}
			inst->led3 = 0;
			break;
		case ST_DEC_POS:
			if (inst->timer > 500)
			{
				inst->led0 = !(inst->led0);
				inst->timer = 0;
			}
			inst->led1 = 0;
			inst->led2 = 0;
			inst->led3 = 0;
			break;
		case ST_DEC_NEG:
			inst->led0 = 1;
			inst->led1 = 1;
			inst->led2 = 1;
			if (inst->timer > 500)
			{
				inst->led3 = !(inst->led3);
				inst->timer = 0;
			}
			break;
	}
	inst->timer++;
	
}

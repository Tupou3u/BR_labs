
TYPE
	states : 
		(
		ST_INIT,
		ST_UNKNOWN,
		ST_OPEN,
		ST_CLOSE,
		ST_ACC_POS,
		ST_ACC_NEG,
		ST_POS,
		ST_NEG,
		ST_DEC_POS,
		ST_DEC_NEG
		);
	drivestates : 
		(
		ST_SWITCH := 3,
		ST_RDY := 7,
		ST_DIS := 17
		);
END_TYPE

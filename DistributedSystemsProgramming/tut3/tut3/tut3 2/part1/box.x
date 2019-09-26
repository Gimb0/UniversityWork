

struct dimensions
{
	float length;
	float width;
	float height;
};

struct box_results
{
	float surface;
	float volume;
};

program RPC_BOX
{
	/* Version 1 definition */
	version BOXVERSION1
	{
		box_results BOX_CALC(dimensions) = 1;
	} = 1;
} = 0x40049453;

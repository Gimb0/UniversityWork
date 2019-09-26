#include "box.h"

/* 
 * Purpose: Calculate surface area of box.
 * Input: length, width, height as float
*/ 
float surface(float l, float w, float h)
{
	return 2*(l*w + l*h + w*h);
}

/* 
 * Purpose: Calculate volume of box.
 * Input: length, width, height as float
*/ 
float volume(float l, float w, float h)
{
	return l*w*h;
}

/*
 * Purpose: caller function to cacl functions
 * Input: dimesions struct(defined in box.h) 
*/ 
box_results * box_calc_1_svc(dimensions *dims, struct svc_req *rqstp)
{
	static box_results res;
	res.surface = surface(dims->length, dims->width, dims->height);
	res.volume = volume(dims->length, dims->width, dims->height);

	return &res;
}

/*
 * box_2_main.c
 * 
 * Client side code
 *
 * Purpose: using remote procedure calls it
 * performs calculations on boxes
 *
 * rpcgen box.x
 * cc box_main.c box_clnt.c box_xdr.x -o box_client
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "box_2.h"

void print_box(float l, float w, float h, float sa, float v)
{
	printf("A box with dimensions %f x %f x %f\n", l, w, h);
	printf("Has a surface area %f\n", sa);
	printf("And volume %f\n", v);

	return;
}

void print_mail(float v, float m)
{
	printf("A box with volume: %f\nHas a mass of %f\n", v, m);
	return;
}

int main(int argc, char* argv[])
{
	CLIENT *c_handle;
	dimensions dims;
	box_results *res;
	mail_dims *mail_res;

	/*
	 * Ensure the program gets the required arguments
	*/ 
	if (argc != 5)
	{
		printf("Usage: %s remote_host length width height\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	dims.length = atof(argv[2]);
	dims.width = atof(argv[3]);
	dims.height = atof(argv[4]);

	/*
	 * Create client handle to connect to RPCs
	*/ 
	c_handle = clnt_create(argv[1], RPC_BOX, BOXVERSION2, "udp");
	if (c_handle == NULL)
	{
		clnt_pcreateerror(argv[1]);
		exit(EXIT_FAILURE);
	}

	res = box_calc_2(&dims, c_handle);
	if (res == NULL) {
		clnt_perror(c_handle, argv[1]);
		exit(EXIT_FAILURE);
	}

	print_box(dims.length, dims.width, dims.height, res->surface, 
		  res->volume);

	mail_res = mail_calc_2(mail_res, c_handle);
	if(mail_res == NULL)
	{
		clnt_perror(c_handle, argv[1]);
		exit(EXIT_FAILURE);
	}

	print_mail(mail_res->volume, mail_res->mass);

	clnt_destroy(c_handle);

	return 0;
}

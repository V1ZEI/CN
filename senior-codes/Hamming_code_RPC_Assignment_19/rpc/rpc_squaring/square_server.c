/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "square.h"

square_out *
squareproc_1_svc(square_in *inp, struct svc_req *rqstp)
{
	static square_out out;

	out.res1=inp->arg1*inp->arg1;

	return &out;
}

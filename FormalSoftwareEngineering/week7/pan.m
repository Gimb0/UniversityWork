#define rand	pan_rand
#define pthread_equal(a,b)	((a)==(b))
#if defined(HAS_CODE) && defined(VERBOSE)
	#ifdef BFS_PAR
		bfs_printf("Pr: %d Tr: %d\n", II, t->forw);
	#else
		cpu_printf("Pr: %d Tr: %d\n", II, t->forw);
	#endif
#endif
	switch (t->forw) {
	default: Uerror("bad forward move");
	case 0:	/* if without executable clauses */
		continue;
	case 1: /* generic 'goto' or 'skip' */
		IfNotBlocked
		_m = 3; goto P999;
	case 2: /* generic 'else' */
		IfNotBlocked
		if (trpt->o_pm&1) continue;
		_m = 3; goto P999;

		 /* CLAIM never_0 */
	case 3: // STATE 1 - q3.pml.nvr:6 - [(!(((P._p==cs)||(Q._p==cs))))] (0:0:0 - 1)
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported1 = 0;
			if (verbose && !reported1)
			{	int nn = (int) ((Pclaim *)pptr(0))->_n;
				printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported1 = 1;
				fflush(stdout);
		}	}
#else
		{	static int reported1 = 0;
			if (verbose && !reported1)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported1 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[2][1] = 1;
		if (!( !(((((int)((P0 *)Pptr(f_pid(0)))->_p)==8)||(((int)((P1 *)Pptr(f_pid(1)))->_p)==3)))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 4: // STATE 6 - q3.pml.nvr:8 - [-end-] (0:0:0 - 1)
		
#if defined(VERI) && !defined(NP)
#if NCLAIMS>1
		{	static int reported6 = 0;
			if (verbose && !reported6)
			{	int nn = (int) ((Pclaim *)pptr(0))->_n;
				printf("depth %ld: Claim %s (%d), state %d (line %d)\n",
					depth, procname[spin_c_typ[nn]], nn, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported6 = 1;
				fflush(stdout);
		}	}
#else
		{	static int reported6 = 0;
			if (verbose && !reported6)
			{	printf("depth %d: Claim, state %d (line %d)\n",
					(int) depth, (int) ((Pclaim *)pptr(0))->_p, src_claim[ (int) ((Pclaim *)pptr(0))->_p ]);
				reported6 = 1;
				fflush(stdout);
		}	}
#endif
#endif
		reached[2][6] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC Q */
	case 5: // STATE 1 - ./q3.pml:21 - [wantQ = 1] (0:0:1 - 1)
		IfNotBlocked
		reached[1][1] = 1;
		(trpt+1)->bup.oval = ((int)now.wantQ);
		now.wantQ = 1;
#ifdef VAR_RANGES
		logval("wantQ", ((int)now.wantQ));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 6: // STATE 2 - ./q3.pml:22 - [(((wantP==0)||(last==1)))] (0:0:0 - 1)
		IfNotBlocked
		reached[1][2] = 1;
		if (!(((((int)now.wantP)==0)||(((int)now.last)==1))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 7: // STATE 3 - ./q3.pml:23 - [wantQ = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[1][3] = 1;
		(trpt+1)->bup.oval = ((int)now.wantQ);
		now.wantQ = 0;
#ifdef VAR_RANGES
		logval("wantQ", ((int)now.wantQ));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 8: // STATE 4 - ./q3.pml:24 - [last = 2] (0:0:1 - 1)
		IfNotBlocked
		reached[1][4] = 1;
		(trpt+1)->bup.oval = ((int)now.last);
		now.last = 2;
#ifdef VAR_RANGES
		logval("last", ((int)now.last));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 9: // STATE 8 - ./q3.pml:26 - [-end-] (0:0:0 - 1)
		IfNotBlocked
		reached[1][8] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC P */
	case 10: // STATE 3 - ./q3.pml:10 - [(0)] (0:0:0 - 1)
		IfNotBlocked
		reached[0][3] = 1;
		if (!(0))
			continue;
		_m = 3; goto P999; /* 0 */
	case 11: // STATE 6 - ./q3.pml:12 - [wantP = 1] (0:0:1 - 3)
		IfNotBlocked
		reached[0][6] = 1;
		(trpt+1)->bup.oval = ((int)now.wantP);
		now.wantP = 1;
#ifdef VAR_RANGES
		logval("wantP", ((int)now.wantP));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 12: // STATE 7 - ./q3.pml:13 - [(((wantQ==0)||(last==2)))] (0:0:0 - 1)
		IfNotBlocked
		reached[0][7] = 1;
		if (!(((((int)now.wantQ)==0)||(((int)now.last)==2))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 13: // STATE 8 - ./q3.pml:14 - [wantP = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[0][8] = 1;
		(trpt+1)->bup.oval = ((int)now.wantP);
		now.wantP = 0;
#ifdef VAR_RANGES
		logval("wantP", ((int)now.wantP));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 14: // STATE 9 - ./q3.pml:15 - [last = 1] (0:0:1 - 1)
		IfNotBlocked
		reached[0][9] = 1;
		(trpt+1)->bup.oval = ((int)now.last);
		now.last = 1;
#ifdef VAR_RANGES
		logval("last", ((int)now.last));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 15: // STATE 13 - ./q3.pml:17 - [-end-] (0:0:0 - 1)
		IfNotBlocked
		reached[0][13] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */
	case  _T5:	/* np_ */
		if (!((!(trpt->o_pm&4) && !(trpt->tau&128))))
			continue;
		/* else fall through */
	case  _T2:	/* true */
		_m = 3; goto P999;
#undef rand
	}


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

		 /* PROC P */
	case 3: // STATE 1 - max.pml:4 - [((a>=b))] (8:0:1 - 1)
		IfNotBlocked
		reached[0][1] = 1;
		if (!((((P0 *)_this)->a>=((P0 *)_this)->b)))
			continue;
		/* merge: max = a(8, 2, 8) */
		reached[0][2] = 1;
		(trpt+1)->bup.oval = ((P0 *)_this)->max;
		((P0 *)_this)->max = ((P0 *)_this)->a;
#ifdef VAR_RANGES
		logval("P:max", ((P0 *)_this)->max);
#endif
		;
		/* merge: .(goto)(8, 6, 8) */
		reached[0][6] = 1;
		;
		/* merge: assert(( ((a>=b)) -> ((max==a)) : ((max==b)) ))(8, 7, 8) */
		reached[0][7] = 1;
		spin_assert(( ((((P0 *)_this)->a>=((P0 *)_this)->b)) ? ((((P0 *)_this)->max==((P0 *)_this)->a)) : ((((P0 *)_this)->max==((P0 *)_this)->b)) ), "( ((a>=b)) ? ((max==a)) : ((max==b)) )", II, tt, t);
		_m = 3; goto P999; /* 3 */
	case 4: // STATE 3 - max.pml:5 - [((b>=a))] (8:0:1 - 1)
		IfNotBlocked
		reached[0][3] = 1;
		if (!((((P0 *)_this)->b>=((P0 *)_this)->a)))
			continue;
		/* merge: max = b(8, 4, 8) */
		reached[0][4] = 1;
		(trpt+1)->bup.oval = ((P0 *)_this)->max;
		((P0 *)_this)->max = ((P0 *)_this)->b;
#ifdef VAR_RANGES
		logval("P:max", ((P0 *)_this)->max);
#endif
		;
		/* merge: .(goto)(8, 6, 8) */
		reached[0][6] = 1;
		;
		/* merge: assert(( ((a>=b)) -> ((max==a)) : ((max==b)) ))(8, 7, 8) */
		reached[0][7] = 1;
		spin_assert(( ((((P0 *)_this)->a>=((P0 *)_this)->b)) ? ((((P0 *)_this)->max==((P0 *)_this)->a)) : ((((P0 *)_this)->max==((P0 *)_this)->b)) ), "( ((a>=b)) ? ((max==a)) : ((max==b)) )", II, tt, t);
		_m = 3; goto P999; /* 3 */
	case 5: // STATE 7 - max.pml:7 - [assert(( ((a>=b)) -> ((max==a)) : ((max==b)) ))] (0:8:0 - 3)
		IfNotBlocked
		reached[0][7] = 1;
		spin_assert(( ((((P0 *)_this)->a>=((P0 *)_this)->b)) ? ((((P0 *)_this)->max==((P0 *)_this)->a)) : ((((P0 *)_this)->max==((P0 *)_this)->b)) ), "( ((a>=b)) ? ((max==a)) : ((max==b)) )", II, tt, t);
		_m = 3; goto P999; /* 0 */
	case 6: // STATE 8 - max.pml:8 - [-end-] (0:0:0 - 1)
		IfNotBlocked
		reached[0][8] = 1;
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


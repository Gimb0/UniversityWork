	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* CLAIM never_0 */
;
		;
		
	case 4: // STATE 6
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC Q */

	case 5: // STATE 1
		;
		now.wantQ = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 7: // STATE 3
		;
		now.wantQ = trpt->bup.oval;
		;
		goto R999;

	case 8: // STATE 4
		;
		now.last = trpt->bup.oval;
		;
		goto R999;

	case 9: // STATE 8
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC P */
;
		;
		
	case 11: // STATE 6
		;
		now.wantP = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 13: // STATE 8
		;
		now.wantP = trpt->bup.oval;
		;
		goto R999;

	case 14: // STATE 9
		;
		now.last = trpt->bup.oval;
		;
		goto R999;

	case 15: // STATE 13
		;
		p_restor(II);
		;
		;
		goto R999;
	}


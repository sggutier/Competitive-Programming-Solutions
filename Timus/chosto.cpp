class program {

	define derecha() {
		iterate(3)
			turnleft() ;
	}

	define vuelta() {
		iterate(2)
			turnleft() ;
	}

	void paso() {
		if( frontIsClear ) {
			move() ;
		}
		else if( leftIsClear ) {
			turnleft() ;
			move() ;
		}
		else {
			derecha() ;
			move() ;
		}
	}

	void cuentaTamanio(x) {
		if( frontIsClear ) {
			move() ;
			cuentaTamanio( succ(x) ) ;
		}
		else {
			vuelta() ;
			iterate(x)
				move() ;
			derecha() ;

			iterate( 100 ) {
				if( frontIsClear ) {
					vuelta() ;
					if( facingSouth ) {
						checaVer( succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(x)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) ) ;
					}
					else if( facingNorth )  {
						checaVer( pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(x)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) ) ;
					}
					else if( facingWest )  {
						checaHor( succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(x)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) ) ;
					}
					else {
						checaHor( pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(x)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) ) ;
					}
					vuelta() ;
					iterate(x) {
						paso() ;
					}
				}
				paso() ;
			}
		}
	}

	void checaHor(x) {
		quiton0H(x) ;
		paso() ;
		if( facingEast ) {
			checaHor( pred(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(x))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) ) ;
		}
		else if( facingWest )  {
			checaHor( pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(x))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) ) ;
		}
		else {
			checaHor( pred(x) ) ;
		}
	}

	void checaVer(x) {
		quiton0V(x) ;
		paso() ;
		if( facingNorth ) {
			checaVer( pred(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(succ(x))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) ) ;
		}
		else if( facingSouth )  {
			checaVer( pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(pred(x))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) ) ;
		}
		else {
			checaVer( pred(x) ) ;
		}
	}

	void quiton0V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton1V(x); } 
	void quiton1V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton2V(x); } 
	void quiton2V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton3V(x); } 
	void quiton3V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton4V(x); } 
	void quiton4V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton5V(x); } 
	void quiton5V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton6V(x); } 
	void quiton6V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton7V(x); } 
	void quiton7V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton8V(x); } 
	void quiton8V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton9V(x); } 
	void quiton9V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton10V(x); } 
	void quiton10V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton11V(x); } 
	void quiton11V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton12V(x); } 
	void quiton12V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton13V(x); } 
	void quiton13V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton14V(x); } 
	void quiton14V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton15V(x); } 
	void quiton15V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton16V(x); } 
	void quiton16V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton17V(x); } 
	void quiton17V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton18V(x); } 
	void quiton18V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton19V(x); } 
	void quiton19V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton20V(x); } 
	void quiton20V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton21V(x); } 
	void quiton21V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton22V(x); } 
	void quiton22V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton23V(x); } 
	void quiton23V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton24V(x); } 
	void quiton24V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton25V(x); } 
	void quiton25V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton26V(x); } 
	void quiton26V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton27V(x); } 
	void quiton27V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton28V(x); } 
	void quiton28V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton29V(x); } 
	void quiton29V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton30V(x); } 
	void quiton30V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton31V(x); } 
	void quiton31V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton32V(x); } 
	void quiton32V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton33V(x); } 
	void quiton33V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton34V(x); } 
	void quiton34V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton35V(x); } 
	void quiton35V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton36V(x); } 
	void quiton36V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton37V(x); } 
	void quiton37V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton38V(x); } 
	void quiton38V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton39V(x); } 
	void quiton39V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton40V(x); } 
	void quiton40V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton41V(x); } 
	void quiton41V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton42V(x); } 
	void quiton42V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton43V(x); } 
	void quiton43V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton44V(x); } 
	void quiton44V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton45V(x); } 
	void quiton45V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton46V(x); } 
	void quiton46V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton47V(x); } 
	void quiton47V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton48V(x); } 
	void quiton48V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton49V(x); } 
	void quiton49V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton50V(x); } 
	void quiton50V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton51V(x); } 
	void quiton51V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton52V(x); } 
	void quiton52V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton53V(x); } 
	void quiton53V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton54V(x); } 
	void quiton54V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton55V(x); } 
	void quiton55V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton56V(x); } 
	void quiton56V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton57V(x); } 
	void quiton57V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton58V(x); } 
	void quiton58V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton59V(x); } 
	void quiton59V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton60V(x); } 
	void quiton60V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton61V(x); } 
	void quiton61V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton62V(x); } 
	void quiton62V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton63V(x); } 
	void quiton63V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton64V(x); } 
	void quiton64V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton65V(x); } 
	void quiton65V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton66V(x); } 
	void quiton66V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton67V(x); } 
	void quiton67V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton68V(x); } 
	void quiton68V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton69V(x); } 
	void quiton69V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton70V(x); } 
	void quiton70V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton71V(x); } 
	void quiton71V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton72V(x); } 
	void quiton72V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton73V(x); } 
	void quiton73V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton74V(x); } 
	void quiton74V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton75V(x); } 
	void quiton75V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton76V(x); } 
	void quiton76V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton77V(x); } 
	void quiton77V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton78V(x); } 
	void quiton78V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton79V(x); } 
	void quiton79V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton80V(x); } 
	void quiton80V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton81V(x); } 
	void quiton81V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton82V(x); } 
	void quiton82V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton83V(x); } 
	void quiton83V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton84V(x); } 
	void quiton84V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton85V(x); } 
	void quiton85V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton86V(x); } 
	void quiton86V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton87V(x); } 
	void quiton87V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton88V(x); } 
	void quiton88V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton89V(x); } 
	void quiton89V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton90V(x); } 
	void quiton90V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton91V(x); } 
	void quiton91V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton92V(x); } 
	void quiton92V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton93V(x); } 
	void quiton93V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton94V(x); } 
	void quiton94V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton95V(x); } 
	void quiton95V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton96V(x); } 
	void quiton96V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton97V(x); } 
	void quiton97V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton98V(x); } 
	void quiton98V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton99V(x); } 
	void quiton99V(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	} 

	void quiton0H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton1H(x); } 
	void quiton1H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton2H(x); } 
	void quiton2H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton3H(x); } 
	void quiton3H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton4H(x); } 
	void quiton4H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton5H(x); } 
	void quiton5H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton6H(x); } 
	void quiton6H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton7H(x); } 
	void quiton7H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton8H(x); } 
	void quiton8H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton9H(x); } 
	void quiton9H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton10H(x); } 
	void quiton10H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton11H(x); } 
	void quiton11H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton12H(x); } 
	void quiton12H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton13H(x); } 
	void quiton13H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton14H(x); } 
	void quiton14H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton15H(x); } 
	void quiton15H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton16H(x); } 
	void quiton16H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton17H(x); } 
	void quiton17H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton18H(x); } 
	void quiton18H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton19H(x); } 
	void quiton19H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton20H(x); } 
	void quiton20H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton21H(x); } 
	void quiton21H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton22H(x); } 
	void quiton22H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton23H(x); } 
	void quiton23H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton24H(x); } 
	void quiton24H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton25H(x); } 
	void quiton25H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton26H(x); } 
	void quiton26H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton27H(x); } 
	void quiton27H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton28H(x); } 
	void quiton28H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton29H(x); } 
	void quiton29H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton30H(x); } 
	void quiton30H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton31H(x); } 
	void quiton31H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton32H(x); } 
	void quiton32H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton33H(x); } 
	void quiton33H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton34H(x); } 
	void quiton34H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton35H(x); } 
	void quiton35H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton36H(x); } 
	void quiton36H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton37H(x); } 
	void quiton37H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton38H(x); } 
	void quiton38H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton39H(x); } 
	void quiton39H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton40H(x); } 
	void quiton40H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton41H(x); } 
	void quiton41H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton42H(x); } 
	void quiton42H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton43H(x); } 
	void quiton43H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton44H(x); } 
	void quiton44H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton45H(x); } 
	void quiton45H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton46H(x); } 
	void quiton46H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton47H(x); } 
	void quiton47H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton48H(x); } 
	void quiton48H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton49H(x); } 
	void quiton49H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton50H(x); } 
	void quiton50H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton51H(x); } 
	void quiton51H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton52H(x); } 
	void quiton52H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton53H(x); } 
	void quiton53H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton54H(x); } 
	void quiton54H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton55H(x); } 
	void quiton55H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton56H(x); } 
	void quiton56H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton57H(x); } 
	void quiton57H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton58H(x); } 
	void quiton58H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton59H(x); } 
	void quiton59H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton60H(x); } 
	void quiton60H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton61H(x); } 
	void quiton61H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton62H(x); } 
	void quiton62H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton63H(x); } 
	void quiton63H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton64H(x); } 
	void quiton64H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton65H(x); } 
	void quiton65H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton66H(x); } 
	void quiton66H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton67H(x); } 
	void quiton67H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton68H(x); } 
	void quiton68H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton69H(x); } 
	void quiton69H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton70H(x); } 
	void quiton70H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton71H(x); } 
	void quiton71H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton72H(x); } 
	void quiton72H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton73H(x); } 
	void quiton73H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton74H(x); } 
	void quiton74H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton75H(x); } 
	void quiton75H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton76H(x); } 
	void quiton76H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton77H(x); } 
	void quiton77H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton78H(x); } 
	void quiton78H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton79H(x); } 
	void quiton79H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton80H(x); } 
	void quiton80H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton81H(x); } 
	void quiton81H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton82H(x); } 
	void quiton82H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton83H(x); } 
	void quiton83H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton84H(x); } 
	void quiton84H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton85H(x); } 
	void quiton85H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton86H(x); } 
	void quiton86H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton87H(x); } 
	void quiton87H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton88H(x); } 
	void quiton88H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton89H(x); } 
	void quiton89H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton90H(x); } 
	void quiton90H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton91H(x); } 
	void quiton91H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton92H(x); } 
	void quiton92H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton93H(x); } 
	void quiton93H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton94H(x); } 
	void quiton94H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton95H(x); } 
	void quiton95H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton96H(x); } 
	void quiton96H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton97H(x); } 
	void quiton97H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton98H(x); } 
	void quiton98H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	quiton99H(x); } 
	void quiton99H(x) { 	if( iszero(x) ) { 		while( notFacingNorth ) 			turnleft() ; 		turnoff(); 	} 	} 


program() {
	derecha() ;
	cuentaTamanio(0) ;
	while( notFacingSouth )
		turnleft() ;
    turnoff();
}

}


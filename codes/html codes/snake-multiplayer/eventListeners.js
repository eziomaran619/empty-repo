'use strict'
// 'use strict' is used to avoid typos from being taken as variables

addEventListener('keydown',listenerForKeyDown) ;

function listenerForKeyDown(e) {
	var action ;

	for (action in player1.controlKeyCodeForAction) {
		if (e.keyCode == player1.controlKeyCodeForAction[action]) {
			player1.velocity.x = coordinateEquivalentForAction[action].x ;
			player1.velocity.y = coordinateEquivalentForAction[action].y ;
			player1.animationFrameIndex = animationFrameIndexEquivalentForAction[action] ;
		}
	}

	for (action in player2.controlKeyCodeForAction) {
		if (e.keyCode == player2.controlKeyCodeForAction[action]) {
			player2.velocity.x = coordinateEquivalentForAction[action].x ;
			player2.velocity.y = coordinateEquivalentForAction[action].y ;
			player2.animationFrameIndex = animationFrameIndexEquivalentForAction[action] ;
		}
	}
}
'use strict'

Game.prototype.update = function() {
	player1.position.x += player1.velocity.x*player1.speed ;
	player1.position.y += player1.velocity.y*player1.speed ;
} ;